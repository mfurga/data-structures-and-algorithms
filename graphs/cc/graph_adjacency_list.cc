#include <iostream>
#include <queue>

#include "graph_adjacency_list.h"

namespace graph
{

template <class T>
Graph<T>::Graph(const T vertices[], unsigned int size) 
: vertices_(size), edges_(0)
{
  for (unsigned int i = 0; i < vertices_; i++)
    lists_[vertices[i]] = new LinkedList<T>();
}

template <class T>
Graph<T>::~Graph()
{
  for (auto elem : lists_)
    delete elem.second;
}

template <class T>
void Graph<T>::add_edge(const T& src, const T& dest)
{
  if (!lists_.contains(src) || !lists_.contains(dest))
    return;
  lists_[src]->push_back(dest);
  edges_++;
}

template <class T>
void Graph<T>::remove_edge(const T& src, const T& dest)
{
  if (!lists_.contains(src) || !lists_.contains(dest))
    return;
  lists_[src]->earse(dest);
  edges_--;
}

template <class T>
void Graph<T>::depth_first_search(const T& vertex,
                                  std::unordered_map<T, bool>& visited)
{
  visited[vertex] = true;
  /* Do whatever with the vertex. We'll just print its value. */
  std::cout << vertex << " ";
  LinkedListNode<T> *current = lists_[vertex]->head();
  while (current != nullptr) {
    if (!visited.contains(current->value))
      depth_first_search(current->value, visited);
    current = current->next;
  }
}

template <class T>
void Graph<T>::depth_first_search(const T &vertex)
{
  std::unordered_map<T, bool> visited;
  depth_first_search(vertex, visited);
}

template <class T>
void Graph<T>::breadth_first_search(const T& vertex)
{
  std::queue<T> q;
  std::unordered_map<T, bool> visited;

  visited[vertex] = true;
  q.push(vertex);

  while (!q.empty()) {
    T v = q.front();
    q.pop();
    /* Do whatever with the vertex. We'll just print its value. */
    std::cout << v << " ";
    LinkedListNode<T> *current = lists_[v]->head();
    while (current != nullptr) {
      if (!visited.contains(current->value)) {
        visited[current->value] = true;
        q.push(current->value);
      }
      current = current->next;
    }
  }
}

}  // namespace graph
