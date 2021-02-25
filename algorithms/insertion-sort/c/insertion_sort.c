#include <stdio.h>

void insertion_sort(int *arr, int sz)
{
  int i, j, key;

  for (i = 1; i < sz; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

int main(void)
{
  int arr[] = {5, 2, 4, 6, 1, 3};
  insertion_sort(arr, 6);
  return 0;
}

