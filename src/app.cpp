#include "app.hpp"
#include "cli.hpp"

void setup() {  //
}

void arg(int argc, char *argv) {  //
    fprintf(stderr, "arg[%i] = <%s>\n", argc, argv);
    if (argc >= 1) {
        yyfile = argv;
        assert(yyin = fopen(yyfile, "r"));
        yyparse();
        fclose(yyin);
        yyfile = nullptr;
    }
}

void loop() {  //
    exit(0);
}
