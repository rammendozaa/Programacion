/* Acccepted */
#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector <vector <int> >& grid) {
  if (grid.size() == 0) {
    return 0;
  }
  int n = grid.size();
  int m = grid[0].size();
  vector <vector <int> > sum(n, vector <int> (m, 0));
  sum[n - 1][m - 1] = grid[n - 1][m - 1];

  for (int i = n - 2 ; i >= 0 ; --i) {
    sum[i][m - 1] = sum[i + 1][m - 1] + grid[i][m - 1];
  }

  for (int i = m - 2 ; i >= 0 ; --i) {
    sum[n - 1][i] = sum[n - 1][i + 1] + grid[n - 1][i];
  }

  for (int i = n - 2 ; i >= 0 ; --i) {
    for (int j = m - 2 ; j >= 0 ; --j) {
      sum[i][j] = min(sum[i + 1][j], sum[i][j + 1]) + grid[i][j];
    }
  }
  return sum[0][0];
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector <vector <int> > grid(n, vector <int> (m, 0));
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < m ; ++j) {
      cin >> grid[i][j];
    }
  }
  cout << minPathSum(grid) << endl;
}
