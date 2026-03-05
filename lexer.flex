%top{
    #include "parser.tab.hh"
    #define YY_DECL yy::parser::symbol_type yylex()
    #include "Node.h"
    int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%

 /* Reserved keywords */
"class"                 {if(USE_LEX_ONLY) {printf("CLASS ");} else {return yy::parser::make_CLASS(yytext);}}
"main"                  {if(USE_LEX_ONLY) {printf("MAIN ");} else {return yy::parser::make_MAIN(yytext);}}
"volatile"              {if(USE_LEX_ONLY) {printf("VOLATILE ");} else {return yy::parser::make_VOLATILE(yytext);}}
"int"                   {if(USE_LEX_ONLY) {printf("INTTYPE ");} else {return yy::parser::make_INTTYPE(yytext);}}
"float"                 {if(USE_LEX_ONLY) {printf("FLOATTYPE ");} else {return yy::parser::make_FLOATTYPE(yytext);}}
"boolean"               {if(USE_LEX_ONLY) {printf("BOOLEAN ");} else {return yy::parser::make_BOOLEAN(yytext);}}
"void"                  {if(USE_LEX_ONLY) {printf("VOID ");} else {return yy::parser::make_VOID(yytext);}}
"if"                    {if(USE_LEX_ONLY) {printf("IF ");} else {return yy::parser::make_IF(yytext);}}
"else"                  {if(USE_LEX_ONLY) {printf("ELSE ");} else {return yy::parser::make_ELSE(yytext);}}
"for"                   {if(USE_LEX_ONLY) {printf("FOR ");} else {return yy::parser::make_FOR(yytext);}}
"print"                 {if(USE_LEX_ONLY) {printf("PRINT ");} else {return yy::parser::make_PRINT(yytext);}}
"read"                  {if(USE_LEX_ONLY) {printf("READ ");} else {return yy::parser::make_READ(yytext);}}
"return"                {if(USE_LEX_ONLY) {printf("RETURN ");} else {return yy::parser::make_RETURN(yytext);}}
"break"                 {if(USE_LEX_ONLY) {printf("BREAK ");} else {return yy::parser::make_BREAK(yytext);}}
"continue"              {if(USE_LEX_ONLY) {printf("CONTINUE ");} else {return yy::parser::make_CONTINUE(yytext);}}
"true"                  {if(USE_LEX_ONLY) {printf("TRUE ");} else {return yy::parser::make_TRUE(yytext);}}
"false"                 {if(USE_LEX_ONLY) {printf("FALSE ");} else {return yy::parser::make_FALSE(yytext);}}
"length"                {if(USE_LEX_ONLY) {printf("LENGTH ");} else {return yy::parser::make_LENGTH(yytext);}}

 /* Identifiers */
[a-zA-Z_][a-zA-Z0-9_]*  {if(USE_LEX_ONLY) {printf("ID ");} else {return yy::parser::make_ID(yytext);}}

 /* Float literals (before INT so "1.0" isn't split into INT + DOT + INT) */
(0|[1-9][0-9]*)\.[0-9]+  {if(USE_LEX_ONLY) {printf("FLOAT ");} else {return yy::parser::make_FLOAT(yytext);}}

 /* Integer literals */
0|[1-9][0-9]*            {if(USE_LEX_ONLY) {printf("INT ");} else {return yy::parser::make_INT(yytext);}}

 /* Operators */
":="                    {if(USE_LEX_ONLY) {printf("ASSIGN ");} else {return yy::parser::make_ASSIGN(yytext);}}
"<="                    {if(USE_LEX_ONLY) {printf("LEQ ");} else {return yy::parser::make_LEQ(yytext);}}
">="                    {if(USE_LEX_ONLY) {printf("GEQ ");} else {return yy::parser::make_GEQ(yytext);}}
"!="                    {if(USE_LEX_ONLY) {printf("NEQ ");} else {return yy::parser::make_NEQ(yytext);}}
":"                     {if(USE_LEX_ONLY) {printf("COLON ");} else {return yy::parser::make_COLON(yytext);}}
"<"                     {if(USE_LEX_ONLY) {printf("LT ");} else {return yy::parser::make_LT(yytext);}}
">"                     {if(USE_LEX_ONLY) {printf("GT ");} else {return yy::parser::make_GT(yytext);}}
"="                     {if(USE_LEX_ONLY) {printf("EQ ");} else {return yy::parser::make_EQ(yytext);}}
"&"                     {if(USE_LEX_ONLY) {printf("AND ");} else {return yy::parser::make_AND(yytext);}}
"|"                     {if(USE_LEX_ONLY) {printf("OR ");} else {return yy::parser::make_OR(yytext);}}
"!"                     {if(USE_LEX_ONLY) {printf("NOT ");} else {return yy::parser::make_NOT(yytext);}}
"+"                     {if(USE_LEX_ONLY) {printf("PLUSOP ");} else {return yy::parser::make_PLUSOP(yytext);}}
"-"                     {if(USE_LEX_ONLY) {printf("MINUSOP ");} else {return yy::parser::make_MINUSOP(yytext);}}
"*"                     {if(USE_LEX_ONLY) {printf("MULTOP ");} else {return yy::parser::make_MULTOP(yytext);}}
"/"                     {if(USE_LEX_ONLY) {printf("DIVOP ");} else {return yy::parser::make_DIVOP(yytext);}}
"^"                     {if(USE_LEX_ONLY) {printf("POWOP ");} else {return yy::parser::make_POWOP(yytext);}}
"."                     {if(USE_LEX_ONLY) {printf("DOT ");} else {return yy::parser::make_DOT(yytext);}}

 /* Delimiters */
"("                     {if(USE_LEX_ONLY) {printf("LP ");} else {return yy::parser::make_LP(yytext);}}
")"                     {if(USE_LEX_ONLY) {printf("RP ");} else {return yy::parser::make_RP(yytext);}}
"{"                     {if(USE_LEX_ONLY) {printf("LCB ");} else {return yy::parser::make_LCB(yytext);}}
"}"                     {if(USE_LEX_ONLY) {printf("RCB ");} else {return yy::parser::make_RCB(yytext);}}
"["                     {if(USE_LEX_ONLY) {printf("LSB ");} else {return yy::parser::make_LSB(yytext);}}
"]"                     {if(USE_LEX_ONLY) {printf("RSB ");} else {return yy::parser::make_RSB(yytext);}}
","                     {if(USE_LEX_ONLY) {printf("COMMA ");} else {return yy::parser::make_COMMA(yytext);}}

 /* Whitespace */
[ \t\r]+                {}
\n                      {if(USE_LEX_ONLY) {printf("NEWLINE ");} else {return yy::parser::make_NEWLINE(yytext);}}
"//"[^\n]*              {}

 /* Lexical error */
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); fprintf(stderr,"\t@error at line %d. Character %s is not recognized\n", yylineno, yytext); lexical_errors = 1;}

<<EOF>>                 {return yy::parser::make_END();}
%%
