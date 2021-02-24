#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "weighted_graph.h"

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
  for (unsigned int i = 0; i < graph->vertices; i++)
    graph->lists[i] = create_linked_list();
  return graph;
}

void remove_graph(graph_t *g)
{
  assert(g != NULL && g->lists != NULL);
  for (unsigned int i = 0; i < g->vertices; i++)
    remove_linked_list(g->lists[i]);
  free(g);
}

void add_edge(graph_t *g, unsigned int src, unsigned int dest,
              unsigned int weight)
{
  if (src >= g->vertices || dest >= g->vertices)
    return;
  push_back(g->lists[src], dest, weight);
  g->edges++;
}

void remove_edge(graph_t *g, unsigned int src, unsigned int dest)
{
  if (src >= g->vertices || dest >= g->vertices)
    return;
  erase(g->lists[src], dest);
  g->edges--;
}

static inline bool empty_set(bool set[], unsigned int size)
{
  for (unsigned int i = 0; i < size; i++)
    if (set[i] == true)
      return false;
  return true;
}

static inline unsigned int extract_min(bool set[], unsigned int d[],
                                       unsigned int size)
{
  unsigned int min = UINT_MAX;
  for (unsigned int i = 0; i < size; i++)
    if (set[i] == true && d[i] < min)
      min = i;
  return min;
}

static void print_shortest_path(int p[], unsigned int src, unsigned int dest)
{
  while (dest != src) {
    printf("%u ", dest);
    dest = p[dest];
  }
  printf("%u\n", dest);
}

/* The shortest path finding using the Dijkstra's algorithm. */
void find_shortest_path(graph_t *g, unsigned int src, unsigned int dest)
{
  #define UNDEFINED -1
  if (src >= g->vertices || dest >= g->vertices)
    return;
  unsigned int d[g->vertices]; int p[g->vertices];
  bool S[g->vertices], Q[g->vertices];
  for (unsigned int i = 0; i < g->vertices; i++) {
    p[i] = UNDEFINED;  /* Set all parents of vertices to undefined (-1). */
    d[i] = UINT_MAX;   /* Mark distances to vertices as infinity (UINT_MAX). */
    S[i] = false;      /* Clear the set. */
    Q[i] = true;       /* Fill the set with all vertices. */
  }
  d[src] = 0;
  
  while (!empty_set(Q, g->vertices)) {
    /* TODO: We should use the fibonacci min-heap here for better performances. */
    unsigned int min = extract_min(Q, d, g->vertices);
    Q[min] = false; S[min] = true;

    linked_list_node_t *current = g->lists[min]->head;
    for (; current != NULL; current = current->next) {
      /* Relaxation condition. */
      if (d[current->value] > d[min] + current->weight) {
        d[current->value] = d[min] + current->weight;
        p[current->value] = min;
      }
    }
  }

  print_shortest_path(p, src, dest);
  printf("weight of path: %u\n", d[dest]);
  #undef UNDEFINED
}
