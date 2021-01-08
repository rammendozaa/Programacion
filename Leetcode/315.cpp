#include <set>
#include <utility>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

set<pair<int, int>, greater<pair<int, int> > >::iterator iterateSet(int target, set <pair <int, int>, greater <pair <int, int> > >& valToPos) {
  set <pair <int, int>, greater <pair <int, int> > >::iterator it;
  for (it = valToPos.begin() ; it != valToPos.end() ; ++it) {
    if (it -> first < target) {
      return it;
    }
  }
  return valToPos.end();
}

vector <int> countSmaller(vector <int>& nums) {
  if (nums.size() == 0) {
    return {};
  }
  if (nums.size() == 1) {
    return {0};
  }
  pair <int, int> posToCount;
  unordered_map <int, int> counts;
  set <pair <int, int>, greater <pair<int, int> > > valueToPosition;
  vector <int> res(nums.size(), 0);
  reverse(nums.begin(), nums.end());
  valueToPosition.insert(make_pair(nums[0], 0));
  counts[nums[0]]++;
  for (int i = 1 ; i < nums.size() ; ++i) {
    set<pair <int, int>, greater <pair <int, int> > >::iterator posToCount = iterateSet(nums[i], valueToPosition);
    valueToPosition.insert(make_pair(nums[i], i));
    counts[nums[i]]++;
    if (posToCount == valueToPosition.end()) {
      continue;
    }
    int value = posToCount -> first;
    int pos = posToCount -> second;
    int greaterThan = 0;
    for (set <pair <int, int>, greater <pair <int, int> > >::iterator it = valueToPosition.begin() ; it != posToCount ; ++it) {
      if (it -> first >= nums[i] && it -> second > pos) {
        greaterThan++;
      }
    }
    res[i] = counts[value] + res[pos] + (i - pos - greaterThan);
  }
  reverse(res.begin(), res.end());
  return res;
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  vector <int> res = countSmaller(nums);

  for (auto a : res) {
    cout << a << " ";
  }
  cout << endl;

  return 0;
}
