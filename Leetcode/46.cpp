/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

void helper(int ini, int fin, vector <int>& nums, vector <vector <int> >& res) {
  if (ini == fin) {
    res.push_back(nums);
    return;
  }
  for (int i = ini ; i <= fin ; ++i) {
    swap(nums[i], nums[ini]);
    helper(ini + 1, fin, nums, res);
    swap(nums[i], nums[ini]);
  }
}

vector <vector <int> > permutations(vector <int>& nums) {
  if (nums.size() == 1) {
    return {nums};
  }
  vector <vector <int> > res;
  helper(0, nums.size() - 1, nums, res);
  return res;
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  vector <vector <int> > res = permutations(nums);
  cout << endl;
  for (auto a : res) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
}
