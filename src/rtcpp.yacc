%{
#include "rtcpp.hpp"
%}

%defines %union { Object *o; }

%token <o> INT FLOAT
%type <o> ex

%%
syntax: | syntax ex { $2->dump(); }

ex : INT
   | FLOAT
