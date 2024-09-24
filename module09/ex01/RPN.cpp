#include "RPN.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>

RPN::RPN(void) {}

RPN::RPN(const RPN &src) { *this = src; }

RPN::~RPN(void) {}

int RPN::evaluateAnExpression(const std::string &rPNExpression) {
  std::istringstream iss(rPNExpression);
  std::string element;
  std::stack<double> stackElements;

  while (iss >> element) {
    RPN::elementType elementType = getElementType(element);
    switch (elementType) {
      case INVALID: {
        std::cout << "Error: " << element << " is an invalid token."
                  << std::endl;
        return 1;
      }
      case OPERAND: {
        float number = std::strtof(element.c_str(), NULL);
        stackElements.push(number);
        continue;
      }
      case OPERATOR: {
        double result = 0;
        if (stackElements.size() < 2) {
          std::cout << "Error: invalid expression syntax." << std::endl;
          return 1;
        }
        double operand2 = stackElements.top();
        stackElements.pop();
        double operand1 = stackElements.top();
        stackElements.pop();
        if (!makeOperation(element[0], operand1, operand2, result)) return 1;
        stackElements.push(result);
      }
    }
  }
  if (stackElements.size() != 1) {
    std::cout << "Error: invalid expression syntax." << std::endl;
    return 1;
  }
  std::cout << stackElements.top() << std::endl;
  return 0;
}

RPN &RPN::operator=(const RPN &rhs) {
  (void)rhs;
  return *this;
}

RPN::elementType RPN::getElementType(const std::string &toCheck) {
  if (toCheck.size() != 1) return RPN::INVALID;
  std::string::size_type validChar = toCheck.find_first_of("0123456789");
  if (validChar != std::string::npos) return RPN::OPERAND;
  validChar = toCheck.find_first_of("+-*/");
  if (validChar != std::string::npos) return RPN::OPERATOR;
  return RPN::INVALID;
}

bool RPN::makeOperation(char theOperator, double operand1, double operand2,
                        double &result) {
  switch (theOperator) {
    case '+':
      result = operand1 + operand2;
      break;
    case '-':
      result = operand1 - operand2;
      break;
    case '*':
      result = operand1 * operand2;
      break;
    case '/': {
      if (operand2 == 0) {
        std::cout << "Error: / by zero" << std::endl;
        return false;
      }
      result = operand1 / operand2;
      break;
    }
    default:
      return false;
  }
  return true;
}
