#include <utility>
#include "quick_sort.h"

namespace mf
{

template<typename T>
static int partition(T *arr, int lo, int hi)
{
  /* We'll take the first element in the array as our pivot. */
  T pivot = arr[lo];

  int i = lo, j = hi + 1;
  while (true) {
    while (arr[++i] < pivot) if (i == hi) break;
    while (arr[--j] > pivot);  /* if (j == lo) break; */

    if (j <= i) break;
    std::swap(arr[i], arr[j]);
  }

  std::swap(arr[lo], arr[j]);
  return j;
}

template<typename T>
static void quicksort(T *arr, int lo, int hi)
{
  if (lo >= hi) return;
  int j = partition(arr, lo, hi);
  quicksort(arr, lo, j - 1);
  quicksort(arr, j + 1, hi);
}

template<typename T=int>
void quicksort(T *arr, int size)
{
  return quicksort(arr, 0, size - 1);
}

}  // namespace mf
