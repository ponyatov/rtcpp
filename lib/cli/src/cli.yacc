%{
    #include "os.hpp"
    #include "vm.hpp"
    #include "led.hpp"
    #include "cli.hpp"
%}

%defines %union { char c; int n; float f; void *p; }

%token <n> DEC HEX OCT BIN
%token <f> NUM
/* %token <p> PTR */
%token END LED ON OFF

%%
syntax: | syntax ex { vm.dump(); }

ex : num
   | END     { std::cerr << std::endl; }
   | LED ON  { led.on();  }
   | LED OFF { led.off(); }

num : DEC { vm.push($1); }
    | HEX { vm.push($1); }
    | OCT { vm.push($1); }
    | BIN { vm.push($1); }
    | NUM { vm.push($1); }
