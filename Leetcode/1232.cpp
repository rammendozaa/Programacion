/* Accepted */
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair <int, int> reduceFraction(int x, int y) {
  if (x == 0 || y == 0) {
    return {0, 0};
  }
  if (x == y) {
    return {1,1};
  }
  if (abs(x) > abs(y)) {
    if (x % y == 0) {
      return {x / y, 1};
    } else {
      return {x, y};
    }
  }

  if (abs(x) < abs(y)) {
    if (y % x == 0) {
      return {1, y / x};
    } else
      return {x, y};
  }
  return {x, y};
}

bool checkVertical(vector <vector<int> >& coords) {
  int x = coords[0][0];
  for (auto a : coords) {
    if (a[0] != x) {
      return false;
    }
  }
  return true;
}

bool checkHorizontal(vector <vector<int> >& coords) {
  int y = coords[0][1];
  for (auto a : coords) {
    if (a[1] != y) {
      return false;
    }
  }
  return true;
}

bool checkDiagonal(vector <vector<int> >& coords) {
  int x, y, changeX, changeY;
  pair <int, int> firstChange, laterChange;
  firstChange = reduceFraction(coords[1][0] - coords[0][0], coords[1][1] - coords[0][1]);
  x = firstChange.first;
  y = firstChange.second;
  for (int i = 0 ; i < coords.size() - 1 ; ++i) {
    laterChange = reduceFraction(coords[i + 1][0] - coords[i][0], coords[i + 1][1] - coords[i][1]);
    changeX = laterChange.first;
    changeY = laterChange.second;

    if (changeX == 0 || changeY == 0) {
      return false;
    }

    if (changeX == x && changeY == y) {
      continue;
    } else if (changeX > x && changeY > y) {
      if (changeX % x != 0 || changeY % y != 0 || ((float)changeX / (float)x != (float)changeY / (float)y)) {
        return false;
      }
    } else if (changeX < x && changeY < y) {
      if (x % changeX != 0 || y % changeY != 0 || ((float)x / (float)changeX != (float)y / (float)changeY)) {
        return false;
      }
    } else {
      return false;
    }
  }

  return true;
}

bool checkStraightLine(vector <vector<int> >& coords) {
  int x, y;
  x = coords[1][0] - coords[0][0];
  y = coords[1][1] - coords[0][1];
  if (x == 0) {
    return checkVertical(coords);
  } else if (y == 0) {
    return checkHorizontal(coords);
  } else {
    return checkDiagonal(coords);
  }
}

int main(void) {
  int coord;
  cin >> coord;
  vector <vector <int> > coords(coord, vector <int> (2));
  for (int i = 0 ; i < coord ; i++) {
    cin >> coords[i][0] >> coords[i][1];
  }
  sort(coords.begin(), coords.end());
  cout << checkStraightLine(coords) << endl;
}
