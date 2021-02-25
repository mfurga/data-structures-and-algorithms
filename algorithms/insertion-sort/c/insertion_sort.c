#include <stdio.h>

void insertion_sort(int *arr, size_t size)
{
  size_t i = 1, j = 1;
  int key;

  for (i = 1; i < size; i++) {
    j = i;
    key = arr[j];

    while (j > 0 && arr[j - 1] < key) {
      arr[j] = arr[j - 1];
      j--;
    }

    arr[j] = key;
  }
}

int main(void)
{
  int arr[] = {5, 1, 3, -10, 2, 4};
  size_t n = 6;

  insertion_sort(arr, n);

  return 0;
}