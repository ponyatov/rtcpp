%option prefix="cli_"

%{
#include "app.hpp"
#include "cli.hpp"
char *cli_file = nullptr;
%}

%option noyywrap yylineno

s [+\-]
n [0-9]

%%
#[^\n]*     {}  // line comment
[ \t\r\n]+  {}  // drop spaces

.           {cli_error("");}  // any undetected char
