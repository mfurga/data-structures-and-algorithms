#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>

typedef struct binary_tree_node
{
  int value;
  struct binary_tree_node *parent;
  struct binary_tree_node *left;
  struct binary_tree_node *right;
} binary_tree_node_t;

binary_tree_node_t *create_binary_tree(int value);

static binary_tree_node_t *add_left_child(binary_tree_node_t *node, int value);

static binary_tree_node_t *add_right_child(binary_tree_node_t *node, int value);

void insert(binary_tree_node_t *node, int value);

binary_tree_node_t *find(binary_tree_node_t *node, int value);

int height(binary_tree_node_t *node);

int maximum(binary_tree_node_t *node);

int minimum(binary_tree_node_t *node);

int count(binary_tree_node_t *node);

bool is_binary_search_tree(binary_tree_node_t *root);

int successor(binary_tree_node_t *root, int value);

#endif  // BINARY_SEARCH_TREE_H
