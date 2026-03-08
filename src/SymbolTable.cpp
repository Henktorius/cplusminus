#include "SymbolTable.h"
#include <iomanip>
#include <sstream>

// Helpers
string scopeKindName(ScopeKind k) {
    switch (k) {
        case ScopeKind::PROGRAM: return "PROGRAM";
        case ScopeKind::CLASS:   return "CLASS";
        case ScopeKind::METHOD:  return "METHOD";
        case ScopeKind::BLOCK:   return "BLOCK";
    }
    return "?";
}

static string symbolKindName(SymbolKind k) {
    switch (k) {
        case SymbolKind::CLASS:    return "class";
        case SymbolKind::METHOD:   return "method";
        case SymbolKind::VARIABLE: return "variable";
    }
    return "?";
}

static string indent(int n) { return string(n * 2, ' '); }

// Scope
Scope::~Scope() {
    for (auto& kv : symbols) delete kv.second;
    for (auto* c  : children) delete c;
}

bool Scope::insert(Symbol* sym) {
    if (symbols.count(sym->name)) {
        cerr << "[ST] Error (line " << sym->lineno << "): '"
             << sym->name << "' already declared in "
             << scopeKindName(kind) << " scope '" << name << "'.\n";
        delete sym;
        return false;
    }
    symbols[sym->name] = sym;
    return true;
}

Symbol* Scope::lookupLocal(const string& n) const {
    auto it = symbols.find(n);
    return (it != symbols.end()) ? it->second : nullptr;
}

Symbol* Scope::lookup(const string& n) const {
    Symbol* s = lookupLocal(n);
    return (s || !parent) ? s : parent->lookup(n);
}

// Pretty-printer
void Scope::print(int ind) const {
    // scope header
    cout << indent(ind) << "┌─ " << scopeKindName(kind)
         << " scope: " << (name.empty() ? "<anonymous>" : name) << "\n";

    int col = ind + 1;

    // symbols declared in this scope
    // Print in insertion order using the map (alphabetical).
    // We separate classes, methods, and variables for readability.

    // Collect symbols by kind in original map order (alphabetical by name).
    vector<Symbol*> classes, methods, variables;
    for (auto& kv : symbols) {
        switch (kv.second->kind) {
            case SymbolKind::CLASS:    classes.push_back(kv.second);    break;
            case SymbolKind::METHOD:   methods.push_back(kv.second);    break;
            case SymbolKind::VARIABLE: variables.push_back(kv.second);  break;
        }
    }

    for (auto* s : classes) {
        cout << indent(col) << "│  CLASS    " << s->name
             << "  (line " << s->lineno << ")\n";
    }
    for (auto* s : methods) {
        cout << indent(col) << "│  METHOD   " << s->name
             << "  returns: " << s->type;
        if (!s->params.empty()) {
            cout << "  params: (";
            for (size_t i = 0; i < s->params.size(); ++i) {
                if (i) cout << ", ";
                cout << s->params[i].first << ": " << s->params[i].second;
            }
            cout << ")";
        }
        cout << "  (line " << s->lineno << ")\n";
    }
    for (auto* s : variables) {
        cout << indent(col) << "│  VARIABLE " << s->name
             << "  type: " << s->type;
        if (s->isVolatile) cout << "  [volatile]";
        if (s->isParam)    cout << "  [param]";
        cout << "  (line " << s->lineno << ")\n";
    }

    // recurse into child scopes
    for (auto* child : children)
        child->print(col);

    cout << indent(ind) << "└─ end " << scopeKindName(kind)
         << " '" << (name.empty() ? "<anonymous>" : name) << "'\n";
}

// SymbolTable
SymbolTable::SymbolTable()
    : programScope_(nullptr), current_(nullptr), errors_(false) {}

SymbolTable::~SymbolTable() {
    delete programScope_;
}

// Scope management
Scope* SymbolTable::enterScope(const string& name, ScopeKind kind) {
    int depth = current_ ? current_->depth + 1 : 0;
    Scope* s  = new Scope(name, kind, current_, depth);
    if (current_)
        current_->children.push_back(s);
    current_ = s;
    return s;
}

void SymbolTable::leaveScope() {
    if (current_ && current_->parent)
        current_ = current_->parent;
}

bool SymbolTable::declare(Symbol* sym) {
    bool ok = current_->insert(sym);
    if (!ok) errors_ = true;
    return ok;
}

// Public interface
void SymbolTable::build(Node* root) {
    if (!root) return;
    visitProgram(root);
}

void SymbolTable::print() const {
    cout << "\n╔══════════════════════════════════════════════════════════════╗\n";
    cout <<   "║                      SYMBOL  TABLE                           ║\n";
    cout <<   "╚══════════════════════════════════════════════════════════════╝\n\n";
    if (programScope_)
        programScope_->print(0);
    cout << "\n";
}

