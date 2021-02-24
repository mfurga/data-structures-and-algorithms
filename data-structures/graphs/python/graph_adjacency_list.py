#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from collections import deque
from typing import List, Dict, TypeVar

# types
VertexType = TypeVar('VertexType',  # Any hashable object
                     str, int, float, complex, str, tuple, frozenset, bytes)
Stack = List


class Graph(object):
  """The graph implementation using the adjacency list approach."""
  def __init__(self, vertices: List[VertexType]) -> None:
    self._vertices: Dict[VertexType, List[VertexType]] = dict((v, []) for v in vertices)
    self._edges: int = 0

  def add_edge(self, src: VertexType, dest: VertexType) -> None:
    if src not in self._vertices or dest not in self._vertices:
      return
    self._vertices[src].append(dest)
    self._edges += 1

  def remove_edge(self, src: VertexType, dest: VertexType) -> None:
    if src not in self._vertices or dest not in self._vertices:
      return
    self._vertices[src].remove(dest)
    self._edges -= 1

  def breadth_first_search(self, vertex: VertexType) -> None:
    if vertex not in self._vertices:
      return
    q: deque = deque()
    visited: Dict[VertexType, bool] = {}

    visited[vertex] = True
    q.append(vertex)

    while len(q) > 0:
      v: VertexType = q.popleft()
      # Do whatever with the vertex. We'll just print its value.
      print(v, end=" ")
      for u in self._vertices[v]:
        if u in visited:
          continue
        visited[u] = True
        q.append(u)

  def _depth_first_search(self, vertex: VertexType,
                          visited: Dict[VertexType, bool]) -> None:
    visited[vertex] = True
    # Do whatever with the vertex. We'll just print its value.
    print(vertex, end=" ")
    for u in self._vertices[vertex]:
      if u not in visited:
        self._depth_first_search(u, visited)

  def depth_first_search(self, vertex: VertexType) -> None:
    if vertex not in self._vertices:
      return
    visited: Dict[VertexType, bool] = {}
    self._depth_first_search(vertex, visited)

  def depth_first_search_iter(self, vertex: VertexType) -> None:
    if vertex not in self._vertices:
      return
    visited: Dict[VertexType, bool] = {}
    s: Stack[VertexType] = []

    visited[vertex] = True
    s.append(vertex)

    while len(s) > 0:
      v: VertexType = s.pop()
      # Do whatever with the vertex. We'll just print its value.
      print(v, end=" ")
      for u in self._vertices[v]:
        if u not in visited:
          visited[u] = True
          s.append(u)

  def _print_shortest_path(self, path: Dict[VertexType, VertexType], src: VertexType,
                           dest: VertexType) -> None:
    v: VertexType = dest
    res: List[VertexType] = []
    while v != src:
      res.append(v)
      v = path[v]
    res.append(v)
    print(' '.join(str(v) for v in res[::-1]))

  def find_shortest_path(self, src: VertexType, dest: VertexType) -> bool:
    if src not in self._vertices or dest not in self._vertices:
      return False
    q: deque = deque()
    visited: Dict[VertexType, VertexType] = {}

    visited[src] = src
    q.append(src)

    while len(q) > 0:
      v: VertexType = q.popleft()
      for u in self._vertices[v]:
        if u in visited:
          continue
        visited[u] = v
        q.append(u)
        if u == dest:
          # Print the shortest path and we're done.
          self._print_shortest_path(visited, src, dest)
          return True
    return False  # The shortest path doesn't exist.
