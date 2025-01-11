#pragma once

extern int yylex();
extern char *yyfile;
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
extern int yyparse();
extern void yyerror(const char *msg);
#include "rtcpp.parser.hpp"
