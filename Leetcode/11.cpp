/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector <int>& heights) {
  if (heights.size() == 2) {
    return min(heights[0], heights[1]);
  }
  int maxArea = 0;
  int pivot = 0;
  int i = 0;
  int j = heights.size() - 1;
  while (i < j) {
    maxArea = max(maxArea, (j - i) * min(heights[i], heights[j]));
    if (heights[i] < heights[j]) {
      pivot = heights[i];
      while (i < j && pivot >= heights[i]) {
        i++;
      }
    } else {
      pivot = heights[j];
      while (i < j && pivot >= heights[j]) {
        j--;
      }
    }
  }
  return maxArea;
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << maxArea(nums) << endl;
}
