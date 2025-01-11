#include "rtcpp.hpp"

extern void yyerror(const char *msg) {  //
    fprintf(stderr, "\n%s:%i %s [%s]\n\n", yyfile, yylineno, msg, yytext);
    exit(-1);
}
