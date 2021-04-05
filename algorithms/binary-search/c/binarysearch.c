#include <stdio.h>

int binary_search(int *arr, int len, int val)
{
  int lo = 0, hi = len - 1;
  int mid;

  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (arr[mid] < val) {
      lo = mid + 1;
    } else if (arr[mid] > val) {
      hi = mid - 1;
    } else {
      return 1;
    }
  }
  return 0;
}

int _binary_search_rec(int *arr, int val, int lo, int hi)
{
  if (lo > hi) {
    return 0;
  }

  int mid = (lo + hi) / 2;

  if (arr[mid] < val) {
    return _binary_search_rec(arr, val, mid + 1, hi);
  }

  if (arr[mid] > val) {
    return _binary_search_rec(arr, val, lo, mid - 1);
  }

  return 1;
}

int binary_search_rec(int *arr, int len, int val)
{
  return _binary_search_rec(arr, val, 0, len - 1);
}


