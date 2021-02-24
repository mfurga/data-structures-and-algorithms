#include <stdio.h>
#include "reverse_polish_notation.h"

int parse_reverse_polish_notation(const char expression[])
{
  /* This parser doesn't check if the given expression is correct! */
  stack_t *s = create_stack();
  int a, b, res;

  for (unsigned int i = 0; expression[i] != '='; i++) {
    if (expression[i] >= '0' && expression[i] <= '9') {
      push(s, expression[i] - '0'); continue;
    }
    switch (expression[i]) {
      case '+':
        b = pop(s); a = pop(s);
        push(s, a + b);
      break;
      case '-':
        b = pop(s); a = pop(s);
        push(s, a - b);
      break;
      case '*':
        b = pop(s); a = pop(s);
        push(s, a * b);
      break;
      case '/':
        b = pop(s); a = pop(s);
        push(s, a / b);
      break;
    }
  }
  res = pop(s);
  remove_stack(s);
  return res;
}

void convert_to_reverse_polish_notation(const char expression[])
{
  stack_t *s = create_stack();
  for (unsigned int i = 0; expression[i] != '='; i++) {
    if (expression[i] >= '0' && expression[i] <= '9') {
      printf("%c", expression[i]); continue;
    }
    switch (expression[i]) {
      case '(':
        push(s, expression[i]);
      break;
      case ')':
        while (!empty_stack(s) && top(s) != '(')
          printf("%c", pop(s));
        pop(s);  /* Remove the opening bracket. */
      break;
      case '+':
      case '-':
      case '*':
      case '/':
        while (!empty_stack(s) && (top(s) == '*' || top(s) == '/'))
          printf("%c", pop(s));
        push(s, expression[i]);
      break;
    }
  }
  printf("%c", pop(s));
  remove_stack(s);
}

int main(void)
{
  // char expression[] = "352*+=";
  // printf("%i\n", parse_reverse_polish_notation(expression));

  char expression[] = "(5+3)*2/(2*5-3)=";
  convert_to_reverse_polish_notation(expression);

  return 0;
}
