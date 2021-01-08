/* Accepted */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
  if (num.length() <= k) {
    return "0";
  }
  stack <int> s;
  s.push(num[0] - '0');
  int i = 1;
  while (i < num.length()) {
    while (!s.empty() && k > 0 && s.top() > (num[i] - '0')) {
      s.pop();
      k--;
    }
    s.push(num[i] -'0');
    i++;
  }
  if (k > 0 && !s.empty()) {
    while (k > 0 && !s.empty()) {
      k--;
      s.pop();
    }
  }
  string str;
  while (!s.empty()) {
    str.push_back(s.top() + '0');
    s.pop();
  }
  reverse(str.begin(), str.end());
  int zero = 0;
  while (str[zero] == '0' && zero < str.length()) {
    zero++;
  }
  if (str.length() == 0 || zero >= str.length()) {
    return (str.length() == 0 || zero >= str.length()) ? "0" : str;
  }
  return (zero == 0) ? str : str.substr(zero);
}

int main (void) {
  int k;
  string str;
  cin >> str >> k;
  cout << removeKdigits(str, k) << endl;
}
