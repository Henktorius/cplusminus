%skeleton "lalr1.cc"
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false
}

%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;

  Node* root;
  extern int yylineno;
}

/* Keywords */
%token <std::string> CLASS MAIN VOLATILE
%token <std::string> INTTYPE FLOATTYPE BOOLEAN VOID
%token <std::string> IF ELSE FOR
%token <std::string> PRINT READ RETURN BREAK CONTINUE
%token <std::string> TRUE FALSE LENGTH

/* Identifiers and literals */
%token <std::string> ID INT FLOAT

/* Punctuation */
%token <std::string> ASSIGN
%token <std::string> COLON
%token <std::string> COMMA
%token <std::string> DOT
%token <std::string> LP RP
%token <std::string> LCB RCB
%token <std::string> LSB RSB

/* Arithmetic operators */
%token <std::string> PLUSOP MINUSOP MULTOP DIVOP POWOP

/* Logical operators */
%token <std::string> AND OR NOT
%token <std::string> LT GT LEQ GEQ EQ NEQ

/* Whitespace */
%token <std::string> NEWLINE
%token END 0 "end of file"

/* Operator precedence */
%left  OR
%left  AND
%left  EQ NEQ
%left  LT GT LEQ GEQ
%left  PLUSOP MINUSOP
%left  MULTOP DIVOP
%right POWOP          // right-associative, e.g. 2^3^4 = 2^(3^4)
%right NOT            // unary, highest among all operators

/* Pseudo-token used to resolve the dangling-else conflict, "if without else" is given lower precedence than ELSE so the parser always attaches an ELSE to the nearest unmatched IF. */
%nonassoc IFX
%nonassoc ELSE

/* Non-terminal types */
%type <Node*> program
%type <Node*> top_var_decls top_class_decls trailing_newlines
%type <Node*> class_decl class_body
%type <Node*> entry
%type <Node*> method params
%type <Node*> var
%type <Node*> type base_type
%type <Node*> stmt_block stmt_list stmt stmt_end
%type <Node*> for_init for_cond
%type <Node*> expr args

%%

program
  : top_var_decls top_class_decls entry trailing_newlines
      {
        root = new Node("Program", "", yylineno);
        root->children.push_back($1);
        root->children.push_back($2);
        root->children.push_back($3);
      }
  ;

/* Absorb any trailing newlines that follow the closing } of main */
trailing_newlines
  : /* empty */             { $$ = new Node("Trailing", "", yylineno); }
  | trailing_newlines NEWLINE { $$ = $1; }
  ;

top_var_decls
  : /* empty */
      { $$ = new Node("VarDecls", "", yylineno); }
  | top_var_decls var stmt_end
      { $$ = $1; $$->children.push_back($2); }
  | top_var_decls NEWLINE       /* blank line between top-level decls */
      { $$ = $1; }
  ;

top_class_decls
  : /* empty */
      { $$ = new Node("ClassDecls", "", yylineno); }
  | top_class_decls class_decl stmt_end
      { $$ = $1; $$->children.push_back($2); }
  | top_class_decls NEWLINE
      { $$ = $1; }
  ;

class_decl
  : CLASS ID LCB class_body RCB
      {
        $$ = new Node("Class", $2, yylineno);
        $$->children.push_back($4);
      }
  ;

class_body
  : /* empty */
      { $$ = new Node("ClassBody", "", yylineno); }
  | class_body var stmt_end
      { $$ = $1; $$->children.push_back($2); }
  | class_body method stmt_end
      { $$ = $1; $$->children.push_back($2); }
  | class_body NEWLINE          /* blank lines inside a class body */
      { $$ = $1; }
  ;

entry
  : MAIN LP RP COLON INTTYPE stmt_block
      {
        $$ = new Node("Entry", "main", yylineno);
        $$->children.push_back($6);
      }
  ;

