#pragma once

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL int Mochi::FlexScanner::yylex()

#include "mochi.tab.hpp"

namespace Mochi {
  class FlexScanner : public yyFlexLexer {
    public:
      int yylex(Mochi::BisonParser::semantic_type * lval) { yylval = lval; return yylex();  }
    private:
      int yylex();
      Mochi::BisonParser::semantic_type * yylval;
  };
}
