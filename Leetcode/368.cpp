/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

void getValues(vector <int>& nums, vector <int>& dp, vector <int>& res, int index, int maxCount) {
  int value = nums[index];
  index--;
  for (int i = index ; i >= 0 && maxCount > 0 ; --i) {
    if (dp[i] == maxCount && value % nums[i] == 0) {
      res.push_back(nums[i]);
      maxCount--;
      value = nums[i];
    }
  }
}

vector <int> largestDivisibleSubset(vector <int>& nums) {
  if (nums.size() == 0 || nums.size() == 1) {
    return nums;
  }
  sort(nums.begin(), nums.end());
  vector <int> dp(nums.size(), 1);
  for (int i = 1 ; i < nums.size() ; ++i) {
    for (int j = i - 1 ; j >= 0 ; --j) {
      if (nums[i] % nums[j] == 0) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  vector <int> res;
  int maxCount = 1;
  int index = 0;
  for (int i = dp.size() - 1 ; i >= 0 ; --i) {
    if (dp[i] > maxCount) {
      maxCount = dp[i];
      index = i;
    }
  }
  res.push_back(nums[index]);
  getValues(nums, dp, res, index, maxCount - 1);
  return res;
}

int main(void) {
  int n;
  vector <int> nums;
  vector <int> res;
  while (cin >> n) {
    nums.push_back(n);
  }
  res = largestDivisibleSubset(nums);
  for (auto a : res) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
