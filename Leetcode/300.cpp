#include <iostream>
#include <vector>
using namespace std;
// for every small one take the max of the small one plus one and the current value at i
int lengthOfLIS(vector <int>& nums) {
  if (nums.size() < 2) {
    return nums.size();
  }
  vector <int> dp(nums.size(), 1);
  for (int i = 1 ; i < nums.size() ; ++i) {
    for (int j = i - 1 ; j >= 0 ; --j) {
      if (nums[j] < nums[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int maxCount = 1;
  for (auto a : dp) {
    maxCount = max(maxCount, a);
  }
  return maxCount;
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << lengthOfLIS(nums) << endl;
}
