/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

bool validDiag(vector <vector <int> >& board, int diag, int i, int j) {
  return ((i - diag) >= 0 && (j - diag) >= 0 && board[i][j] + board[i - diag][j - diag] - board[i - diag][j] - board[i][j - diag] == (diag * diag));
}

int binary (int i, int j, vector <vector <int> >& board) {
  int ini = 0;
  int fin = min(i, j);
  int mid;
  while (ini <= fin) {
    mid = (ini + fin) >> 1;
    bool here, next;
    here = validDiag(board, mid, i, j);
    next = validDiag(board, mid + 1, i, j);
    if (here && !next) {
      return mid;
    }
    if (!here && !next) {
      fin = mid - 1;
    } else {
      ini = mid + 1;
    }
  }
  return 0;
}

int countSquares(vector <vector <int> >& board) {
  if (board.size() == 0) {
    return 0;
  }
  int n = board.size();
  int m = board[0].size();
  int res = 0;
  vector <vector <int> > sum(n + 1, vector <int>(m + 1, 0));
  for (int i = 1 ; i <= n ; ++i) {
    for (int j = 1 ; j <= m ; ++j) {
      sum[i][j] = board[i - 1][j - 1] + sum[i][j - 1];
    }
  }
  for (int j = 1 ; j <= m ; ++j) {
    for (int i = 1 ; i <= n ; ++i) {
      sum[i][j] += sum[i - 1][j];
    }
  }
  /*
  for (auto a : sum) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  cout << endl;
  */
  for (int i = 1 ; i <= n ; ++i) {
    for (int j = 1 ; j <= m ; ++j) {
      res += binary(i, j, sum);
    }
  }
  return res;
}

// Also accepted
int countSquares(vector <vector <int> >& board) {
  int count = 0;
  for (int i = 0 ; i < board.size() ; ++i) {
    for (int j = 0 ; j < board[0].size() ; ++j) {
      if (board[i][j] && (i - 1 >= 0) && (j - 1 >= 0)) {
        board[i][j] = 1 + (min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])));
      }
      count += board[i][j];
    }
  }
  return count;
}

int main (void) {
  int n, m;
  cin >> n >> m;
  vector <vector <int> > board(n, vector <int>(m, 0));
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < m ; ++j) {
      cin >> board[i][j];
    }
  }
  cout << countSquares(board) << endl;
}
