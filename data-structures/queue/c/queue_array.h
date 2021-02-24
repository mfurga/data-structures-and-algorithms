// Queue using the fixed-sized array.

#ifndef QUEUE_FIXED_SIZE_ARRAY_H
#define QUEUE_FIXED_SIZE_ARRAY_H

#include <stdbool.h>

typedef struct queue
{
  int capacity;
  int read;
  int write;
  int *array;
} queue_t;

queue_t *create_queue(int capacity);

void enqueue(queue_t *queue, int value);

int dequeue(queue_t *queue);

bool empty(queue_t *queue);

#endif  // QUEUE_FIXED_SIZE_ARRAY_H
