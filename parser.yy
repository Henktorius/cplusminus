/* Skeleton and definitions for generating a LALR(1) parser in C++ */
%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

/* Required code included before the parser definition begins */
%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}

/* Code included in the parser implementation file */
%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

/* Token definitions for the grammar */
/* Tokens represent the smallest units of the language, like operators and parentheses */
%token <std::string> PLUSOP SUBOP MULTOP INT LP RP ASS TYPEDEF COMMA LS RS LL RL AND OR GTE LTE NE NOT EQL GT LT DIVOP POW PRD VAR CLASS VOL INT_T FLOAT_T BOOL_T IF ELSE FOR RET BREAK CONT PRINT READ LEN TRUE FALSE ID
%token END 0 "end of file"

/* Operator precedence and associativity rules */
/* Used to resolve ambiguities in parsing expressions See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl */ 
/* Precedence is processed from bottom to top */
%right ASS
%left OR
%left AND
%left EQL NE
%left GT LT GTE LTE
%left PLUSOP SUBOP
%left MULTOP DIVOP
%left POW

/* Specify types for non-terminals in the grammar */
/* The type specifies the data type of the values associated with these non-terminals */
%type <Node *> root program expression
%type <Node *> assignment declaration volatile_declaration nonvolatile_declaration
%type <Node *> arithmetic_expr logic_expr math_expr
%type <Node *> type
%type <Node *> builtin

/* Grammar rules section */
/* This section defines the production rules for the language being parsed */
%%
root:       program {root = $1;};

program:
    program expression {
        $1->children.push_back($2);
        $$ = $1;
    }
    | expression {
        $$ = new Node("Program", "", yylineno);
        $$->children.push_back($1);
    }
    ;

expression:
    declaration terminator { $$ = $1; }
    | assignment terminator { $$ = $1; }
    | math_expr terminator { $$ = $1; }
    | builtin terminator { $$ = $1; }
    | RET math_expr terminator {
        $$ = new Node("Return", "", yylineno);
        $$->children.push_back($2);
    }
    | '{' program '}' { $$ = $2; }
    ;

terminator:
    '\n'
    | /* empty */
    ;

declaration:
    nonvolatile_declaration { $$ = $1; }
    | volatile_declaration { $$ = $1; }
    ;

nonvolatile_declaration:
    type assignment {
        $$ = new Node("DeclarationAssign", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($2);
    }
    ;

volatile_declaration:
    VOL type ID {
        $$ = new Node("VolatileDeclaration", "", yylineno);
        $$->children.push_back($2);
        $$->children.push_back(new Node("Id", $3, yylineno));
    }
    | VOL nonvolatile_declaration {
        $$ = new Node("VolatileDeclaration", "", yylineno);
        $$->children.push_back($2);
    }
    ;

assignment:
    ID ASS arithmetic_expr {
        $$ = new Node("Assignment", "", yylineno);
        $$->children.push_back(new Node("Id", $1, yylineno));
        $$->children.push_back($3);
    }
    | ID ASS logic_expr {
        $$ = new Node("Assignment", "", yylineno);
        $$->children.push_back(new Node("Id", $1, yylineno));
        $$->children.push_back($3);
    }
    ;

type:
    INT_T { $$ = new Node("Type", "int", yylineno); }
    | FLOAT_T { $$ = new Node("Type", "float", yylineno); }
    | BOOL_T { $$ = new Node("Type", "bool", yylineno); }

builtin:
    PRINT LP ID RP {
        $$ = new Node("PrintVar", "", yylineno);
        $$->children.push_back(new Node("Id", $3, yylineno));
    }
    | READ LP ID RP {
        $$ = new Node("ReadVar", "", yylineno);
        $$->children.push_back(new Node("Id", $3, yylineno));
    }
    ;

math_expr:
    arithmetic_expr { $$ = $1; }
    | logic_expr { $$ = $1; }
    ;

arithmetic_expr:
    arithmetic_expr PLUSOP arithmetic_expr {
        $$ = new Node("AddExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | arithmetic_expr SUBOP arithmetic_expr {
        $$ = new Node("SubExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | arithmetic_expr MULTOP arithmetic_expr {
        $$ = new Node("MultExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | arithmetic_expr DIVOP arithmetic_expr {
        $$ = new Node("DivExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | arithmetic_expr POW arithmetic_expr {
        $$ = new Node("PowerExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | INT { $$ = new Node("Id", $1, yylineno); }
    | LP expression RP { $$ = $2; }
    ;

logic_expr:
    logic_expr AND logic_expr {
        $$ = new Node("AndExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | logic_expr OR logic_expr {
        $$ = new Node("OrExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | NOT logic_expr {
        $$ = new Node("NotExpression", "", yylineno);
        $$->children.push_back($2);
    }
    | TRUE { $$ = new Node("BoolExpression", $1, yylineno); }
    | FALSE { $$ = new Node("BoolExpression", $1, yylineno); }
    | LP expression RP { $$ = $2; }
    ;

/*
    | expression GTE expression {
        $$ = new Node("GreaterEqualExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression LTE expression {
        $$ = new Node("LessEqualExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression NE expression {
        $$ = new Node("NotEqualExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression EQL expression {
        $$ = new Node("EqualExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression GT expression {
        $$ = new Node("GreaterExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression LT expression {
        $$ = new Node("LessExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    | expression EQL expression {
        $$ = new Node("EqualExpression", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
    }
    ;
*/
