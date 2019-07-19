#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from typing import List, Dict, Callable

# types
Stack = List

def _add(s: Stack, a: int, b: int):
  s.append(a + b)

def _sub(s: Stack, a: int, b: int):
  s.append(a - b)

def _mul(s: Stack, a: int, b: int):
  s.append(a * b)

def _div(s: Stack, a: int, b: int):
  s.append(a / b)

def parse_reverse_polish_notation(expression: str) -> int:
  """Parses the reverse polish notation given in `expression` and
     evaluates it.
     NOTE: This parser doesn't check if the `expression` is correct!
  """
  OPERATIONS: Dict[str, Callable[Stack, int, int]] = {
    '+': _add,
    '-': _sub,
    '*': _mul,
    '/': _div
  }
  s: Stack[int] = []

  # Go through 0..n-1, where n is the last element.
  # We assumes that the last element is '='.
  for c in expression[:-1]:
    if '0' <= c <= '9':
      s.append(int(c))
      continue

    try:
      b = s.pop()
      a = s.pop()
      OPERATIONS[c](s, a, b)
    except KeyError:
      continue

  return s.pop()

def convert_to_reverse_polish_notation(expression: str) -> None:
  """Converts the given `expression` into the reverse polish notation."""
  s: Stack[str] = []

  # Go through 0..n-1, where n is the last element.
  # We assumes that the last element is '='.
  for c in expression[:-1]:
    if '0' <= c <= '9':
      print(c, end='')
      continue

    if c == '(':
      s.append(c)
    elif c == ')':
      while len(s) > 0 and s[-1] != '(':
        print('%c' % s.pop(), end='')
      s.pop()  # Remove the opening bracket
    elif c in ('+', '-', '*', '/'):
      while len(s) > 0 and (s[-1] == '*' or s[-1] == '/'):
        print('%c' % s.pop(), end='')
      s.append(c)

  print('%c' % s.pop(), end='')


if __name__ == '__main__':
  # print(parse_reverse_polish_notation('53+2*25*3-/='))
  convert_to_reverse_polish_notation('(5+3)*2/(2*5-3)=')
