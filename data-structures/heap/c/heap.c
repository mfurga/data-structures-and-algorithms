/* Binary max heap implemented using array. */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "heap.h"

#define swap(a, b) int tmp = (a); (a) = (b); (b) = tmp;

binary_max_heap_t *create_binary_max_heap(void)
{
  binary_max_heap_t *h = (binary_max_heap_t *)malloc(sizeof(binary_max_heap_t));
  if (h == NULL)
    exit(EXIT_FAILURE);
  h->capacity = BINARY_MAX_HEAP_CAPACITY + 1;  /* We won't use the first index. */
  h->size = 0;
  h->array = (int *)malloc(sizeof(int) * h->capacity);
  if (h->array == NULL)
    exit(EXIT_FAILURE);
  return h;
}

void delete_binary_max_heap(binary_max_heap_t *h)
{
  if (h == NULL || h->array == NULL)
    return;
  free(h->array);
  free(h);
}

static void sift_up(binary_max_heap_t *h, int index)
{
  while (index > 1 && h->array[index] > h->array[index / 2]) {
    /* Now we need to swap the values (change their priority). */
    swap(h->array[index], h->array[index / 2]);
    index /= 2;
  }
}

static void sift_down(binary_max_heap_t *h, int index)
{
  int max_index = index;
  /* Check if the left child exists and compare. */
  if (index * 2 <= h->size &&
      h->array[index * 2] > h->array[max_index]) {
    max_index = index * 2;
  }

  /* Check if the right child exists and compare. */
  if ((index * 2 + 1) <= h->size &&
       h->array[index * 2 + 1] > h->array[max_index]) {
    max_index = index * 2 + 1;
  }

  if (index != max_index) {
    swap(h->array[index], h->array[max_index]);
    sift_down(h, max_index);
  }
}

void insert(binary_max_heap_t *h, int value)
{
  if (h->size == h->capacity)
    return;  /* Heap is full. */

  h->array[++h->size] = value;
  sift_up(h, h->size);
}

int extract_max(binary_max_heap_t *h)
{
  if (h->size == 0)
    return -1;  /* Heap is empty. */

  int res = h->array[1];
  h->array[1] = h->array[h->size--];
  sift_down(h, 1);
  return res;
}

int get_max(binary_max_heap_t *h)
{
  if (h->size == 0)
    return -1;  /* Heap is empty. */
  return h->array[1];
}

binary_max_heap_t *heapify(int *array, size_t len)
{
  binary_max_heap_t *h = create_binary_max_heap();
  h->size = (int)len;
  memcpy(h->array + 1, array, sizeof(int) * len);

  for (int i = h->size / 2; i > 0; i--) {
    sift_down(h, i);
  }
  return h;
}

void heap_sort(int *array, size_t len)
{
  binary_max_heap_t *h = heapify(array, len);
  for (int i = 0; i < len; i++) {
    array[i] = extract_max(h);
  }
  delete_binary_max_heap(h);
}
