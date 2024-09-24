#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
 public:
  RPN(void);
  RPN(const RPN &src);
  ~RPN(void);

  enum elementType
  {
      INVALID = 1,
      OPERAND,
      OPERATOR
  };

  int evaluateAnExpression(const std::string &rPNExpression);

  RPN &operator=(const RPN &rhs);

 private:
    elementType getElementType(const std::string &toCheck); 
    bool makeOperation(char theOperator, double operand1, double operand2, double &result);
};

#endif
