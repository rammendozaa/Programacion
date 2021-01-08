/* Accepted */
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool checkMultiset(multiset <long long int>& values, long long int t) {
  for (multiset <long long int>::iterator it = values.begin() ; it != values.end() && next(it) != values.end() ; ++it) {
    if (abs(*it - *next(it)) <= t) {
      return true;
    }
  }
  return false;
}

bool containsNearbyAlmostDuplicate(vector <long long int>& nums, long long int k, long long int t) {
  if (k == 0 || nums.size() == 1 || nums.size () == 0) {
    return false;
  }
  
  multiset <long long int> values;
  multiset <long long int>::iterator it;
  multiset <long long int>::iterator after;
  multiset <long long int>::iterator before;
  for (long long int i = 0 ; i <= k && i < nums.size() ; ++i) {
    values.insert(nums[i]);
  }

  if (checkMultiset(values, t)) {
    return true;
  }

  for (long long int i = k + 1 ; i < nums.size() ; ++i) {
    multiset<long long int>::iterator auxIt(values.find(nums[i - k - 1]));
    if (auxIt != values.end()) {
      values.erase(auxIt);
    }
    values.insert(nums[i]);
    it = values.find(nums[i]);
    if (it != values.begin()) {
      before = prev(it);
      if (abs(*before - *it) <= t) {
        return true;
      }
    }
    if (next(it) != values.end()) {
      after = next(it);
      if (abs(*after - *it) <= t) {
        return true;
      }
    }
  }
  return false;
}

int main(void) {
  long long int n, t, k;
  cin >> n >> k >> t;
  vector <long long int> nums(n);
  for (long long int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
  }
  cout << containsNearbyAlmostDuplicate(nums, k, t) << endl;
}
