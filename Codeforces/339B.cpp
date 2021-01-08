#include <iostream>
using namespace std;

int main (void) {
  long long int n, t;
  cin >> n >> t;
  long long int pos = 1;
  long long int sum = 0;
  long long int input;
  for (long long int i = 1 ; i <= t ; ++i) {
    cin >> input;
    sum += (input < pos) ? (n - pos + input) : input - pos;
    pos = input;
  }
  cout << sum << endl;
  return 0;
}
