#include <limits>
#include <algorithm>
#include "binary_search_tree.h"

namespace mf
{

template <class T>
BinarySearchTreeNode<T> *BinarySearchTreeNode<T>::add_left_child(const T& value)
{
  left_ = new BinarySearchTreeNode<T>(value, this);
  return left_;
}

template <class T>
BinarySearchTreeNode<T> *BinarySearchTreeNode<T>::add_right_child(const T& value)
{
  right_ = new BinarySearchTreeNode<T>(value, this);
  return right_;
}

template <class T>
void BinarySearchTree<T>::insert(const T& value)
{
  BinarySearchTreeNode<T> *curr = root_;

  while (curr->value_ > value && curr->left_ != nullptr ||
         curr->value_ < value && curr->right_ != nullptr) {
    if (curr->value_ > value)
      curr = curr->left_;
    else
      curr = curr->right_;
  }

  if (curr->value_ > value)
    curr->add_left_child(value);
  else if (curr->value_ < value)
    curr->add_right_child(value);
  else return;  /* If they're the same, do nothing */
}

template <class T>
BinarySearchTreeNode<T> *BinarySearchTree<T>::find(BinarySearchTreeNode<T> *node,
                                                   const T& value) const
{
  while (node != nullptr) {
    if (node->value_ == value)
      return node;
    else if (node->value_ > value)
      node = node->left_;
    else
      node = node->right_;
  }
  return nullptr;
}

template <class T>
void BinarySearchTree<T>::remove(BinarySearchTreeNode<T> *node, const T& value)
{
  BinarySearchTreeNode<T> *curr = this->find(node, value);
  if (curr == nullptr)
    return;

  /* The node doesn't have any children. */
  if (curr->left_ == nullptr && curr->right_ == nullptr) {
    if (curr->parent_->left_ == curr)
      curr->parent_->left_ = nullptr;
    else
      curr->parent_->right_ = nullptr;

    delete curr;
    return;
  }

  /* The node has only a left children. */
  if (curr->right_ == nullptr) {
    curr->left_->parent_ = curr->parent_;

    if (curr->parent_->left_ == curr)
      curr->parent_->left_ = curr->left_;
    else
      curr->parent_->right_ = curr->left_;

    delete curr;
    return;
  }

  /* The node has only a right children. */
  if (curr->left_ == nullptr) {
    curr->right_->parent_ = curr->parent_;

    if (curr->parent_->left_ == curr)
      curr->parent_->left_ = curr->right_;
    else
      curr->parent_->right_ = curr->right_;

    delete curr;
    return;
  }

  /* The node has two children. */
  /* Now we're looking for the smallest value in the right subtree. */
  BinarySearchTreeNode<T> *smallest = curr->right_;

  while (smallest->left_ != nullptr) {
    smallest = smallest->left_;
  }

  curr->value_ = smallest->value_;
  return remove(smallest, smallest->value_);
}

template <class T>
int BinarySearchTree<T>::height(BinarySearchTreeNode<T> *node)
{
  if (node == nullptr)
    return -1;
  return 1 + std::max(height(node->left_), height(node->right_));
}

template <class T>
int BinarySearchTree<T>::min_height(BinarySearchTreeNode<T> *node)
{
  if (node == nullptr)
    return -1;
  return 1 + std::min(min_height(node->left_), min_height(node->right_));
}

template <class T>
int BinarySearchTree<T>::nodes_with_one_child(BinarySearchTreeNode<T> *node)
{
  if (node == nullptr)
    return 0;
  if (node->left_ == nullptr ^ node->right_ == nullptr)
    return 1;
  return nodes_with_one_child(node->left_) + nodes_with_one_child(node->right_);
}

template <class T>
int BinarySearchTree<T>::count(BinarySearchTreeNode<T> *node)
{
  if (node == nullptr)
    return 0;
  return 1 + count(node->left_) + count(node->right_);
}

template <class T>
BinarySearchTreeNode<T> *BinarySearchTree<T>::maximum() const
{
  BinarySearchTreeNode<T> *curr = root_;
  while (curr->right_ != nullptr)
    curr = curr->right_;
  return curr;
}

template <class T>
BinarySearchTreeNode<T> *BinarySearchTree<T>::minimum() const
{
  BinarySearchTreeNode<T> *curr = root_;
  while (curr->left_ != nullptr)
    curr = curr->left_;
  return curr;
}

template <class T>
int BinarySearchTree<T>::leaf(BinarySearchTreeNode<T> *node)
{
  if (node == nullptr)
    return 0;
  if (node->left_ == nullptr && node->right_ == nullptr)
    return 1;
  return leaf(node->left_) + leaf(node->right_);
}

template <class T>
bool BinarySearchTree<T>::is_between(BinarySearchTreeNode<T> *node,
                                     int min, int max)
{
  if (node == nullptr)
    return true;
  return (node->value_ > min && node->value_ < max &&
          is_between(node->left_, min, node->value_) &&
          is_between(node->right_, node->value_, max));
}

/* 
  We can also use the in-order traversal and check each time
  that incoming data is sorted or not.
 */
template <class T>
bool BinarySearchTree<T>::is_binary_search_tree()
{
  return is_between(root_, std::numeric_limits<int>::min(),
                           std::numeric_limits<int>::max());
}

template <class T>
BinarySearchTreeNode<T> *BinarySearchTree<T>::successor(const T& value) const
{
  BinarySearchTreeNode<T> *node = find(value);
  if (node == nullptr)
    return nullptr;

  /* The node has a right subtree. */
  if (node->right_ != nullptr) {
    BinarySearchTreeNode<T> *curr = node->right_;
    while (curr->left_ != nullptr)
      curr = curr->left_;
    return curr;
  }

  /* The node doesn't have a right subtree. */
  BinarySearchTreeNode<T> *parent = node->parent_;
  while (parent != nullptr && node == parent->right_) {
    node = parent;
    parent = parent->parent_;
  }
  return parent;
}

template <class T>
BinarySearchTreeNode<T> *BinarySearchTree<T>::predecessor(const T& value) const
{
  BinarySearchTreeNode<T> *node = find(value);
  if (node == nullptr)
    return nullptr;

  /* The node has a left subtree. */
  if (node->left_ != nullptr) {
    BinarySearchTreeNode<T> *curr = node->left_;
    while (curr->right_ != nullptr)
      curr = curr->right_;
    return curr;
  }

  /* The node doesn't have a left subtree. */
  BinarySearchTreeNode<T> *parent = node->parent_;
  while (parent != nullptr && node == parent->left_) {
    node = parent;
    parent = parent->parent_;
  }
  return parent;
}

}  // namespace mf
