#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct linked_list_node
{
  int value;
  struct linked_list_node *prev;
  struct linked_list_node *next;
} linked_list_node_t;

typedef struct linked_list
{
  struct linked_list_node *head;
  struct linked_list_node *tail;
} linked_list_t;

linked_list_t *create_linked_list(void);

int size(linked_list_t *list);

bool is_empty(linked_list_t *list);

void push_front(linked_list_t *list, int value);

int pop_front(linked_list_t *list);

void push_back(linked_list_t *list, int value);

int pop_back(linked_list_t *list);

int front(linked_list_t *list);

int back(linked_list_t *list);

void insert(linked_list_t *list, int index, int value);

void erase(linked_list_t *list, int index);

void reverse(linked_list_t *list);

#endif  // LINKED_LIST_H
