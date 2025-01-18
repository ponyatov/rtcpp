/// @defgroup cli cli
/// @brief CLI: Command Line Interface

/// @defgroup parser parser
/// @ingroup cli
/// @brief @ref cli commands parser
/// @{

#include <stdio.h>

/// @name lexer
/// @{
extern int cli_lex();   ///< lexer
extern int cli_lineno;  //< current line
extern char* cli_text;  //< lexeme value
extern char* cli_file;  ///< script file name
extern FILE* cli_in;    ///< script file handler
/// @}

/// @name parser
/// @{
extern int cli_parse();                  ///< parser
extern void cli_error(const char* msg);  ///< syntax error calback
/// @}

/// @}
