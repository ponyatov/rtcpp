#include "app.hpp"
#include "cli.hpp"

void setup() {  //
}

void arg(int argc, char *argv) {  //
    fprintf(stderr, "arg[%i] = <%s>\n", argc, argv);
    cli_file = argv;
    assert(cli_in = fopen(cli_file, "r"));
    cli_parse();
    fclose(cli_in);
    cli_file = nullptr;
}

void loop() {  //
    exit(0);
}
