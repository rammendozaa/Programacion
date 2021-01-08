/* Accepted */
#include <iostream>
using namespace std;

long long int solve(long long int num) {
  int times = 0;
  while (num != 1) {
    while (num % 6 == 0) {
      times++;
      num /= 6;
    }
    if (num == 1) {
      return times;
    }
    if (num % 3 == 0) {
      times++;
      num *= 2;
    } else {
      return -1;
    }
  }
  return times;
}

int main(void) {
  int cases;
  cin >> cases;
  while (cases--) {
    long long int num;
    cin >> num;
    cout << solve(num) << endl;
  }
}
