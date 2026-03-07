#include "SemanticAnalyzer.h"
#include <sstream>

// Constructor
SemanticAnalyzer::SemanticAnalyzer(SymbolTable& st)
    : st_(st),
      current_(st.programScope()),
      currentReturnType_(""),
      currentClassName_(""),
      errorCount_(0),
      warningCount_(0)
{}

// Error reporting
void SemanticAnalyzer::error(int lineno, const string& msg) {
    cerr << "[SA] Error (line " << lineno << "): " << msg << "\n";
    ++errorCount_;
}

void SemanticAnalyzer::warning(int lineno, const string& msg) {
    cerr << "[SA] Warning (line " << lineno << "): " << msg << "\n";
    ++warningCount_;
}

// Control-flow analysis helpers
// Returns true when every execution path through `stmt` is guaranteed to end in a Return statement.
// Rules:
// - Return -> true (obviously)
// - Break / Continue -> false (exits, but not via Return)
// - IfElse(c, t, e) -> definitelyReturns(t) && definitelyReturns(e)
// - If(c, body) -> false (else branch falls through)
// - For(...) -> false (loop might not execute at all)
// - Block -> true if ANY sequential statement definitely returns (that statement is reached; everything after it is dead code)
// - Everything else -> false (assignment, call, print, …)
bool SemanticAnalyzer::definitelyReturns(Node* stmt) {
    if (!stmt) return false;
    const string& t = stmt->type;

    if (t == "Return") return true;

    if (t == "IfElse") {
        auto it = stmt->children.begin();
        if (it == stmt->children.end()) return false;
        ++it; // skip condition
        if (it == stmt->children.end()) return false;
        Node* thenBr = *it++;
        if (it == stmt->children.end()) return false;
        Node* elseBr = *it;
        return definitelyReturns(thenBr) && definitelyReturns(elseBr);
    }

    if (t == "Block") {
        for (Node* child : stmt->children)
            if (definitelyReturns(child)) return true;
        return false;
    }

    return false;
}

// Returns true when every execution path through `stmt` is guaranteed to
// exit via Return, Break, or Continue (i.e. the statement never falls through
// to the next statement in its enclosing block).
// Same structural rules as definitelyReturns, but Break and Continue also
// count as definite exits.
bool SemanticAnalyzer::isDefiniteExit(Node* stmt) {
    if (!stmt) return false;
    const string& t = stmt->type;

    if (t == "Return" || t == "Break" || t == "Continue") return true;

    if (t == "IfElse") {
        auto it = stmt->children.begin();
        if (it == stmt->children.end()) return false;
        ++it; // skip condition
        if (it == stmt->children.end()) return false;
        Node* thenBr = *it++;
        if (it == stmt->children.end()) return false;
        Node* elseBr = *it;
        return isDefiniteExit(thenBr) && isDefiniteExit(elseBr);
    }

    if (t == "Block") {
        for (Node* child : stmt->children)
            if (isDefiniteExit(child)) return true;
        return false;
    }

    return false;
}

// Scope navigation
// Both the ST builder and this analyser traverse the AST in the same DFS order.
// Every time the ST builder opened a new scope, we advance the cursor by one
// child. pushScope() enters that child; popScope() returns to the parent.
void SemanticAnalyzer::pushScope() {
    size_t& idx = cursor_[current_];
    if (idx < current_->children.size()) {
        current_ = current_->children[idx++];
    }
    // If idx is out of range the AST and ST are out of sync – this indicates a
    // bug in the ST builder, not in user code; we silently stay where we are.
}

void SemanticAnalyzer::popScope() {
    if (current_->parent)
        current_ = current_->parent;
}

// Public entry point
void SemanticAnalyzer::analyze(Node* root) {

    cout << "\n╔══════════════════════════════════════════════════════════════╗\n";
    cout <<   "║                     SEMANTIC ANALYSIS                        ║\n";
    cout <<   "╚══════════════════════════════════════════════════════════════╝\n\n";
    if (!root || root->type != "Program") {
        error(0, "Expected 'Program' root node.");
        return;
    }
    // current_ is already programScope_ (set in constructor).
    visitProgram(root);
}

