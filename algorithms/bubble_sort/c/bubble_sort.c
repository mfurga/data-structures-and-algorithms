#include <stdio.h>

void bubble_sort(int *arr, size_t sz)
{
  size_t i, j;
  int tmp;

  for (i = 0; i < sz; i++) {
    for (j = 1; j < sz - i; j++) {
      if (arr[j - 1] > arr[j]) {
        tmp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

int main(void)
{
  int arr[] = {5, -1, 3, 8, -4, 0};
  size_t sz = 6;

  bubble_sort(arr, sz);
  return 0;
}
