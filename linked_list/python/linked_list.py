#!/usr/bin/evn python2


class LinkedListNode(object):
  def __init__(self, value):
    self._value = value
    self._prev = None
    self._next = None

  @property
  def value(self):
    return self._value

  @value.setter
  def value(self, value):
    self._value = value

  @property
  def next(self):
    return self._next

  @next.setter
  def next(self, next):
    self._next = next

  @property
  def prev(self):
    return self._prev

  @prev.setter
  def prev(self, prev):
    self._prev = prev


class LinkedList(object):
  def __init__(self):
    self._head = None  # Instance of LinkedListNode
    self._tail = None  # Instance of LinkedListNode

  def __len__(self):
    size = 0
    node = self._head
    while node is not None:
      size += 1
      node = node.next
    return size

  def is_empty(self):
    return self._head is None

  def push_front(self, value):
    node = LinkedListNode(value)
    node.prev = None
    node.next = self._head

    if self._head is None:
      self._tail = None
    else:
      self._head.prev = node

    self._head = node

  def pop_front(self):
    if self._head is None:
      return

    node = self._head
    value = node.value

    self._head = self._head.next
    if self._head is None:
      self._tail = None
    else:
      self._head.prev = None

    del node
    return value

  def push_back(self, value):
    node = LinkedListNode(value)
    node.prev = self._tail
    node.next = None

    if self._head is None:
      self._head = node
    else:
      self._tail.next = node

    self._tail = node

  def pop_back(self):
    if self._head is None:
      return

    node = self._tail
    value = node.value

    self._tail = self._tail.prev
    if self._tail is None:
      self._head = None
    else:
      self._tail.next = None

    del node
    return value

  def front(self):
    if self._head is None:
      return
    return self._head.value

  def back(self):
    if self._head is None:
      return
    return self._tail.value

  def insert(self, index, value):
    if index < 0 or index >= len(self):
      return

    node = LinkedListNode(value)
    it = self._head
    i = 0
    while i != index:
      it = it.next
      i += 1

    node.next = it
    node.prev = it.prev

    if it.prev is None:
      self._head = node
    else:
      it.prev.next = node

    it.prev = node

  def erase(self, index):
    if index < 0 or index >= len(self):
      return

    it = self._head
    i = 0
    while i != index:
      it = it.next
      i += 1

    if it.prev is None:
      self._head = it.next
    else:
      it.prev.next = it.next

    if it.next is None:
      self._tail = it.prev
    else:
      it.next.prev = it.prev

    del it

  def reverse(self):
    if self._head is None or self._head.next is None:
      return

    self._tail = self._head
    tmp = None
    i = self._head

    while i is not None:
      tmp = i.prev
      i.prev, i.next = i.next, i.prev
      i = i.prev

    self._head = tmp.prev
