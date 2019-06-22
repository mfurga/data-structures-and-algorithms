#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph_adjacency_lists.h"

graph_t *create_graph(int vertices)
{
  graph_t *graph = (graph_t *)malloc(sizeof(graph_t));
  if (graph == NULL)
    exit(EXIT_FAILURE);
  graph->edges = 0;
  graph->vertices = vertices;
  graph->lists = (linked_list_t **)malloc(sizeof(linked_list_t *) * graph->vertices);
  if (graph->lists == NULL)
    exit(EXIT_FAILURE);
  for (int i = 0; i < graph->vertices; i++)
    graph->lists[i] = create_linked_list();
  return graph;
}

void remove_graph(graph_t *g)
{
  assert(g != NULL && g->lists != NULL);
  for (int i = 0; i < g->vertices; i++)
    remove_linked_list(g->lists[i]);
  free(g);
}

void add_edge(graph_t *g, int src, int dest)
{
  if (src < 0 || dest < 0 || src >= g->vertices || dest >= g->vertices)
    return;
  push_back(g->lists[src], dest);
  g->edges++;
}

void remove_edge(graph_t *g, int src, int dest)
{
  if (src < 0 || dest < 0 || src >= g->vertices || dest >= g->vertices)
    return;
  erase(g->lists[src], dest);
  g->edges--;
}
