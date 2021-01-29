/* Accepted */
#include <stack>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void helper(int l, int r, string& curr, stack <char>& s,
  vector <string>& res) {
    if (l == 0 && r == 0 && s.empty() && curr.length() > 0) {
      res.push_back(curr);
      return;
    }
    if (l > r) {
      return;
    }
    if (l == 0 && r == s.size()) {
      res.push_back(curr);
      while (r--) {
        res.back().push_back(')');
      }
      return;
    }
    if (l > 0) {
      curr.push_back('(');
      s.push('(');
      l--;
      helper(l, r, curr, s, res);
      l++;
      s.pop();
      curr.pop_back();
    }
    if (r > 0 && (!s.empty() && s.top() == '(')) {
      curr.push_back(')');
      s.pop();
      r--;
      helper(l, r, curr, s, res);
      r++;
      curr.pop_back();
      s.push('(');
    }
  }

vector <string> generateParenthesis(int n) {
  if (n == 1) {
    return {"()"};
  }
  int l = n;
  int r = n;
  stack <char> par;
  vector <string> res;
  string curr = "";
  helper(l, r, curr, par, res);
  return res;
}

int main(void) {
  int n;
  while (cin >> n) {
    vector <string> res = generateParenthesis(n);
    cout << endl;
    for (auto a : res) {
      cout << a << endl;
    }
    cout << endl;
  }
  return 0;
}
