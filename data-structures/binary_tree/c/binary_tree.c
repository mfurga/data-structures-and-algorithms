#include <stdio.h>
#include "binary_tree.h"

binary_tree_node_t *create_binary_tree(int value)
{
  binary_tree_node_t *root = (binary_tree_node_t *)malloc(sizeof(binary_tree_node_t));
  if (root == NULL) {
    exit(EXIT_FAILURE);
  }
  root->value = value;
  root->parent = NULL;
  root->left = NULL;
  root->right = NULL;
  return root;
}

binary_tree_node_t *add_left_child(binary_tree_node_t *node, int value)
{
  node->left = (binary_tree_node_t *)malloc(sizeof(binary_tree_node_t));
  if (node->left == NULL) {
    return NULL;
  }
  node->left->value = value;
  node->left->parent = node;
  node->left->left = NULL;
  node->left->right = NULL;
  return node->left;
}

binary_tree_node_t *add_right_child(binary_tree_node_t *node, int value)
{
  node->right = (binary_tree_node_t *)malloc(sizeof(binary_tree_node_t));
  if (node->right == NULL) {
    return NULL;
  }
  node->right->value = value;
  node->right->parent = node;
  node->right->left = NULL;
  node->right->right = NULL;
  return node->right;
}

void pre_order(binary_tree_node_t *node)
{
  if (node == NULL)
    return;

  printf("%i ", node->value);
  pre_order(node->left);
  pre_order(node->right);
}

void post_order(binary_tree_node_t *node)
{
  if (node == NULL)
    return;

  post_order(node->left);
  post_order(node->right);
  printf("%i ", node->value);
}

void in_order(binary_tree_node_t *node)
{
  if (node == NULL)
    return;

  in_order(node->left);
  printf("%i ", node->value);
  in_order(node->right);
}

void level_order(binary_tree_node_t *node)
{
  queue_t *queue = create_queue();
  enqueue(queue, node);

  while (queue->head != NULL) {
    binary_tree_node_t *current = dequeue(queue);

    if (current->left != NULL)
      enqueue(queue, current->left);

    if (current->right != NULL)
      enqueue(queue, current->right);

    printf("%i ", current->value);
  }
  remove_queue(queue);
}


int main(void)
{
  binary_tree_node_t *root = create_binary_tree(1);
  binary_tree_node_t *left = NULL;
  binary_tree_node_t *right = NULL;
  binary_tree_node_t *left2 = NULL;

  left = add_left_child(root, 2);
  right = add_right_child(root, 3);

  left2 = add_left_child(left, 4);
  add_right_child(left, 5);

  add_left_child(right, 6);
  add_right_child(right, 7);

  add_left_child(left2, 8);
  add_right_child(left2, 9);

  level_order(root);

  return 0;
}