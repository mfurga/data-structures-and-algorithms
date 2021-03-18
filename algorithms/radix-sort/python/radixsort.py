#!/usr/bin/env python3

def countingsort(a, n, e):
  c = [0] * 10
  t = [0] * n

  for i in range(n):
    c[(a[i] // e) % 10] += 1

  for i in range(1, 10):
    c[i] += c[i - 1]

  for i in range(n - 1, -1, -1):
    c[(a[i] // e) % 10] -= 1
    t[c[(a[i] // e) % 10]] = a[i]

  for i in range(n):
    a[i] = t[i]

  return a

def radixsort(a):
  n = len(a)
  m = max(a)
  e = 1
  while m // e > 0:
    countingsort(a, n, e)
    e *= 10
  return a

