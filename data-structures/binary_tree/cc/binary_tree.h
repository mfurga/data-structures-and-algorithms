#ifndef BINARY_TREE_H
#define BINARY_TREE_H

namespace mf
{
/* Used for the friend relationship between BinaryTree and BinaryTreeNode */
template <class T> class BinaryTree;

template <class T>
class BinaryTreeNode
{
 private:
  T value_;
  BinaryTreeNode<T> *parent_;
  BinaryTreeNode<T> *left_;
  BinaryTreeNode<T> *right_;

  friend class BinaryTree<T>;

 public:
  BinaryTreeNode(const T& value, BinaryTreeNode<T> *parent) : value_(value), 
                 parent_(parent), left_(nullptr), right_(nullptr) {}
  ~BinaryTreeNode() {}

  BinaryTreeNode<T> *add_left_child(const T &value);
  BinaryTreeNode<T> *add_right_child(const T &value);
};

template <class T>
class BinaryTree
{
 private:
  BinaryTreeNode<T> *root_;

  /* Depth-first search */
  void pre_order(BinaryTreeNode<T> *node);
  void post_order(BinaryTreeNode<T> *node);
  void in_order(BinaryTreeNode<T> *node);

 public:
  BinaryTree(const T &value) { root_ = new BinaryTreeNode<T>(value, nullptr); }
  BinaryTreeNode<T> *get_root() const { return root_; }

  /* Depth-first search */
  void pre_order() { pre_order(root_); }
  void post_order() { post_order(root_); }
  void in_order() { in_order(root_); }

  /* Breadth-first search */
  void level_order();
};

}  // namespace mf

#endif  // BINARY_TREE_H
