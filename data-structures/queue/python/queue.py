#!/usr/bin/env python2


class QueueNode(object):
  def __init__(self, value):
    self._value = value
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


class Queue(object):
  def __init__(self):
    self._head = None
    self._tail = None

  def enqueue(self, value):
    node = QueueNode(value)
    node.next = None

    if self._head is None:
      self._head = node
    else:
      self._tail.next = node

    self._tail = node

  def dequeue(self):
    if self._head is None:
      return

    node = self._head
    value = node.value

    self._head = self._head.next
    if self._head is None:
      self._tail = None

    del node
    return value

  def empty(self):
    return self._head is None
