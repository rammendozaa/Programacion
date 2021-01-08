/* Accepted */
#include <vector>
#include <iostream>
using namespace std;

bool isSectionValid(vector <int>& valid) {
  for (auto a : valid) {
    if (a > 1) {
      return false;
    }
  }
  return true;
}

bool isVerticalValid(vector <vector <char> >& board, int column) {
  vector <int> valid(9, 0);
  for (int i = 0 ; i < 9 ; ++i) {
    if (board[i][column] != '.') {
      valid[(board[i][column] - '0') - 1]++;
    }
  }
  return isSectionValid(valid);
}

bool isHorizontalValid(vector <vector <char> >& board, int row) {
  vector <int> valid(9, 0);
  for (int i = 0 ; i < 9 ; ++i) {
    if (board[i][row] != '.') {
      valid[(board[row][i] - '0') - 1]++;
    }
  }
  return isSectionValid(valid);
}

bool isSquareValid(vector <vector <char> >& board,
  int iniI, int endI, int iniJ, int endJ) {
    vector <int> valid(9, 0);
    for (int i = iniI ; i <= endI ; ++i) {
      for (int j = iniJ ; j <= endJ ; ++j) {
        if (board[i][j] != '.') {
          valid[(board[i][j] - '0') - 1]++;
        }
      }
    }
    return isSectionValid(valid);
  }

bool isValidSudoku(vector <vector <char> >& board) {
  for (int i = 0 ; i < 9 ; ++i) {
    if (!isVerticalValid(board, i)) {
      return false;
    }
  }

  for (int i = 0 ; i < 9 ; ++i) {
    if (!isHorizontalValid(board, i)) {
      return false;
    }
  }
  for (int i = 0 ; i < 9 ; i += 3) {
    for (int j = 0 ; j < 9 ; j += 3) {
      if (!isSquareValid(board, i, i + 2, j, j + 2)) {
      return false;
      }
    }
  }

  return true;
}

int main(void) {
  vector <vector <char> > board(9, vector <char> (9, '.'));
  for (int i = 0 ; i < 9 ; ++i) {
    for (int j = 0 ; j < 9 ; ++j) {
      cin >> board[i][j];
    }
  }
  cout << isValidSudoku(board) << endl;
}
