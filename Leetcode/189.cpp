/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector <int>& nums, int k) {
  if (nums.size() == 0 || nums.size() == 1 || k % nums.size() == 0) {
    return;
  }

  int newNumber = nums[0];
  int newPos = 0;
  int oldPos = 0;
  int oldNumber;
  int processedNums = 0;
  int iniPos = 0;
  while (processedNums < nums.size()) {
    do {
      newPos = (newPos + k) % nums.size();
      oldNumber = nums[newPos];
      nums[newPos] = newNumber;
      newNumber = oldNumber;
      processedNums++;
    } while (oldPos != newPos);
    oldPos++;
    newPos = oldPos;
    newNumber = nums[newPos];
  }
}

int main(void) {
  int k;
  int n;
  vector <int> nums;
  cin >> k;
  while (cin >> n) {
    nums.push_back(n);
  }
  rotate(nums, k);
  for (auto a : nums) {
    cout << a << " ";
  }
  cout << endl;
}
