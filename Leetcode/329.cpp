#include <iostream>
#include <vector>

int longestIncreasingPath(vector<vector<int>>& matrix) {
  vector <vector <int> > mat(matrix.size(), <vector <int> > (matrix[0].size(), -1);
}

int main(void) {
  int n;
  int m;
  cin >> n >> m;
  vector <vector <int> > matrix(n, vector <int> (m, 0));
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < m ; ++j) {
      cin >> matrix[i][j];
    }
  }
  cout << longestIncreasingPath(matrix) << endl;
}
// vector and vector of sets to add the nodes that we need to visit
