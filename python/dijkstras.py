import heapq

def dijkstra(graph, source):
  """ finds shortest path from source node to all other nodes in a graph
  args: graph- a dictionary representing the graph wehre keys are nodes and values are dictionaries of neighboring nodes and their distances 
  source: source node
  returns: dictionary of shortest distances from source node to all other nodes
  """
  distances = {node: float('infinity') for node in graph}
  distances[source] = 0
  pq = [(0, source)] 

  while pq:
    current_distance, current_node = heapq.heappop(pq)

    if current_distance > distances[current_node]:
      continue 

    for neighbor, weight in braph[current_node].items():
      distance = current_distance + weight
      if distance < distances[neighbor]:
        distances[neighbor] = distance 
        heapq.heappush(pq, (distance, neighbor))

  return distances 

# example usage

graph   
 = {
    'A': {'B': 10, 'C': 3},
    'B': {'C': 1, 'D': 2},
    'C': {'B': 4, 'D': 8, 'E': 2},
    'D': {'E': 7},
    'E': {}
}

source_node = 'A'
shortest_distances = dijkstra(graph, source_node)
print(shortest_distances) 
