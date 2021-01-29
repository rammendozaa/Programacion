#include <iostream>
#include <vector>
using namespace std;

void helper(int i, vector <int>& nums, vector <int> curr,
  vector <vector <int> >& res) {
  if (i >= nums.size()) {
    res.push_back(curr);
    return;
  }
  helper(i + 1, nums, curr, res);
  curr.push_back(nums[i]);
  helper(i + 1, nums, curr, res);
}

vector <vector <int> > subsets(vector <int>& nums) {
  vector <vector <int> > res;
  vector <int> curr;
  int i = 0;
  helper(i, nums, curr, res);
  return res;
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  vector <vector <int> > res = subsets(nums);
  for (auto a : res) {
    for (auto b : a) {
      cout << b << endl;
    }
    cout << endl;
  }
}
