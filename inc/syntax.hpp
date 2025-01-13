#pragma once

/// @defgroup cli cli
/// @brief REPL/CLI command line inteface

/// @defgroup syntax syntax
/// @brief control script syntax parser
/// @ingroup cli
/// @{
#ifdef LINUX
/// @name lexer
/// @{
extern int yylex();   ///< lexer
extern char *yyfile;  ///< current file name
extern FILE *yyin;    ///< current file handler
extern int yylineno;  ///< current line
extern char *yytext;  ///< lexed text
/// generate token object for parser
#define TOKEN(C, X)               \
    {                             \
        yylval.o = new C(yytext); \
        return X;                 \
    }
/// @}
/// @name parser
/// @{
extern int yyparse();                  ///< syntax parser
extern void yyerror(const char *msg);  ///< @brief syntax error callback
/// @}
#include "rtcpp.parser.hpp"
#endif
/// @}
