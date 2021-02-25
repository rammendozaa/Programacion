/* Accepted */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplifyPath(string str) {
  int i = 0;
  stack <string> s;
  string resStr = "";
  while (i < str.length()) {
    while (i < str.length() && str[i] == '/') {
      i++;
    }
    if ((i < str.length() - 1 && str[i] == '.' && str[i + 1] == '/')
    || (i + 1 == str.length() && str[i] == '.')) {
      i += 2;
      continue;
    }
    if ((i < str.length() - 2 && str[i] == '.' && str[i + 1] == '.' && str[i + 2] == '/')
    || (i + 2 == str.length() && str[i] == '.' && str[i + 1] == '.')) {
      if (!s.empty()) {
        s.pop();
      }
      i += 3;
      continue;
    }
    string auxStr = "";
    while (i < str.length() && str[i] != '/') {
      auxStr += str[i];
      i++;
    }
    if (auxStr.length() > 0) {
      s.push(auxStr);
    }
  }
  while (!s.empty()) {
    resStr = ("/" + s.top() + resStr);
    s.pop();
  }
  return (resStr.length() == 0) ? "/" : resStr;
}

int main(void) {
  string s;
  while (cin >> s) {
    cout << simplifyPath(s) << endl;
  }
  return 0;
}
