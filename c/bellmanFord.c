#include <stdio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], bool sptset[])
{
  int min = INT_MAX, min_index;
  for(int v = 0; v < V; v++)
    if(sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;

  return min_index;
}

void printSolution(int dist[])
{
  printf("vertex \t distance from source \n");
  for(int i = 0; i < V; i++)
    printf("%d \t\t %d \n", i, dist[i]);
}

void bellmanFord(int graph[V][V], int src)
{
  int dist[V];
  bool sptSet[V];

  // initialize distance array and sptSet
  for(int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;

  dist[src] = 0;

  // relax all edges |V - 1| times
  for(int i = 1; i < V; i++) {
    for(int u = 0; u < V; u++) {
      for(int v = 0; v < V; v++) {
        if(graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
          dist[v] = dist[u] + graph[u][v];
      }
    }
  }
// detect negative cycle
  for(int u = 0; u < V; u++) {
    for(int v = 0; v < V; v++) {
      if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
        printf("Graph contains negative weight cycle");
        return;
    }
  }
printSolution(dist);
}


int main() {
    int graph[V][V] = {
        {0, -1, 4, 0, 0},
        {0, 0, 3, 2, 2},
        {-1, -2, 0, 0, -1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

bellmandFord(graph, 0);
return 0;
}


