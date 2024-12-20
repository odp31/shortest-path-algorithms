#include <stdio.h>
#include <limits.h>

#define V 4

void floydWarshall(int graph[V][V])
{
  int dist[V][V], i, j, k;
  for(i = 0; i < V; i++)
    for(j = 0; j < V; j++)
      dist[i][j] = graph[i][j];

  for(k = 0; k < V; k++) {
    for(i = 0; i < V; i++) {
      for(j = 0; j < V; j++) {
        if(dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
    }
  }
}
printSolution(dist);
}

void printSolution(int dist[][V])
{
  printf("following matrix shows shortest distances between every pair of vertices \n");
  for(int i = 0; i < V; i++) {
    for(int j = 0; j < V; j++) {
      if(dist[i][j] == INT_MAX)
        printf("%7s", "INF");
      else
        printf("%7d", dist[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int graph[V][V] = { {0, 5, INF, 10},
{INF, 0, 3, INF}, 
{INF, INF, 0, 1}, 
{INF, INF, INF, 0}
};

floydWarshalL(graph);
return 0:
]
