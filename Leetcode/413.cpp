/* Accepted */
#include <vector>
#include <iostream>
using namespace std;

void buildConsecutive(vector <int>& numConsecutive, int value) {
  numConsecutive.push_back(0);
  numConsecutive.push_back(0);
  numConsecutive.push_back(1);
  for (int i = 3 ; i <= value ; ++i) {
    numConsecutive.push_back(numConsecutive[i - 1] + (i - 1));
  }
}

int numberOfArithmeticSlices(vector <int>& nums) {
  vector <int> differences;
  vector <int> consecutive;
  vector <int> numConsecutive;
  for (int i = 1 ; i < nums.size() ; ++i) {
    differences.push_back(nums[i] - nums[i - 1]);
  }
  int i = 0;
  int j = 1;
  int maxValue = 0;
  while (j < differences.size()) {
    while (j < differences.size() && differences[i] == differences[j]) {
      j++;
    }
    if (j - i > 1) {
      maxValue = max(maxValue, j - i);
      consecutive.push_back(j - i);
    }
    i = j;
    j++;
  }
  buildConsecutive(numConsecutive, maxValue);
  int sum = 0;
  for (auto a : consecutive) {
    sum += numConsecutive[a];
  }
  return sum;
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << numberOfArithmeticSlices(nums) << endl;
  return 0;
}
