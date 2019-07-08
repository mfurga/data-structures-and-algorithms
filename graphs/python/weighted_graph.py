#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from typing import List, Dict, TypeVar, NamedTuple, Set

# types
VertexType = TypeVar('VertexType',  # Any hashable object
                     str, int, float, complex, str, tuple, frozenset, bytes)
Stack = List


class Edge(NamedTuple):
  """The weighted edge structure."""
  dest: VertexType
  weight: int


class WeightedGraph(object):
  """
  The weighted graph implementation using the adjacency list approach.
  """
  def __init__(self, vertices: List[VertexType]) -> None:
    self._vertices: Dict[VertexType, List[Edge]] = dict((v, []) for v in vertices)
    self._edges: int = 0

  def add_edge(self, src: VertexType, dest: VertexType, weight: int) -> None:
    if src not in self._vertices or dest not in self._vertices:
      return
    self._vertices[src].append(Edge(dest, weight))
    self._edges += 1

  def remove_edge(self, src: VertexType, dest: VertexType) -> None:
    if src not in self._vertices or dest not in self._vertices:
      return
    self._vertices[src] = [e for e in self._vertices[src] if e.dest != dest]
    self._edges -= 1

  def _print_shortest_path(self, path: Dict[VertexType, VertexType], src: VertexType,
                           dest: VertexType) -> None:
    v: VertexType = dest
    res: List[VertexType] = []
    while v != src:
      res.append(v)
      v = path[v]
    res.append(v)
    print(' '.join(str(v) for v in res[::-1]))

  def find_shortest_path(self, src: VertexType, dest: VertexType) -> None:
    """The shortest path finding using the Dijkstra's algorithm."""
    if src not in self._vertices or dest not in self._vertices:
      return
    d: Dict[VertexType, int] = dict.fromkeys(self._vertices.keys(), float('inf'))
    p: Dict[VertexType, VertexType] = {src: src}
    S: Set[VertexType] = {src}
    Q: Set[VertexType] = set(self._vertices.keys())
    d[src] = 0

    while len(Q) > 0:
      # TODO: We should use the fibonacci min-heap here for better performances.
      edge = min([Edge(q, d[q]) for q in Q], key=lambda v: v.weight)
      S.add(edge.dest)
      Q.remove(edge.dest)

      for e in self._vertices[edge.dest]:
        # Relaxation condition.
        if d[e.dest] > d[edge.dest] + e.weight:
          d[e.dest] = d[edge.dest] + e.weight
          p[e.dest] = edge.dest

    self._print_shortest_path(p, src, dest)
    print(f'weight of path: {d[dest]}')
