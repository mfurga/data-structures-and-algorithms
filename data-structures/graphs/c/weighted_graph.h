#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include "linked_list_weighted.h"

typedef struct
{
  unsigned int vertices;  /* number of vertices */
  unsigned int edges;     /* number of edges */
  linked_list_t **lists;
} graph_t;

graph_t *create_graph(int vertices);

void remove_graph(graph_t *g);

void add_edge(graph_t *g, unsigned int src, unsigned int dest,
              unsigned int weight);

void remove_edge(graph_t *g, unsigned int src, unsigned int dest);

static inline bool empty_set(bool set[], unsigned int size);

static inline unsigned int extract_min(bool set[], unsigned int d[],
                                       unsigned int size);

static void print_shortest_path(int p[], unsigned int src, unsigned int dest);

void find_shortest_path(graph_t *g, unsigned int src, unsigned int dest);

#endif  // WEIGHTED_GRAPH_H
