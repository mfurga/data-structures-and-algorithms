#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

bool binary_search(int target, int numbers[], int size)
{
  int left = 0;
  int right = size - 1;
  int mid;

  while (left <= right) {
    mid = (left + right) / 2;

    if (target > numbers[mid])
      left = mid + 1;
    else if (target < numbers[mid])
      right = mid - 1;
    else
      return true;
  }
  return false;
}

bool binary_search_rec(int target, int numbers[], int left, int right)
{
  if (left > right)
    return false;

  int mid = (left + right) / 2;
  if (target > numbers[mid])
    return binary_search_rec(target, numbers, mid + 1, right);
  else if (target < numbers[mid])
    return binary_search_rec(target, numbers, left, mid - 1);
  else
    return true;
}

#endif  // BINARY_SEARCH_H
