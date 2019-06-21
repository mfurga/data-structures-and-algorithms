#include <stdio.h>
#define swap(a, b) int tmp = (a); (a) = (b); (b) = tmp;

static int partition(int *arr, int lo, int hi)
{
  /* We'll take the first element in the array as our pivot. */
  int pivot = arr[lo];

  int i = lo, j = hi + 1;
  while (true) {
    while (arr[++i] < pivot) if (i == hi) break;
    while (arr[--j] > pivot); /* if (j == lo) break; */

    if (j <= i) break;
    swap(arr[i], arr[j]);
  }

  swap(arr[lo], arr[j]);
  return j;
}

static void quicksort_(int *arr, int lo, int hi)
{
  if (hi <= lo) return;
  int j = partition(arr, lo, hi);
  quicksort_(arr, lo, j - 1);
  quicksort_(arr, j + 1, hi);
}

void quicksort(int *arr, int size)
{
  return quicksort_(arr, 0, size - 1);
}
