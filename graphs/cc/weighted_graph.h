#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <unordered_map>
#include <utility>
#include <list>
#include <set>

namespace mf
{

template <class T>
class WeightedGraph
{
 public:
  WeightedGraph(const T vertices[], unsigned int size);
  ~WeightedGraph() {}

  void add_edge(const T& src, const T& dest, const unsigned int weight);
  void remove_edge(const T& src, const T& dest);
  void find_shortest_path(const T& src, const T& dest) const;

 private:
  unsigned int vertices_;  // number of vertices
  unsigned int edges_;     // number of edges
  std::unordered_map<T, std::list<std::pair<T, unsigned int>>> lists_;

  T extract_min(const std::set<T>& Q,
                const std::unordered_map<T, unsigned int>& d) const;
  void print_shortest_path(const std::unordered_map<T, T>& p, const T& src,
                           const T& dest) const;
};

}  // namespace mf

#endif  // WEIGHTED_GRAPH_H
