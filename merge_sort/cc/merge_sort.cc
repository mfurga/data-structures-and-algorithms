#include "merge_sort.h"

namespace mf
{

template <typename T=int>
static void merge(T arr[], T copy[], int lo, int mid, int hi)
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

template <typename T=int>
static void sort(T arr[], T copy[], int lo, int hi)
{
  if (hi <= lo) return;
  int mid = lo + (hi - lo) / 2;
  sort(arr, copy, lo, mid);
  sort(arr, copy, mid + 1, hi);
  merge(arr, copy, lo, mid, hi);
}

template <typename T=int>
void sort(T arr[], int size)
{
  T copy[size];
  sort(arr, copy, 0, size - 1);
}

}  // namespace mf
