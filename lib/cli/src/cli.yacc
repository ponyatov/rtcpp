%{
    #include "os.hpp"
    #include "vm.hpp"
    #include "led.hpp"
    #include "cli.hpp"
%}

%defines %union { char c; int n; void *p; }

%token <n> DEC HEX OCT BIN
%type  <n> num
/* %token <p> PTR */
%token END LED ON OFF

%%
syntax: | syntax ex { vm.dump(); }

ex : END     { std::cerr << std::endl;  }   // end of file
   | num     { vm.push($1);             }   // number: push on stack
   | LED ON  { led.on();                }   // \ LED control
   | LED OFF { led.off();               }   // /

num : DEC | HEX | OCT | BIN
