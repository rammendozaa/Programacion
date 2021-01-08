/* Accepted */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkValidString(string str) {
  if (str.length() == 0) {
    return true;
  }
  if (str.length() == 1) {
    return str[0] == '*';
  }
  if (str[0] == ')' || str[str.length() - 1] == '(') {
    return false;
  }
  stack <int> parStack;
  stack <int> astStack;
  for (int i = 0 ; i < str.length() ; ++i) {
    if (str[i] == '(') {
      parStack.push(i);
    } else if (str[i] == ')') {
      if (parStack.empty() && astStack.empty()) {
        return false;
      }
      if (!parStack.empty()) {
        parStack.pop();
      } else {
        astStack.pop();
      }
    } else {
      astStack.push(i);
    }
  }

  if (!parStack.empty()) {
    if (astStack.empty() || astStack.size() < parStack.size()) {
      return false;
    }
    while (!parStack.empty() && !astStack.empty()) {
      if (parStack.top() > astStack.top()) {
        return false;
      }
      parStack.pop();
      astStack.pop();
    }
  }
  return parStack.empty();
}

int main (void) {
  string str;
  cin >> str;
  cout << checkValidString(str) << endl;
}