// Top-level visitors
// Program children: [VarDecls, ClassDecls, Entry, Trailing]
void SemanticAnalyzer::visitProgram(Node* node) {
    for (Node* child : node->children) {
        if (child->type == "VarDecls") {
            for (Node* v : child->children)
                if (v->type == "VarDecl") visitVarDecl(v);
        }
        else if (child->type == "ClassDecls") {
            for (Node* c : child->children)
                if (c->type == "Class") visitClass(c);
        }
        else if (child->type == "Entry") {
            visitEntry(child);
        }
        // "Trailing" – ignored
    }
}

// Class value=className, children: [ClassBody]
void SemanticAnalyzer::visitClass(Node* node) {
    string prevClass = currentClassName_;
    currentClassName_ = node->value;

    // Enter the CLASS scope that the ST builder created for this class.
    pushScope();

    for (Node* child : node->children) {
        if (child->type == "ClassBody") {
            for (Node* member : child->children) {
                if      (member->type == "VarDecl") visitVarDecl(member);
                else if (member->type == "Method")  visitMethod(member);
            }
        }
    }

    popScope();
    currentClassName_ = prevClass;
}

// Entry value="main", children: [Block]
void SemanticAnalyzer::visitEntry(Node* node) {
    string prevReturn = currentReturnType_;
    currentReturnType_ = "int";

    // Enter the METHOD scope for "main".
    pushScope();

    Node* body = nullptr;
    for (Node* child : node->children)
        if (child->type == "Block") { body = child; break; }

    if (body) {
        visitBlock(body);

        // main() must always return an int on every path.
        if (!definitelyReturns(body)) {
            error(node->lineno,
                  "Method 'main' may not return a value on all execution paths.");
        }
    }

    popScope();
    currentReturnType_ = prevReturn;
}

// Method value=name, children: [Params, ReturnType, Block]
// (no-param variant also has [Params(empty), ReturnType, Block])
void SemanticAnalyzer::visitMethod(Node* node) {
    // Retrieve the already-declared method symbol for its return type.
    Symbol* sym = current_->lookupLocal(node->value);
    string retType = sym ? sym->type : "?";

    string prevReturn = currentReturnType_;
    currentReturnType_ = retType;

    // Enter the METHOD scope.
    pushScope();

    // Find the Block child (skip Params and ReturnType nodes).
    Node* body = nullptr;
    for (Node* child : node->children)
        if (child->type == "Block") { body = child; break; }

    if (body) {
        visitBlock(body);

        // Non-void methods must return a value on every execution path.
        if (retType != "void" && retType != "?" && !definitelyReturns(body)) {
            error(node->lineno,
                  "Method '" + node->value + "' (return type '" + retType +
                  "') may not return a value on all execution paths.");
        }
    }

    popScope();
    currentReturnType_ = prevReturn;
}

// Local helper: human-readable name of the exit kind for warning messages.
static string exitKindName(Node* stmt) {
    if (!stmt) return "exit";
    if (stmt->type == "Return")   return "return";
    if (stmt->type == "Break")    return "break";
    if (stmt->type == "Continue") return "continue";
    // IfElse where both branches exit — name the construct.
    return "unconditional exit";
}

