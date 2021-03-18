#!/usr/bin/env python3

def find_max(a, n):
  max = a[0]
  for i in range(1, n):
    if a[i] > max:
      max = a[i]
  return max

def countingsort(a):
  n = len(a)
  k = find_max(a, n) + 1

  c = [0] * k
  t = [0] * n

  for i in range(n):
    c[a[i]] += 1

  for i in range(1, k):
    c[i] += c[i - 1]

  for i in range(n - 1, -1, -1):
    c[a[i]] -= 1
    t[c[a[i]]] = a[i]

  for i in range(n):
    a[i] = t[i]

  return a

