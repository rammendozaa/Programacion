/* Accepted */
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int main (void) {
  int n;
  int height = 1e9;
  cin >> n;
  vector <int> nums(n);
  pair <int, int> pos;
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
  }

  for (int i = 0 ; i < n - 1 ; ++i) {
    if (abs(nums[i] - nums[i + 1]) < height) {
      pos.first = i;
      pos.second = i + 1;
      height = abs(nums[i] - nums[i + 1]);
    }
  }

  if (abs(nums[0] - nums[nums.size() - 1]) < height) {
    pos.first = 0;
    pos.second = nums.size() - 1;
  }

  cout << pos.first + 1 << " " << pos.second + 1 << endl;
}
