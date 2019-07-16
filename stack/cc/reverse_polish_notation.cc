#include <iostream>
#include <stack>
#include "reverse_polish_notation.h"

namespace mf
{

int parse_reverse_polish_notation(const char expression[])
{
  /* This parser doesn't check if the given expression is correct! */
  std::stack<int> s;
  int a, b;

  for (unsigned int i = 0; expression[i] != '='; i++) {
    if (expression[i] >= '0' && expression[i] <= '9')
      s.push(expression[i] - '0');
    else {
      switch (expression[i]) {
        case '+':
          b = s.top(); s.pop();
          a = s.top(); s.pop();
          s.push(a + b);
        break;
        case '-':
          b = s.top(); s.pop();
          a = s.top(); s.pop();
          s.push(a - b);
        break;
        case '*':
          b = s.top(); s.pop();
          a = s.top(); s.pop();
          s.push(a * b);
        break;
        case '/':
          b = s.top(); s.pop();
          a = s.top(); s.pop();
          s.push(a / b);
        break;
      }
    }
  }
  return s.top();
}

void convert_to_reverse_polish_notation(const char expression[])
{
  std::stack<char> s;

  for (unsigned int i = 0; expression[i] != '='; i++) {
    if (expression[i] >= '0' && expression[i] <= '9')
      std::cout << expression[i];
    else {
      switch (expression[i]) {
        case '(':
          s.push(expression[i]);
        break;
        case ')':
          while (!s.empty() && s.top() != '(') {
            std::cout << s.top(); s.pop();
          }
          s.pop();  /* Remove the opening bracket. */
        break;
        case '+':
        case '-':
        case '*':
        case '/':
          while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
            std::cout << s.top(); s.pop();
          }
          s.push(expression[i]);
        break;
      }
    }
  }
  std::cout << s.top() << std::endl;
}

}  // namespace mf

int main()
{
  // std::cout << mf::parse_reverse_polish_notation("352*+=") << std::endl;
  mf::convert_to_reverse_polish_notation("(5+3)*2/(2*5-3)=");
  return 0;
}