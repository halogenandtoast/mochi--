#pragma once

namespace Mochi {
  class Parser {
    public:
      Parser() : parser(scanner) {}
      int parse() {
        return parser.parse();
      }

    private:
      Mochi::FlexScanner scanner;
      Mochi::BisonParser parser;
  };
}
