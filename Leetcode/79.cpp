/* Accepted */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void recursive(vector <vector <char> >& board, vector <vector <bool> >& visited,
  bool& found, int wordPos, string& word, int currI, int currJ) {
  if (wordPos >= word.length()) {
    found = true;
    return;
  }
  if (currI < 0 || currI >= board.size() || currJ < 0 || currJ >= board[0].size() ||
    visited[currI][currJ] || board[currI][currJ] != word[wordPos]) {
    return;
  }
  visited[currI][currJ] = true;
  recursive(board, visited, found, wordPos + 1, word, currI + 1, currJ);
  if (found) {
    return;
  }
  recursive(board, visited, found, wordPos + 1, word, currI - 1, currJ);
  if (found) {
    return;
  }
  recursive(board, visited, found, wordPos + 1, word, currI, currJ + 1);
  if (found) {
    return;
  }
  recursive(board, visited, found, wordPos + 1, word, currI, currJ - 1);
  if (found) {
    return;
  }
  visited[currI][currJ] = false;
}

bool exist(vector <vector <char> >& board, string word) {
  vector <vector <bool> > visited(board.size(), vector <bool> (board[0].size(), false));
  for (int i = 0 ; i < board.size() ; ++i) {
    for (int j = 0 ; j < board[0].size() ; ++j) {
      if (board[i][j] == word[0]) {
        bool found = false;
        recursive(board, visited, found, 0, word, i, j);
        if (found) {
          return true;
        }
      }
    }
  }
  return false;
}

int main(void) {
  int n;
  int m;
  cin >> n >> m;
  string word;
  cin >> word;
  vector <vector <char> > board(n, vector <char> (m));
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < m ; ++j) {
      cin >> board[i][j];
    }
  }
  cout << exist(board, word) << endl;
}
