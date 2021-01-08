#include <vector>
#include <iostream>
using namespace std;

int main (void) {
  int n;
  int mini = 1e9;
  int maxi = -1e9;
  int moves = 0;
  cin >> n;
  vector <int> nums(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> nums[i];
    mini = min(mini, nums[i]);
    maxi = max(maxi, nums[i]);
  }
  int left = 0;
  int right = n - 1;
  while (nums[left] != maxi) {
    moves++;
    left++;
  }
  while (nums[right] != mini) {
    moves++;
    right--;
  }
  if (right < left) {
    moves--;
  }
  cout << moves << endl;
  return 0;
}
