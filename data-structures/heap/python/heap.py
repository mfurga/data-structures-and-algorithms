#!/usr/bin/env python3

class Heap(object):
  def __init__(self):
    self.t = []

  @property
  def n(self):
    return len(self.t)

  @classmethod
  def build(cls, t):
    self = cls()
    self.t = t
    for i in range(Heap.parent(self.n - 1), -1, -1):
      self._heapify(i)
    return self

  @staticmethod
  def left(i):
    return 2 * i + 1

  @staticmethod
  def right(i):
    return 2 * i + 2

  @staticmethod
  def parent(i):
    return (i - 1) // 2

  def _heapify(self, i):
    l = Heap.left(i)
    r = Heap.right(i)
    m = i

    if l < self.n and self.t[l] > self.t[m]:
      m = l
    if r < self.n and self.t[r] > self.t[m]:
      m = r

    if m != i:
      self.t[m], self.t[i] = self.t[i], self.t[m]
      self._heapify(m)

  def get_max(self):
    return self.t[0]

  def extract_max(self):
    if self.n <= 0:
      return None
    self.t[0], self.t[self.n - 1] = self.t[self.n - 1], self.t[0]
    max = self.t.pop()
    self._heapify(0)
    return max

  def increase_key(self, i, key):
    if key < self.t[i]:
      return
    self.t[i] = key
    while i > 0 and self.t[Heap.parent(i)] < self.t[i]:
      self.t[Heap.parent(i)], self.t[i] = self.t[i], self.t[Heap.parent(i)]
      i = Heap.parent(i)

  def insert(self, elem):
    self.t.append(float("-inf"))
    self.increase_key(self.n - 1, elem)

