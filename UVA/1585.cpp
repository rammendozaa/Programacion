/* Accepted */
#include <iostream>
#include <string>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int cases;
  int totalSum;
  int consecutive;
  string result;
  cin >> cases;
  while (cases--) {
    cin >> result;
    totalSum = 0;
    consecutive = 0;
    for (auto a : result) {
      if (a == 'O') {
        consecutive++;
      } else {
        consecutive = 0;
      }
      totalSum += consecutive;
    }
    cout << totalSum << endl;
  }
}
