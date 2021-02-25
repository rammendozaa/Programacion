/* Accepted */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int scoreOfParentheses(string str) {
  int sum;
  stack <int> s;
  string helperStr = "";
  int i = 0;
  while (i < str.length()) {
    if ((i + 1 < str.length()) && str[i] == '(' && str[i + 1] == ')') {
      helperStr.push_back('1');
      i++;
    } else {
      helperStr.push_back(str[i]);
    }
    i++;
  }
  for (auto a : helperStr) {
    if (a == '(') {
      s.push(0);
    } else if (a == ')') {
      int sum = 0;
      while (!s.empty() && s.top() != 0) {
        sum += s.top();
        s.pop();
      }
      if (!s.empty() && s.top() == 0) {
        sum *= 2;
        s.pop();
      }
      s.push(sum);
    } else {
      s.push(1);
    }
  }
  sum = 0;
  while (!s.empty()) {
    sum += s.top();
    s.pop();
  }
  return sum;
}

int main(void) {
  string str;
  while (cin >> str) {
    cout << scoreOfParentheses(str) << endl;
  }
  return 0;
}
