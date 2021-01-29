/* Accepted */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector <int> topKFrequent(vector <int>& nums, int k) {
  priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
  unordered_map <int, int> numToCount;
  vector <int> res;
  vector <pair <int, int> > numToCountVector;
  for (auto a : nums) {
    numToCount[a]++;
  }
  for (auto a : numToCount) {
    numToCountVector.push_back(make_pair(a.second, a.first));
  }
  int i = 0;
  while (i < k) {
    q.push(make_pair(numToCountVector[i].first, numToCountVector[i].second));
    i++;
  }
  while (i < numToCountVector.size()) {
    if (numToCountVector[i].first > q.top().first) {
      q.pop();
      q.push(make_pair(numToCountVector[i].first, numToCountVector[i].second));
    }
    i++;
  }
  while (!q.empty()) {
    res.push_back(q.top().second);
    q.pop();
  }
  return res;
}

int main(void) {
  int k;
  int n;
  cin >> k;
  vector <int> nums;
  vector <int> res;
  while (cin >> n) {
    nums.push_back(n);
  }
  res = topKFrequent(nums, k);
  for (auto a : res) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
