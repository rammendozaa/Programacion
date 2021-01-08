/* Accepted */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findCircleNum(vector<vector<int>>& board) {
  int n = board.size();
  int count = 0;
  if (n == 1) {
    return 1;
  }

  vector <int> graph(n);
  for (int i = 0 ; i < n ; ++i) {
    graph[i] = i;
  }

  vector <vector <int> > adj;
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < i ; ++j) {
      if (board[i][j] == 1) {
        adj.push_back({min(i,j), max(i, j)});
      }
    }
  }

  for (auto a : adj) {
    int sets, takes;
    sets = a[0];
    while (graph[sets] != sets) {
      sets = graph[sets];
    }
    takes = a[1];
    while (graph[takes] != takes) {
      takes = graph[takes];
    }
    graph[takes] = sets;
  }

  for (int i = 0 ; i < n ; ++i) {
    if (graph[i] == i) {
      count++;
    }
  }

  return count;
}

int main (void) {
  int n;
  cin >> n;
  vector <vector <int> > board(n, vector <int>(n, 0));
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < n ; ++j) {
      cin >> board[i][j];
    }
  }
  cout << findCircleNum(board) << endl;
}
