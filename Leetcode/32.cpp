/* Accepted */
#include <string>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int longestValidParentheses(string one) {
  if (one.length() == 0 || one.length() == 1) {
    return 0;
  }
  int i = 0;
  int currSum = 0;
  int maxSum = -1;
  stack <int> s;
  for (int i = 0 ; i < one.length() ; ++i) {
    if (one[i] == ')' && !s.empty() && one[s.top()] == '(') {
      one[i] = '1';
      one[s.top()] = '1';
      s.pop();
    } else if (one[i] == '(') {
      s.push(i);
    }
  }

  while (i < one.size()) {
    while (i < one.size() && one[i] != '1') {
      i++;
    }
    currSum = 0;
    while (i < one.size() && one[i] == '1') {
      currSum += 1;
      i++;
    }
    maxSum = max(maxSum, currSum);
  }

  return maxSum;
}

int main(void) {
  string one;
  cin >> one;
  cout << longestValidParentheses(one) << endl;
}
