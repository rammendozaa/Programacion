#include <iostream>
#include <vector>
using namespace std;

/*
int helper(int index, int currProfit, int k, vector <int>& nums) {
  if (index >= nums.size() || k <= 0) {
    return currProfit;
  }
  int maxProfit = 0;
  for (int i = index + 1; i < nums.size() ; ++i) {
    if (nums[index] < nums[i]) {
      maxProfit = max(maxProfit, helper(i + 1, currProfit + (nums[i] - nums[index]), k--, nums));
    } else {
      maxProfit = max(maxProfit, helper(i + 1, currProfit, k, nums));
    }
  }
  return max(maxProfit, currProfit);
}

int maxProfit(int k, vector <int>& nums) {
  return helper(0, 0, k, nums);
}
*/

int maxProfitRec(int i, int j, int k, vector <int>& nums, vector <vector <int> >& dp) {
  if (i >= k || j >= nums.size()) {
    return 0;
  }
  if (dp[i][j] == -1) {
    int maxP = maxProfitRec(i, j + 1, k, nums, dp);
    for (int index = j + 1 ; index < nums.size() ; ++index) {
      if (nums[index] > nums[j]) {
        //cout << i << " " << index << endl;
        maxP = max(maxP, ((nums[index] - nums[j]) + maxProfitRec(i + 1, index + 1, k, nums, dp)));
      }
    }
    dp[i][j] = maxP;
  }
  return dp[i][j];
}

int maxProfit(int k, vector <int>& nums) {
  if (nums.size() == 1 || nums.size() == 0 || k == 0) {
    return 0;
  }
  int size;
  if (k > nums.size()) {
    size = nums.size();
  }
  if (k < nums.size()) {
    size = k;
  }
  vector <vector <int> > dp(size + 1, vector <int> (nums.size() + 1, -1));
  return maxProfitRec(0, 0, k, nums, dp);
  /*
  for (auto a : dp) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  return res;
  */
}

int main(void) {
  int n, k;
  cin >> n >> k;
  vector <int> nums(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
  }
  cout << maxProfit(k, nums) << endl;
}
