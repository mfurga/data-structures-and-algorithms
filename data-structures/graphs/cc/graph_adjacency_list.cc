#include <iostream>
#include <queue>
#include <stack>

#include "graph_adjacency_list.h"

namespace graph
{

template <class T>
Graph<T>::Graph(const T vertices[], unsigned int size) 
: vertices_(size), edges_(0)
{
  for (unsigned int i = 0; i < vertices_; i++)
    lists_[vertices[i]] = std::list<T>();
}

template <class T>
void Graph<T>::add_edge(const T& src, const T& dest)
{
  if (!lists_.contains(src) || !lists_.contains(dest))
    return;
  lists_[src].push_back(dest);
  edges_++;
}

template <class T>
void Graph<T>::remove_edge(const T& src, const T& dest)
{
  if (!lists_.contains(src) || !lists_.contains(dest))
    return;
  lists_[src].erase(dest);
  edges_--;
}

template <class T>
void Graph<T>::breadth_first_search(const T& vertex)
{
  if (!lists_.contains(vertex))
    return;
  std::unordered_map<T, bool> visited;
  std::queue<T> q;

  visited[vertex] = true;
  q.push(vertex);

  while (!q.empty()) {
    T v = q.front(); q.pop();
    /* Do whatever with the vertex. We'll just print its value. */
    std::cout << v << " ";
    for (auto u : lists_[v]) {
      if (visited.contains(u))
        continue;
      visited[u] = true;
      q.push(u);
    }
  }
}

template <class T>
void Graph<T>::depth_first_search(const T& vertex,
                                  std::unordered_map<T, bool>& visited)
{
  visited[vertex] = true;
  /* Do whatever with the vertex. We'll just print its value. */
  std::cout << vertex << " ";
  for (auto u : lists_[vertex]) {
    if (visited.contains(u))
      continue;
    depth_first_search(u, visited);
  }
}

template <class T>
void Graph<T>::depth_first_search(const T& vertex)
{
  if (!lists_.contains(vertex))
    return;
  std::unordered_map<T, bool> visited;
  depth_first_search(vertex, visited);
}

template <class T>
void Graph<T>::depth_first_search_iter(const T& vertex)
{
  if (!lists_.contains(vertex))
    return;
  std::unordered_map<T, bool> visited;
  std::stack<T> s;

  visited[vertex] = true;
  s.push(vertex);

  while (!s.empty()) {
    T v = s.top(); s.pop();
    /* Do whatever with the vertex. We'll just print its value. */
    std::cout << v << " ";
    for (auto u : lists_[v]) {
      if (visited.contains(u))
        continue;
      visited[u] = true;
      s.push(u);
    }
  }
}

template <class T>
void Graph<T>::find_shortest_path(const T& src, const T& dest)
{
  if (!lists_.contains(src) || !lists_.contains(dest))
    return;
  std::unordered_map<T, T> visited;
  std::queue<T> q;

  visited[src] = src;
  q.push(src);

  while (!q.empty()) {
    T v = q.front(); q.pop();
    for (auto u : lists_[v]) {
      if (visited.contains(u))
        continue;
      visited[u] = v;
      q.push(u);
      /* Print the shortest path and we're done. */ 
      if (u == dest) {
        v = u;
        while (v != src) {
          std::cout << v << " ";
          v = visited[v];
        }
        std::cout << v << " ";
        return;
      }
    }
  }
  /* The shortest path doesn't exist. */
}

}  // namespace graph
