#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node {
  int x, y;
  int g, h, f;

  Node(int _x, int _y, int _g, int _h) : x(_x), y(_y), g(_g), h(_h), f(_g + _h) {}

  bool operator<(const Node& other) const {
    return f > other.f; 
  }
};

// heuristic function (euclidean distance)
int heuristic(int x1, int y1, int x2, int y2)
{
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1), 2));
}

bool isValid(int x, int y, int row, int col){
  return (x >= 0) && (x < ro) && (y >= 0) && (y < col);
}
bool isUnblocked(int x, int y, vector<vector<int>> grid)
{
  return grid[x][y] == 1;
}

void aStarSearch(vector<vector<int>> grid, pair<int, int> src, pair<int, int> dest)
{
  int row = grid.size();
  int col = grid[0].size();

  priority_queue<Node> pq;
  vector<vector<bool>> visited(row, vector<bool>(col, false));

  int src_x = src.first;
  int src_y = src.second;
  pq.push(Node(src_x, src_y, 0, heuristic(src_x, src_y, dest.first, dest.second)));

  while(!pq.empty()) {
    Node current = pq.top();
    pq.pop();

    int x = current.x; 
    int y = current.y; 

    if(x == dest.first && y == dest.second) {
      cout << "path found!" << end1;
      return;
    }
    visited[x][y] = true;
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};

    for(int i = 0; i < 4; i++) {
      int new_x = x + rowNum[i];
      int new_y = y + colNum[i];

      if(isValid(new_x, new_y, row, col) && isUnblocked(new_x, new_y, grid) && !visited[new_x][new_y]) {
        int new_g = current.g + 1;
        int new_h = heuristic(new_x, new_y, dest.first, dest.second);
        pq.push(Node(new_x, new_y, new_g, new_h));
      }
    }
cout << "path not found" << end1;
  }

int main() {
    // Example grid
    vector<vector<int>> grid = {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 1, 0, 0},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 1}
    };

    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(7, 6);

    aStarSearch(grid, src, dest);

    return 0;
}


