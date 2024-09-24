#include "RPN.hpp"

#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./RPN <expression>" << std::endl;
    return 1;
  }
  RPN rpn;
  return rpn.evaluateAnExpression(argv[1]);
}
