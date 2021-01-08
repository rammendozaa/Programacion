/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector <int>& nums) {
  if (nums.size () == 1) {
    return nums[0];
  }
  int ini, mid, fin, left, right;
  ini = 0;
  fin = nums.size() - 1;
  while (ini <= fin) {
    mid = (fin + ini) >> 1;
    if (mid > 0 && nums[mid - 1] == nums[mid]) {
      left = mid - 1;
      right = mid;
    } else if (mid < nums.size() - 1 && nums[mid + 1] == nums[mid]) {
      left = mid;
      right = mid + 1;
    } else {
      return nums[mid];
    }

    if (left % 2 == 0 && right % 2 != 0) {
      ini = mid + 1;
    } else if (left % 2 != 0 && right % 2 == 0) {
      fin = mid - 1;
    } else {
      return nums[mid];
    }
  }
  return nums[mid];
}

int main (void) {
  int n;
  cin >> n;
  vector <int> nums(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
  }
  cout << singleNonDuplicate(nums) << endl;
}
