#include <string>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void permutations(int pos, string s, string currStr, vector <string>& res) {
  if (pos == s.length()) {
    res.push_back(currStr);
    return;
  }

  if (s[pos] >= '0' && s[pos] <= '9') {
    currStr.push_back(s[pos]);
    permutations(pos + 1, s, currStr, res);
  } else if (s[pos] >= 'a' && s[pos] <= 'z') {
    currStr.push_back(s[pos]);
    permutations(pos + 1, s, currStr, res);
    currStr.pop_back();
    currStr.push_back(toupper(s[pos]));
    permutations(pos + 1, s, currStr, res);
  } else {
    currStr.push_back(s[pos]);
    permutations(pos + 1, s, currStr, res);
    currStr.pop_back();
    currStr.push_back(tolower(s[pos]));
    permutations(pos + 1, s, currStr, res);
  }

}

vector <string> letterCasePermutation(string s) {
  vector <string> res;
  string currStr = "";
  permutations(0, s, currStr, res);
  return res;
}

int main(void) {
  string s;
  while (cin >> s) {
    vector <string> res = letterCasePermutation(s);
    for (auto a : res) {
      cout << a << endl;
    }
    cout << endl;
  }
  return 0;
}
