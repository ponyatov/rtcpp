%{
#include "cli.hpp"
#include "vm.hpp"
%}

%defines %union { char c; int n; }

%token <n> DEC HEX OCT BIN
%type  <n> num
%token END LED ON OFF

%%
syntax: | syntax ex { vm.dump(); }

ex : num { vm.push($1); }
   | END { fprintf(stderr,"\n\n");        }
   | LED ON  { fprintf(stderr,"LED\n");   }
   | LED OFF { fprintf(stderr,"led\n");   }

num : DEC { $$=$1; }
    | HEX { $$=$1; }
    | OCT { $$=$1; }
    | BIN { $$=$1; }
