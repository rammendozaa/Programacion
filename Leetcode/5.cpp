#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getFarthestIndexOneChar(string s, int j) {
  int i = j;
  int k = j;
  while (i >= 0 && k < s.length() && s[i] == s[k]) {
    i--;
    k++;
  }
  return i + 1;
}

int getFarthestIndexTwoChars(string s, int j) {
  int i = j;
  int k = j + 1;
  while (i >= 0 && k < s.length() && s[i] == s[k]) {
    i--;
    k++;
  }
  return i + 1;
}

string longestPalindrome(string s) {
  if (s.length() == 0 || s.length() == 1) {
    return s;
  }
  string lps{s[0]};
  if (s.length() == 2) {
    return (s[0] == s[1]) ? s : lps;
  }
  int maxLength = 1;
  int ini = 0;
  int fin = 0;
  int i = 1;
  int j;
  while (i < s.length() - 1) {
    if (s[i - 1] == s[i + 1]) {
      int ind = getFarthestIndexOneChar(s, i);
      if (((i - ind) * 2 + 1) > maxLength) {
        maxLength = ((i - ind) * 2 + 1);
        ini = ind;
        fin = i + (i - ind);
      }
    }
    i++;
  }
  i = 0;
  j = 1;
  while (j < s.length()) {
    if (s[i] == s[j]) {
      int ind = getFarthestIndexTwoChars(s, i);
      if (((i - ind) * 2 + 2) > maxLength) {
        maxLength = ((i - ind) * 2 + 2);
        ini = ind;
        fin = j + (i - ind);
      }
    }
    i++;
    j++;
  }
  if (fin - ini > 0) {
    lps = "";
    for (int i = ini ; i <= fin ; ++i) {
      lps.push_back(s[i]);
    }
  }
  return lps;
}

int main(void) {
  string s;
  while (cin >> s) {
    cout << longestPalindrome(s) << endl;
  }
  return 0;
}
