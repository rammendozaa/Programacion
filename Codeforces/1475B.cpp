/* Accepted */
#include <iostream>
using namespace std;

bool canBeExpressed(int n) {
  for (int i = 0 ; i <= 2020 ; ++i) {
    int sub = (n - (2021 * i));
    if (sub % 2020 == 0 && sub >= 0) {
      return true;
    }
  }
  return false;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int cases;
  int n;
  cin >> cases;
  while (cases--) {
    cin >> n;
    cout << (canBeExpressed(n) ? "YES\n" : "NO\n");
  }
  return 0;
}
