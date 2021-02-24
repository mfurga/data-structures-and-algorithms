#include <stdio.h>
#include <stdbool.h>

bool binary_search(int array[], int length, int target)
{
  int left = 0, right = length - 1;
  int mid;

  while (left <= right) {
    mid = (left + right) / 2;

    if (array[mid] < target) {
      left = mid + 1;
    } else if (array[mid] > target) {
      right = mid - 1;
    } else {
      return true;
    }
  }

  return false;
}

bool binary_search_rec(int array[], int target, int left, int right)
{
  if (left > right) {
    return false;
  }

  int mid = (left + right) / 2;

  if (array[mid] < target) {
    return binary_search_rec(array, target, mid + 1, right);
  }

  if (array[mid] > target) {
    return binary_search_rec(array, target, left, mid - 1);
  }

  return true;
}
