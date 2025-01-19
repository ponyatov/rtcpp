%{
#include "cli.hpp"
#include "vm.hpp"
#include "type.hpp"
#include "led.hpp"
#include "os.hpp"
%}

%defines %union { char c; int n; float f; }

%token <n> DEC HEX OCT BIN
%token <f> NUM
%token END LED_ ON OFF

%%
syntax: | syntax ex { std::cerr << vm.dump() << std::endl; }

ex : num
   | END      { std::cerr << std::endl; }
   | LED_     { vm.push({Type::Obj,{.o=&led}}); }
   | ON       { Cell c = vm.pop(); assert(c.t==Type::Obj); c.v.o->on();  }
   | OFF      { Cell c = vm.pop(); assert(c.t==Type::Obj); c.v.o->off(); }

num : DEC { vm.push({Type::Int ,{.n=$1}}); }
    | HEX { vm.push({Type::Hex ,{.n=$1}}); }
    | OCT { vm.push({Type::Oct ,{.n=$1}}); }
    | BIN { vm.push({Type::Bin ,{.n=$1}}); }
    | NUM { vm.push({Type::Num ,{.f=$1}}); }
