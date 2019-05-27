#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

linked_list_t *create_linked_list(void)
{
  linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
  if (list == NULL) {
    fprintf(stderr, "Unable to allocate the memory for the linked_list_t.\n");
    exit(EXIT_FAILURE);
  }
  list->head = NULL;
  list->tail = NULL;
  return list;
}

int size(linked_list_t *list)
{
  int count = 0;
  for (linked_list_node_t *i = list->head; i != NULL; i = i->next) {
    count++;
  }
  return count;
}

bool is_empty(linked_list_t *list)
{
  return list->head == NULL;
}

void push_front(linked_list_t *list, int value)
{
  linked_list_node_t *node = (linked_list_node_t *)malloc(sizeof(linked_list_node_t));
  if (node == NULL) {
    fprintf(stderr, "Unable to allocate the memory for the linked_list_node_t.\n");
    return;
  }
  node->value = value;
  node->prev = NULL;
  node->next = list->head;

  if (list->head == NULL)
    list->tail = node;
  else
    list->head->prev = node;

  list->head = node;
}

int pop_front(linked_list_t *list)
{
  if (list->head == NULL) {
    fprintf(stderr, "The linked list is empty.\n");
    return -1;
  }
  linked_list_node_t *node = list->head;
  int value = node->value;

  list->head = list->head->next;
  if (list->head == NULL)
    list->tail = NULL;
  else
    list->head->prev = NULL;

  free(node);
  return value;
}

void push_back(linked_list_t *list, int value)
{
  linked_list_node_t *node = (linked_list_node_t *)malloc(sizeof(linked_list_node_t));
  if (node == NULL) {
    fprintf(stderr, "Unable to allocate the memory for the linked_list_node_t.\n");
    return;
  }
  node->value = value;
  node->next = NULL;
  node->prev = list->tail;

  if (list->head == NULL)
    list->head = node;
  else
    list->tail->next = node;

  list->tail = node;
}

int pop_back(linked_list_t *list)
{
  if (list->head == NULL) {
    fprintf(stderr, "The linked list is empty.\n");
    return -1;
  }
  linked_list_node_t *node = list->tail;
  int value = node->value;

  list->tail = list->tail->prev;
  if (list->tail == NULL)
    list->head = NULL;
  else
    list->tail->next = NULL;

  free(node);
  return value;
}

int front(linked_list_t *list)
{
  if (list->head == NULL) {
    fprintf(stderr, "The linked list is empty.\n");
    return -1;
  }
  return list->head->value;
}

int back(linked_list_t *list)
{
  if (list->head == NULL) {
    fprintf(stderr, "The linked list is empty.\n");
    return -1;
  }
  return list->tail->value;
}

void insert(linked_list_t *list, int index, int value)
{
  if (index < 0 || index >= size(list)) {
    fprintf(stderr, "Invalid index.\n");
    return;
  }

  linked_list_node_t *node = (linked_list_node_t *)malloc(sizeof(linked_list_node_t));
  if (node == NULL) {
    fprintf(stderr, "Unable to allocate the memory for the linked_list_node_t.\n");
    return;
  }
  node->value = value;

  linked_list_node_t *in = list->head;
  for (int i = 0; i != index; i++, in = in->next);

  node->next = in;
  node->prev = in->prev;

  if (in->prev == NULL)
    list->head = node;
  else
    in->prev->next = node;

  in->prev = node;
}

void erase(linked_list_t *list, int index)
{
  if (index < 0 || index >= size(list)) {
    fprintf(stderr, "Invalid index.\n");
    return;
  }

  linked_list_node_t *in = list->head;
  for (int i = 0; i != index; i++, in = in->next);

  if (in->prev == NULL)
    list->head = in->next;
  else
    in->prev->next = in->next;

  if (in->next == NULL)
    list->tail = in->prev;
  else
    in->next->prev = in->prev;

  free(in);
}

void reverse(linked_list_t *list)
{
  if (list->head == NULL || list->head->next == NULL)
    return;

  list->tail = list->head;
  linked_list_node_t *tmp = NULL;

  for (linked_list_node_t *in = list->head; in != NULL; in = in->prev) {
    tmp = in->prev;
    in->prev = in->next;
    in->next = tmp;
  }

  list->head = tmp->prev;
}
