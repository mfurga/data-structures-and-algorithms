#!/usr/bin/env python3

from typing import List

def insertion_sort(arr: List, size: int) -> None:
  for i in range(1, size):
    j = i
    key = arr[i]

    while j > 0 and arr[j - 1] > key:
      arr[j] = arr[j - 1]
      j -= 1

    arr[j] = key

if __name__ == "__main__":
  arr = [6, 3, 5, 10, -1, 7, -4]
  insertion_sort(arr, len(arr))
