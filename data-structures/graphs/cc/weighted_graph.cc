#include <iostream>
#include "weighted_graph.h"

namespace mf
{

template <class T>
WeightedGraph<T>::WeightedGraph(const T vertices[], unsigned int size)
: vertices_(size), edges_(0)
{
  for (unsigned int i = 0; i < vertices_; i++)
    lists_[vertices[i]] = std::list<std::pair<T, unsigned int>>();
}

template <class T>
void WeightedGraph<T>::add_edge(const T& src, const T& dest,
                                const unsigned int weight)
{
  lists_[src].push_back(std::make_pair(dest, weight));
  edges_++;
}

template <class T>
void WeightedGraph<T>::remove_edge(const T& src, const T& dest)
{
  lists_[src].earse(dest);
  edges_--;
}

template <class T>
T WeightedGraph<T>::extract_min(const std::set<T>& Q,
                                const std::unordered_map<T, unsigned int>& d) const
{
  T min_v; unsigned int min = std::numeric_limits<unsigned int>::max();
  for (auto v : Q) {
    if (d.at(v) < min) {
      min = d.at(v); min_v = v;
    }
  }
  return min_v;
}

template <class T>
void WeightedGraph<T>::print_shortest_path(const std::unordered_map<T, T>& p, 
                                           const T& src, const T& dest) const
{
  T i = dest;
  while (i != src) {
    std::cout << i << " ";
    i = p.at(i);
  }
  std::cout << i << std::endl;
}

template <class T>
void WeightedGraph<T>::find_shortest_path(const T& src, const T& dest) const
{
  std::set<T> Q, S;
  std::unordered_map<T, unsigned int> d;
  std::unordered_map<T, T> p;
 
  for (auto const& [key, _] : lists_) {
    d[key] = std::numeric_limits<unsigned int>::max();
    Q.insert(key);
  }
  d[src] = 0;

  while (!Q.empty()) {
    /* TODO: We should use the fibonacci min-heap here for better performances. */
    T v = extract_min(Q, d);
    S.insert(v); Q.erase(v);
    for (auto u : lists_.at(v)) {
      /* Relaxation condition. */
      if (d[u.first] > d[v] + u.second) {
        d[u.first] = d[v] + u.second;
        p[u.first] = v;
      }
    }
  }
  print_shortest_path(p, src, dest);
}

}  // namespace mf
