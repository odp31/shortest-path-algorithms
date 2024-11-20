def bellman_ford(graph, source):
  """ finds shortest path from source node to all other nodes in a graph, even with negative edge weights"""
  num_vertices = len(graph)
  distances = {node: float('infinity') for node in graph}
  distances[source] = 0

  for i in range(num_vertices - 1):
    for node in graph:
      for neighbor, weight in graph[node].items():
        if distances[neighbor] > distances[node] + weight:
          distances[neighbor] = distances[node] + weight 


  # detect negative cycle
  for node in graph:
    for neighbor, weight in graph[node].items():
      if distances[neighbor] > distances[node] + weight:
        return None 

  return distances 

# Example usage
graph = {
    'A': {'B': -1, 'C': 4},
    'B': {'C': 3, 'D': 2},
    'C': {'B': -2, 'D': 5, 'E': 2},
    'D': {'E': -3},
    'E': {}
}

source_node = 'A'
shortest_distances = bellman_ford(graph, source_node)

if shortest_distances:
    print(shortest_distances)
else:
    print("Negative cycle detected")