// AST visitors
void SymbolTable::visitProgram(Node* node) {
    if (!node || node->type != "Program") {
        cerr << "[ST] Expected 'Program' node at root.\n";
        errors_ = true;
        return;
    }

    programScope_ = enterScope("program", ScopeKind::PROGRAM);

    for (Node* child : node->children) {
        if (child->type == "VarDecls")   {
            for (Node* v : child->children)
                if (v->type == "VarDecl") visitVarDecl(v);
        }
        else if (child->type == "ClassDecls") {
            for (Node* c : child->children)
                if (c->type == "Class") visitClass(c);
        }
        else if (child->type == "Entry") visitEntry(child);
        // "Trailing" – ignored
    }

    // leaveScope() intentionally omitted: programScope_ stays as current_
    // so callers can access it directly without a separate pointer dance.
}

// Class value=className, children: [ClassBody]
void SymbolTable::visitClass(Node* node) {
    const string& className = node->value;

    // Register the class name in the enclosing (program) scope.
    declare(new Symbol(className, SymbolKind::CLASS, "", node->lineno));

    // Open a new scope for the class body.
    enterScope(className, ScopeKind::CLASS);

    for (Node* child : node->children)
        if (child->type == "ClassBody") visitClassBody(child);

    leaveScope();
}

// ClassBody children: mixed VarDecl / Method (in any order)
void SymbolTable::visitClassBody(Node* node) {
    for (Node* child : node->children) {
        if      (child->type == "VarDecl") visitVarDecl(child);
        else if (child->type == "Method")  visitMethod(child);
    }
}

// Entry value="main", children: [Block]
void SymbolTable::visitEntry(Node* node) {
    // Register main() in the program scope.
    Symbol* sym = new Symbol("main", SymbolKind::METHOD, "int", node->lineno);
    declare(sym);

    // Open a method scope for the body.
    enterScope("main", ScopeKind::METHOD);

    for (Node* child : node->children)
        if (child->type == "Block") visitBlock(child);

    leaveScope();
}

// Method value=name, children: [Params, ReturnType, Block]
void SymbolTable::visitMethod(Node* node) {
    const string& methodName = node->value;

    auto it = node->children.begin();
    if (it == node->children.end()) return;

    Node* paramsNode  = *it++;
    Node* retTypeNode = (it != node->children.end()) ? *it++ : nullptr;
    Node* bodyNode    = (it != node->children.end()) ? *it   : nullptr;

    // Build the return-type string.
    string retType = retTypeNode ? resolveType(retTypeNode) : "void";

    // Register the method in the enclosing (class) scope.
    Symbol* sym = new Symbol(methodName, SymbolKind::METHOD, retType, node->lineno);

    // Collect parameter types for the symbol record.
    if (paramsNode) {
        for (Node* p : paramsNode->children) {
            if (p->type == "Param") {
                Node* pTypeNode = p->children.empty() ? nullptr
                                                      : p->children.front();
                string pType = pTypeNode ? resolveType(pTypeNode) : "?";
                sym->params.push_back({p->value, pType});
            }
        }
    }
    declare(sym);

    // Open a method scope.
    enterScope(methodName, ScopeKind::METHOD);

    // Insert parameters as variables inside the method scope.
    if (paramsNode) visitParams(paramsNode);

    // Traverse the method body.
    if (bodyNode && bodyNode->type == "Block") visitBlock(bodyNode);

    leaveScope();
}

// Params
void SymbolTable::visitParams(Node* node) {
    for (Node* p : node->children) {
        if (p->type != "Param") continue;
        Node* typeNode = p->children.empty() ? nullptr : p->children.front();
        string pType   = typeNode ? resolveType(typeNode) : "?";
        declare(new Symbol(p->value, SymbolKind::VARIABLE, pType,
                           p->lineno, /*volatile=*/false, /*param=*/true));
    }
}

// VarDecl value=name
// children variants (from parser):
//   [Type]                       – plain declaration
//   [Type, Expr]                 – declaration with initialiser
//   [Volatile, Type]             – volatile, no init
//   [Volatile, Type, Expr]       – volatile, with init
void SymbolTable::visitVarDecl(Node* node, bool isParam) {
    bool   vol      = isVolatile(node);
    Node*  typeNode = getTypeNode(node);
    string varType  = typeNode ? resolveType(typeNode) : "?";

    // If this is not itself a parameter declaration, make sure the name does
    // not shadow a parameter of the enclosing method.  Shadowing a parameter
    // is illegal in C+-.
    if (!isParam) {
        if (checkParamShadowing(node->value, node->lineno)) {
            return;   // error already recorded; skip insertion
        }
    }

    declare(new Symbol(node->value, SymbolKind::VARIABLE, varType,
                       node->lineno, vol, isParam));
}

