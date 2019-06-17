#!/usr/bin/env python2


class Mergesort(object):
  def _merge(self, arr, copy, lo, mid, hi):
    # Arr[lo] to arr[mid] and arr[mid + 1] to arr[hi] must be sorted.
    copy[lo:hi + 1] = arr[lo:hi + 1]

    i, j = lo, mid + 1
    for k in xrange(lo, hi + 1):
      if i > mid:
        arr[k] = copy[j]; j += 1
      elif j > hi:
        arr[k] = copy[i]; i += 1
      elif copy[i] < copy[j]:
        arr[k] = copy[i]; i += 1
      elif copy[i] >= copy[j]:
        arr[k] = copy[j]; j += 1

  def _sort(self, arr, copy, lo, hi):
    if hi <= lo:
      return
    mid = lo + (hi - lo) / 2
    self._sort(arr, copy, lo, mid)
    self._sort(arr, copy, mid + 1, hi)
    self._merge(arr, copy, lo, mid, hi)

  def sort(self, arr):
    copy = arr[:]
    self._sort(arr, copy, 0, len(arr) - 1)
