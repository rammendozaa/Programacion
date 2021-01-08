/* Accepted */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solve(string &cad) {
  stack <char> s;
  int count = 0;
  for (auto a : cad) {
    if (a == ')' && s.empty()) {
      count++;
    } else if (a == '('){
      s.push(a);
    } else {
      s.pop();
    }
  }
  return count;
}

int main(void) {
  int cases;
  cin >> cases;
  while (cases--) {
    int n;
    string cad;
    cin >> n;
    cin >> cad;
    cout << solve(cad) << endl;
  }
}
