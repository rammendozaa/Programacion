/* Accepted */
#include <iostream>
#include <string>
using namespace std;

/*

follow-up:
 for greater values, we could store the positions of each char in t
 then find the first appearance of the first char of s in t, and based on that
 do binary search to find the appearance that is closest to the most recent
 char in s

*/


bool isSubsequence(string& s, string& t) {
  if (s.length() == 0 || (s.length() == t.length() && s.length() == 0)) {
    return true;
  }
  if (s.length() > t.length() || t.length() == 0) {
    return false;
  }
  int i = 0;
  int j = 0;
  while (i < s.length() && j < t.length()) {
    while (j < t.length() && s[i] != t[j]) {
      j++;
    }
    if (j == t.length()) {
      break;
    }
    i++;
    j++;
  }

  return (i == s.length());
}

int main (void) {
  string s, t;
  cin >> s >> t;
  cout << isSubsequence(s, t) << endl;
}
