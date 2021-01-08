/* Accepted */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// can do with heap - done
// can also do with deque - done

vector <int> maxSlidingWindow(vector <int>& nums, int k) {
    if (nums.size() == 0 || k == 0 || k == 1) {
      return nums;
    }
    deque <int> ind;
    vector <int> res;
    int maxV;
    ind.push_front(0);
    for (int i = 1 ; i < k ; ++i) {
      while (!ind.empty() && nums[ind.back()] <= nums[i]) {
        ind.pop_back();
      }
      if (ind.empty() || nums[i] >= nums[ind.front()]) {
        ind.push_front(i);
      } else if (nums[i] <= nums[ind.back()]) {
        ind.push_back(i);
      }
    }
    res.push_back(nums[ind.front()]);
    for (int i = k ; i < nums.size() ; ++i) {
      while (!ind.empty() && i - ind.front() >= k) {
        ind.pop_front();
      }
      while (!ind.empty() && (nums[ind.back()] <= nums[i] || i - ind.back() >= k)) {
        ind.pop_back();
      }

      if (ind.empty() || (!ind.empty() && nums[i] >= nums[ind.front()])) {
        ind.push_front(i);
      } else if (!ind.empty() && nums[i] <= nums[ind.back()]) {
        ind.push_back(i);
      }
      res.push_back(nums[ind.front()]);
    }
    return res;
}

int main(void) {
  int n, k;
  cin >> n >> k;
  vector <int> nums(n);
  vector <int> res;
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
  }
  res = maxSlidingWindow(nums, k);
  for (auto a : res) {
    cout << a << " ";
  }
  cout << endl;
}
