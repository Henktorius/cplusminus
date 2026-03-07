#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Node.h"
#include "SymbolTable.h"

using namespace std;

// SemanticAnalyzer
// Performs a second, left-to-right DFS over the AST using the already-built
// SymbolTable. It navigates the ST's scope tree with a child-cursor map so
// that every lookup uses the same scope chain that was used when the ST was
// populated (no re-building of scopes).
class SemanticAnalyzer {
public:
    explicit SemanticAnalyzer(SymbolTable& st);

    // Run the analysis.  Call after SymbolTable::build().
    void analyze(Node* root);

    bool hasErrors()    const { return errorCount_ > 0; }
    int  errorCount()   const { return errorCount_; }
    int  warningCount() const { return warningCount_; }

private:
    // State
    SymbolTable& st_;
    Scope*       current_;               // position in the ST scope tree
    map<Scope*, size_t> cursor_;         // next-child index per scope

    string currentReturnType_;           // declared return type of enclosing method
    string currentClassName_;            // name of the class being analysed

    int    errorCount_;
    int    warningCount_;

    // Error / warning reporting
    void error  (int lineno, const string& msg);
    void warning(int lineno, const string& msg);

    // Scope navigation (mirrors ST builder traversal order)
    // Push: advance into the next child of current_ (in declaration order).
    void pushScope();
    // Pop: return to parent scope.
    void popScope();

    // Top-level statement visitors
    void visitProgram  (Node* node);
    void visitClass    (Node* node);
    void visitEntry    (Node* node);
    void visitMethod   (Node* node);
    void visitBlock    (Node* node);
    void visitStmt     (Node* node);    // dispatcher for all statement types
    void visitVarDecl  (Node* node);
    void visitAssign   (Node* node);
    void visitIf       (Node* node);
    void visitIfElse   (Node* node);
    void visitFor      (Node* node);
    void visitPrint    (Node* node);
    void visitRead     (Node* node);
    void visitReturn   (Node* node);
    void visitExprStmt (Node* node);

    // Expression type inference
    // Returns the inferred type string, or "error" on failure.
    string typeOf         (Node* node);
    string typeOfBinOp    (Node* node);
    string typeOfNot      (Node* node);
    string typeOfId       (Node* node);
    string typeOfArrayAccess (Node* node);
    string typeOfFieldAccess (Node* node);
    string typeOfCall     (Node* node);
    string typeOfMethodCall  (Node* node);
    string typeOfArrayLit    (Node* node);

    // Type predicates and utilities
    bool   isNumeric (const string& t) const;
    bool   isArray   (const string& t) const;
    bool   isClass   (const string& t) const;
    // "int[]" → "int"
    string elementType (const string& arrayType) const;
    // Widened numeric type: (int,float)→float, (int,int)→int, etc.
    string numericResult (const string& a, const string& b) const;
    // True when rhs is assignable to a variable of type lhs
    // (exact match, or int widened to float).
    bool   assignCompatible (const string& lhsType, const string& rhsType) const;

    // Scope/symbol search helpers
    // Walk programScope_->children to find the CLASS scope named `className`.
    Scope*  findClassScope  (const string& className)  const;
    // Within a class scope, find the METHOD symbol named `methodName`.
    Symbol* findMethodSymbol(const string& className,
                             const string& methodName) const;

    // Argument checking
    // Check that the arg list (children of an Args node) matches the
    // param list recorded on `sym`.  Reports errors and returns false on mismatch.
    bool checkArgs(Node* argsNode, Symbol* sym, int callLineno);

    // Control-flow analysis
    static bool definitelyReturns(Node* stmt); // no missing return statement
    static bool isDefiniteExit   (Node* stmt); // no unreachable code
};

#endif // SEMANTIC_ANALYZER_H
