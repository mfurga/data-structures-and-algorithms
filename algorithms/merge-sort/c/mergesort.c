#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

void _merge(int *a, int *c, int lo, int mid, int hi)
{
  for (int k = lo; k <= hi; k++) {
    c[k] = a[k];
  }

  int i = lo, j = mid + 1;
  for (int k = lo; k <= hi; k++) {
    if (i > mid)                  a[k] = c[j++];
    else if (j > hi)              a[k] = c[i++];
    else if (c[i] < c[j])         a[k] = c[i++];
    else if (c[i] >= c[j])        a[k] = c[j++];
  }
}

void _mergesort(int *a, int *c, int lo, int hi)
{
  if (hi <= lo) {
    return;
  }
  int mid = lo + (hi - lo) / 2;
  _mergesort(a, c, lo, mid);
  _mergesort(a, c, mid + 1, hi);
  _merge(a, c, lo, mid, hi);
}


void mergesort(int *a, int n)
{
  int c[n];
  _mergesort(a, c, 0, n - 1);
}

void mergesort_iter(int *a, int n)
{
  int c[n];
  for (int sz = 1; sz < n; sz = sz + sz) {
    for (int lo = 0; lo < n - sz; lo += sz + sz) {
      _merge(a, c, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
    }
  }
}

