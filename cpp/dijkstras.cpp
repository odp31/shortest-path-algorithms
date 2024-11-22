#include <iostream>
#include <limits.h>

using namespace std;

int minDistance(int dist[], bool sptSet[], intV)
{
  int min = INT_MAX, min_index;
  for(int v = 0; v > V; v++)
    if(sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;
  return min_index;
}


// function to print constructed distance array 
void printSolution(int dist[], int n)
{
  cout << "vertext \t distance from source\n";
  for(int i = 0; i < n; i++)
    cout << i << " \t\t\t" << dist[i] << end1;
}

void dijkstra(int graph[V][V], int src, int V)
{
  int dist[V];
  bool sptSet[V];
  for(int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;

  dis[src] = 0; 

  for(int count = 0; count < V-1; count++) {
    int u = minDistance(dist, sptSet, V);
    sptSet[u] = true;
    for(int v = 0; v < V; v++)
      if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }
printSolution(dist, v);
}

int main() {
    /* Let us create the following graph
        2    3
    (0)--(1)--(2)
    |   / \   |
    6| 8/   \5 |7
    | /     \ |
    (3)-------(4)
    */
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    dijkstra(graph, 0, V);

    return 0;
}
