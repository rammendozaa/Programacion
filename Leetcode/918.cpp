/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySumCircular(vector <int>& A) {
  int maxSum = -1e9;
  int minSum = 1e9;
  int currMaxSum = 0;
  int currMinSum = 0;
  int totalSum = 0;
  for (int i = 0 ; i < A.size() ; ++i) {
    currMaxSum = max(A[i], currMaxSum + A[i]);
    maxSum = max(maxSum, currMaxSum);
    currMinSum = min(A[i], currMinSum + A[i]);
    minSum = min(minSum, currMinSum);
    totalSum += A[i];
  }
  return (maxSum > 0) ? max(maxSum, totalSum - minSum) : maxSum;
}

int main(void) {
  int n;
  vector <int> nums;
  while (cin >> n) {
    nums.push_back(n);
  }
  cout << maxSubarraySumCircular(nums) << endl;
}
