#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binary_tree_node
{
  int value;
  struct binary_tree_node *parent;
  struct binary_tree_node *left;
  struct binary_tree_node *right;
} binary_tree_node_t;

binary_tree_node_t *create_binary_tree(int value);

binary_tree_node_t *add_left_child(binary_tree_node_t *node, int value);

binary_tree_node_t *add_right_child(binary_tree_node_t *node, int value);

/* Depth-first search */
void pre_order(binary_tree_node_t *node);

/* Depth-first search */
void post_order(binary_tree_node_t *node);

/* Depth-first search */
void in_order(binary_tree_node_t *node);

/* Breadth-first search */
// void level_order(binary_tree_node_t *node);

#endif  // BINARY_TREE_H
