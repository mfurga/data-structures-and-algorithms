#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>

typedef struct binary_tree_node
{
  int value;
  struct binary_tree_node *parent;
  struct binary_tree_node *left;
  struct binary_tree_node *right;
} binary_tree_node_t;

binary_tree_node_t *create_binary_tree(int value);

binary_tree_node_t *add_left_child(binary_tree_node_t *node, int value);

binary_tree_node_t *add_right_child(binary_tree_node_t *node, int value);

/* Depth-first search */
void pre_order(binary_tree_node_t *node);

/* Depth-first search */
void post_order(binary_tree_node_t *node);

/* Depth-first search */
void in_order(binary_tree_node_t *node);

/* Breadth-first search */
void level_order(binary_tree_node_t *node);

/* Implementation of queue using the linked list structure below */
/* The queue is used to help us go through the tree by using the level order traversal */

typedef struct queue_node
{
  binary_tree_node_t *item;
  struct queue_node *next;
} queue_node_t;

typedef struct queue
{
  queue_node_t *head;
  queue_node_t *tail;
} queue_t;

queue_t *create_queue(void);

void remove_queue(queue_t *queue)
{
  queue_node_t *current = queue->head;
  queue_node_t *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  free(queue);
}

void enqueue(queue_t *queue, binary_tree_node_t *item);

binary_tree_node_t *dequeue(queue_t *queue);

queue_t *create_queue(void)
{
  queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
  if (queue == NULL)
    exit(EXIT_FAILURE);

  queue->head = NULL;
  queue->tail = NULL;
  return queue;
}

void enqueue(queue_t *queue, binary_tree_node_t *item)
{
  queue_node_t *node = (queue_node_t *)malloc(sizeof(queue_node_t));
  if (node == NULL)
    return;
  node->item = item;
  node->next = NULL;

  if (queue->head == NULL)
    queue->head = node;
  else
    queue->tail->next = node;

  queue->tail = node;
}

binary_tree_node_t *dequeue(queue_t *queue)
{
  if (queue->head == NULL)
    return NULL;  // The queue is empty.

  queue_node_t *node = queue->head;
  binary_tree_node_t *item = node->item;

  queue->head = queue->head->next;
  if (queue->head == NULL)
    queue->tail = NULL;

  free(node);
  return item;
}

#endif  // BINARY_TREE_H
