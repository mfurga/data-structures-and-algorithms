#ifndef GRAPH_ADJACENCY_LISTS_H
#define GRAPH_ADJACENCY_LISTS_H

#include <stdbool.h>
#include "linked_list.h"

typedef struct
{
  int vertices;  /* number of vertices */
  int edges;     /* number of edges */
  linked_list_t **lists;
} graph_t;

graph_t *create_graph(int vertices);

void remove_graph(graph_t *g);

void add_edge(graph_t *g, int src, int dest);

void remove_edge(graph_t *g, int src, int dest);

void breadth_first_search(graph_t *g, int vertex);

static void depth_first_search_(graph_t *g, int vertex, bool visited[]);

void depth_first_search(graph_t *g, int vertex);

static bool find_path_(graph_t *g, int src, int dest, bool visited[],
                       stack_t *s);

void find_path(graph_t *g, int src, int dest);

#endif  // GRAPH_ADJACENCY_LISTS_H

/* ================ Queue implementation. ================ */

#ifndef QUEUE_FIXED_SIZE_ARRAY_H
#define QUEUE_FIXED_SIZE_ARRAY_H

#include <stdlib.h>

typedef struct queue
{
  int capacity;
  int read;
  int write;
  int *array;
} queue_t;

queue_t *create_queue(int capacity)
{
  queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
  if (queue == NULL)
    exit(EXIT_FAILURE);

  queue->capacity = capacity + 1;
  queue->read = 0;
  queue->write = 0;
  queue->array = (int *)malloc(sizeof(int) * queue->capacity);
  if (queue->array == NULL)
    exit(EXIT_FAILURE);

  return queue;
}

void remove_queue(queue_t *queue)
{
  if (queue == NULL || queue->array == NULL)
    return;
  free(queue->array);
  free(queue);
}

bool empty(queue_t *queue)
{
  return queue->write == queue->read;
}

void enqueue(queue_t *queue, int value)
{
  if ((queue->write + 1) % queue->capacity == queue->read)
    return;  // The queue is full.

  queue->array[queue->write] = value;
  queue->write = (queue->write + 1) % queue->capacity;
}

int dequeue(queue_t *queue)
{
  if (queue->write == queue->read)
    return -1;  // The queue is empty.

  int res = queue->array[queue->read];
  queue->read = (queue->read + 1) % queue->capacity;
  return res;
}

#endif  // QUEUE_FIXED_SIZE_ARRAY_H

/* ================ Stack implementation. ================ */

#ifndef STACK_FIXED_SIZE_ARRAY_H
#define STACK_FIXED_SIZE_ARRAY_H

typedef struct
{
  int top;
  int capacity;
  int *array;
} stack_t;

stack_t *create_stack(int capacity)
{
  stack_t *st = (stack_t *)malloc(sizeof(stack_t));
  if (st == NULL)
    exit(EXIT_FAILURE);
  st->capacity = capacity;
  st->top = 0;
  st->array = (int *)malloc(sizeof(int) * st->capacity);
  if (st->array == NULL)
    exit(EXIT_FAILURE);
  return st;
}

void remove_stack(stack_t *st)
{
  if (st == NULL || st->array == NULL)
    return;
  free(st->array);
  free(st);
}

void push(stack_t *st, int value)
{
  if (st->top == st->capacity)
    return;  /* Stack is full. */
  st->array[st->top++] = value;
}

int pop(stack_t *st)
{
  if (st->top == 0)
    return -1;  /* Stack is empty. */
  return st->array[--st->top];
}

bool empty_stack(stack_t *st)
{
  return st->top == 0;
}

#endif  // STACK_FIXED_SIZE_ARRAY_H
