/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
  if (nums.size() < 2) {
    return 0;
  }
  int minVal = 1e9;
  int maxVal = 0;
  for (auto a : nums) {
    minVal = min(minVal, a);
  }
  if (minVal < 0) {
    for (int i = 0 ; i < nums.size() ; ++i) {
      nums[i] += abs(minVal);
    }
  }
  for (auto a : nums) {
    maxVal = max(maxVal, a);
  }
  vector <int> auxV(maxVal + 1, 0);
  vector <int> newVector;
  for (auto a : nums) {
    auxV[a]++;
  }
  for (int i = 0 ; i < auxV.size() ; ++i) {
    while (auxV[i]--) {
      newVector.push_back(i);
    }
  }

  int i = 0;
  int j = newVector.size() - 1;
  while (i < j) {
    if (nums[i] != newVector[i] && nums[j] != newVector[j]) {
      return (j - i + 1);
    }
    while (i < newVector.size() && nums[i] == newVector[i]) {
      i++;
    }
    while (j >= 0 && nums[j] == newVector[j]) {
      j--;
    }
  }
return 0;
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
}
