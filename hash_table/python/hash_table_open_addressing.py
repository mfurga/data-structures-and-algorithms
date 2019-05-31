#!/usr/bin/env python2
# Hash table using the open addressing approach (linear probing).

from __future__ import division


class HashTableEntry(object):
  def __init__(self, key=None, value=None):
    self.key = key
    self.value = value


class HashTable(object):
  def __init__(self, size=8):
    self.array = [HashTableEntry() for _ in xrange(size)]
    self.m = size
    self.n = 0

  def __setitem__(self, key, value):
    return self.insert(key, value)

  def __getitem__(self, key):
    return self.get(key)

  def __delitem__(self, key):
    return self.delete(key)

  def __str__(self):
    return '\n'.join(['%s: %s' % (entry.key, entry.value) for entry in self.array])

  def _hash(self, key):
    return hash(key) % self.m

  def _resize(self):
    self.m *= 2  # table doubling
    array = [HashTableEntry() for _ in xrange(self.m)]

    for entry in self.array:
      if entry.key is not None and entry.key != '<dummy>':
        h = self._hash(entry.key)
        while array[h].key is not None:
          h = (h + 1) % self.m

        array[h] = entry

    self.array = array

  def insert(self, key, value):
    if self.n / self.m > 0.6:  # load factor
      self._resize()

    h = self._hash(key)

    while self.array[h].key is not None and self.array[h].key != '<dummy>':
      if self.array[h].key == key:
        self.array[h].value = value
        return
      h = (h + 1) % self.m

    self.array[h] = HashTableEntry(key, value)
    self.n += 1

  def get(self, key):
    h = self._hash(key)

    if self.array[h].key is None:
      raise KeyError

    while self.array[h].key is not None:
      if self.array[h].key == key:
        return self.array[h].value
      h = (h + 1) % self.m
    else:
      raise KeyError

  def delete(self, key):
    h = self._hash(key)

    if self.array[h].key is None:
      raise KeyError

    while self.array[h].key is not None:
      if self.array[h].key == key:
        self.array[h].key = '<dummy>'
        return
      h = (h + 1) % self.m
    else:
     raise KeyError


if __name__ == '__main__':
  hash_table = HashTable(16)
  hash_table[0] = 'a'
  hash_table[0 + 16] = 'b'
  # hash_table[0 + 32] = 'c'

  print hash_table
  print hash_table[0 + 32]
