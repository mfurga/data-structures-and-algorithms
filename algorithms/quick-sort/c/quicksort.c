#include <stdio.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int *a, int l, int h)
{
  int p = a[h];
  int i = l - 1;

  for (int j = l; j < h; j++) {
    if (a[j] < p) {
      i += 1;
      swap(&a[i], &a[j]);
    }
  }

  swap(&a[i + 1], &a[h]);
  return i + 1;
}

void _quicksort(int *a, int l, int h)
{
  if (l < h) {
    int p = partition(a, l, h);
    _quicksort(a, l, p - 1);
    _quicksort(a, p + 1, h);
  }
}

void quicksort(int *a, int n)
{
  return _quicksort(a, 0, n - 1);
}

int main(void)
{
  return 0;
}

