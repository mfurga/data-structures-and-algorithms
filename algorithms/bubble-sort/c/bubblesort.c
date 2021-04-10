#include <stdio.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void bubble_sort(int *a, int n)
{
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n - i; j++) {
      if (a[j - 1] > a[j]) {
        swap(&a[j - 1], &a[j]);
      }
    }
  }
}

int main(void)
{
  int a[] = {5, -1, 3, 8, -4, 0};
  bubble_sort(arr, 6);
  return 0;
}