// Block children: statement nodes in order.
void SemanticAnalyzer::visitBlock(Node* node) {
    // Enter the BLOCK scope created by the ST builder.
    pushScope();

 bool exitSeen = false; // true once a definite-exit statement was found
 int exitLineno = 0; // line of the first definite-exit statement
 bool warnedOnce = false; // suppress duplicate "unreachable" warnings

    for (Node* child : node->children) {
        // Unreachable-code check
        // Report the FIRST unreachable statement once; then silently type-check
        // all subsequent ones (so we don't miss cascading type errors inside
        // unreachable regions, and scope push/pop stays balanced).
        if (exitSeen && !warnedOnce) {
            warning(child->lineno,
                    "Unreachable code after "
 + exitKindName(child) // "return" / "break" / "continue"
                    + " on line " + to_string(exitLineno) + ".");
            warnedOnce = true;
        }

        // Always type-check, even if unreachable (scope balance + deeper errors).
        visitStmt(child);

        // Record the first definite-exit statement
        if (!exitSeen && isDefiniteExit(child)) {
            exitSeen   = true;
            exitLineno = child->lineno;
        }
    }

    popScope();
}

// Statement dispatcher
void SemanticAnalyzer::visitStmt(Node* node) {
    if (!node) return;
    const string& t = node->type;

    if      (t == "VarDecl")  visitVarDecl(node);
    else if (t == "Assign")   visitAssign(node);
    else if (t == "If")       visitIf(node);
    else if (t == "IfElse")   visitIfElse(node);
    else if (t == "For")      visitFor(node);
    else if (t == "Print")    visitPrint(node);
    else if (t == "Read")     visitRead(node);
    else if (t == "Return")   visitReturn(node);
    else if (t == "ExprStmt") visitExprStmt(node);
    else if (t == "Block")    visitBlock(node);
    // Break, Continue – no type checking needed.
}

// Statement checkers
// VarDecl value=name
// children: [Type] | [Type,Expr] | [Volatile,Type] | [Volatile,Type,Expr]
void SemanticAnalyzer::visitVarDecl(Node* node) {
    // Find the type node (skip optional Volatile child).
    auto it = node->children.begin();
    if (it == node->children.end()) return;
    if ((*it)->type == "Volatile") ++it;
    if (it == node->children.end()) return;
    Node* typeNode = *it;
    ++it;

    // Get the declared type string from the symbol already in the ST.
    Symbol* sym = current_->lookupLocal(node->value);
    string declaredType = sym ? sym->type : "?";

    // Validate array types: only primitive-element arrays are allowed.
    if (isArray(declaredType)) {
        string elem = elementType(declaredType);
        if (!isNumeric(elem) && elem != "boolean") {
            error(node->lineno, "Only primitive arrays (int[], float[], boolean[]) "
                  "are allowed; '" + declaredType + "' is not permitted.");
        }
    }

    // Validate class types: every class-typed variable must name a class that
    // is actually declared somewhere in the program.  Primitive types, array
    // types, and the sentinel values "?" / "error" / "void" are exempt.
    if (isClass(declaredType) && !findClassScope(declaredType)) {
        error(node->lineno,
              "Variable '" + node->value + "' is declared with unknown class type '"
              + declaredType + "'; no such class exists.");
    }

    // Check the initialiser expression (if present).
    if (it != node->children.end()) {
        Node* initExpr = *it;
        string initType = typeOf(initExpr);

        if (initType != "error" && declaredType != "?" &&
            !assignCompatible(declaredType, initType)) {
            error(node->lineno,
                  "Cannot initialise '" + node->value + "' (type '" + declaredType +
                  "') with expression of type '" + initType + "'.");
        }
    }
}

// Assign children: [lhs_expr, rhs_expr]
void SemanticAnalyzer::visitAssign(Node* node) {
    auto it = node->children.begin();
    if (it == node->children.end()) return;
    Node* lhsNode = *it++;
    if (it == node->children.end()) return;
    Node* rhsNode = *it;

    string lhsType = typeOf(lhsNode);
    string rhsType = typeOf(rhsNode);

    if (lhsType == "error" || rhsType == "error") return;

    if (!assignCompatible(lhsType, rhsType)) {
        error(node->lineno,
              "Type mismatch in assignment: cannot assign '" + rhsType +
              "' to '" + lhsType + "'.");
    }
}

