/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector <int>& nums) {
  if (nums.size() == 0 || nums.size() == 1) {
    return;
  }
  int i = 0;
  int j = nums.size() - 1;
  int k;
  while (i < nums.size() && nums[i] == 0) {
    i++;
  }
  while (j >= 0 && nums[j] == 2) {
    j--;
  }
  if (i == nums.size() || j == 0 || i == j) {
    return;
  }
  k = i;
  while (k <= j && i <= j) {
    if (nums[k] == 0) {
      swap(nums[k], nums[i]);
      i++;
    } else if (nums[k] == 2) {
      swap(nums[k], nums[j]);
      j--;
    } else {
      k++;
      continue;
    }
    while (i < nums.size() && nums[i] == 0) {
      i++;
    }
    while (j >= 0 && nums[j] == 2) {
      j--;
    }
    if (i == nums.size() || j == 0 || i == j) {
      return;
    }
    k = i;
    for (auto a : nums) {
      cout << a << " ";
    }
    cout << endl;
  }
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  sortColors(nums);
  for (auto a : nums) {
    cout << a << " ";
  }
  cout << endl;

  return 0;
}
