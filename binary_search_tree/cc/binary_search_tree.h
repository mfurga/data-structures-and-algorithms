#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

namespace mf
{
/* Used for the friend relationship between BinarySearchTree and BinarySearchTreeNode */
template <class T> class BinarySearchTree;

template <class T>
class BinarySearchTreeNode
{
 private:
  T value_;
  BinarySearchTreeNode<T> *parent_;
  BinarySearchTreeNode<T> *left_;
  BinarySearchTreeNode<T> *right_;

  friend class BinarySearchTree<T>;

  public:
  BinarySearchTreeNode(const T& value, BinarySearchTreeNode<T> *parent) : value_(value), 
                       parent_(parent), left_(nullptr), right_(nullptr) {}
  ~BinarySearchTreeNode() {}

  BinarySearchTreeNode<T> *add_left_child(const T& value);
  BinarySearchTreeNode<T> *add_right_child(const T& value);
};

template <class T>
class BinarySearchTree
{
 private:
  BinarySearchTreeNode<T> *root_;
  int height(BinarySearchTreeNode<T> *node);
  int min_height(BinarySearchTreeNode<T> *node);
  int nodes_with_one_child(BinarySearchTreeNode<T> *node);
  int count(BinarySearchTreeNode<T> *node);
  int leaf(BinarySearchTreeNode<T> *node);
  void remove(BinarySearchTreeNode<T> *node, const T& value);
  bool is_between(BinarySearchTreeNode<T> *node, int min, int max);
  BinarySearchTreeNode<T> *find(BinarySearchTreeNode<T> *node, const T& value) const;

 public:
  BinarySearchTree(const T& value) { root_ = new BinarySearchTreeNode<T>(value, nullptr); }
  ~BinarySearchTree() {}

  void insert(const T& value);
  void remove(const T& value) { return remove(root_, value); }
  BinarySearchTreeNode<T> *find(const T& value) const { return find(root_, value); };

  int height() { return height(root_); }
  int min_height() { return min_height(root_); }
  int nodes_with_one_child() { return nodes_with_one_child(root_); }
  int count() { return count(root_); }
  int leaf() { return leaf(root_); }

  BinarySearchTreeNode<T> *maximum() const;
  BinarySearchTreeNode<T> *minimum() const;

  bool is_binary_search_tree();
  BinarySearchTreeNode<T> *successor(const T& value) const;
};

}  // namespace mf

#endif  // BINARY_SEARCH_TREE_H
