/// @defgroup syntax syntax
/// @ingroup cli
/// @{

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
extern int yyparse();
/// @}

/// @}
