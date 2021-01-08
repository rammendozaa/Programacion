/* Accepted */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solve(priority_queue <int, vector <int>, greater <int> > left, priority_queue <int, vector <int>, greater <int> > right, priority_queue <int, vector <int>, greater <int> > both, int k) {
  int totalTime = 0;
  while (k > 0) {
    if (!both.empty() && (left.empty() || right.empty())) {
      totalTime += (both.top());
      both.pop();
      k--;
    } else if (!left.empty() && !right.empty() && both.empty()) {
      totalTime += (left.top() + right.top());
      left.pop();
      right.pop();
      k--;
    } else if (!left.empty() && !right.empty() && !both.empty()) {
      if (both.top() > (left.top() + right.top())) {
        totalTime += (left.top() + right.top());
        k--;
        left.pop();
        right.pop();
      } else {
        totalTime += (both.top());
        both.pop();
        k--;
      }
    }
  }
  return totalTime;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int howMany, k, totalRight = 0, totalLeft = 0, time, left, right;
  cin >> howMany >> k;
  priority_queue <int, vector <int>, greater <int> > pqLeft;
  priority_queue <int, vector <int>, greater <int> > pqRight;
  priority_queue <int, vector <int>, greater <int> > pqBoth;
  for (int i = 0 ; i < howMany ; ++i) {
    cin >> time >> left >> right;
    if (left == 1 && right == 0) {
      pqLeft.push(time);
      totalLeft++;
    } else if (left == 0 && right == 1) {
      pqRight.push(time);
      totalRight++;
    } else if (left == 1 && right == 1) {
      pqBoth.push(time);
      totalLeft++;
      totalRight++;
    }
  }
  if (totalRight < k || totalLeft < k) {
    cout << "-1" << endl;
    return 0;
  }
  cout << solve(pqLeft, pqRight, pqBoth, k) << endl;
  return 0;
}
