/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int reverse(int x) {
  if (x == 0) {
    return 0;
  }
  bool isNeg = (x < 0);
  x = abs(x);
  vector <long long int> number(11, 0);
  long long int auxN;
  long long int count = 1;
  long long int pos = 0;
  long long int sum = 0;
  while (x > 0) {
    auxN = x % 10;
    number[pos] = auxN;
    pos++;
    x /= 10;
    count *= 10;
  }
  count /= 10;
  long long int i = 0;
  while (count > 0) {
    sum += (count * number[i]);
    if (sum > INT_MAX) {
      return 0;
    }
    count /= 10;
    i++;
  }
  return (isNeg) ? -1 * sum : sum;
}

int main(void) {
  int n;
  while (cin >> n)
    cout << reverse(n) << endl;
}
