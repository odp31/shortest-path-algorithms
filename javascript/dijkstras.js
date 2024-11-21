function dijkstra(graph, startNode)
{
  const distances = {};
  const visited = {};
  const previous = {};
  // initialize distances to infinity and previous nodes to null
  for(const node in graph)
    {
      distances[node] = Infinity;
      previous[node] = null;
    }
  // set distance to start node to 0
  distances[startNode] = 0;
  const nodes = Object.keys(graph);

  while(nodes.length)
    {
      // find node with smallest distance
      let closestNode = null;
      for(const node of nodes)
        {
          if(!visited[node] && (closestNode === null || distances[node] < distances[closestNode]))
          {
            closestNode = node;
          }
        }
      if(closestNode === null)
      {
        break;
      }
      // mark node as visited
      visited[closestNode] = true;
      // update distances to neighbors
      for(const neighbor in graph[closestNode])
        {
          const distance = distances[closestNode] + graph[closestNode][neighbor];
          if(distance < distances[neighbor])
          {
            distances[neighbor] = distance;
            previous[neighbor] = closestNode;
          }
        }
      // remove node from list of nodes to process
      nodes.splice(nodes.indexOf(closestNode), 1);
    }
  return{distances, previous};
}

// Example usage:
const graph = {
  A: { B: 10, C: 3 },
  B: { C: 1, D: 2 },
  C: { B: 4, D: 8, E: 2 },
  D: { E: 7 },
  E: {}
};

const{distances, previous} = dijkstra(graph,'A');
console.log(distances);
console.log(previous); 

