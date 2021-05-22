#ifndef STACK_FIXED_SIZE_ARRAY_H
#define STACK_FIXED_SIZE_ARRAY_H

#include <stdlib.h>

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