/* Accepted */
#include <iostream>
using namespace std;

long long int findRes(long long int dividend, long long int divisor) {
  long long int mid, ini, fin;
  ini = 0;
  fin = dividend;
  while (ini <= fin) {
    mid = (ini + fin) >> 1;
    if (divisor * mid == dividend || (divisor * mid < dividend && divisor * (mid + 1) > dividend)) {
      return mid;
    }
    if (divisor * mid < dividend) {
      ini = mid + 1;
    } else {
      fin = mid - 1;
    }
  }
  return mid;
}

long long int divide(long long int dividend, long long int divisor) {
  if (dividend == 0 || abs(dividend) < abs(divisor)) {
    return 0;
  }

  if (dividend < 0 && abs(dividend) == 2147483648 && divisor == 1) {
    return -2147483648;
  }

  if (dividend < 0 && abs(dividend) == 2147483648 && divisor == -1) {
    return 2147483647;
  }

  long long int res;
  bool isResNeg = false;
  if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
    isResNeg = true;
  }
  if (abs(divisor) == abs(dividend)) {
    return (isResNeg) ? -1 : 1;
  }
  if (abs(divisor) == 1) {
    res = dividend;
    return (isResNeg) ? (-1 * res) : res;
  }
  res = findRes(abs(dividend), abs(divisor));
  return (isResNeg) ? (-1 * res) : res;
}

int main (void) {
  long long int dividend, divisor;
  cin >> dividend >> divisor;
  cout << divide(dividend, divisor) << endl;
}
