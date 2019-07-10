#ifndef REVERSE_POLISH_NOTATION_H
#define REVERSE_POLISH_NOTATION_H

#include <stdlib.h>
#include <stdbool.h>

int parse_reverse_polish_notation(const char expression[]);

void convert_to_reverse_polish_notation(const char expression[]);

/* A dynamic stack implementation below. */

typedef struct stack_node
{
  int value;
  struct stack_node *next;
} stack_node_t;

typedef struct
{
  stack_node_t *head;
} stack_t;

stack_t *create_stack(void)
{
  stack_t *s = (stack_t *)malloc(sizeof(stack_t));
  if (s == NULL)
    exit(EXIT_FAILURE);
  s->head = NULL;
  return s;
}

void remove_stack(stack_t *s)
{
  if (s == NULL)
    return;
  stack_node_t *curr = s->head;
  stack_node_t *next = NULL;
  for (; curr != NULL; curr = next) {
    next = curr->next;
    free(curr);
  }
  free(s);
}

void push(stack_t *s, int value)
{
  stack_node_t *node = (stack_node_t *)malloc(sizeof(stack_node_t));
  if (node == NULL)
    return;
  node->value = value;
  node->next = s->head;
  s->head = node;
}

int pop(stack_t *s)
{
  if (s->head == NULL)
    return -1;  /* The stack is empty. */
  stack_node_t *node = s->head;
  int v = node->value;
  s->head = s->head->next;
  free(node);
  return v;
}

int top(stack_t *s)
{
  return s->head->value;
}

bool empty_stack(stack_t *s)
{
  return s->head == NULL;
}

/* End of a dynamic stack implementation. */

#endif  // REVERSE_POLISH_NOTATION_H
