/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int main (void) {
  int n;
  int input;
  cin >> n;
  vector <int> nums(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> input;
    nums[input - 1] = i + 1;
  }
  for (auto a : nums) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
