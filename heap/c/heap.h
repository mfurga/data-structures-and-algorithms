/* Binary max heap implemented using array. */
#ifndef BINARY_MAX_HEAP_H
#define BINARY_MAX_HEAP_H

#define BINARY_MAX_HEAP_CAPACITY 256

typedef struct
{
  int capacity;
  int size;
  int *array;
} binary_max_heap_t;

binary_max_heap_t *create_binary_max_heap(void);

static void sift_up(binary_max_heap_t *h, int index);

static void sift_down(binary_max_heap_t *h, int index);

void insert(binary_max_heap_t *h, int value);

int extract_max(binary_max_heap_t *h);

int get_max(binary_max_heap_t *h);

binary_max_heap_t *heapify(int *array, size_t len);

#endif  // BINARY_MAX_HEAP_H
