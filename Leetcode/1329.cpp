/* Accepted */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void assignDiagonalValues(int posI, int posJ, vector <vector <int> >& res,
  priority_queue <int, vector <int>, greater <int> >& q) {
    for (int i = posI, j = posJ ; i < res.size() && j < res[0].size() ; ++i, ++j) {
      res[i][j] = q.top();
      q.pop();
    }
  }

void getDiagonalValues(int posI, int posJ, vector <vector <int> >& mat,
  priority_queue <int, vector <int>, greater <int> >& q) {
    for (int i = posI, j = posJ ; i < mat.size() && j < mat[0].size() ; ++i, ++j) {
      q.push(mat[i][j]);
    }
  }

vector <vector <int> > diagonalSort(vector <vector <int> >& mat) {
  int m = mat.size();
  int n = mat[0].size();
  vector <vector <int> > res(m, vector <int> (n, 0));
  priority_queue <int, vector <int>, greater <int> > q;
  for (int i = 0 ; i < m ; ++i) {
    getDiagonalValues(i, 0, mat, q);
    assignDiagonalValues(i, 0, res, q);
  }
  for (int j = 1 ; j < n ; ++j) {
    getDiagonalValues(0, j, mat, q);
    assignDiagonalValues(0, j, res, q);
  }
  return res;
}

int main(void) {
  int n;
  int m;
  cin >> m >> n;
  vector <vector <int> > mat(m, vector <int> (n));
  for (int i = 0 ; i < m ; ++i) {
    for (int j = 0 ; j < n ; ++j) {
      cin >> mat[i][j];
    }
  }
  vector <vector <int> > res = diagonalSort(mat);
  for (auto a : res) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  return 0;
}
