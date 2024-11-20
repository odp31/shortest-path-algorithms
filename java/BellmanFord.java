import java.util.HashMap;
import java.util.Map;

public class BellmanFord
  {
    public static Map<Integer, Integer> bellmanFord(Map<Integer, Map<Integer, Integer>> graph, int source)
    {
      int V = graph.size();
      Map<Integer, Integer> dist = new HashMap<>();

      // initialize distances to infinity and source distance to 0 
      for (int node: graph.keySet()){
        dist.put(node, Integer.MAX_VALUE);
      }
      dist.put(source, 0);
      // relax all edges V - 1 times
      for(int i = 0; i < V - 1; i++){
        for(int u: graph.keySet()){
          for(Map.Entry<Integer, Integer> pair: graph.get(u).entrySet()) {
            int v = pair.getKey();
            int weight = pair.getValue();
            if(dist.get(v) > dist.get(u) + weight) {
              dist.put(v, dist.get(u) + weight);
            }
          }
        }
      }
      // detect negative cycle
      for(int u: graph.keySet()) {
        for(Map.Entry<Integer, Integer> pair: graph.get(u).entrySet()){
          int v = pair.getKey();
          int weight = pair.getValue();
          if (dist.get(v) > dist.get(u) + weight) {
            System.out.println("graph contains negative weight cycle");
            return null;
          }
        }
      }
      return dist;
    }
    public static void main(String[] args)
    {
      // example graph
      Map<Integer, Map<Integer, Integer>> graph = new HashMap<>();
      graph.put(0, Map.of(1, -1, 2, 4));
      graph.put(1, Map.of(2,3));
      graph.put(2, Map.of(3, 2));
      graph.put(3, Map.of(1, -2));

      int source = 0;
      Map<Integer, Integer> distances = bellmanFord(graph, source);

      if(distances != null){
        System.out.println("shortest distances from node" + source + ":");
        for (Map.Entry<Integer, Integer> entry: distances.entrySet()) {
          System.out.println("to node" + entry.getKey() + ": " _ entry.getValue());
        }
      }
    }
  }

          
      
    
