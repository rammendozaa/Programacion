/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector <int>& nums) {
  if (nums.size() == 0) {
    return true;
  }
  if (nums.size() == 1) {
    return nums[0] != 0;
  }
  bool ableLast = false;
  for (int i = nums.size() - 2 ; i >= 0 ; --i) {
    if (nums[i] >= i) {
      ableLast = true;
      break;
    }
  }
  if (!ableLast) {
    return false;
  }
  for (int i = nums.size() - 2 ; i >= 0 ; --i) {
    if (nums[i] == 0) {
    bool ableJump = false;
      for (int j = i - 1 ; j >= 0 ; --j) {
        if (nums[j] >= i + 1) {
          ableJump = true;
          break;
        }
      }
      if (!ableJump) {
        return false;
      }
    }
  }
  return true;
}

int main(void) {
  vector <int> nums;
  int n;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << canJump(nums) << endl;
}
