/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

bool validPos(int i, int j, int m, int n) {
  return (i >= 0 && j >= 0 && i < m && j < n);
}

bool searchMatrix(vector <vector <int> >& num, int target) {
  int i = 0;
  int j = num[0].size() - 1;
  while (validPos(i, j, num.size(), num[0].size())) {
    if (num[i][j] == target) {
      return true;
    }
    if (num[i][j] < target) {
      i++;
    } else {
      j--;
    }
  }
  return false;
}

int main(void) {
  int target;
  int n;
  int m;
  int num;
  cin >> m >> n >> target;
  vector <vector <int> > mat (m, vector <int> (n));
  for (int i = 0 ; i < m ; ++i) {
    for (int j = 0 ; j < n ; ++j) {
      cin >> mat[i][j];
    }
  }
  cout << searchMatrix(mat, target) << endl;
  return 0;
}
