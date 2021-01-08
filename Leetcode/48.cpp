/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector <vector <int> >& board) {
  for (int i = 0 ; i < board.size() >> 1 ; ++i) {
    for (int j = 0 ; j < board[0].size() ; ++j) {
      swap(board[i][j], board[board.size() - 1 - i][j]);
    }
  }

  for (int i = 0 ; i < board.size() ; ++i) {
    for (int j = i + 1 ; j < board.size() ; ++j) {
      swap(board[i][j], board[j][i]);
    }
  }
}

int main(void) {
  int n;
  cin >> n;
  vector <vector <int> > board(n, vector <int> (n, 0));
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < n ; ++j) {
      cin >> board[i][j];
    }
  }
  rotate(board);
  for (auto a : board) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
}
