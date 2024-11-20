import java.util.*;

class Node implements Comparable<Node>
  {
    public int x, y, cost, fCost, gCost;

    public Node(int x, int y, int cost, int gCost, int fCost)
    {
      this.x = x;
      this.y = y;
      this.cost = cost;
      this.gCost = gCost;
      this.fCost = fCost;
    }
    @Override
    public int compareTo(Node other) {
      return Integer.compare(this.fCost, other.fCost);
    }
  }

public class AStarSearch
  {
    public static boolean[][] grid = {
      {false, false, false, false},
      {true, true, false, true}, 
      {false, true, true, false}, 
      {false, false, false, false}
    };
    public static int heuristic(int x, int y, int goalX, int goalY) {
      // manhattan distance heuristic
      return Math.abs(x - goalX) + Math.abs(y - goalY);
    }
    public static List<Node> aStarSearch(int startX, int startY, int goalX, int goalY){
      PriorityQueue<Node> openSet = new PriorityQueue<>();
      Set<Node> closedSet = new HashSet<>();

      openset.offer(new Node(startX, startY, 0, 0, heuristic(startX, startY, goalX, goalY)));
      while (!openSet.isEmpty()){
        Node current = openSet.poll();
        if (current.x == goalX && current.y== goalY) {
          List<Node> path = new ArrayList<>();
          while (current != null) {
            path.add(current);
            current = current.parent;
          }
          Collections.reverse(path);
          return path;
        }
        closedSet.add(current);
        for(int dx = -1; dx <= 1; dx++){
          for(int dy = -1; dy <= 1; dy++) {
            if(Math.abs(dx) == Math.abs(dy)) {
              continue;
            }
            int newX = current.x + dx;
            int newY = current.y + dy;

            if (newX >= 0 && newX < grid.length && newY >= 0 && newY < grid[0].length && !grid[newX][newY] && !closedSet.contains(new Node(newX, newY, 0, 0, 0))){
              int gCost = current.gCost + 1; 
              int hCost = heuristic(newX, newY, goalX, goalY);
              int fCost = gCost + hCost;

              Node neighbor = new Node(newX, newY, 1, gCost, fCost);
              neighbor.parent = current;
              openSet.offer(neighbor);
            }
          }
        }
      }
      return null; // no path found
    }

    public static void main(String[] args)
    {
      List<Node> path = aStarSearch(0, 0, 3, 3);
      if(path != null) {
        for(Node node: path) {
          System.out.println("(" + node.x + ", " + node.y + ")");
        }
      }
      else {
        System.out.println("no path found.");
      }
    }
  }
