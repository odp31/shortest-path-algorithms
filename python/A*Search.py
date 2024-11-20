# used to find shortest path between 2 nodes in a weighted graph 
# combines best aspects of Dijkstra's and greedy best-first search 

from collections import default dict
from heapq import heappush, heappop

def a_star_search(graph, start, goal):
  open_set = [(0, start)] # priority queue 
  came_from = {}
  g_score = {node: float('infinity') for node in graph}
  g_score[start] = 0
  f_score = {node: float('infinity') for node in graph}
  f_score[start] = heuristic(start, goal)

  while open_set:
    current = heappop(open_set)[1]
    if current == goal:
      return reconstruct_path(came_from, current)
    closed_set.add(current)

    for neighbor, cost in graph[current].items():
      tentative_g_score = g_score[current] + cost
      if neighbor not in closed set and tentative_g_score < g_score[neighbor]:
        g_score[neighbor] = tentative_g_score
        f_score[neighbor] = g_score[neighbor] + heuristic(neighbor, goal)

        heappush(open_set, (f_score[neighbor], neighbor))
  return None

def reconstruct_path(came_from, current_node):
  path = []
  while current_node:
    path.append(current_node)
    current_node = came_from.get(current_node)
  return path[::-1]

# example usage 
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1, 'E': 3},
    'D': {'B': 5, 'C': 1, 'E': 1},
    'E': {'C': 3, 'D': 1}
}

start_node = 'A'
goal_node = 'E'
path = a_star_search(graph, start_node, goal_node)
print(path) 
