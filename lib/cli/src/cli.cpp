#include <stdio.h>
#include <stdlib.h>
#include "cli.hpp"

void cli_error(const char *msg) {  //
    fprintf(stderr, "\n%s:%i %s [%s]\n\n", cli_file, cli_lineno, msg, cli_text);
    exit(-1);
}
