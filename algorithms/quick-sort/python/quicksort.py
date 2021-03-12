#!/usr/bin/env python3

def _partition(arr, lo, hi):
  pivot = arr[lo]
  i, j = lo + 1, hi

  while True:
    while arr[i] < pivot:
      if i == hi: break
      i += 1
    while arr[j] > pivot:
      j -= 1

    if j <= i: break
    arr[i], arr[j] = arr[j], arr[i]

  arr[lo], arr[j] = arr[j], arr[lo]
  return j

def _quicksort(arr, lo, hi):
  if lo >= hi:
    return
  j = _partition(arr, lo, hi)
  _quicksort(arr, lo, j - 1)
  _quicksort(arr, j + 1, hi)

def quicksort(arr):
  return _quicksort(arr, 0, len(arr) - 1)

