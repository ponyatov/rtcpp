%{
#include "cli.hpp"
#include <string>
char *yyfile = nullptr;
%}

%option noyywrap yylineno

s [+\-]
n [0-9]

%%
#[^\n]*             {}  // line comment
[ \t\r\n]+          {}  // drop spaces

{s}?{n}+\.{n}+          { yylval.f = atof(yytext); return FLO; }
{s}?{n}+[eE]{s}?{n}+    { yylval.f = atof(yytext); return FLO; }

"0x"[0-9a-fA-F]+    { yylval.n = std::stol(&yytext[2], nullptr, 0x10); return HEX; }
"0o"[0-7]+          { yylval.n = std::stol(&yytext[2], nullptr, 0x08); return OCT; }
"0b"[01]+           { yylval.n = std::stol(&yytext[2], nullptr, 0x02); return BIN; }
{s}?{n}+            { yylval.n = std::stol(&yytext[0], nullptr, 0x0A); return DEC; }

"led"               { return LED_; }
"on"                { return ON;   }
"off"               { return OFF;  }

.                   {yyerror("");}  // any undetected char
