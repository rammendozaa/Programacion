/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

vector <vector <int> > merge(vector <vector <int> >& nums) {
  if (nums.size() <= 1) {
    return nums;
  }
  sort(nums.begin(), nums.end());
  vector <vector <int> > res;
  res.push_back(nums[0]);
  int i = 1;
  while (i < nums.size()) {
    if (res.back()[1] >= nums[i][0]) {
      res.back()[1] = max(res.back()[1], nums[i][1]);
    } else {
      res.push_back(nums[i]);
    }
    i++;
  }
  return res;
}

int main(void) {
  int n;
  cin >> n;
  vector <vector <int> > nums(n, vector <int> (2));
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i][0] >> nums[i][1];
  }
  vector <vector <int> > res = merge(nums);
  for (auto a : res) {
    cout << a[0] << " " << a[1] << endl;
  }
  cout << endl;
  return 0;
}
