// Queue using the linked list data structure.

#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include <stdbool.h>

typedef struct queue_node
{
  int value;
  struct queue_node *next;
} queue_node_t;

typedef struct queue
{
  struct queue_node *head;
  struct queue_node *tail;
} queue_t;

queue_t *create_queue(void);

void enqueue(queue_t *queue, int value);

int dequeue(queue_t *queue);

bool empty(queue_t *queue);

#endif  // QUEUE_LINKED_LIST_H
