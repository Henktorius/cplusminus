%top{
    #include "parser.tab.hh"
    #define YY_DECL yy::parser::symbol_type yylex()
    #include "Node.h"
    int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack
%%

"+"                     {if(USE_LEX_ONLY) {printf("PLUSOP ");} else {return yy::parser::make_PLUSOP(yytext);}}
"-"                     {if(USE_LEX_ONLY) {printf("SUBOP ");} else {return yy::parser::make_SUBOP(yytext);}}
"*"                     {if(USE_LEX_ONLY) {printf("MULTOP ");} else {return yy::parser::make_MULTOP(yytext);}}
"("                     {if(USE_LEX_ONLY) {printf("LP ");} else {return yy::parser::make_LP(yytext);}}
")"                     {if(USE_LEX_ONLY) {printf("RP ");} else {return yy::parser::make_RP(yytext);}}
"=:"                    {if(USE_LEX_ONLY) {printf("ASS ");} else {return yy::parser::make_ASS(yytext);}}
":"                     {if(USE_LEX_ONLY) {printf("TYPEDEF ");} else {return yy::parser::make_TYPEDEF(yytext);}}
","                     {if(USE_LEX_ONLY) {printf("COMMA ");} else {return yy::parser::make_COMMA(yytext);}}
"["                     {if(USE_LEX_ONLY) {printf("LS ");} else {return yy::parser::make_LS(yytext);}}
"]"                     {if(USE_LEX_ONLY) {printf("RS ");} else {return yy::parser::make_RS(yytext);}}
"{"                     {if(USE_LEX_ONLY) {printf("LL ");} else {return yy::parser::make_LL(yytext);}}
"}"                     {if(USE_LEX_ONLY) {printf("RL ");} else {return yy::parser::make_RL(yytext);}}
"&"                     {if(USE_LEX_ONLY) {printf("AND ");} else {return yy::parser::make_AND(yytext);}}
"|"                     {if(USE_LEX_ONLY) {printf("OR ");} else {return yy::parser::make_OR(yytext);}}
">="                    {if(USE_LEX_ONLY) {printf("GTE ");} else {return yy::parser::make_GTE(yytext);}}
"<="                    {if(USE_LEX_ONLY) {printf("LTE ");} else {return yy::parser::make_LTE(yytext);}}
"!="                    {if(USE_LEX_ONLY) {printf("NE ");} else {return yy::parser::make_NE(yytext);}}
"!"                     {if(USE_LEX_ONLY) {printf("NOT ");} else {return yy::parser::make_NOT(yytext);}}
"="                     {if(USE_LEX_ONLY) {printf("EQL ");} else {return yy::parser::make_EQL(yytext);}}
">"                     {if(USE_LEX_ONLY) {printf("GT ");} else {return yy::parser::make_GT(yytext);}}
"<"                     {if(USE_LEX_ONLY) {printf("LT ");} else {return yy::parser::make_LT(yytext);}}
"/"                     {if(USE_LEX_ONLY) {printf("DIVOP ");} else {return yy::parser::make_DIVOP(yytext);}}
"^"                     {if(USE_LEX_ONLY) {printf("POW ");} else {return yy::parser::make_POW(yytext);}}
"."                     {if(USE_LEX_ONLY) {printf("PRD ");} else {return yy::parser::make_PRD(yytext);}}

"var"                   {if(USE_LEX_ONLY) {printf("VAR ");} else {return yy::parser::make_VAR(yytext);}}
"class"                 {if(USE_LEX_ONLY) {printf("CLASS ");} else {return yy::parser::make_CLASS(yytext);}}
"volatile"              {if(USE_LEX_ONLY) {printf("VOL ");} else {return yy::parser::make_VOL(yytext);}}
"int"                   {if(USE_LEX_ONLY) {printf("INT_T ");} else {return yy::parser::make_INT_T(yytext);}}
"float"                 {if(USE_LEX_ONLY) {printf("FLOAT_T ");} else {return yy::parser::make_FLOAT_T(yytext);}}
"boolean"               {if(USE_LEX_ONLY) {printf("BOOL_T ");} else {return yy::parser::make_BOOL_T(yytext);}}

"if"                    {if(USE_LEX_ONLY) {printf("IF ");} else {return yy::parser::make_IF(yytext);}}
"else"                  {if(USE_LEX_ONLY) {printf("ELSE ");} else {return yy::parser::make_ELSE(yytext);}}
"for"                   {if(USE_LEX_ONLY) {printf("FOR ");} else {return yy::parser::make_FOR(yytext);}}
"return"                {if(USE_LEX_ONLY) {printf("RET ");} else {return yy::parser::make_RET(yytext);}}
"break"                 {if(USE_LEX_ONLY) {printf("BREAK ");} else {return yy::parser::make_BREAK(yytext);}}
"continue"              {if(USE_LEX_ONLY) {printf("CONT ");} else {return yy::parser::make_CONT(yytext);}}
"print"                 {if(USE_LEX_ONLY) {printf("PRINT ");} else {return yy::parser::make_PRINT(yytext);}}
"read"                  {if(USE_LEX_ONLY) {printf("READ ");} else {return yy::parser::make_READ(yytext);}}
"length"                {if(USE_LEX_ONLY) {printf("LEN ");} else {return yy::parser::make_LEN(yytext);}}

"true"                  {if(USE_LEX_ONLY) {printf("TRUE ");} else {return yy::parser::make_TRUE(yytext);}}
"false"                 {if(USE_LEX_ONLY) {printf("FALSE ");} else {return yy::parser::make_FALSE(yytext);}}
[a-zA-Z][a-zA-Z0-9]*                    {if(USE_LEX_ONLY) {printf("ID ");} else{return yy::parser::make_ID(yytext);}}
0|[1-9][0-9]*           {if(USE_LEX_ONLY) {printf("INT ");} else {return yy::parser::make_INT(yytext);}}


[ \t\n\r]+              {}
"//"[^\n]*              {}
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); fprintf(stderr,"\t@error at line %d. Character %s is not recognized\n", yylineno, yytext); lexical_errors = 1;}
<<EOF>>                  {return yy::parser::make_END();}
%%
