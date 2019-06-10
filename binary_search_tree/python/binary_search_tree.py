#!/usr/bin/env python2


class BinarySearchTreeNode(object):
  def __init__(self, value, parent):
    self.value = value
    self.parent = parent
    self.left = None
    self.right = None

  def add_left_child(self, value):
    self.left = BinarySearchTreeNode(value, self)

  def add_right_child(self, value):
    self.right = BinarySearchTreeNode(value, self)


class BinarySearchTree(object):
  def __init__(self, value):
    self._root = BinarySearchTreeNode(value, None)

  def __len__(self):
    return self._count(self._root)

  def _count(self, node):
    if node is None:
      return 0
    return 1 + self._count(node.left) + self._count(node.right)

  def insert(self, value):
    curr = self._root
    while (curr.value > value and curr.left is not None) or \
          (curr.value < value and curr.right is not None):
      if curr.value > value:
        curr = curr.left
      else:
        curr = curr.right

    if curr.value > value:
      curr.add_left_child(value)
    elif curr.value < value:
      curr.add_right_child(value)

  def _find(self, node, value):
    while node is not None:
      if node.value == value:
        return node
      elif node.value > value:
        node = node.left
      else:
        node = node.right
    return None

  def find(self, value):
    return self._find(self._root, value)

  def _delete(self, node, value):
    curr = self._find(node, value)
    if curr is None:
      return

    # The node doesn't have any children.
    if curr.left is None and curr.right is None:
      if curr.parent.left == curr:
        curr.parent.left = None
      else:
        curr.parent.right = None
      return

    # The node has only a left children.
    if curr.right is None:
      curr.left.parent = curr.parent
      if curr.parent.left == curr:
        curr.parent.left = curr.left
      else:
        curr.parent.right = curr.left
      return

    # The node has only a right children.
    if curr.left is None:
      curr.right.parent = curr.parent
      if curr.parent.left == curr:
        curr.parent.left = curr.right
      else:
        curr.parent.right = curr.right
      return

    # The node has two children.
    # Now we're looking for the smallest value in the right sub-tree.
    smallest = curr.right
    while smallest.left is not None:
      smallest = smallest.left

    curr.value = smallest.value
    return self._delete(smallest, smallest.value)

  def delete(self, value):
    return self._delete(self._root, value)

  def _height(self, node):
    if node is None:
      return -1
    return 1 + max(self._height(node.left), self._height(node.right))

  @property
  def height(self):
    return self._height(self._root)

  @property
  def maximum(self):
    if self._root is None:
      return
    curr = self._root
    while curr.right is not None:
      curr = curr.right
    return curr.value

  @property
  def minimum(self):
    if self._root is None:
      return
    curr = self._root
    while curr.left is not None:
      curr = curr.left
    return curr.value

  def _is_binary_search_tree(self, node, min, max):
    if node is None:
      return True
    return node.value > min and node.value < max and                    \
           self._is_binary_search_tree(node.left, min, node.value) and  \
           self._is_binary_search_tree(node.right, node.value, max)

  @property
  def is_binary_search_tree(self):
    # We can also use the in-order traversal and check each time
    # that incoming data is sorted or not.
    return self._is_binary_search_tree(self._root, float('-inf'), float('inf'))

  def successor(self, value):
    node = self._find(self._root, value)
    if node is None:
      return

    # The node has a right sub-tree.
    if node.right is not None:
      curr = node.right
      while curr.left is not None:
        curr = curr.left
      return curr

    # The node doesn't have a right sub-tree.
    successor = None
    curr = self._root
    while curr is not node:
      if curr.value > node.value:
        successor = curr
        curr = curr.left
      else:
        curr = curr.right
    return successor