// If children: [cond_expr, body_stmt]
void SemanticAnalyzer::visitIf(Node* node) {
    auto it = node->children.begin();
    if (it == node->children.end()) return;
    Node* cond = *it++;

    string condType = typeOf(cond);
    if (condType != "error" && condType != "boolean") {
        error(node->lineno,
              "Condition in 'if' must be boolean, got '" + condType + "'.");
    }

    if (it != node->children.end()) visitStmt(*it);
}

// IfElse children: [cond_expr, then_stmt, else_stmt]
void SemanticAnalyzer::visitIfElse(Node* node) {
    auto it = node->children.begin();
    if (it == node->children.end()) return;
    Node* cond = *it++;

    string condType = typeOf(cond);
    if (condType != "error" && condType != "boolean") {
        error(node->lineno,
              "Condition in 'if' must be boolean, got '" + condType + "'.");
    }

    if (it != node->children.end()) { visitStmt(*it); ++it; }
    if (it != node->children.end())   visitStmt(*it);
}

// For children: [for_init, for_cond, Assign(update), body_stmt]
void SemanticAnalyzer::visitFor(Node* node) {
    auto it = node->children.begin();
    if (it == node->children.end()) return;

    // init
    Node* initNode = *it++;
    if (initNode->type == "VarDecl")  visitVarDecl(initNode);
    else if (initNode->type == "Assign") visitAssign(initNode);
    // ForInit (empty sentinel) → nothing to check

    if (it == node->children.end()) return;

    // condition
    Node* condNode = *it++;
    // ForCond (empty sentinel) is allowed (infinite loop).
    if (condNode->type != "ForCond") {
        string condType = typeOf(condNode);
        if (condType != "error" && condType != "boolean") {
            error(condNode->lineno,
                  "For-loop condition must be boolean, got '" + condType + "'.");
        }
    }

    if (it == node->children.end()) return;

    // update
    Node* updateNode = *it++;
    if (updateNode->type == "Assign") visitAssign(updateNode);

    if (it == node->children.end()) return;

    // body
    visitStmt(*it);
}

// Print children: [expr]
void SemanticAnalyzer::visitPrint(Node* node) {
    if (node->children.empty()) return;
    string t = typeOf(node->children.front());
    // Any non-void, non-error type is printable.
    if (t != "error" && t == "void") {
        error(node->lineno, "Cannot print a void expression.");
    }
}

// Read children: [expr] (expr must be a variable reference)
void SemanticAnalyzer::visitRead(Node* node) {
    if (node->children.empty()) return;
    Node* target = node->children.front();
    if (target->type != "Id" && target->type != "ArrayAccess") {
        error(node->lineno, "'read' requires an l-value (variable or array element).");
    }
 typeOf(target); // triggers undeclared-identifier check
}

// Return children: [expr]
void SemanticAnalyzer::visitReturn(Node* node) {
    if (node->children.empty()) {
        if (currentReturnType_ != "void") {
            error(node->lineno,
                  "Empty 'return' in method that returns '" +
                  currentReturnType_ + "'.");
        }
        return;
    }

    string retType = typeOf(node->children.front());
    if (retType == "error") return;

    if (currentReturnType_.empty()) {
        error(node->lineno, "'return' used outside a method.");
        return;
    }

    if (!assignCompatible(currentReturnType_, retType)) {
        error(node->lineno,
              "Return type mismatch: method returns '" + currentReturnType_ +
              "' but expression has type '" + retType + "'.");
    }
}

// ExprStmt children: [expr]
void SemanticAnalyzer::visitExprStmt(Node* node) {
    if (!node->children.empty())
        typeOf(node->children.front());
}

// Expression type inference
string SemanticAnalyzer::typeOf(Node* node) {
    if (!node) return "error";
    const string& t = node->type;

    if (t == "IntLit")    return "int";
    if (t == "FloatLit")  return "float";
    if (t == "BoolLit")   return "boolean";

    if (t == "BinOp")         return typeOfBinOp(node);
    if (t == "Not")           return typeOfNot(node);
    if (t == "Id")            return typeOfId(node);
    if (t == "ArrayAccess")   return typeOfArrayAccess(node);
    if (t == "FieldAccess")   return typeOfFieldAccess(node);
    if (t == "Call")          return typeOfCall(node);
    if (t == "MethodCall")    return typeOfMethodCall(node);
    if (t == "ArrayLit")      return typeOfArrayLit(node);

    // Should not normally be reached with a well-formed AST.
    return "error";
}

