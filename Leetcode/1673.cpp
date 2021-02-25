#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector <int> mostCompetitive(vector <int>& nums, int k) {
  deque <int> q;
  vector <int> res;
  q.push_front(nums[0]);
  int i = 1;
  int rem = nums.size() - k;
  while (i < nums.size()) {
    while (!q.empty() && q.back() > nums[i] && rem > 0) {
      q.pop_back();
      rem--;
    }
    q.push_back(nums[i]);
    i++;
  }
  i = 0;
  while (i < k) {
    res.push_back(q.front());
    q.pop_front();
    i++;
  }
  return res;
}

int main(void) {
  int k;
  int n;
  vector <int> nums;
  vector <int> res;
  cin >> k;
  while (cin >> n) {
    nums.push_back(n);
  }
  res = mostCompetitive(nums, k);
  for (auto a : res) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
