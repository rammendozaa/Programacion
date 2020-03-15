/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

vector <vector <int> > myMatrix;
void numMatrix(vector <vector <int> >& matrix) {
  if (matrix.size() == 0 || matrix[0].size() == 0) {
      return;
  }
  myMatrix.resize(matrix.size() + 1, vector <int> (matrix[0].size() + 1, 0));
  for (int i = 1 ; i <= matrix.size() ; ++i) {
      for (int j = 1 ; j <= matrix[0].size() ; ++j) {
          myMatrix[i][j] += (myMatrix[i][j - 1] + matrix[i - 1][j - 1]);
      }
  }
  for (int j = 1 ; j <= matrix[0].size() ; ++j) {
      for (int i = 1 ; i <= matrix.size() ; ++i) {
          myMatrix[i][j] += myMatrix[i - 1][j];
      }
  }
}

int sumRegion(int row1, int col1, int row2, int col2) {
    row1++;
    col1++;
    row2++;
    col2++;
    if (myMatrix.size() == 0 && myMatrix[0].size() == 0) {
        return 0;
  }
  return (myMatrix[row2][col2] - myMatrix[row2][col1 - 1] - myMatrix[row1 - 1][col2] + myMatrix[row1 - 1][col1 - 1]);
}

int main(void) {
  vector <vector <int> > nums;
  int n;
  int m;
  cin >> n >> m;
  vector <vector <int> > input(n, vector <int> (m));
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < m ; ++j) {
      cin >> input[i][j];
    }
  }
  int rowOne;
  int rowTwo;
  int colOne;
  int colTwo;
  cin >> rowOne >> colOne >> rowTwo >> colTwo;
  numMatrix(input);
  cout << sumRegion(rowOne, colOne, rowTwo, colTwo) << endl;

}
