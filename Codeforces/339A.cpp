#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main (void) {
  vector <int> nums(3, 0);
  int total = 0;
  int count = 0;
  string in;
  cin >> in;
  for (auto a : in) {
    if (a != '+') {
      total++;
      nums[a - 49]++;
    }
  }
  for (int i = 0 ; i < 3 ; ++i) {
    while (nums[i] > 0) {
      if (count >= total - 1) {
        cout << i + 1;
      } else {
        cout << i + 1 << "+";
        count++;
      }
      nums[i]--;
    }
  }
  cout << endl;
  return 0;
}