method
  : ID LP RP COLON type stmt_block
      {
        $$ = new Node("Method", $1, yylineno);
        $$->children.push_back(new Node("Params", "", yylineno));
        $$->children.push_back($5);
        $$->children.push_back($6);
      }
  | ID LP params RP COLON type stmt_block
      {
        $$ = new Node("Method", $1, yylineno);
        $$->children.push_back($3);
        $$->children.push_back($6);
        $$->children.push_back($7);
      }
  ;

params
  : ID COLON type
      {
        $$ = new Node("Params", "", yylineno);
        Node* p = new Node("Param", $1, yylineno);
        p->children.push_back($3);
        $$->children.push_back(p);
      }
  | params COMMA ID COLON type
      {
        $$ = $1;
        Node* p = new Node("Param", $3, yylineno);
        p->children.push_back($5);
        $$->children.push_back(p);
      }
  ;

var
  : ID COLON type
      {
        $$ = new Node("VarDecl", $1, yylineno);
        $$->children.push_back($3);
      }
  | ID COLON type ASSIGN expr
      {
        $$ = new Node("VarDecl", $1, yylineno);
        $$->children.push_back($3);
        $$->children.push_back($5);
      }
  | VOLATILE ID COLON type
      {
        $$ = new Node("VarDecl", $2, yylineno);
        $$->children.push_back(new Node("Volatile", "", yylineno));
        $$->children.push_back($4);
      }
  | VOLATILE ID COLON type ASSIGN expr
      {
        $$ = new Node("VarDecl", $2, yylineno);
        $$->children.push_back(new Node("Volatile", "", yylineno));
        $$->children.push_back($4);
        $$->children.push_back($6);
      }
  ;

type
  : base_type              { $$ = $1; }
  | base_type LSB RSB
      { $$ = new Node("ArrayType", "", yylineno); $$->children.push_back($1); }
  | ID                     { $$ = new Node("Type", $1, yylineno); }
  | VOID                   { $$ = new Node("Type", "void", yylineno); }
  ;

base_type
  : INTTYPE    { $$ = new Node("BaseType", "int",     yylineno); }
  | FLOATTYPE  { $$ = new Node("BaseType", "float",   yylineno); }
  | BOOLEAN    { $$ = new Node("BaseType", "boolean", yylineno); }
  ;

stmt_block
  : LCB RCB               { $$ = new Node("Block", "", yylineno); }
  | LCB stmt_list RCB     { $$ = $2; }
  ;

stmt_list
  : stmt
      { $$ = new Node("Block", "", yylineno); $$->children.push_back($1); }
  | stmt_list stmt
      { $$ = $1; $$->children.push_back($2); }
  | NEWLINE                        /* leading blank line in a block */
      { $$ = new Node("Block", "", yylineno); }
  | stmt_list NEWLINE              /* blank line between statements */
      { $$ = $1; }
  ;

stmt_end
  : NEWLINE { $$ = new Node("StmtEnd", "", yylineno); }
  ;

