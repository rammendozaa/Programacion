/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector <int>& nums) {
  if (nums.size() == 0 || nums.size() == 1) {
    return nums.size();
  }
  int j = 1;
  int currPos = 1;
  int currValue = nums[0];
  while (j < nums.size()) {
    while (j < nums.size() && nums[j] <= currValue) {
      j++;
    }
    if (j < nums.size()) {
      swap(nums[j], nums[currPos]);
      currValue = nums[currPos];
      currPos++;
    }
  }
  return currPos;
}

int main(void) {
  vector <int> nums;
  int n;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << removeDuplicates(nums) << endl;
  for (auto a : nums) {
    cout << a << " ";
  }
  cout << endl;
}
