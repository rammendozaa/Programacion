/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int findTarget (vector <int>& nums, int target) {
  int mid, ini, fin;
  ini = 0;
  fin = nums.size() - 1;
  while (ini <= fin) {
    mid = (ini + fin) >> 1;
    if (nums[mid] == target) {
      return mid;
    }
    if (nums[mid] < target) {
      ini = mid + 1;
    } else {
      fin = mid - 1;
    }
  }
  return -1;
}

int findLeft (vector <int>& nums, int pos, int target) {
  int mid, ini, fin;
  ini = 0;
  fin = pos;
  if (nums[ini] == target) {
    return 0;
  }

  while (ini <= pos) {
    mid = (ini + fin) >> 1;
    if (nums[mid] == target && nums[mid - 1] < target) {
      return mid;
    }
    if (nums[mid] == target && nums[mid - 1] == target) {
      fin = mid - 1;
    } else {
      ini = mid + 1;
    }
  }
  return mid;
}

int findRight (vector <int>& nums, int pos, int target) {
  int mid, ini, fin;
  ini = pos;
  fin = nums.size() - 1;
  if (nums[fin] == target) {
    return fin;
  }

  while (ini <= fin) {
    mid = (ini + fin) >> 1;
    if (nums[mid] > target && nums[mid - 1] == target) {
      return mid - 1;
    }

    if (nums[mid] > target && nums[mid - 1] > target) {
      fin = mid - 1;
    } else {
      ini = mid + 1;
    }
  }
  return mid;
}

vector <int> searchRange (vector <int>& nums, int target) {
  int pos = findTarget(nums, target), left, right;
  if (pos == -1) {
    return {-1, -1};
  }
  left = findLeft(nums, pos, target);
  right = findRight(nums, pos, target);
  return {left, right};
}

int main(void) {
  int size, target;
  cin >> size >> target;
  vector <int> nums(size);
  for (int i = 0 ; i < size ; ++i) {
    cin >> nums[i];
  }
  vector <int> res = searchRange(nums, target);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}