stmt
  /* Block statement: no stmt_end needed, already has the closing RCB */
  : stmt_block
      { $$ = $1; }

  | var stmt_end
      { $$ = $1; }

  | expr ASSIGN expr stmt_end
      {
        $$ = new Node("Assign", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
      }

  | IF LP expr RP stmt %prec IFX
      {
        $$ = new Node("If", "", yylineno);
        $$->children.push_back($3);
        $$->children.push_back($5);
      }

  | IF LP expr RP stmt ELSE stmt
      {
        $$ = new Node("IfElse", "", yylineno);
        $$->children.push_back($3);
        $$->children.push_back($5);
        $$->children.push_back($7);
      }

  | FOR LP for_init COMMA for_cond COMMA expr ASSIGN expr RP stmt
      {
        $$ = new Node("For", "", yylineno);
        $$->children.push_back($3);   /* init  */
        $$->children.push_back($5);   /* cond  */
        Node* upd = new Node("Assign", "", yylineno);
        upd->children.push_back($7);
        upd->children.push_back($9);
        $$->children.push_back(upd);  /* update */
        $$->children.push_back($11);  /* body   */
      }

  | PRINT LP expr RP stmt_end
      { $$ = new Node("Print", "", yylineno); $$->children.push_back($3); }

  | READ LP expr RP stmt_end
      { $$ = new Node("Read", "", yylineno); $$->children.push_back($3); }

  | RETURN expr stmt_end
      { $$ = new Node("Return", "", yylineno); $$->children.push_back($2); }

  | BREAK stmt_end
      { $$ = new Node("Break", "", yylineno); }

  | CONTINUE stmt_end
      { $$ = new Node("Continue", "", yylineno); }

  /* Function call */
  | expr stmt_end
      { $$ = new Node("ExprStmt", "", yylineno); $$->children.push_back($1); }
  ;

for_init
  : /* empty */
      { $$ = new Node("ForInit", "", yylineno); }
  | var
      { $$ = $1; }
  | expr ASSIGN expr
      {
        $$ = new Node("Assign", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
      }
  ;

for_cond
  : /* empty */
      { $$ = new Node("ForCond", "", yylineno); }
  | expr
      { $$ = $1; }
  ;

expr
  : expr OR     expr { $$ = new Node("BinOp", "|",  yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr AND    expr { $$ = new Node("BinOp", "&",  yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr EQ     expr { $$ = new Node("BinOp", "=",  yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr NEQ    expr { $$ = new Node("BinOp", "!=", yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr LT     expr { $$ = new Node("BinOp", "<",  yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr GT     expr { $$ = new Node("BinOp", ">",  yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr LEQ    expr { $$ = new Node("BinOp", "<=", yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr GEQ    expr { $$ = new Node("BinOp", ">=", yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr PLUSOP  expr { $$ = new Node("BinOp", "+", yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr MINUSOP expr { $$ = new Node("BinOp", "-", yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr MULTOP  expr { $$ = new Node("BinOp", "*", yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr DIVOP   expr { $$ = new Node("BinOp", "/", yylineno); $$->children.push_back($1); $$->children.push_back($3); }
  | expr POWOP   expr { $$ = new Node("BinOp", "^", yylineno); $$->children.push_back($1); $$->children.push_back($3); }

  | expr LSB expr RSB
      {
        $$ = new Node("ArrayAccess", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
      }

  | expr DOT LENGTH
      {
        $$ = new Node("FieldAccess", "length", yylineno);
        $$->children.push_back($1);
      }

  | expr DOT ID LP args RP
      {
        $$ = new Node("MethodCall", $3, yylineno);
        $$->children.push_back($1);
        $$->children.push_back($5);
      }

  | ID LP args RP
      {
        $$ = new Node("Call", $1, yylineno);
        $$->children.push_back($3);
      }

  /* Literals */
  | INT   { $$ = new Node("IntLit",   $1,      yylineno); }
  | FLOAT { $$ = new Node("FloatLit", $1,      yylineno); }
  | ID    { $$ = new Node("Id",       $1,      yylineno); }
  | TRUE  { $$ = new Node("BoolLit",  "true",  yylineno); }
  | FALSE { $$ = new Node("BoolLit",  "false", yylineno); }

  /* Array literal */
  | base_type LSB args RSB
      {
        $$ = new Node("ArrayLit", "", yylineno);
        $$->children.push_back($1);
        $$->children.push_back($3);
      }

  | NOT expr
      {
        $$ = new Node("Not", "", yylineno);
        $$->children.push_back($2);
      }

  | LP expr RP
      { $$ = $2; }
  ;

args
  : /* empty */
      { $$ = new Node("Args", "", yylineno); }
  | expr
      { $$ = new Node("Args", "", yylineno); $$->children.push_back($1); }
  | args COMMA expr
      { $$ = $1; $$->children.push_back($3); }
  ;

%%
