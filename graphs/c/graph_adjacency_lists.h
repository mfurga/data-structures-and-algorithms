#ifndef GRAPH_ADJACENCY_LISTS_H
#define GRAPH_ADJACENCY_LISTS_H

#include "linked_list.h"

typedef struct
{
  int vertices;  /* number of vertices */
  int edges;     /* number of edges */
  linked_list_t **lists;
} graph_t;

graph_t *create_graph(int vertices);

void remove_graph(graph_t *g);

void add_edge(graph_t *g, int src, int dest);

void remove_edge(graph_t *g, int src, int dest);

#endif  // GRAPH_ADJACENCY_LISTS_H
