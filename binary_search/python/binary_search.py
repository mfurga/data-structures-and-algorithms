#!/usr/bin/env python2


def binary_search(target, numbers, size):
  left = 0
  right = size - 1

  while left <= right:
    mid = (left + right) / 2

    if target > numbers[mid]:
      left = mid + 1
    elif target < numbers[mid]:
      right = mid - 1
    else:
      return True

  return False


def binary_search_rec(target, numbers, left, right):
  if left > right:
    return False

  mid = (left + right) / 2
  if target > numbers[mid]:
    return binary_search_rec(target, numbers, mid + 1, right)
  elif target < numbers[mid]:
    return binary_search_rec(target, numbers, left, mid - 1)
  else:
    return True


if __name__ == '__main__':
  numbers = [1, 3, 5, 6, 7, 8, 10]
  print binary_search_rec(9, numbers, 0, len(numbers) - 1)
