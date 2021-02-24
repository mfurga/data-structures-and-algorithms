// Queue using the linked list data structure.

#include <stdlib.h>
#include "queue_linked_list.h"

queue_t *create_queue(void)
{
  queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
  if (queue == NULL)
    exit(EXIT_FAILURE);

  queue->head = NULL;
  queue->tail = NULL;
  return queue;
}

void enqueue(queue_t *queue, int value)
{
  queue_node_t *node = (queue_node_t *)malloc(sizeof(queue_node_t));
  if (node == NULL)
    return;
  node->value = value;
  node->next = NULL;

  if (queue->head == NULL)
    queue->head = node;
  else
    queue->tail->next = node;

  queue->tail = node;
}

int dequeue(queue_t *queue)
{
  if (queue->head == NULL)
    return -1;  // The queue is empty.

  queue_node_t *node = queue->head;
  int value = node->value;

  queue->head = queue->head->next;
  if (queue->head == NULL)
    queue->tail = NULL;

  free(node);
  return value;
}

bool empty(queue_t *queue)
{
  return queue->head == NULL;
}
