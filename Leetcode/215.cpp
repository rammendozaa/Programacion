/* Accepted */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
  priority_queue <int, vector <int>, greater <int> > q;
  int i = 0;
  while (i < k) {
    q.push(nums[i]);
    i++;
  }
  while (i < nums.size()) {
    if (nums[i] > q.top()) {
      q.pop();
      q.push(nums[i]);
    }
    i++;
  }
  return q.top();
}

int main(void) {
  int k;
  int n;
  cin >> k;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << findKthLargest(nums, k) << endl;
}
