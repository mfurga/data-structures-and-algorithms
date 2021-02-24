#!/usr/bin/env python2

from collections import deque


class BinaryTreeNode(object):
  def __init__(self, value=None, parent=None):
    self._parent = parent
    self._value = value
    self._left = None
    self._right = None

  def add_left_child(self, value):
    self._left = BinaryTreeNode(value, self)
    return self._left

  def add_right_child(self, value):
    self._right = BinaryTreeNode(value, self)
    return self._right

  @property
  def left(self):
    return self._left

  @property
  def right(self):
    return self._right

  @property
  def value(self):
    return self._value


class BinaryTree(object):
  def __init__(self, value):
    self._root = BinaryTreeNode(value, None)

  @property
  def root(self):
    return self._root

  def _pre_order(self, node):
    """Depth-first search"""
    if node is None:
      return

    print node.value,
    self._pre_order(node.left)
    self._pre_order(node.right)

  def pre_order(self):
    """Depth-first search"""
    self._pre_order(self._root)

  def _post_order(self, node):
    """Depth-first search"""
    if node is None:
      return

    self._post_order(node.left)
    self._post_order(node.right)
    print node.value,

  def post_order(self):
    """Depth-first search"""
    self._post_order(self._root)

  def _in_order(self, node):
    """Depth-first search"""
    if node is None:
      return

    self._in_order(node.left)
    print node.value,
    self._in_order(node.right)

  def in_order(self):
    """Depth-first search"""
    self._in_order(self._root)

  def level_order(self):
    """Breadth-first search"""
    queue = deque()
    queue.append(self._root)

    while len(queue) > 0:
      node = queue.popleft()

      if node.left is not None:
        queue.append(node.left)

      if node.right is not None:
        queue.append(node.right)

      print node.value,
