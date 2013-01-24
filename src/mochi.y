%{
  #include "node.hpp"
  NBlock *programBlock;
%}

%require "2.6.2"
%skeleton "lalr1.cc"
%defines
%define namespace "Mochi"
%define parser_class_name "BisonParser"
%parse-param { Mochi::FlexScanner& parser }
%lex-param { Mochi::FlexScanner& parser }

%union {
  Node *node;
  NBlock *block;
  NExpression *expr;
  NStatement *stmt;
  std::string* string;
  int token;
}

%code requires {
  namespace Mochi {
    class FlexScanner;
  };
}

%code {
  static int yylex(Mochi::BisonParser::semantic_type * yylval, Mochi::FlexScanner &scanner);
}

%token <token> TPLUS
%token <string> TINTEGER

%type <expr> numeric expr
%type <block> program stmts
%type <stmt> stmt
%type <token> op

%start program

%%
program: stmts { programBlock = $1; }
       ;

stmts: stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1); }
     | stmts stmt { $$->statements.push_back($<stmt>2); }
     ;

stmt: expr { $$ = new NExpressionStatement(*$1); }
    ;

expr: numeric
    | expr op expr { $$ = new NBinaryOperator(*$1, $2, *$3); }
    ;

numeric: TINTEGER { $$ = new NInteger(atol(yylval.string->c_str())); delete $1; }
       ;

op: TPLUS
  ;
%%

void Mochi::BisonParser::error(const Mochi::BisonParser::location_type &loc, const std::string &msg) {
  std::cerr << "Error: " << msg << std::endl;
}

#include "MochiScanner.h"
static int yylex(Mochi::BisonParser::semantic_type * yylval, Mochi::FlexScanner &scanner) {
  return scanner.yylex(yylval);
}
