// Accepted
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dir {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool invalidPos(int posN, int posM, vector<vector<int>>& riverMatrix, vector<vector<bool>>& visitedRiverMatrix) {
  return (posN >= riverMatrix.size() || posM >= riverMatrix[0].size() || visitedRiverMatrix[posN][posM] || riverMatrix[posN][posM] == 0 || posN < 0 || posM < 0);
}

int riverSize(int posN, int posM, vector<vector<int>> &riverMatrix, vector<vector<bool>> &visitedRiverMatrix, int riverSizeCount) {
  if (invalidPos(posN, posM, riverMatrix, visitedRiverMatrix)) {
    return 0;
  }
  riverSizeCount++;
  visitedRiverMatrix[posN][posM] = true;
  for (auto a : dir) {
    riverSizeCount += riverSize(posN + a[0], posM + a[1], riverMatrix, visitedRiverMatrix, 0);
  }
  return riverSizeCount;
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> riverMatrix(n, vector<int>(m));
  vector<vector<bool>> visitedRiverMatrix(n, vector<bool>(m, false));
  vector<int> riverSizeVector;
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < m ; ++j) {
      cin >> riverMatrix[i][j];
    }
  }

  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < m ; ++j) {
      if(riverMatrix[i][j] == 0 || visitedRiverMatrix[i][j]) {
        continue;
      } else {
        int size = riverSize(i, j, riverMatrix, visitedRiverMatrix, 0);
        riverSizeVector.push_back(size);
      }
    }
  }
  if (riverSizeVector.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  for (auto a : riverSizeVector) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
