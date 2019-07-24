#include <stdio.h>

// int pow_iter(int base, unsigned int exp)
// {
//   /* Divide and conquer approach:
//      n ^ e = n ^ (e / 2) * n ^ (e / 2) (* n if e is odd). */
//   int res = 1;
//   while (exp > 0) {
//     if (exp % 2 != 0)
//       res *= base;
//     exp /= 2;
//     base = base * base;
//   }
//   return res;
// }

int pow(int base, unsigned int exp)
{
  /* Divide and conquer approach:
     n ^ e = n ^ (e / 2) * n ^ (e / 2) (* n if e is odd). */
  if (exp == 0) return 1;
  int half = pow(base, exp / 2);
  if (exp % 2 == 0)
    return half * half;
  else
    return half * half * base;
}

int main(void)
{
  printf("%i", pow(-2, 10));

  return 0;
}