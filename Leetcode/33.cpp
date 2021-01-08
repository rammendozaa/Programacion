/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int findChangePos(vector <int>& nums) {
  if (nums[0] < nums[nums.size() - 1]) {
    return 0;
  }
  if (nums[0] > nums[1]) {
      return 1;
  }
  int ini, fin, mid;
  ini = 0;
  fin = nums.size() - 2;
  while (ini <= fin) {
    mid = ini + ((fin - ini) >> 1);
    if (nums[0] > nums[mid + 1] && nums[0] < nums[mid]) {
      return mid + 1;
    }
    if (nums[0] > nums[mid + 1] && nums[0] > nums[mid]) {
      fin = mid - 1;
    } else {
      ini = mid + 1;
    }
  }
  return mid + 1;
}

int binarySearch(int ini, int fin, vector <int>& nums, int target) {
  int mid = 0;
  while (ini <= fin) {
    mid = ini + ((fin - ini) >> 1);
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[mid] > target) {
      fin = mid - 1;
    } else {
      ini = mid + 1;
    }
  }
  return (nums[mid] == target) ? mid : -1;
}

int search(vector <int>& nums, int target) {
  if (nums.size() == 0) {
    return -1;
  }
  if (nums.size() == 1) {
    return (nums[0] == target) ? 0 : -1;
  }
  int changePosL = findChangePos(nums);
  int changePosR = changePosL;
  int pos = -1;
  if (changePosL - 1 >= 0) {
    changePosL--;
    changePosR = changePosL + 1;
  } else {
    changePosL = 0;
    changePosR = 0;
  }
  if (target >= nums[0] && target <= nums[changePosL]) {
    pos = binarySearch(0, changePosL, nums, target);
  } else {
    pos = binarySearch(changePosR, nums.size() - 1, nums, target);
  }
  return pos;
}

int main (void) {
  int n, k;
  cin >> n >> k;
  vector <int> nums(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
  }
  cout << search(nums, k) << endl;
}
