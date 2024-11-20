import java.util.*;

public class Dijkstra
  {
    public static Map<Integer, Integer> dijkstra(Map<Integer, Map<Integer, Integer>> graph, int source)
    {
      int n = graph.size();
      Map<Integer, Integer> dist = new HashMap<>();
      PriorityQueue<Pair> pq = new PriorityQueue<>();

      // initalize distances to infinity and add source node to pq
      for (int node: graph.keySet()) {
        dist.put(node, Integer.MAX_VALUE);
      }
      dist.put(source, 0);
      pq.offer(new Pair(source, 0));

      while (!pq.isEmpty() {
        Pair p = pq.poll();
        int u = p.node;
        int weight = p.weight;

        // skip if we already found shorter path to u 
        if (weight > dist.get(u)) {
          continue;
        }
        for (Mat.Entry<Integer, Integer> neighbor: graph.get(u).entrySet()) {
          int v = neighbor.getKey();
          int w = neighbor.getValue();

          if(dist.get(v) > weight + w) {
            dist.put(v, weight + w);
            pq.offer(new Pair(v, weight + w));
          }
        }
      }
      return dist;
    }

    static class Pair implemetns Comparable<Pair> {
      int node, weight;

      public Pair(int node, int weight) {
        this.node = node;
        this.weight = weight;
      }
      @Override
      public int compareTo(Pair other) {
        return this.weight - other.weight;
    }
  }
