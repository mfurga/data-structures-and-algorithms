#!/usr/bin/env python3

from typing import List

def bubble_sort(arr: List, size: int) -> None:
  for i in range(size):
    for j in range(1, size - i):
      if arr[j - 1] > arr[j]:
        arr[j - 1], arr[j] = arr[j], arr[j - 1]

if __name__ == "__main__":
  arr = [6, 3, 5, 10, -1, 7, -4]
  bubble_sort(arr, len(arr))
