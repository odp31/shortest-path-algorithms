// can handle negative edge weights 

function bellmanFord(graph, source)
{
  const distances = {};
  const previous = {};
  // initialize distances to infinity and previous nodes to nul
  for(const node in graph)
    {
      distances[node] = Infinity;
      previous[node] = null;
    }
  // set distance to source node to 0
  distances[source] = 0;
  // relax edges |V| - 1 times
  for(let i = 0; i < Object.keys(graph).length - 1; i++)
    {
      for(const node in graph)
        {
          for(const neighbor in graph[node])
            {
              const distance = distances[node] + graph[node][neighbor];
              if(distance < distances[neighbor])
              {
                distances[neighbor] = distance;
                previous[neighbor] = node;
              }
            }
        }
    }
  // detect negative cycles
  for(const node in graph)
    {
      for(const neighbor in graph[node])
        {
          const distance = distances[node] + graph[node][neighbor];
          if(distance < distances[neighbor])
          {
            console.log("graph contains negative weight cycle");
            return:
              }
        }
    }
  return {distances, previous};
}

