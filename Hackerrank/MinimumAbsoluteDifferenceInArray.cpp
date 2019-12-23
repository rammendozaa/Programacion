// Accepted
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector <int> nums(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  int differences = 1e9;
  for (int i = 0 ; i < n - 1 ; ++i) {
    differences = min(differences, abs(nums[i + 1] - nums[i]));
  }
  cout << differences << endl;
}
