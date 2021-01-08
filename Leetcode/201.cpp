/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

/*
  Between a number there is always going to be some bits to the right that are
  going to differ, so those will always give 0 when ANDing so we check the bits
  that are the same, because those will give us 1 if they're both turned on
  We shift bits to the right the number of times that the bits werent equal
*/

int rangeBitwiseAnd(int m, int n) {
  int left = 0;
  while (m != n) {
    m >>= 1;
    n >>= 1;
    left++;
  }
  return m << left;
}

int main(void) {
  int m, n, res;
  cin >> m >> n;
  cout << rangeBitwiseAnd(m, n) << endl;
}
