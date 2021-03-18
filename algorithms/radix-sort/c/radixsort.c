#include <stdio.h>
#include <stdlib.h>

int find_max(int *a, int n)
{
  int max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max) { max = a[i]; }
  }
  return max;
}

void countingsort(int *a, int n, int e)
{
  int c[10] = {0};

  int *t = (int *)malloc(sizeof(int) * n);
  if (t == NULL) {
    return;
  }

  for (int i = 0; i < n; i++) {
    c[(a[i] / e) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    c[i] += c[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    t[--c[(a[i] / e) % 10]] = a[i];
  }

  for (int i = 0; i < n; i++) {
    a[i] = t[i];
  }

  free(t);
}

void radixsort(int *a, int n)
{
  int m = find_max(a, n);
  for (int e = 1; m / e > 0; e *= 10) {
    countingsort(a, n, e);
  }
}

