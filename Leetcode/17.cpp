/* Accepted */
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void recursive(int pos, string& digit, string& curr, unordered_map <char, vector <char> >& mapping,
  vector <string>& res) {
  if (pos >= digit.length()) {
    if (curr.length() > 0) {
      res.push_back(curr);
      return;
    }
  }
  for (auto a : mapping[digit[pos]]) {
    curr.push_back(a);
    recursive(pos + 1, digit, curr, mapping, res);
    curr.pop_back();
  }
}

vector <string> letterCombinations(string digits) {
  if (digits.length() < 1) {
    return {};
  }
  unordered_map <char, vector <char> > digitMap;
  digitMap['2'] = {'a', 'b', 'c'};
  digitMap['3'] = {'d', 'e', 'f'};
  digitMap['4'] = {'g', 'h', 'i'};
  digitMap['5'] = {'j', 'k', 'l'};
  digitMap['6'] = {'m', 'n', 'o'};
  digitMap['7'] = {'p', 'q', 'r', 's'};
  digitMap['8'] = {'t', 'u', 'v'};
  digitMap['9'] = {'w', 'x', 'y', 'z'};
  int i = 0;
  vector <string> res;
  string curr = "";
  recursive(i, digits, curr, digitMap, res);
  return res;
}

int main(void) {
  string s;
  while (cin >> s) {
    vector <string> res = letterCombinations(s);
    for (auto a : res) {
      cout << a << endl;
    }
    cout << endl;
  }
  return 0;
}
