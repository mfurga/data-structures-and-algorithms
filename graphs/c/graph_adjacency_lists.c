#include <stdio.h>
#include <assert.h>
#include <string.h>
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

void breadth_first_search(graph_t *g, int vertex)
{
  bool visited[g->vertices];
  memset(visited, false, sizeof(bool) * g->vertices);
  queue_t *q = create_queue(g->vertices);

  visited[vertex] = true;
  enqueue(q, vertex);

  while (!empty(q)) {
    int v = dequeue(q);
    /* Do whatever with the vertex. We'll just print its value. */
    printf("%i ", v);
    linked_list_node_t *current = g->lists[v]->head;
    while (current != NULL) {
      if (visited[current->value] == false) {
        visited[current->value] = true;
        enqueue(q, current->value);
      }
      current = current->next;
    }
  }
  remove_queue(q);
}

static void depth_first_search_(graph_t *g, int vertex, bool visited[])
{
  visited[vertex] = true;
  /* Do whatever with the vertex. We'll just print its value. */
  printf("%i ", vertex);
  linked_list_node_t *current = g->lists[vertex]->head;
  while (current != NULL) {
    if (visited[current->value] == false)
      depth_first_search_(g, current->value, visited);
    current = current->next;
  }
}

void depth_first_search(graph_t *g, int vertex)
{
  bool visited[g->vertices];
  memset(visited, false, sizeof(bool) * g->vertices);
  depth_first_search_(g, vertex, visited);
  /* Visit all the vertices.
  (void)vertex;
  for (int v = 0; v < g->vertices && visited[v] == false; v++)
    depth_first_search_(g, v, visited);
  */
}

void depth_first_search_iter(graph_t *g, int vertex)
{
  bool visited[g->vertices];
  memset(visited, false, sizeof(bool) * g->vertices);
  stack_t *s = create_stack(g->vertices);

  visited[vertex] = true;
  push(s, vertex);

  while (!empty_stack(s)) {
    int v = pop(s);
    /* Do whatever with the vertex. We'll just print its value. */
    printf("%i ", v);
    linked_list_node_t *current = g->lists[v]->head;
    while (current != NULL) {
      if (visited[current->value] == false) {
        visited[current->value] = true;
        push(s, current->value);
      }
      current = current->next;
    }
  }
  remove_stack(s);
}

static bool find_path_(graph_t *g, int src, int dest, bool visited[],
                       stack_t *s)
{
  visited[src] = true;
  push(s, src);
  if (src == dest) return true;

  linked_list_node_t *current = g->lists[src]->head;
  while (current != NULL) {
    if (!visited[current->value] && find_path_(g, current->value, dest, visited, s))
      return true;
    current = current->next;
  }
  pop(s);
  return false;
}

/* Finding a path between two vertices using the depth first search. */
void find_path(graph_t *g, int src, int dest)
{
  if (src < 0 || dest < 0 || src >= g->vertices || dest >= g->vertices)
    return;
  bool visited[g->vertices];
  memset(visited, false, sizeof(bool) * g->vertices);
  stack_t *s = create_stack(g->vertices);

  if (find_path_(g, src, dest, visited, s) == true) {
    while (!empty_stack(s))
      printf("%i ", pop(s));
  } else
    printf("The path doesn't exist.\n");

  remove_stack(s);
}
