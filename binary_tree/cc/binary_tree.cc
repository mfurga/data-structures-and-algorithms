#include <iostream>
#include "binary_tree.h"

namespace mf
{

template <class T>
BinaryTreeNode<T> *BinaryTreeNode<T>::add_left_child(const T &value)
{
  left_ = new BinaryTreeNode<T>(value, this);
  return left_;
}

template <class T>
BinaryTreeNode<T> *BinaryTreeNode<T>::add_right_child(const T &value)
{
  right_ = new BinaryTreeNode<T>(value, this);
  return right_;
}

template <class T>
void BinaryTree<T>::pre_order(BinaryTreeNode<T> *node)
{
  if (node == nullptr)
    return;

  std::cout << node->value_ << " ";
  pre_order(node->left_);
  pre_order(node->right_);
}

template <class T>
void BinaryTree<T>::post_order(BinaryTreeNode<T> *node)
{
  if (node == nullptr)
    return;

  post_order(node->left_);
  post_order(node->right_);
  std::cout << node->value_ << " ";
}

template <class T>
void BinaryTree<T>::in_order(BinaryTreeNode<T> *node)
{
  if (node == nullptr)
    return;

  in_order(node->left_);
  std::cout << node->value_ << " ";
  in_order(node->right_);
}

}  // namespace mf
