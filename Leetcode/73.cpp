/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

void setColumnAndRow(int row, int column, vector <vector <int> >& mat) {
  for (int i = 0 ; i < mat.size() ; ++i) {
    mat[i][column] = 0;
  }
  for (int j = 0 ; j < mat[0].size() ; ++j) {
    mat[row][j] = 0;
  }
}

void setColumn(int column, vector <vector <int> >& mat) {
  for (int i = 0 ; i < mat.size() ; ++i) {
    mat[i][column] = 0;
  }
}

void setRow(int row, vector <vector <int> >& mat) {
  for (int j = 0 ; j < mat[0].size() ; ++j) {
    mat[row][j] = 0;
  }
}

void setZeroes(vector <vector <int> >& mat) {
  if (mat.size() == 1 && mat[0].size() == 1) {
    return;
  }
  int m = mat.size() - 1;
  int n = mat[0].size() - 1;
  bool topLeft = (mat[0][0] == 0);
  bool topRight = (mat[0][n] == 0);
  bool bottomLeft = (mat[m][0] == 0);
  bool bottomRight = (mat[m][n] == 0);
  bool left = false;
  bool right = false;
  bool top = false;
  bool bottom = false;
  for (int i = 1 ; i < m ; ++i) {
    if (mat[i][0] == 0) {
      left = true;
      break;
    }
  }
  for (int i = 1 ; i < m ; ++i) {
    if (mat[i][n] == 0) {
      right = true;
      break;
    }
  }
  for (int j = 1 ; j < n ; ++j) {
    if (mat[0][j] == 0) {
      top = true;
      break;
    }
  }
  for (int j = 1 ; j < n ; ++j) {
    if (mat[m][j] == 0) {
      bottom = true;
      break;
    }
  }
  for (int i = 1 ; i < m ; ++i) {
    for (int j = 1 ; j < n ; ++j) {
      cout << mat[i][j] << endl;
      if (mat[i][j] == 0) {
        mat[i][0] = 0;
        mat[0][j] = 0;
      }
    }
  }
  for (int i = 1 ; i < m ; ++i) {
    if (mat[i][0] == 0) {
      setRow(i, mat);
    }
  }
  for (int i = 1 ; i < m ; ++i) {
    if (mat[i][n] == 0) {
      setRow(i, mat);
    }
  }
  for (int j = 1 ; j < n ; ++j) {
    if (mat[0][j] == 0) {
      setColumn(j, mat);
    }
  }
  for (int j = 1 ; j < n ; ++j) {
    if (mat[m][j] == 0) {
      setColumn(j, mat);
    }
  }

  if (top) {
    setRow(0, mat);
  }
  if (bottom) {
    setRow(m, mat);
  }
  if (left) {
    setColumn(0, mat);
  }
  if (right) {
    setColumn(n, mat);
  }

  if (topLeft) {
    setRow(0, mat);
    setColumn(0, mat);
  }
  if (topRight) {
    setRow(0, mat);
    setColumn(n, mat);
  }
  if (bottomLeft) {
    setRow(m, mat);
    setColumn(0, mat);
  }
  if (bottomRight) {
    setRow(m, mat);
    setColumn(n, mat);
  }
  for (auto a : mat) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  cout << endl;
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
  for (auto a : mat) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  cout << endl;
  setZeroes(mat);
  for (auto a : mat) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
