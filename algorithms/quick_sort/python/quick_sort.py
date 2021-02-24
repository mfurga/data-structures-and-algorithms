#!/usr/bin/env python3

from typing import List, Any


def _partition(arr: List[Any], lo: int, hi: int) -> int:
  # We'll take the first element in the array as our pivot.
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

def _quicksort(arr: List[Any], lo: int, hi: int) -> None:
  if lo >= hi:
    return
  j = _partition(arr, lo, hi)
  _quicksort(arr, lo, j - 1)
  _quicksort(arr, j + 1, hi)

def quicksort(arr: List[Any]) -> None:
  return _quicksort(arr, 0, len(arr) - 1)
