#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic_array.h"

dynamic_array_t *create_dynamic_array(void)
{
  dynamic_array_t *da = (dynamic_array_t *)malloc(sizeof(dynamic_array_t));
  if (da == NULL) {
    fprintf(stderr, "Unable to allocate the memory for the dynamic array.\n");
    return NULL;
  }

  da->size = 0;
  da->capacity = 4;
  da->array = (int *)malloc(sizeof(int) * da->capacity);
  if (da->array == NULL) {
    fprintf(stderr, "Unable to allocate the memory for the array.\n");
    return NULL;
  }
  return da;
}

static void resize(dynamic_array_t *da)
{
  int *array = (int *)malloc(sizeof(int) * da->capacity * 2);
  if (array == NULL) {
    fprintf(stderr, "Unable to allocate the memory for the array.\n");
    return;
  }
  memcpy(array, da->array, sizeof(int) * da->size);
  free(da->array);

  da->capacity = da->capacity * 2;
  da->array = array;
}

void push_back(dynamic_array_t *da, int value)
{
  if (da->size >= da->capacity)
    resize(da);
  da->array[da->size++] = value;
}

int pop_back(dynamic_array_t *da)
{
  if (da->size <= 0)
    return -1;
  return da->array[--da->size];
}

int get(dynamic_array_t *da, int index)
{
  if (index < 0 || index >= da->size)
    return -1;  // ERROR: index out of range
  return da->array[index];
}

void set(dynamic_array_t *da, int index, int value)
{
  if (index < 0 || index >= da->size)
    return;  // ERROR: index out of range
  da->array[index] = value;
}

void insert(dynamic_array_t *da, int index, int value)
{
  if (index < 0 || index >= da->size)
    return;  // ERROR: index out of range

  if (da->size >= da->capacity)
    resize(da);

  for (int i = da->size - 1; i >= index; i--) {
    da->array[i + 1] = da->array[i];
  }
  da->array[index] = value;
  da->size++;
}

void delete(dynamic_array_t *da, int index)
{
  if (index < 0 || index >= da->size)
    return;  // ERROR: index out of range
  for (int i = index; i < da->size; i++) {
    da->array[i] = da->array[i + 1];
  }
  da->size--;
}

int find(dynamic_array_t *da, int value)
{
  for (int i = 0; i < da->size; i++) {
    if (da->array[i] == value)
      return i;
  }
  return -1;
}
