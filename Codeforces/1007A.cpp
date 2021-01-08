#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool mycomp(long long int a, long long int b) {
  return a > b;
}

long long int solve(vector <long long int> nums) {
  long long int count = 0;
  long long int i = 0;
  long long int j = nums.size() - 1;
  sort(nums.begin(), nums.end(), mycomp);
  while (i < j && nums[i] != nums[j]) {
    count++;
    i++;
    j--;
    if (i == j && nums[i - 1] != nums[i] && nums[i] != nums[i + 1]) {
      count++;
    }
  }
  return count;
}

int main (void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int size;
  cin >> size;
  vector <long long int> nums(size);
  for (long long int i = 0 ; i < size ; ++i) {
    cin >> nums[i];
  }
  cout << solve(nums) << endl;
}
