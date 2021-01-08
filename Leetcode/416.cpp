/* Accepted */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
int rec(int i, int j, int target, vector <int>& nums, vector <vector <int> >& dp) {
  if (i >= nums.size() || j > target) {
    return 0;
  }
  if (j == target) {
    return 1;
  }
  cout << i << " " << j << endl;
  if (dp[i][j] == -1) {
    dp[i][j] = max(rec(i + 1, j + nums[i], target, nums, dp), rec(i + 1, j, target, nums, dp));
  }
  return dp[i][j];
}

bool canPartition(vector <int>& nums) {
  if (nums.size() == 0 || nums.size() == 1) {
    return false;
  }
  int sum = 0;
  for (auto a : nums) {
    sum += a;
  }
  if (sum % 2 != 0) {
    return false;
  }
  vector <vector <int> > dp((nums.size()) + 1, vector <int> ((sum >> 1) + 1, -1));
  for (auto a : dp) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  int res = rec(0, 0, sum >> 1, nums, dp);
  return res == 1;
}
*/

bool canPartition(vector <int>& nums) {
  if (nums.size() == 0 || nums.size() == 1) {
    return false;
  }
  int sum = 0;
  for (auto a : nums) {
    sum += a;
  }
  if (sum % 2 != 0) {
    return false;
  }
  vector <vector <bool> > dp((nums.size()) + 1, vector <bool> ((sum >> 1) + 1, false));
  dp[0][0] = true;
  for (int i = 1 ; i <= nums.size() ; ++i) {
    dp[i][0] = true;
    for (int j = 1 ; j <= (sum >> 1) ; ++j) {
      dp[i][j] = (j - nums[i - 1] >= 0) ? (dp[i - 1][j] || dp[i - 1][j - nums[i - 1]]) : dp[i - 1][j];
    }
  }
  for (auto a : dp) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  return dp[nums.size()][(sum >> 1)];
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << canPartition(nums) << endl;
}
