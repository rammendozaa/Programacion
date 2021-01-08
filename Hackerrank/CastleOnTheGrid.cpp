#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector <vector <int> > dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//                            right    down    left     up

bool validPos(int currI, int currJ, vector <vector <char> >& grid,
  vector <vector <int> >& visited) {
    return (currI >= 0 && currJ >= 0 && currI < grid.size() &&
      currJ < grid[0].size() && visited[currI][currJ] == 0);
}

void findMinMoves(queue <pair <int, int> > moves, int &minMoves) {
  pair <int, int> aux = moves.front();
  int numberMoves = 0;
  int size = moves.size();
  stack <pair<int, int> > s;
  while (!moves.empty()) {
    s.push(make_pair(aux.first - moves.front().first, aux.second - moves.front().second));
    aux = moves.front();
    moves.pop();
  }
  pair <int, int> auxS = s.top();
  while (!s.empty()) {
    if (auxS != s.top()) {
      numberMoves++;
      auxS = s.top();
    }
    s.pop();
  }

  minMoves = min(minMoves, numberMoves);
}

void minimumMoves(int currI, int currJ, int finI, int finJ,
  vector <vector <char> >& grid, vector <vector <int> >& visited,
  int& minMoves, queue <pair <int, int> > movements, queue <pair<int, int> > another) {
    if (!validPos(currI, currJ, grid, visited)) {
      movements.pop();
      return;
    }
    if (currI == finI && currJ == finJ) {
      movements.push(make_pair(currI, currJ));
      findMinMoves(another, minMoves);
      return;
    }

    movements.push(make_pair(currI, currJ));
    for (int i = 0 ; i < 4 ; ++i) {
      visited[currI][currJ] = 1;
      minimumMoves(currI + dir[i][0], currJ + dir[i][1], finI, finJ,
        grid, visited, minMoves, movements);
      visited[currI][currJ] = 0;
    }
    return;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int iniI;
  int iniJ;
  int finI;
  int finJ;
  int minMoves = 1e9;
  bool reached = false;
  cin >> n;
  vector <vector <char> > grid(n, vector <char> (n));
  // 0 not visited
  // 1 visited
  // -1 cant go
  vector <vector <int> > visited(n, vector <int> (n, 0));
  queue <pair <int, int> > movements;
  queue <pair <int, int> > another;
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < n ; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 'X') {
        visited[i][j] = -1;
      }
    }
  }
  cin >> iniI >> iniJ >> finI >> finJ;
  minimumMoves(iniI, iniJ, finI, finJ, grid, visited, minMoves, movements, another);
  cout << minMoves << endl;


}
