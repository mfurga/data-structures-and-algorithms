/* Doubly linked list implementation. */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

linked_list_t *create_linked_list(void);

void remove_linked_list(linked_list_t *list);

void push_back(linked_list_t *list, int value);

void erase(linked_list_t *list, int value);

#endif  // LINKED_LIST_H
