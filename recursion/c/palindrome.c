#include <stdbool.h>
#include <string.h>
#include <stdio.h>

// bool is_palindrome_iter(const char *s, unsigned int sz)
// {
//   unsigned int j = sz - 1;
//   for (unsigned int i = 0; (j - i) > 1; i++, j--)
//     if (s[i] != s[j]) return false;
//   return true;
// }

bool is_palindrome_wrapper(const char *s, unsigned int lo, 
                           unsigned int hi)
{
  if ((hi - lo) <= 1) return true;
  return s[lo] == s[hi] && is_palindrome_wrapper(s, lo + 1, hi - 1);
}

bool is_palindrome(const char *s, unsigned int sz)
{
  return is_palindrome_wrapper(s, 0, sz - 1);
}

int main(void)
{
  const char s[] = "kajak";
  printf("%i\n", is_palindrome(s, strlen(s)));

  return 0;
}