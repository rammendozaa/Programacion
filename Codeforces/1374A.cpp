/* Accepted */
#include <iostream>
using namespace std;

int main(void) {
  long long int n, m, x, y, cases;
  cin >> cases;
  while (cases--) {
    cin >> x >> y >> n;
    m = (n / x);
    (m * x + y <= n) ? cout << (m * x + y) : cout << ((m - 1) * x + y);
    cout << endl;
  }
}
