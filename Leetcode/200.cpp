/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

bool validPos(int i, int j, int h, int w) {
  return !(i < 0 || j < 0 || i >= h || j >= w);
}

void markIsland(vector <vector <char> >& grid, int i, int j) {
  if (!validPos(i, j, grid.size(), grid[0].size()) || grid[i][j] != '1') {
    return;
  }
  grid[i][j] = '-';
  markIsland(grid, i + 1, j);
  markIsland(grid, i - 1, j);
  markIsland(grid, i, j + 1);
  markIsland(grid, i, j - 1);
}

int numIslands(vector <vector <char> >& grid) {
  if (grid.size() == 0) {
    return 0;
  }
  int n = grid.size();
  int m = grid[0].size();
  int currIsland = 0;
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < m ; ++j) {
      if (grid[i][j] == '1') {
        markIsland(grid, i, j);
        currIsland++;
      }
    }
  }
  return currIsland;
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector <vector <char> > grid(n, vector <char> (m, '0'));
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < m ; ++j) {
      cin >> grid[i][j];
    }
  }
  cout << numIslands(grid) << endl;
}
