#!/usr/bin/env python3

def bubble_sort(arr):
  n = len(arr)
  for i in range(n):
    for j in range(1, n - i):
      if arr[j - 1] > arr[j]:
        arr[j - 1], arr[j] = arr[j], arr[j - 1]

if __name__ == "__main__":
  arr = [6, 3, 5, 10, -1, 7, -4]
  bubble_sort(arr)

