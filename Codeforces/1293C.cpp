/* Accepted */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool checkForBlock (vector <vector <char> >& board, int c, int r, int& blocks, int& sameblocks) {
  if (board[c][r] != board[c][r ^ 1] && board[c][r] == '0') {
    sameblocks++;
  } else if (board[c][r] == board[c][r ^ 1] && board[c][r] == '1') {
    sameblocks--;
  }

  if (board[c - 1][r ^ 1] == '1' && board[c][r] == '0') {
    blocks++;
  } else if (board[c - 1][r ^ 1] == '1' && board[c][r] == '1') {
    blocks--;
  }

  if (board[c + 1][r ^ 1] == '1' && board[c][r] == '0') {
    blocks++;
  } else if (board[c + 1][r ^ 1] == '1' && board[c][r] == '1') {
    blocks--;
  }

  board[c][r] = (board[c][r] == '0') ? '1' : '0';
  return !((blocks == 0) && (sameblocks == 0));
}

int main (void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q, c, r, blocks, sameblocks;
  bool isThereBlock;
  cin >> n >> q;
  vector <vector <char> > board(n + 2, vector <char> (2, '0'));
  blocks = 0;
  sameblocks = 0;
  isThereBlock = false;
  for (int i = 0 ; i < q ; ++i) {
    cin >> r >> c;
    r--;
    (checkForBlock(board, c, r, blocks, sameblocks)) ? cout << "No\n" : cout << "Yes\n";
  }

  return 0;
}
