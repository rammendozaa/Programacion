/* Accepted */
#include <iostream>
#include <cmath>
using namespace std;
#define ull unsigned long long int
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ull cases;
  ull n;
  cin >> cases;
  while (cases--) {
    cin >> n;
    if (n == 0 || n == 1) {
      cout << n << endl;
      continue;
    }
    ull square = 8 * n;
    square = (ull)round(sqrt((double)square) - (double)1) >> 1;
    if (((square) * (square + 1)) >> 1 > n) {
      cout << square - 1 << endl;
    } else {
      cout << (square) << endl;
    }
  }
}
