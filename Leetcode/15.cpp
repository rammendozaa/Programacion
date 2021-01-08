/* Accepted */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;
//TLE
/*
struct hash_pair {
  template <class T1, class T2>
  bool operator() (const pair <T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

int binarySearch(vector <int>& nums, int ini, int fin, int target) {
  int mid;
  while (ini <= fin) {
    mid = ini + ((fin - ini) >> 1);
    if (target == nums[mid]) {
      return target;
    }
    if (target < nums[mid]) {
      fin = mid - 1;
    } else {
      ini = mid + 1;
    }
  }
  return -1e9;
}

vector <vector <int> > threeSum(vector <int>& nums) {
  if (nums.size() < 3) {
    return {};
  }
  sort(nums.begin(), nums.end());
  unordered_map <pair <int, int>, int, hash_pair> pairsToInt;
  vector <vector <int> > res;
  int first;
  int second;
  int third;
  int i = 0;
  int j;
  int n = nums.size();
  while (i < n - 2) {
    first = nums[i];
    j = i + 1;
    while (j < n - 1) {
      second = nums[j];
      third = binarySearch(nums, j + 1, n, 0 - (first + second));
      cout << first << " " << second << " " << third << endl;
      if (pairsToInt.find({first, second}) == pairsToInt.end() && (first + second + third == 0)) {
        pairsToInt[{first, second}] = third;
      }
      j++;
    }
    i++;
  }
  for (auto a : pairsToInt) {
    res.push_back({a.first.first, a.first.second, a.second});
  }
  return res;
}
*/

vector <vector <int> > threeSum(vector <int>& nums) {
  if (nums.size() < 3) {
    return {};
  }
  sort(nums.begin(), nums.end());
  vector <vector <int> > res;
  int target;
  int i = 0;
  int j;
  int k;
  int n = nums.size();
  while (i < n - 2) {
    target = (-1 * nums[i]);
    k = n - 1;
    j = i + 1;
    while (j < k) {
      if (nums[j] + nums[k] > target) {
        k--;
      } else if (nums[j] + nums[k] < target) {
        j++;
      } else {
        int auxJ = nums[j];
        int auxK = nums[k];
        res.push_back({(target * -1), nums[j], nums[k]});
        while (j < k && nums[j] == auxJ) {
          j++;
        }
        while (j < k && nums[k] == auxK) {
          k--;
        }
      }
    }
    while (i < n - 2 && nums[i] == nums[i + 1]) {
      i++;
    }
    i++;
  }
  return res;
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  vector <vector <int> > res = threeSum(nums);
  for (auto a : res) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
