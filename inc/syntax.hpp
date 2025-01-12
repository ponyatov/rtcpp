#pragma once

/// @defgroup cli cli
/// @brief REPL/CLI command line inteface

/// @defgroup syntax syntax
/// @brief control script syntax parser
/// @ingroup cli
/// @{
extern int yylex();
extern char *yyfile;
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
extern int yyparse();
extern void yyerror(const char *msg);
#include "rtcpp.parser.hpp"
/// @}
