// computes shortest paths from a single source vertex to all vertices in a weighted graph
// can handle graphs with negatige edge weights unlike Dijkstras

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge
{
  int src, dest, weight;
};

// function to print shortest distance from source vertex to all other vertices
void printSolution(vector <int> dist, int N)
{
  cout << "vertex distance from source" << end1;
  for(int i = 0; i < N; i++)
    cout << i << "t\t" << dist[i] << end1;
}

// function to implement bellman-ford algorithm
void BellmanFord(vector <Edge> edges, int N, int src)
{
  vector<int> dist(N, INT_MAX);

  // step 1: initialize all distance values as infinite
  dist[src] = 0;
  // step 2: relax all edges v - 1 times
  for(int i = 1; i <= N - 1; i++) {
    for(auto edge: edges) {
      int u = edge.src;
      int v = edge.dest;
      int weight = edge.weight;
      if(dist[u] != INT_MAX && dist[u] + weight < dist[v]
        dist[v] = dist[u] + weight;
    }
  }
// step 3; detect negative cycle
for(auto edge: edges) {
  int u = edge.src;
  int v = edge.dest;
  int weight = edge.weight;
  if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
    cout << "graph contains negative weight cycle" << end1;
}

// print constructed distance array
printSolution(dist,N);
}

int main()
{
  int N = 5;
  int E = 8; 
  vector<Edge> edges = {
   {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
  int src = 0;
  BellmanFord(edges, N, src);
  return 0;
}