// BinOp
string SemanticAnalyzer::typeOfBinOp(Node* node) {
    auto it = node->children.begin();
    if (it == node->children.end()) return "error";
    string lhs = typeOf(*it++);
    if (it == node->children.end()) return "error";
    string rhs = typeOf(*it);
    const string& op = node->value;

    if (lhs == "error" || rhs == "error") return "error";

    // Logical operators: &, |
    if (op == "&" || op == "|") {
        if (lhs != "boolean" || rhs != "boolean") {
            error(node->lineno,
                  "Operator '" + op + "' requires boolean operands, got '" +
                  lhs + "' and '" + rhs + "'.");
            return "error";
        }
        return "boolean";
    }

    // Relational operators: <, >, <=, >=
    if (op == "<" || op == ">" || op == "<=" || op == ">=") {
        if (!isNumeric(lhs) || !isNumeric(rhs)) {
            error(node->lineno,
                  "Operator '" + op + "' requires numeric operands, got '" +
                  lhs + "' and '" + rhs + "'.");
            return "error";
        }
        return "boolean";
    }

    // Equality operators: =, !=
    // Allow comparison of two numerics (with widening) or two identical types.
    if (op == "=" || op == "!=") {
        bool bothNumeric  = isNumeric(lhs) && isNumeric(rhs);
        bool sameType     = (lhs == rhs);
        if (!bothNumeric && !sameType) {
            error(node->lineno,
                  "Operator '" + op + "' requires operands of the same type, got '" +
                  lhs + "' and '" + rhs + "'.");
            return "error";
        }
        return "boolean";
    }

    // Arithmetic operators: +, -, *, /, ^
    if (op == "+" || op == "-" || op == "*" || op == "/" || op == "^") {
        if (!isNumeric(lhs) || !isNumeric(rhs)) {
            error(node->lineno,
                  "Operator '" + op + "' requires numeric operands, got '" +
                  lhs + "' and '" + rhs + "'.");
            return "error";
        }
        return numericResult(lhs, rhs);
    }

    error(node->lineno, "Unknown operator '" + op + "'.");
    return "error";
}

// Not
string SemanticAnalyzer::typeOfNot(Node* node) {
    if (node->children.empty()) return "error";
    string inner = typeOf(node->children.front());
    if (inner == "error") return "error";
    if (inner != "boolean") {
        error(node->lineno,
              "Operator '!' requires boolean operand, got '" + inner + "'.");
        return "error";
    }
    return "boolean";
}

// Id
string SemanticAnalyzer::typeOfId(Node* node) {
    Symbol* sym = current_->lookup(node->value);
    if (!sym) {
        error(node->lineno,
              "Undeclared identifier '" + node->value + "'.");
        return "error";
    }
    // Use-before-declaration: reject any reference to a variable or parameter
    // whose VarDecl / parameter declaration appears later in the source than
    // this usage site.  Methods and class names are hoisted, so they are exempt.
    // A lineno of 0 on the symbol means it was synthesised (e.g. a built-in),
    // and is also exempt.
    if (sym->kind != SymbolKind::METHOD && sym->kind != SymbolKind::CLASS &&
        sym->lineno > 0 && sym->lineno > node->lineno) {
        error(node->lineno,
              "Variable '" + node->value + "' is used before its declaration "
              "(declared on line " + to_string(sym->lineno) + ").");
        return "error";
    }
    // Methods should be called via Call/MethodCall, not used as values.
    if (sym->kind == SymbolKind::METHOD) {
        error(node->lineno,
              "'" + node->value + "' is a method and cannot be used as a value.");
        return "error";
    }
    // CLASS names used as bare identifiers are only valid in call expressions.
    if (sym->kind == SymbolKind::CLASS) {
        error(node->lineno,
              "'" + node->value + "' is a class name and cannot be used as a value.");
        return "error";
    }
    return sym->type;
}

