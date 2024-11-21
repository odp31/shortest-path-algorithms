function aStarSearch(graph, startNode, goalNode, heuristic)
{
  const openSet = new Set();
  const closedSet = new Set();
  const gScore = {};
  const fScore = {};

  openSet.add(startNode);
  gScore[startNode] = 0;
  fScore[startNode] = heuristic(startNode, goalNode);

  while(openSet.size > 0)
    {
      let current = null;
      for(const node of openSet)
        {
          if(current === null || fScore[node] < fScore[current])
          {
            current = node;
          }
        }
      if(current === goalNode)
      {
        return reconstructPath(cameFrom, current);
      }
      openSet.delete(current);
      closedSet.add(current);
      for(const neighbor in graph[current])
        {
          if(closedSet.has(neighbor)) continue;
          const tentativeGScore = gScore[current] + graph[current][neighbor];
          if(!openSet.has(neighbor))
          {
            openSet.add(neighbor);
          }
          else if(tenativeGScore >= gScore[neighbor])
          {
            continue;
          }
          cameFrom[neighbor] = current;
          gScore[neighbor] = tentativeGScore;
          fScore[neighbor] = gScore[neighbor] + heuristic(neighbor, goalNode);
        }
    }
  return null;
}
function reconstructPath(cameFrom, current)
{
  const totalPath = [current];
  while(current in cameFrom)
    {
      current = cameFrom[current];
      totalPath.unshift(current);
    }
  return totalPath;
}

// Example   
 usage:
const graph = {
  A: { B: 1, C: 4 },
  B: { A: 1, C: 2, D: 5 },
  C: { A: 4, B: 2, D: 1, E: 3 },
  D: { B: 5, C: 1, E: 1 },
  E: { C: 3, D: 1 }
};

const heuristic = (node, goal) => {
  // Euclidean distance heuristic (can be adjusted based on problem specifics)
  const dx = Math.abs(node.x - goal.x);
  const dy = Math.abs(node.y - goal.y);
  return Math.sqrt(dx * dx + dy * dy);
};

const start = 'A';
const goal = 'E';
const path = aStarSearch(graph, start, goal, heuristic);
console.log(path); //output ['A', 'C', 'D', 'E']

      
