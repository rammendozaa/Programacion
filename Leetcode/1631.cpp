#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct compare {
  bool operator() (const vector <int>& one, const vector <int>& two) {
    return one[0] > two[0];
  }
};

int minimumEffortPath(vector <vector <int> >& matrix) {
  vector <vector <int> > moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  vector <vector <int> > effortMat(matrix.size(), vector <int> (matrix[0].size(), 1e9));
  priority_queue <vector <int>, vector <vector <int> >, compare> q;
  q.push({0, 0, 0});
  while (!q.empty()) {
    vector <int> currEffort = q.top();
    q.pop();
    int effort = currEffort[0];
    int x = currEffort[1];
    int y = currEffort[2];
    if (effort > effortMat[x][y]) {
      continue;
    }
    if (x == matrix.size() - 1 && y == matrix[0].size() - 1) {
      return effort;
    }
    for (auto a : moves) {
      int newX = x + a[0];
      int newY = y + a[1];
      if (newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size()) {
        int newDistance = max(effort, abs(matrix[newX][newY] - matrix[x][y]));
        if (newDistance < effortMat[newX][newY]) {
          effortMat[newX][newY] = newDistance;
          q.push({newDistance, newX, newY});
        }
      }
    }
  }
  return 0;
}

int main(void) {
  int m;
  int n;
  cin >> m >> n;
  vector <vector <int> > mat(m, vector <int> (n));
  for (int i = 0 ; i < m ; ++i) {
    for (int j = 0 ; j < n ; ++j) {
      cin >> mat[i][j];
    }
  }
  cout << minimumEffortPath(mat) << endl;
}
