#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool distinct(vector <int>& letters) {
  for (auto a : letters) {
    if (a > 1) {
      return false;
    }
  }
  return true;
}

int lengthOfLongestSubstring(string s) {
  if (s.length() ==  0 || s.length() == 1) {
    return s.length();
  }
  int minI = 1000;
  int maxI = -1;
  for (auto a : s) {
    minI = min(minI, (int)a);
    maxI = max(maxI, (int)a);
  }
  vector <int> letters(maxI - minI + 1, 0);
  letters[s[0] - minI] = 1;
  int i = 0;
  int j = 1;
  int maxLength = 1;
  while (j < s.length()) {
    while (j < s.length() && distinct(letters)) {
      letters[s[j] - minI]++;
      j++;
    }
    maxLength = max(maxLength, j - i - 1);
    while (i < j && !distinct(letters)) {
      letters[s[i] - minI]--;
      i++;
    }
  }
  maxLength = max(maxLength, j - i);
  return maxLength;
}

int main(void) {
  string s;
  while (cin >> s) {
    cout << lengthOfLongestSubstring(s) << endl;
  }
  return 0;
}
