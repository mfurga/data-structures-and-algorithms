#ifndef _QUEUE_H_INCLUDED_
#define _QUEUE_H_INCLUDED_

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define QUEUE_PARENT(n) ((n - 1) / 2)
#define QUEUE_LEFT(n)   (n * 2 + 1)
#define QUEUE_RIGHT(n)  (n * 2 + 2)

typedef struct queue_item_s {
  tree_t *value;
  int     prio;
} queue_item_t;

typedef struct queue_s {
  queue_item_t **items;
  int             len;
  int             cap;
} queue_t;

queue_t *queue_init(int cap)
{
  queue_t *q = (queue_t *)malloc(sizeof(queue_t));
  q->items = (queue_item_t **)malloc(sizeof(queue_item_t *));

  for (int i = 0; i < cap; i++) {
    q->items[i] = (queue_item_t *)malloc(sizeof(queue_item_t));
  }

  q->len = 0;
  q->cap = cap;
  return q;
}

queue_item_t *queue_item_init(tree_t *t, int p)
{
  queue_item_t *i = (queue_item_t *)malloc(sizeof(queue_item_t));
  i->value = t;
  i->prio = p;
  return i;
}

tree_t *queue_item_remove(queue_item_t *i)
{
  tree_t *t = i->value;
  free(i);
  return t;
}

void queue_remove(queue_t *q)
{
  for (int i = 0; i < q->len; i++) {
    queue_item_remove(q->items[i]);
  }
  free(q);
}

void queue_swap(queue_item_t **a, queue_item_t **b)
{
  queue_item_t *t = *a;
  *a = *b;
  *b = t;
}

void queue_siftup(queue_t *q, int i)
{
  while (i > 0 && q->items[QUEUE_PARENT(i)]->prio > q->items[i]->prio) {
    queue_swap(&q->items[QUEUE_PARENT(i)], &q->items[i]);
    i = QUEUE_PARENT(i);
  }
}

void queue_heapify(queue_t *q, int i)
{
  int l = QUEUE_LEFT(i);
  int r = QUEUE_RIGHT(i);
  int m = i;

  if (l < q->len && q->items[l]->prio < q->items[m]->prio) {
    m = l;
  }

  if (r < q->len && q->items[r]->prio < q->items[m]->prio) {
    m = r;
  }

  if (m != i) {
    queue_swap(&q->items[m], &q->items[i]);
    queue_heapify(q, m);
  }
}

void queue_enqueue(queue_t *q, tree_t *t, int p)
{
  if (q->len == q->cap) {
    return;
  }
  q->items[q->len++] = queue_item_init(t, p);
  queue_siftup(q, q->len - 1);
}

tree_t *queue_dequeue(queue_t *q)
{
  queue_swap(&q->items[0], &q->items[--q->len]);
  tree_t *t = queue_item_remove(q->items[q->len]);
  queue_heapify(q, 0);
  return t;
}

int queue_length(queue_t *q)
{
  return q->len;
}

#endif  // _QUEUE_H_INCLUDED_

