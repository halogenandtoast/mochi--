#pragma once
#include <iostream>
#include <vector>

class NStatement;

typedef std::vector<NStatement*> StatementList;

struct value_t {
  union {
    int integerVal;
  } value;
  char type;
};

typedef struct value_t Value;

class Node {
  public:
    virtual ~Node() {}
    virtual Value eval() {};
};

class NExpression : public Node {
};

class NStatement : public Node {
};

class NInteger : public NExpression {
  public:
    long long value;
    NInteger(long long value) : value(value) {}
    virtual Value eval();
};

class NBinaryOperator : public NExpression {
  public:
    int op;
    NExpression& lhs;
    NExpression& rhs;
    NBinaryOperator(NExpression& lhs, int op, NExpression& rhs) : lhs(lhs), op(op), rhs(rhs) {}
    virtual Value eval();
};

class NExpressionStatement : public NStatement {
  public:
    NExpression& expression;
    NExpressionStatement(NExpression& expression) : expression(expression) {}
    virtual Value eval();
};

class NBlock : public NExpression {
  public:
    StatementList statements;
    NBlock() { }
    virtual Value eval();
};
