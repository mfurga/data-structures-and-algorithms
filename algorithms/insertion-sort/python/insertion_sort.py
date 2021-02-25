#!/usr/bin/env python3

def insertion_sort(arr, sz):
  for i in range(1, sz):
    key = arr[i]
    j = i - 1

    while j >= 0 and arr[j] > key:
      arr[j + 1] = arr[j]
      j -= 1

    arr[j + 1] = key

if __name__ == "__main__":
  arr = [5, 2, 4, 6, 1, 3]
  insertion_sort(arr, len(arr))
  print(arr)

