%{
  #include "node.hpp"
  #include "MochiScanner.h"
  #include <iostream>
  #include <string>
  typedef Mochi::BisonParser::token token;
%}

%option nodefault yyclass="FlexScanner" noyywrap c++

%%

[1-9][0-9]* { yylval->string = new std::string(yytext, yyleng); return token::TINTEGER; }
"+"         { yylval->token = 1; return token::TPLUS; }
\n          {}
" "+        {}
.           { std::cout << "Unknown token: " << yytext << std::endl; yyterminate(); }

%%
