/* Accepted */
#include <iostream>
#include <string>
using namespace std;

bool wordFound(int ind, string one, string two) {
  int i = 0;
  while (i < two.length() && ind < one.length() && one[ind] == two[i]) {
    i++;
    ind++;
  }
  return i >= two.length();
}

int strStr(string one, string two) {
  if (two.length() == 0) {
    return 0;
  }
  if (one.length() < two.length()) {
    return -1;
  }
  for (int i = 0 ; i < one.length() - two.length() + 1 ; ++i) {
    if (one[i] == two[0]) {
      if (wordFound(i, one, two)) {
        return i;
      }
    }
  }
  return -1;
}

int main(void) {
  string one, two;
  cin >> one >> two;
  cout << strStr(one, two) << endl;
}
