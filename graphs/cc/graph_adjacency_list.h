#ifndef GRAPH_ADJACENCY_LIST_H
#define GRAPH_ADJACENCY_LIST_H

#include <unordered_map>
#include <list>

namespace graph
{

template <class T>
class Graph
{
 private:
  unsigned int vertices_;  // number of vertices
  unsigned int edges_;     // number of edges
  std::unordered_map<T, std::list<T>> lists_;

  void depth_first_search(const T& vertex, std::unordered_map<T, bool>& visited);

 public: 
  Graph(const T vertices[], unsigned int size);
  ~Graph() {};

  void add_edge(const T& src, const T& dest);
  void remove_edge(const T& src, const T& dest);

  void breadth_first_search(const T& vertex);
  void depth_first_search(const T& vertex);
  void depth_first_search_iter(const T& vertex);

  void find_shortest_path(const T& src, const T& dest);
};

}  // namespace graph

#endif  // GRAPH_ADJACENCY_LIST_H
