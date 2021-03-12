#!/usr/bin/env python3

def _partition(a, lo, hi):
  p = a[hi]
  i = lo - 1

  for j in range(lo, hi):
    if a[j] < p:
      i += 1
      a[i], a[j] = a[j], a[i]

  a[i + 1], a[hi] = a[hi], a[i + 1]
  return i + 1

def _quicksort(a, lo, hi):
  if lo < hi:
    j = _partition(a, lo, hi)
    _quicksort(a, lo, j - 1)
    _quicksort(a, j + 1, hi)

def quicksort(A):
  return _quicksort(A, 0, len(A) - 1)

