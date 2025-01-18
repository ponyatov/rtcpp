#include <stdio.h>
#include <stdlib.h>
#include "cli.hpp"

void yyerror(const char *msg) {  //
    fprintf(stderr, "\n%s:%i %s [%s]\n\n", yyfile, yylineno, msg, yytext);
    exit(-1);
}
