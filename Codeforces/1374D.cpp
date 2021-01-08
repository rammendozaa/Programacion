/* Accepted */
#include <iostream>
#include <queue>
#include <map>
using namespace std;

long long int solve(vector <long long int>& nums, long long int k) {
  long long int rem, maxRem = 0;
  map <long long int, long long int> countNums;
  for (auto a : nums) {
    rem = (a % k == 0) ? 0 : (((a / k) + 1) * k) - a;
    countNums[rem]++;
  }

  for (auto a : countNums) {
    if (a.first != 0) {
      maxRem = max(maxRem, 1 + (a.first + (k * (a.second - 1))));
    }
  }
  return maxRem;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cases;
  cin >> cases;
  while (cases--) {
    int size;
    long long int k, in;
    cin >> size >> k;
    vector <long long int> nums(size);
    for (int i = 0 ; i < size ; ++i) {
      cin >> nums[i];
    }
    cout << solve(nums, k) << endl;
  }
}
