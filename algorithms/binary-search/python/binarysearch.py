#!/usr/bin/env python3

def binary_search(arr, val):
  left, right = 0, len(arr) - 1
  while left <= right:
    mid = (left + right) // 2
    if val > arr[mid]:
      left = mid + 1
    elif val < arr[mid]:
      right = mid - 1
    else:
      return True
  return False

def _binary_search_rec(arr, val, lo, hi):
  if lo > hi:
    return False
  mid = (lo + hi) // 2
  if arr[mid] > val:
    return _binary_search_rec(arr, val, lo, mid - 1)
  if arr[mid] < val:
    return _binary_search_rec(arr, val, mid + 1, hi)
  return True

def binary_search_rec(arr, val):
  return _binary_search_rec(arr, val, 0, len(arr) - 1)

