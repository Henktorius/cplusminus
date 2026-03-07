#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Node.h"

using namespace std;

// What kind of identifier a symbol represents
enum class SymbolKind {
    CLASS,
    METHOD,
    VARIABLE
};

// A single entry in the symbol table.
struct Symbol {
    string       name;
    SymbolKind   kind;
    string       type;         // return type for METHOD; data type for VARIABLE
    bool         isVolatile;   // only meaningful for VARIABLE
    bool         isParam;      // true when the variable was a method parameter
    int          lineno;

    // For METHOD symbols: ordered list of (paramName, paramType) pairs
    vector<pair<string,string>> params;

    // Constructors
    Symbol(string n, SymbolKind k, string t, int ln,
           bool vol = false, bool param = false)
        : name(n), kind(k), type(t), isVolatile(vol),
          isParam(param), lineno(ln) {}
};

// What kind of scope a Scope node represents in the hierarchy
enum class ScopeKind {
    PROGRAM,
    CLASS,
    METHOD,
    BLOCK
};

string scopeKindName(ScopeKind k);

// A single scope.
class Scope {
public:
    string           name;      // meaningful label (class name, method name, …)
    ScopeKind        kind;
    Scope*           parent;
    int              depth;     // distance from program scope (for indentation)

    map<string, Symbol*>  symbols;   // symbols declared directly in this scope
    vector<Scope*>        children;  // child scopes in declaration order

    Scope(string n, ScopeKind k, Scope* p, int d)
        : name(n), kind(k), parent(p), depth(d) {}

    ~Scope();

    // Insert a symbol; returns false (and prints a warning) on duplicate.
    bool insert(Symbol* sym);

    // Look up only in this scope.
    Symbol* lookupLocal(const string& name) const;

    // Look up in this scope then walk up the parent chain.
    Symbol* lookup(const string& name) const;

    // Pretty-print the entire scope subtree.
    void print(int indent = 0) const;
};

// The symbol table.
class SymbolTable {
public:
    SymbolTable();
    ~SymbolTable();

    // Main entry point: traverse the AST and populate the table.
    void build(Node* root);

    // Print the complete symbol table to stdout.
    void print() const;

    // Whether any errors were detected during construction.
    bool hasErrors() const { return errors_; }

    // Access the outermost scope (useful for later analysis phases).
    Scope* programScope() const { return programScope_; }

private:
    Scope* programScope_;   // root of the scope tree
    Scope* current_;        // scope active during traversal
    bool   errors_;

    // Scope management
    Scope* enterScope(const string& name, ScopeKind kind);
    void   leaveScope();
    bool   declare(Symbol* sym);

    // AST visitors
    void visitProgram   (Node* node);
    void visitClass     (Node* node);
    void visitClassBody (Node* node);
    void visitEntry     (Node* node);
    void visitMethod    (Node* node);
    void visitParams    (Node* node);          // registers params as variables
    void visitVarDecl   (Node* node, bool isParam = false);
    void visitBlock     (Node* node);
    void visitStmt      (Node* node);
    void visitForInit   (Node* node);

    // Helpers
    // Convert a type AST node (BaseType / ArrayType / Type) to a string.
    string resolveType(Node* typeNode) const;

    // Return the type node from a VarDecl's child list,
    // skipping an optional leading "Volatile" child.
    Node*  getTypeNode(Node* varDecl) const;

    // True when the first child of a VarDecl is the "Volatile" sentinel.
    bool   isVolatile(Node* varDecl) const;
};

#endif // SYMBOL_TABLE_H