// ArrayAccess expr[expr]
string SemanticAnalyzer::typeOfArrayAccess(Node* node) {
    auto it = node->children.begin();
    if (it == node->children.end()) return "error";
    string arrType  = typeOf(*it++);
    if (it == node->children.end()) return "error";
    string idxType  = typeOf(*it);

    if (arrType == "error" || idxType == "error") return "error";

    if (!isArray(arrType)) {
        error(node->lineno,
              "Array subscript applied to non-array type '" + arrType + "'.");
        return "error";
    }
    if (idxType != "int") {
        error(node->lineno,
              "Array index must be 'int', got '" + idxType + "'.");
        return "error";
    }
    return elementType(arrType);
}

// FieldAccess expr.length
string SemanticAnalyzer::typeOfFieldAccess(Node* node) {
    if (node->children.empty()) return "error";
    string objType = typeOf(node->children.front());
    if (objType == "error") return "error";

    // Only "length" field access exists in C+-.
    if (node->value == "length") {
        if (!isArray(objType)) {
            error(node->lineno,
                  "'.length' can only be applied to an array type, got '" +
                  objType + "'.");
            return "error";
        }
        return "int";
    }

    error(node->lineno, "Unknown field access '." + node->value + "'.");
    return "error";
}

// Call ID(args)
string SemanticAnalyzer::typeOfCall(Node* node) {
    const string& name = node->value;
    Node* argsNode = node->children.empty() ? nullptr : node->children.front();

    // Look up the name in the current scope chain.
    Symbol* sym = current_->lookup(name);

    if (!sym) {
        error(node->lineno, "Call to undeclared function/constructor '" + name + "'.");
        // Still evaluate args to catch nested errors.
        if (argsNode) for (Node* a : argsNode->children) typeOf(a);
        return "error";
    }

    // Constructor call: the name resolves to a CLASS symbol.
    if (sym->kind == SymbolKind::CLASS) {
        // Constructor takes no arguments in C+- (all tests confirm this).
        if (argsNode && !argsNode->children.empty()) {
            error(node->lineno,
                  "Constructor '" + name + "' takes no arguments.");
        }
 return name; // type is the class name
    }

    // Regular method call.
    if (sym->kind == SymbolKind::METHOD) {
        if (argsNode) checkArgs(argsNode, sym, node->lineno);
        return sym->type;
    }

    // Calling a variable as a function.
    error(node->lineno, "'" + name + "' is not a function.");
    return "error";
}

// MethodCall expr.ID(args)
string SemanticAnalyzer::typeOfMethodCall(Node* node) {
    // children: [object_expr, Args]
    auto it = node->children.begin();
    if (it == node->children.end()) return "error";
    Node* objNode  = *it++;
    Node* argsNode = (it != node->children.end()) ? *it : nullptr;

    string objType = typeOf(objNode);
    if (objType == "error") return "error";

    const string& methodName = node->value;

    // The object must be of a class type (not a primitive or array).
    if (isNumeric(objType) || objType == "boolean" || isArray(objType)) {
        error(node->lineno,
              "Cannot call method '" + methodName + "' on value of type '" +
              objType + "'. Expected a class instance.");
        return "error";
    }

    // Look up the method in that class.
    Symbol* method = findMethodSymbol(objType, methodName);
    if (!method) {
        error(node->lineno,
              "Class '" + objType + "' has no method '" + methodName + "'.");
        if (argsNode) for (Node* a : argsNode->children) typeOf(a);
        return "error";
    }

    if (argsNode) checkArgs(argsNode, method, node->lineno);
    return method->type;
}

