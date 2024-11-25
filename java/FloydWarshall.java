public class FloydWarshall
  {
    public static void floydWarshall(int[][] graph)
    {
      int V = graph.length;
      int[][] dist = new int[V][V];
      int[][] next = new int[V][V];

      // initialize distance matrix and next matrix
      for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
          dist[i][j] = graph[i][j];
          if(graph[i][j] != Integer.MAX_VALUE && i != j) {
            next[i][j] = j;
          }
          else
          {
            next[i][j] = -1;
          }
        }
      }
      // perform floyd warshall algorithm 
      for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
          for(int j = 0; j < V; j++) {
            if(dist[i][k] != Integer.MAX_VALUE && dist[k][j] != Integer.MAX_VALUE && dist[i][j] > dist[i][k] + dist[k][j]){
              dist[i][j] = dist[i][k] + dist[k][j];
              next[i][j] = next[i][k];
            }
          }
        }
      }
      // print shortest distances
      printSolution(dist, next);
    }

public static void printSolution(int[][] dist, int[][] next)
    {
      int V = dist.length;
      for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
          if(dist[i][j] == Integer.MAX_VALUE) {
            System.out.print("INF ");
          }
          else
          {
            System.out.print(dist[i][j] + " ");
          }
        }
        System.out.println();
      }
    }

public static void main(String[] args)
    {
      int graph[][] = { {0, 5, INF, 10},
                       {INF, 0, 3, INF}, 
                       {INF, INF, 0, 1}, 
                       {INF, INF, INF, 0}
                      };
      floydWarshall(graph);
    }
  }
