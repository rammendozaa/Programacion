/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int numRescueBoats(vector <int>& nums, int lim) {
  if (nums.size() == 1) {
    return 1;
  }
  int i = 0;
  int j = nums.size() - 1;
  int count = 0;
  sort(nums.begin(), nums.end(), greater <int>());
  while (i <= j) {
    if (nums[i] + nums[j] <= lim) {
      i++;
      j--;
    } else {
      i++;
    }
    count++;
  }
  return count;
}

int main(void) {
  int lim;
  int n;
  cin >> lim;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << numRescueBoats(nums, lim) << endl;
  return 0;
}
