/* Doubly linked list implementation. */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <assert.h>

typedef struct linked_list_node
{
  int value;
  struct linked_list_node *next;
  struct linked_list_node *prev;
} linked_list_node_t;

typedef struct linked_list
{
  struct linked_list_node *head;
  struct linked_list_node *tail;
} linked_list_t;

linked_list_t *create_linked_list(void)
{
  linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
  if (list == NULL)
    exit(EXIT_FAILURE);
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void remove_linked_list(linked_list_t *list)
{
  assert(list != NULL);
  linked_list_node_t *current = list->head;
  linked_list_node_t *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

void push_back(linked_list_t *list, int value)
{
  linked_list_node_t *node = 
    (linked_list_node_t *)malloc(sizeof(linked_list_node_t));
  if (node == NULL)
    return;

  node->value = value;
  node->next = NULL;
  node->prev = list->tail;

  if (list->head == NULL)
    list->head = node;
  else
    list->tail->next = node;

  list->tail = node;
}

void erase(linked_list_t *list, int value)
{
  linked_list_node_t *current;
  for (current = list->head; current != NULL && current->value != value; 
       current = current->next);
  if (current == NULL)
    return;

  if (current->prev == NULL)
    list->head = current->next;
  else
    current->prev->next = current->next;

  if (current->next == NULL)
    list->tail = current->prev;
  else
    current->next->prev = current->prev;

  free(current);
}

#endif  // LINKED_LIST_H
