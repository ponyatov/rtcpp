%{
#include "cli.hpp"
#include "vm.hpp"
#include "type.hpp"
%}

%defines %union { char c; int n; float f; }

%token <n> DEC HEX OCT BIN
%token <f> FLO
%token END LED ON OFF

%%
syntax: | syntax ex { vm.dump(); }

ex : num
   | END { fprintf(stderr,"\n\n");        }
   | LED ON  { fprintf(stderr,"LED\n");   }
   | LED OFF { fprintf(stderr,"led\n");   }

num : DEC { vm.push({Type::Int  ,{n:$1}}); }
    | HEX { vm.push({Type::Hex  ,{n:$1}}); }
    | OCT { vm.push({Type::Oct  ,{n:$1}}); }
    | BIN { vm.push({Type::Bin  ,{n:$1}}); }
    | FLO { vm.push({Type::Float,{f:$1}}); }
