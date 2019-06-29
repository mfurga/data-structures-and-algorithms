#!/usr/bin/env python3
from typing import List, Any


def _merge(arr: List[Any], copy: List[Any], lo: int, mid: int,
           hi: int) -> None:
  # Arr[lo] to arr[mid] and arr[mid + 1] to arr[hi] must be sorted.
  copy[lo:hi + 1] = arr[lo:hi + 1]

  i, j = lo, mid + 1
  for k in range(lo, hi + 1):
    if i > mid:
      arr[k] = copy[j]; j += 1
    elif j > hi:
      arr[k] = copy[i]; i += 1
    elif copy[i] < copy[j]:
      arr[k] = copy[i]; i += 1
    elif copy[i] >= copy[j]:
      arr[k] = copy[j]; j += 1

def _sort(arr: List[Any], copy: List[Any], lo: int, hi: int) -> None:
  if hi <= lo:
    return
  mid = lo + (hi - lo) // 2
  _sort(arr, copy, lo, mid)
  _sort(arr, copy, mid + 1, hi)
  _merge(arr, copy, lo, mid, hi)

def sort(arr: List[Any]) -> None:
  copy = arr[:]
  _sort(arr, copy, 0, len(arr) - 1)
