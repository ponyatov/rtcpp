%define api.prefix {cli_}

%{
#include "app.hpp"
#include "cli.hpp"
%}

%defines %union { char c; int n; }

%token <n> INT

%%
syntax: | syntax ex

ex : INT { fprintf(stderr,"int:%i\n",$1); }
