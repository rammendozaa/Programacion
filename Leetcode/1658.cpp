/* Accepted */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minOperations(vector <int>& people, int x) {
  if (people.size() == 1) {
    return (people[0] == x) ? 1 : -1;
  }
  int i = 0;
  int j = people.size() - 1;
  while (i < people.size() && people[i] > x) {
    i++;
  }
  if (i >= people.size()) {
    return -1;
  }
  while (j >= 0 && people[j] > x) {
    j--;
  }
  if (j < 0) {
    return -1;
  }
  vector <int> nums;
  while (i <= j) {
    nums.push_back(people[i]);
    i++;
  }
  int minV = (1e9 + 7);
  unordered_map <int, vector <int> > firstMap;
  unordered_map <int, vector <int> > secondMap;
  vector <int> first = {0};
  vector <int> second = {0};
  i = 0;
  j = nums.size() - 1;
  while (i < nums.size()) {
    first.push_back(nums[i] + first.back());
    second.push_back(nums[j] + second.back());
    i++;
    j--;
  }
  for (int i = 1 ; i < first.size() ; ++i) {
    firstMap[first[i]].push_back(i);
  }
  for (int i = 1 ; i < second.size() ; ++i) {
    secondMap[second[i]].push_back(i);
  }
  if (firstMap.find(x) != firstMap.end()) {
    for (auto a : firstMap[x]) {
      minV = min(minV, a);
    }
  }
  if (secondMap.find(x) != secondMap.end()) {
    for (auto a : secondMap[x]) {
      minV = min(minV, a);
    }
  }
  for (int i = 1 ; i < first.size() ; ++i) {
    if (secondMap.find(x - first[i]) != secondMap.end()) {
      for (auto a : secondMap[x - first[i]]) {
        if (x < a) {
          minV = min(minV, i + a);
        }
      }
    }
  }
  reverse(second.begin(), second.end());
  for (int i = second.size() - 1 ; i >= 0 ; --i) {
    if (firstMap.find(x - second[i]) != firstMap.end()) {
      for (auto a : firstMap[x - second[i]]) {
        if (x > a) {
          minV = min(minV, i + a);
        }
      }
    }
  }
  return (minV == 1e9 + 7) ? -1 : minV;
}

int main(void) {
  int x;
  cin >> x;
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << minOperations(nums, x) << endl;
  return 0;
}
