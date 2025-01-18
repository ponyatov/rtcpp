%{
#include "cli.hpp"
char *yyfile = nullptr;
%}

%option noyywrap yylineno

s [+\-]
n [0-9]

%%
#[^\n]*     {}  // line comment
[ \t\r\n]+  {}  // drop spaces

.           {yyerror("");}  // any undetected char
