#!/usr/bin/env python2


class MaxHeap(object):
  """Binary max heap implemented using array."""
  def __init__(self, array=None, size=None):
    self._size = 0 if size is None else size
    self._array = [] if array is None else array

  @classmethod
  def heapify(cls, array):
    for i in xrange(len(array) / 2 - 1, -1, -1):
      MaxHeap._sift_down(array, len(array), i)
    return cls(array, len(array))

  @staticmethod
  def _sift_up(array, index):
    while index > 0 and array[index] > array[(index - 1) / 2]:
      # Now we need to swap the values (change their priority).
      array[index], array[(index - 1) / 2] = array[(index - 1) / 2], array[index]
      index = (index - 1) / 2

  @staticmethod
  def _sift_down(array, size, index):
    max_index = index

    # Check if the left child exists and compare.
    if (index * 2 + 1) < size and array[index * 2 + 1] > array[max_index]:
      max_index = index * 2 + 1

    # Check if the right child exists and compare.
    if (index * 2 + 2) < size and array[index * 2 + 2] > array[max_index]:
      max_index = index * 2 + 2

    if index != max_index:
      array[index], array[max_index] = array[max_index], array[index]
      MaxHeap._sift_down(array, size, max_index)

  @staticmethod
  def heapsort(array):
    for i in xrange(len(array) / 2 - 1, -1, -1):
      MaxHeap._sift_down(array, len(array), i)

    for j in xrange(len(array) - 1, 0, -1):
      array[0], array[j] = array[j], array[0]
      MaxHeap._sift_down(array, j, 0)

  def insert(self, value):
    self._array.append(value)
    self._size += 1
    MaxHeap._sift_up(self._array, self._size - 1)

  def extract_max(self):
    if self._size == 0:
      return
    res = self._array[0]
    self._size -= 1
    self._array[0] = self._array.pop()
    MaxHeap._sift_down(self._array, self._size, 0)
    return res

  def get_max(self):
    if self._size == 0:
      return
    return self._array[0]
