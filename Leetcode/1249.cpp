/* Accepted */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverseStr(string& str) {
  int i = 0;
  int j = str.length() - 1;
  while (i < j) {
    swap(str[i], str[j]);
    i++;
    j--;
  }
}

string minRemoveToMakeValid(string str) {
  stack <int> s;
  for (int i = 0 ; i < str.length() ; ++i) {
    if (str[i] == '(') {
      s.push(i);
    } else if (str[i] == ')') {
      if (!s.empty() && str[s.top()] == '(') {
        s.pop();
      } else {
        s.push(i);
      }
    }
  }
  string newStr = "";
  for (int i = str.length() - 1 ; i >= 0 ; --i) {
    if (!s.empty() && i == s.top()) {
      s.pop();
    } else {
      newStr.push_back(str[i]);
    }
  }
  reverseStr(newStr);
  return newStr;
}

int main(void) {
  string s;
  while (cin >> s) {
    cout << minRemoveToMakeValid(s) << endl;
  }
  return 0;
}
