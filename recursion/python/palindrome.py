#!/usr/bin/env python3

def is_palindrome_wrapper(s: str, lo: int, hi: int) -> bool:
  if lo > hi:
    return True
  return s[lo] == s[hi] and is_palindrome_wrapper(s, lo + 1, hi - 1)

def is_palindrome(s: str) -> bool:
  return is_palindrome_wrapper(s, 0, len(s) - 1)

if __name__ == "__main__":
  print(is_palindrome("kajak"))
