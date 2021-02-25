/* Accepted */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool validWord(string s, string a) {
  if (s.length() < a.length()) {
    return false;
  }
  int i = 0;
  int j = 0;
  while (i < s.length()) {
    if (s[i] == a[j]) {
      j++;
    }
    i++;
    if (j == a.length()) {
      return true;
    }
  }
  return false;
}

string findLongestWord(string s, vector <string>& d) {
  string res = "";
  for (auto a : d) {
    if (validWord(s, a)) {
      if (a.length() > res.length() || (a.length() == res.length() && a < res)) {
        res = a;
      }
    }
  }
  return res;
}

int main(void) {
  string s, str;
  vector <string> d;
  cin >> s;
  while (cin >> str) {
    d.push_back(str);
  }
  cout << findLongestWord(s, d) << endl;
  return 0;
}
