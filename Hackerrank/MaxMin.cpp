// Accepted
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int n;
  int k;
  cin >> n >> k;
  vector <int> nums(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  int minDif = 1e9 * 2;
  for (int i = 0, j = k - 1 ; i <= n - k ; ++i, ++j) {
    minDif = min(minDif, nums[j] - nums[i]);
  }
  cout << minDif << endl;
}
