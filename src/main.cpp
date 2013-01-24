#include "node.hpp"
#include "MochiScanner.h"
#include "MochiParser.h"
#include "interpreter.hpp"
#include <iostream>

extern NBlock* programBlock;

using namespace std;
int main(int argc, char** argv) {
  Mochi::Parser parser;
  parser.parse();
  Interpreter interpreter;
  interpreter.eval(*programBlock);
  return 0;
}
