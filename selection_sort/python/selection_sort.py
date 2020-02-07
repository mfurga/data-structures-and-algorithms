#!/usr/bin/env python3

from typing import List

def selection_sort(arr: List, size: int) -> None:
  for i in range(size):
    j, k = i, i

    while j < size:
      if arr[j] > arr[k]:
        k = j
      j += 1

    arr[i], arr[k] = arr[k], arr[i]
  return None

if __name__ == "__main__":
  arr = [-13, 1, 6, -3, 0, 5, -2, 10]
  selection_sort(arr, len(arr))
