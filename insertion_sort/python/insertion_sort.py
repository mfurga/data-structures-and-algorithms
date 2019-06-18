#!/usr/bin/env python2


def insertion_sort(arr):
  for i in xrange(1, len(arr)):
    j = i
    while j > 0 and arr[j] < arr[j - 1]:
      arr[j], arr[j - 1] = arr[j - 1], arr[j]
      j -= 1
