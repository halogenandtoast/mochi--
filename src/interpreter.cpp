#include "node.hpp"
#include "interpreter.hpp"

void Interpreter::eval(NBlock& root) {
  root.eval();
}

Value NBlock::eval() {
  Value return_value = { 0, 'i' };
  StatementList::const_iterator it;
  for(it = statements.begin(); it != statements.end(); it++) {
    (**it).eval();
  }
  return return_value;
}

Value NExpressionStatement::eval() {
  Value return_value = { 0, 'i' };
  expression.eval();
  return return_value;
}

Value NBinaryOperator::eval() {
  Value return_value = { 0, 'i' };
  Value lhs_value = lhs.eval();
  Value rhs_value = rhs.eval();
  switch(op) {
    case 1:
      std::cout << (lhs_value.value.integerVal + rhs_value.value.integerVal) << std::endl;
      break;
  }
  return return_value;
}

Value NInteger::eval() {
  Value return_value = { value, 'i' };
  return return_value;
}
