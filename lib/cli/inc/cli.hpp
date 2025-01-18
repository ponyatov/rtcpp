#pragma once

/// @defgroup cli cli
/// @brief CLI: Command Line Interface

/// @defgroup parser parser
/// @ingroup cli
/// @brief @ref cli commands parser
/// @{

#include <stdio.h>

/// @name lexer
/// @{
extern int yylex();   ///< lexer
extern int yylineno;  //< current line
extern char* yytext;  //< lexeme value
extern char* yyfile;  ///< script file name
extern FILE* yyin;    ///< script file handler
/// @}

/// @name parser
/// @{
extern int yyparse();                  ///< parser
extern void yyerror(const char* msg);  ///< syntax error calback
#include "cli.parser.hpp"
/// @}

/// @}
