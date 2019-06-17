#include <stdlib.h>
#include "merge_sort.h"

#define array_size(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#define min(a, b) ((a) < (b) ? (a) : (b))

static void merge(int *arr, int *copy, int lo, int mid, int hi)
{
  /* Arr[lo] to arr[mid] and arr[mid + 1] to arr[hi] must be sorted. */
  
  for (int k = lo; k <= hi; k++)
    copy[k] = arr[k];

  int i = lo, j = mid + 1;
  for (int k = lo; k <= hi; k++) {
    if (i > mid)                  arr[k] = copy[j++];
    else if (j > hi)              arr[k] = copy[i++];
    else if (copy[i] < copy[j])   arr[k] = copy[i++];
    else if (copy[i] >= copy[j])  arr[k] = copy[j++];
  }
}

static void sort_(int *arr, int *copy, int lo, int hi)
{
  if (hi <= lo) return;
  int mid = lo + (hi - lo) / 2;
  sort_(arr, copy, lo, mid);
  sort_(arr, copy, mid + 1, hi);
  merge(arr, copy, lo, mid, hi);
}

void sort_iter(int *arr, int size)
{
  int copy[size];
  for (int sz = 1; sz < size; sz = sz + sz)
    for (int lo = 0; lo < size - sz; lo += sz + sz)
      merge(arr, copy, lo, lo + sz - 1, min(lo + sz + sz - 1, size - 1));
}

void sort(int *arr, int size)
{
  int copy[size];
  sort_(arr, copy, 0, size - 1);
}
