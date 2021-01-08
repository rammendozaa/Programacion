/* Accepted */
#include <iostream>
using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, v;
  while (cin >> t >> v) {
    cout << (t * v * 2) << endl;
  }
  return 0;
}
