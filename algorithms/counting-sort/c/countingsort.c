#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_max(int *a, int n)
{
  int max = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  return max;
}

void countingsort(int *a, int n)
{
  int k = find_max(a, n) + 1;
  int *c = (int *)malloc(sizeof(int) * k);
  int *t = (int *)malloc(sizeof(int) * n);

  if (c == NULL || t == NULL) {
    return;
  }

  memset(c, 0, k);

  for (int i = 0; i < n; i++) {
    c[a[i]]++;
  }

  for (int i = 1; i < k; i++) {
    c[i] += c[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    t[--c[a[i]]] = a[i];
  }

  for (int i = 0; i < n; i++) {
    a[i] = t[i];
  }

  free(c);
  free(t);
}

