/* Accepted */
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void addStr(vector <vector <int> >& resMatrix, string& resStr) {
  stack <int> resStack;
  int carry = 0;
  int sum;
  for (int j = resMatrix[0].size() - 1 ; j >= 0 ; --j) {
    sum = 0;
    for (int i = 0 ; i < resMatrix.size() ; ++i) {
      sum += resMatrix[i][j];
    }
    sum += carry;
    resStack.push(sum % 10);
    carry = sum / 10;
  }
  while (!resStack.empty()) {
    resStr.push_back((resStack.top() + '0'));
    resStack.pop();
  }
}

void multiplyStr(vector <int>& res, string& one, int mult, int pos) {
  int endPos = res.size() - 1 - pos;
  int i = one.size() - 1;
  int carry = 0;
  while (i >= 0) {
    res[endPos] = (carry + (mult * (one[i] - '0')) % 10);
    carry = (mult * (one[i] - '0')) / 10;
    i--;
    endPos--;
  }
  res[endPos] = carry;
}

string multiply(string one, string two) {
  if (one.length() == 1 && one[0] == '0' || two.length() == 1 && two[0] == '0') {
    return "0";
  }
  if (two.length() > one.length()) {
    string aux = one;
    one = two;
    two = aux;
  }
  vector <vector <int> > resSums(two.size(),
    vector <int> (two.size() + one.size() + 2, 0));
  string resStr = "";
  for (int j = two.size() - 1 ; j >= 0 ; --j) {
    multiplyStr(resSums[two.size() - 1 - j], one, (two[j] - '0'), two.size() - 1 - j);
  }
  addStr(resSums, resStr);
  int i = 0;
  while (resStr[i] == '0') {
    i++;
  }
  return resStr.erase(0, i);
}


int main(void) {
  string one;
  string two;
  cin >> one >> two;
  cout << multiply(one, two) << endl;
  return 0;
}
