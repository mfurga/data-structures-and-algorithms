#!/usr/bin/env python3

def left(i):
  return 2 * i + 1

def right(i):
  return 2 * i + 2

def parent(i):
  return (i - 1) // 2

def heapify(t, n, i):
  l = left(i)
  r = right(i)

  m = i
  if l < n and t[l] > t[m]:
    m = l
  if r < n and t[r] > t[m]:
    m = r

  if i != m:
    t[i], t[m] = t[m], t[i]
    heapify(t, n, m)

def build_heap(t, n):
  for i in range(parent(n - 1), -1, -1):
    heapify(t, n, i)

def heapsort(t):
  n = len(t)
  build_heap(t, n)

  for i in range(n - 1, 0, -1):
    t[0], t[i] = t[i], t[0]
    heapify(t, i, 0)