// Block children: statement nodes in order.
// Each block opens its own scope so that variables declared inside are
// correctly scoped (e.g. variables in an if-branch are not visible outside).
void SymbolTable::visitBlock(Node* node) {
    // Generate a human-readable label: "block@<line>".
    string label = "block@" + to_string(node->lineno);
    enterScope(label, ScopeKind::BLOCK);

    for (Node* child : node->children)
        visitStmt(child);

    leaveScope();
}

// We only need to recurse into nodes that may contain declarations or nested blocks.
// Expression-only nodes (BinOp, Id, IntLit, …) are intentionally skipped, usage analysis is deferred to the semantic analyser.
void SymbolTable::visitStmt(Node* node) {
    if (!node) return;
    const string& t = node->type;

    if (t == "VarDecl") {
        visitVarDecl(node);
    }
    else if (t == "Block") {
        visitBlock(node);   // nested block → new scope
    }
    else if (t == "If") {
        // children: [expr, stmt]
        auto it = node->children.begin();
        ++it;  // skip condition expression
        if (it != node->children.end()) visitStmt(*it);
    }
    else if (t == "IfElse") {
        // children: [expr, stmt(then), stmt(else)]
        auto it = node->children.begin();
        ++it;  // skip condition
        if (it != node->children.end()) { visitStmt(*it); ++it; }
        if (it != node->children.end())   visitStmt(*it);
    }
    else if (t == "For") {
        // children: [ForInit, ForCond, Assign(update), stmt(body)]
        auto it = node->children.begin();
        if (it != node->children.end()) { visitForInit(*it); ++it; }
        ++it;  // skip ForCond  (expression – no declarations)
        ++it;  // skip update Assign (expression – no declarations)
        if (it != node->children.end())   visitStmt(*it);  // body
    }
    // All other statement types (Assign, Print, Read, Return, Break,
    // Continue, ExprStmt) contain only expressions – nothing to declare.
}

// ForInit is either empty, a VarDecl, or an Assign expression.
// Only VarDecl introduces a new identifier, declared into the current scope
// (the enclosing method/block scope, there is no separate for-header scope
// in C+-, consistent with C-style for loops).
void SymbolTable::visitForInit(Node* node) {
    if (!node) return;
    if (node->type == "VarDecl")  visitVarDecl(node);
    if (node->type == "ForInit") {
        for (Node* child : node->children)
            if (child->type == "VarDecl") visitVarDecl(child);
    }
}


// Helpers
// Convert a type AST node into a plain string representation:
string SymbolTable::resolveType(Node* n) const {
    if (!n) return "?";
    if (n->type == "BaseType") {
        return n->value;            // "int", "float", "boolean"
    }
    if (n->type == "ArrayType") {
        if (n->children.empty()) return "?[]";
        return resolveType(n->children.front()) + "[]";
    }
    if (n->type == "Type") {
        return n->value;            // "void", or a class name like "Fibonacci"
    }
    // Fallback: shouldn't happen with a well-formed AST.
    return n->value.empty() ? n->type : n->value;
}

// Return the type-node child of a VarDecl, skipping an optional "Volatile".
Node* SymbolTable::getTypeNode(Node* varDecl) const {
    auto it = varDecl->children.begin();
    if (it == varDecl->children.end()) return nullptr;
    if ((*it)->type == "Volatile") ++it;   // skip the volatile sentinel
    return (it != varDecl->children.end()) ? *it : nullptr;
}

bool SymbolTable::isVolatile(Node* varDecl) const {
    return !varDecl->children.empty() &&
           varDecl->children.front()->type == "Volatile";
}

// Walk up from current_ until we hit a METHOD scope (or run out of scopes).
// If that METHOD scope contains a *parameter* symbol with the given name,
// return it so the caller can emit a meaningful diagnostic.
Symbol* SymbolTable::checkParamShadowing(const string& name, int lineno) {
    for (Scope* s = current_; s != nullptr; s = s->parent) {
        if (s->kind == ScopeKind::METHOD) {
            Symbol* sym = s->lookupLocal(name);
            if (sym && sym->kind == SymbolKind::VARIABLE && sym->isParam) {
                cerr << "[ST] Error (line " << lineno << "): '"
                     << name << "' shadows parameter declared at line "
                     << sym->lineno << " in method '" << s->name << "'.\n";
                errors_ = true;
                return sym;
            }
            // Stop searching once we reach a METHOD boundary – a param from
            // an outer (unrelated) method is not in scope here anyway.
            break;
        }
    }
    return nullptr;
}
