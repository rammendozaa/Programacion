#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxOperations(vector <int>& nums, int k) {
  int count = 0;
  unordered_map <int, int> numToFrequency;
  int evenC = 0;

  for (auto a : nums) {
    if (k % 2 == 0 && a == (k >> 1)) {
      evenC++;
    } else if (a < k) {
      numToFrequency[k - a]++;
    }
  }

  if (k % 2 == 0) {
    count += (evenC >> 1);
  }

  for (auto a : numToFrequency) {
    if (numToFrequency.find(k - a.first) != numToFrequency.end()) {
      int howMany = 0;
      howMany = min(a.second, numToFrequency[k - a.first]);
      count += howMany;
      numToFrequency[k - a.first] -= howMany;
      numToFrequency[a.first] -= howMany;
    }
  }

  return count;
}

int main(void) {
  int k;
  int n;
  vector <int> nums;
  cin >> k;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << maxOperations(nums, k) << endl;
  return 0;
}
