#include <stdio.h>

void selection_sort(int *arr, size_t size)
{
  size_t i, j, k;
  int t;

  for (i = 0; i < size; i++) {
    k = i;

    for (j = i + 1; j < size; j++) {
      if (arr[j] > arr[k]) {
        k = j;
      }
    }

    t = arr[i];
    arr[i] = arr[k];
    arr[k] = t;
  }
}


int main(void)
{
  int arr[] = {5, 1, 3, -10, 2, 4};
  size_t n = 6;

  selection_sort(arr, n);

  return 0;
}
