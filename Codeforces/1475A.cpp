/* Accepted */
#include <iostream>
using namespace std;

int oddDivisor(long long int number) {
  while (number % 2 == 0) {
    number >>= 1;
  }
  return number;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int cases;
  cin >> cases;
  while (cases--) {
    long long int n;
    cin >> n;
    if (oddDivisor(n) == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
