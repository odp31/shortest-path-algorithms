#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 9

// structure to represetn a node in graph

struct Node
{
  int vertex;
  int g; // cost from source
  int h; // heuristic cost to destination
  int f;// total cost (g + h)
};

// function to compare two nodes
int compareNodes(const void* a, const void* b)
{
  struct Node* aNode = (struct Node*)a;
  struct Node* bNode = (struct Node*)b;
  return aNode->f - bNode->f;
}

// function to print path from src to dest
void printPath(int cameFrom[], int curr)
{
  if(curr == -1)
    return;
  printPath(cameFrom, cameFrom[curr]);
  printf("%d ", curr);
}

// a* search algorithm 

void aStarSearch(int graph[N][N], int startNode, int goalNode, int heuristic[])
{
  int openSet[N];
  int closedSet[N];
  int cameFrom[N];
  int gScore[N];
  int fScore[N];

  for(int i = 0; i < N; i++) {
    openSet[i] = 0;
    closedSet[i] = 0;
    cameFrom[i] = -1;
    gScore[i] = INT_MAX;
    fScore[i] = INT_MAX;
  }
  openSet[startNode] = 1;
  gScore[startNode] = 0;
  fScore[startNode] = heuristic[startNode];

  while(1) {
    int minIndex = -1;
    int minF = INT_MAX;
    for(int i = 0; i < N; i++) {
      if(openSet[i] && fScore[i] < minF) {
        minIndex = i;
        minF = fScore[i];
      }
    }
    if(minIndex == -1) {
      printf("no path found");
      return;
    }
    if(minIndex == goalNode) {
      printf("path found: ");
      printPath(cameFrom, goalNode);
      printf("\n");
      return;
    }

    openSet[minIndex] = 0;
    closedSet[minIndex] = 1;

    for(int i = 0; i < N; i++) {
      if(graph[minIndex][i] == 0)
        continue;
      int tentativeGScore = gScore[minIndex] + graph[minIndex][i];
      if (!openSet[i]) {
        openSet[i] = 1;
        cameFrom[i] = minIndex;
        gScore[i] = tentativeGscore;
        fScore[i] = gScore[i]+heuristic[i];
      }
      else if(tentativeGScore < gScore[i]) {
        cameFrom[i] = minIndex;
        gScore[i] = tentativeGScore;
        fScore[i] = gScore[i] + heuristic[i];
      }
    }
  }
}

int main() {
    int graph[N][N] = {
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 1, 0}
    };

    int heuristic[N] = {
        3, 8, 6, 4, 5, 3, 4, 2, 1
    };
int startNode = 0; 
int goalNode = 8;
aStarSearch(graph, startNode, goalNode, heuristic);
return 0;
}