// ArrayLit baseType[args]
string SemanticAnalyzer::typeOfArrayLit(Node* node) {
    // children: [BaseType, Args]
    auto it = node->children.begin();
    if (it == node->children.end()) return "error";
    Node* baseTypeNode = *it++;
    Node* argsNode     = (it != node->children.end()) ? *it : nullptr;

 // Only primitive element types are allowed.
 string base = baseTypeNode->value; // "int" | "float" | "boolean"
    if (!isNumeric(base) && base != "boolean") {
        error(node->lineno,
              "Array literals must use primitive element types (int/float/boolean), "
              "got '" + base + "'.");
        return "error";
    }

    string arrayType = base + "[]";

    if (argsNode) {
        for (Node* elem : argsNode->children) {
            string et = typeOf(elem);
            if (et != "error" && !assignCompatible(base, et)) {
                error(elem->lineno,
                      "Array literal element has type '" + et +
                      "' but array element type is '" + base + "'.");
            }
        }
    }

    return arrayType;
}

// Argument checking helper
bool SemanticAnalyzer::checkArgs(Node* argsNode, Symbol* sym, int lineno) {
    vector<Node*> argExprs(argsNode->children.begin(),
                           argsNode->children.end());

    const auto& params = sym->params;

    if (argExprs.size() != params.size()) {
        error(lineno,
              "Call to '" + sym->name + "': expected " +
              to_string(params.size()) + " argument(s), got " +
              to_string(argExprs.size()) + ".");
        for (Node* a : argExprs) typeOf(a);
        return false;
    }

    bool ok = true;
    for (size_t i = 0; i < params.size(); ++i) {
        string argType = typeOf(argExprs[i]);
        const string& paramType = params[i].second;
        if (argType != "error" && !assignCompatible(paramType, argType)) {
            error(argExprs[i]->lineno,
                  "Argument " + to_string(i + 1) + " to '" + sym->name +
                  "': expected '" + paramType + "', got '" + argType + "'.");
            ok = false;
        }
    }
    return ok;
}

// Type predicate and utility helpers
bool SemanticAnalyzer::isNumeric(const string& t) const {
    return t == "int" || t == "float";
}

bool SemanticAnalyzer::isArray(const string& t) const {
    return t.size() > 2 && t.substr(t.size() - 2) == "[]";
}

bool SemanticAnalyzer::isClass(const string& t) const {
    return !t.empty() && !isNumeric(t) && t != "boolean" &&
           t != "void" && !isArray(t) && t != "error" && t != "?";
}

string SemanticAnalyzer::elementType(const string& arrayType) const {
    if (isArray(arrayType))
        return arrayType.substr(0, arrayType.size() - 2);
    return arrayType;
}

// Returns the wider of two numeric types.
string SemanticAnalyzer::numericResult(const string& a, const string& b) const {
    if (a == "float" || b == "float") return "float";
    return "int";
}

// rhs is assignable to a variable of type lhs when:
// • types are exactly equal, OR
// • rhs is int and lhs is float (numeric widening).
bool SemanticAnalyzer::assignCompatible(const string& lhsType,
                                        const string& rhsType) const {
    if (lhsType == rhsType) return true;
    if (lhsType == "float" && rhsType == "int") return true;
    return false;
}

// Scope/symbol search helpers
// Search the program scope's children for a CLASS scope with the given name.
Scope* SemanticAnalyzer::findClassScope(const string& className) const {
    Scope* prog = st_.programScope();
    if (!prog) return nullptr;
    for (Scope* child : prog->children) {
        if (child->kind == ScopeKind::CLASS && child->name == className)
            return child;
    }
    return nullptr;
}

// Find a METHOD symbol in the CLASS scope of `className`.
Symbol* SemanticAnalyzer::findMethodSymbol(const string& className,
                                           const string& methodName) const {
    Scope* cls = findClassScope(className);
    if (!cls) return nullptr;
    Symbol* sym = cls->lookupLocal(methodName);
    return (sym && sym->kind == SymbolKind::METHOD) ? sym : nullptr;
}
