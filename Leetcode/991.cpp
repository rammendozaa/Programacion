#include <iostream>
#include <vector>
using namespace std;

int brokenCalc(int x, int y) {
  if (x >= y) {
    return (x - y);
  }
  int moves = 0;
  while (y > x) {
    if (y % 2 != 0) {
      y++;
      moves++;
    }
    y >>= 1;
    moves++;
  }
  return moves + (x - y);
}

int main(void) {
  int x;
  int y;
  while (cin >> x >> y) {
    cout << brokenCalc(x, y) << endl;
  }
  return 0;
}
