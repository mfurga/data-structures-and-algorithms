#!/usr/bin/env python3

from typing import List, Any

def binary_search(array: List[Any], target: Any) -> bool:
  left, right = 0, len(array) - 1

  while left <= right:
    mid: int = (left + right) // 2

    if target > array[mid]:
      left = mid + 1
    elif target < array[mid]:
      right = mid - 1
    else:
      return True

  return False

def binary_search_rec(array: List[Any], target: Any, left: int, right: int) -> bool:
  if left > right:
    return False

  mid: int = (left + right) // 2

  if array[mid] > target:
    return binary_search_rec(array, target, left, mid - 1)

  if array[mid] < target:
    return binary_search_rec(array, target, mid + 1, right)

  return True
