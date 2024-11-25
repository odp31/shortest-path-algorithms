# dynamic programming algorithm that finds shortest paths between all pairs of nodes in a weighted graph 

def floyd_warshall(graph):
  dist = graph.copy()
  for k in range(len(graph)):
    for i in range(len(graph)):
      for j in range(len(graph)):
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
  return dist 

# example usage
graph = [[0, 5, INF, 10],
         [INF, 0, 3, INF], 
         [INF, INF, 0, 1], 
         [INF, INF, INF, 0]]

dist = floyd_warshall(graph)
print(dist)
