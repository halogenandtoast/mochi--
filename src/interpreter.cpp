#include "node.hpp"
#include "interpreter.hpp"

void Interpreter::eval(NBlock& root) {
  root.eval();
}

// Value NBlock::eval() {
//   Value return_value = { 0, 'i' };
//   StatementList::const_iterator it;
//   for(it = statements.begin(); it != statements.end(); it++) {
//     std::cout << typeid(**it).name() << std::endl;
//     (**it).eval();
//   }
//   return return_value;
// }
// 
// Value NBinaryOperator::eval() {
//   Value return_value = { 0, 'i' };
//   std::cout << op << std::endl;
//   std::cout << "BINARY" << std::endl;
//   return return_value;
// }
// 
// Value NExpressionStatement::eval() {
//   Value return_value = { 0, 'i' };
//   std::cout << typeid(expression).name() << std::endl;
//   expression.eval();
//   return return_value;
// }
