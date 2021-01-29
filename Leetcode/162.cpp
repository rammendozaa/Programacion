/* Accepted */
#include <vector>
#include <iostream>
using namespace std;

int findPeakIndex (int ini, int fin, vector <int>& nums) {
  int mid;
  while (ini <= fin) {
    mid = ini + ((fin - ini) >> 1);
    if ((mid - 1 < 0 || nums[mid - 1] < nums[mid]) && (mid + 1 >= nums.size() ||
      nums[mid + 1] < nums[mid])) {
      return mid;
    }
    if (mid - 1 < 0 || nums[mid + 1] >= nums[mid]) {
      ini = mid + 1;
    } else {
      fin = mid - 1;
    }
  }
  return mid;
}

int findPeakElement(vector <int>& nums) {
  if (nums.size() == 1) {
    return 0;
  }
  return findPeakIndex(0, nums.size() - 1, nums);
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << findPeakElement(nums) << endl;
}
