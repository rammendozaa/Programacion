#include <vector>
#include <iostream>
using namespace std;

int main (void) {
  int posI = 0;
  int posJ = 0;
  int num;
  for (int i = 0 ; i < 5 ; ++i) {
    for (int j = 0 ; j < 5 ; ++j) {
      cin >> num;
      if (num == 1) {
        posI = i;
        posJ = j;
      }
    }
  }
  cout << (abs(posI - 2) + abs(posJ - 2)) << endl;
  return 0;
}
