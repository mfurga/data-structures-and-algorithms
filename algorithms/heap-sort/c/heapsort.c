#include <stdio.h>

#define LEFT_CHILD(n)   (n * 2 + 1)
#define RIGHT_CHILD(n)  (n * 2 + 2)
#define PARENT(n)       ((n - 1) / 2)

#define SWAP(a, b)      do { int _ = (a); (a) = (b); (b) = _; } while (0)

void heapify(int *t, int n, int i)
{
  int l = LEFT_CHILD(i);
  int r = RIGHT_CHILD(i);
  int m = i;

  if (l < n && t[l] > t[m])  m = l;
  if (r < n && t[r] > t[m])  m = r;

  if (m != i) {
    SWAP(t[i], t[m]);
    heapify(t, n, m);
  }
}

void build_heap(int *t, int n)
{
  for (int i = PARENT(n - 1); i >= 0; i--) {
    heapify(t, n, i);
  }
}

void heap_sort(int *t, int n)
{
  build_heap(t, n);

  for (int i = n - 1; i >= 1; i--) {
    SWAP(t[0], t[i]);
    heapify(t, i, 0);
  }
}

