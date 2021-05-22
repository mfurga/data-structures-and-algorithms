#!/usr/bin/env python3

from queue import PriorityQueue

def dijkstra(G, s):
  n = len(G)

  D = [float("+inf")] * n
  P = [None] * n
  V = [False] * n
  Q = PriorityQueue()

  D[s] = 0
  Q.put((0, s))

  while Q.qsize() > 0:
    _, u = Q.get()
    # Skip vertices that have been put to Q with greater weight and have already been processed.
    if V[u]:
      continue
    V[u] = True

    for v, w in G[u]:
      if D[v] > D[u] + w:
        D[v] = D[u] + w
        P[v] = u
        Q.put((D[v], v))

G = [
  [(1, 7), (5, 1)],
  [(0, 7), (2, 10), (5, 3)],
  [(1, 10), (3, 4)],
  [(2, 4), (4, 3), (5, 7)],
  [(3, 3), (5, 2)],
  [(0, 1), (1, 3), (3, 7), (4, 2)]
]
dijkstra(G, 0)

