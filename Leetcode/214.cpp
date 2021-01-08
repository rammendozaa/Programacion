#include <iostream>
#include <vector>
#include <string>
using namespace std;

void createPiTable(vector <int>& pi, string p) {
  pi[0] = 0;
  int i = 1;
  int len = 0;
  while (i < p.length()) {
    if (p[i] == p[len]) {
      len++;
      pi[i] = len;
      i++;
    } else {
      if (len == 0) {
        p[i] = 0;
        i++;
      } else {
        len = pi[len - 1];
      }
    }
  }
}

int KMP(string t, string p) {
  vector <int> pi(p.length(), 0);
  createPiTable(pi, p);
  int j = 0;
  int i = 0;
  while (i < t.length()) {
    if (t[i] == p[j]) {
      i++;
      j++;
    }
    if (i == p.length() || j == p.length()) {
      return (i - j);
    } else if (i < t.length() && p[j] != t[i]) {
      if (j == 0) {
        i++;
      } else {
        j = pi[j - 1];
      }
    }
  }
  return p.length();
}

void flipString(string& s) {
  int i = 0;
  int j = s.length() - 1;
  while (i < j) {
    swap(s[i], s[j]);
    i++;
    j--;
  }
}

string shortestPalindrome(string p) {
  if (p.length() == 0 || p.length() == 1) {
    return p;
  }
  string flipped = p;
  flipString(flipped);
  int index = KMP(flipped, p);
  string auxS(index, '-');
  for (int i = 0 ; i < index ; ++i) {
    auxS[i] = flipped[i];
  }
  return auxS + p;
}

int main(void) {
  string s;
  while (cin >> s) {
    cout << shortestPalindrome(s) << endl;
  }
  return 0;
}
