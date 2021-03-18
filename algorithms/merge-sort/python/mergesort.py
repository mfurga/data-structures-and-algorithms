#!/usr/bin/env python3

def _merge(a, c, lo, mid, hi):
  for i in range(lo, hi + 1):
    c[i] = a[i]

  i, j = lo, mid + 1
  for k in range(lo, hi + 1):
    if i > mid:
      a[k] = c[j]; j += 1
    elif j > hi:
      a[k] = c[i]; i += 1
    elif c[i] < c[j]:
      a[k] = c[i]; i += 1
    elif c[i] >= c[j]:
      a[k] = c[j]; j += 1
  return a

def _mergesort(a, c, lo, hi):
  if hi <= lo:
    return
  mid = lo + (hi - lo) // 2
  _mergesort(a, c, lo, mid)
  _mergesort(a, c, mid + 1, hi)
  return _merge(a, c, lo, mid, hi)

def mergesort(a):
  c = a[:]
  return _mergesort(a, c, 0, len(a) - 1)

