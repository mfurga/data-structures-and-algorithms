#include <stdio.h>
#define swap(a, b) int tmp = (a); (a) = (b); (b) = tmp;

void insertion_sort(int *arr, int size)
{
  int j = 1;
  for (int i = 1; i < size; i++) {
    j = i;
    while (j > 0 && arr[j] < arr[j - 1]) {
      swap(arr[j], arr[j - 1]);
      j--;
    }
  }
}
