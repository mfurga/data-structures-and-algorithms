#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct dynamic_array
{
  int size;
  int capacity;
  int *array;
} dynamic_array_t;

dynamic_array_t *create_dynamic_array(void);

static void resize(dynamic_array_t *da);

void push_back(dynamic_array_t *da, int value);

int pop_back(dynamic_array_t *da);

void insert(dynamic_array_t *da, int index, int value);

void set(dynamic_array_t *da, int index, int value);

int get(dynamic_array_t *da, int index);

void delete(dynamic_array_t *da, int index);

int find(dynamic_array_t *da, int value);

#endif  // DYNAMIC_ARRAY_H
