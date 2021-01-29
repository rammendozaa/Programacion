/* Accepted */
#include <vector>
#include <iostream>
using namespace std;

bool increasingTriplet(vector <int>& nums) {
  if (nums.size() < 3) {
    return false;
  }
  long long int currMin = UINT_MAX;
  long long int midMin = UINT_MAX;
  for (auto a : nums) {
    if (a < currMin) {
      currMin = a;
    }
    if (a > currMin && a < midMin) {
      midMin = a;
    }
    if (a > midMin) {
      return true;
    }
  }
  return false;
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << increasingTriplet(nums) << endl;
  return 0;
}
