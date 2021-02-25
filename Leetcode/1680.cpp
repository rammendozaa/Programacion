/* Accepted */
#include <iostream>
#include <cmath>
using namespace std;

int concatenatedBinary(int n) {
  long long int val = 1;
  if (n == 1) {
    return val;
  }
  long long int currN = 2;
  long long int spaces;
  while (currN <= n) {
    spaces = (long long int)floor((double)log10((double)currN) / (double)log10((double)2));
    spaces++;
    val = ((long long int)(val * (pow(2, spaces))) % (long long int)(1e9 + 7)) + currN;
    val %= (long long int)(1e9 + 7);
    currN++;
  }
  return val;
}

int main(void) {
  int n;
  while (cin >> n) {
    cout << concatenatedBinary(n) << endl;
  }
  return 0;
}
