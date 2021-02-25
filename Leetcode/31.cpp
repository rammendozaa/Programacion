/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int getPosOfBigger(int pos, vector <int>& nums) {
  int value = nums[pos];
  pair <int, int> valToPos = {nums[pos + 1], pos + 1};
  for (int i = pos + 2 ; i < nums.size() ; ++i) {
    if (nums[i] < valToPos.first && nums[i] > value) {
      valToPos.first = nums[i];
      valToPos.second = i;
    }
  }
  return valToPos.second;
}

void nextPermutation(vector <int>& nums) {
  if (nums.size() == 1) {
    return;
  }
  int i = nums.size() - 1;
  while (i > 0) {
    if (nums[i] > nums[i - 1]) {
      int pos = i - 1;
      int value = nums[i - 1];
      int nextPos = getPosOfBigger(pos, nums);
      swap(nums[pos], nums[nextPos]);
      if (pos + 1 < nums.size()) {
        sort(nums.begin() + pos + 1, nums.end());
        return;
      }
    }
    i--;
  }
  sort(nums.begin(), nums.end());
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  nextPermutation(nums);
  for (auto a : nums) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
