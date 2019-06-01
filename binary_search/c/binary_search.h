#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stdbool.h>

bool binary_search(int target, int numbers[], int size);
bool binary_search_rec(int target, int numbers[], int left, int right);

bool binary_search(int target, int numbers[], int size)
{
  int left = 0;
  int right = size - 1;
  int mid;

  while (left <= right) {
    mid = (left + right) / 2;

    if (numbers[mid] < target) {
      left = mid + 1;
      continue;
    }

    if (numbers[mid] > target) {
      right = mid - 1;
      continue;
    } 

    if (numbers[mid] == target)
      return true;
  }

  return false;
}

bool binary_search_rec(int target, int numbers[], int left, int right)
{
  if (left >= right)
    return false;

  int mid = (left + right) / 2;
  if (numbers[mid] < target)
    binary_search_rec(target, numbers, mid + 1, right);
  else if (numbers[mid] > target)
    binary_search_rec(target, numbers, left, right - 1);
  else 
    return true;
}


#endif  // BINARY_SEARCH_H
