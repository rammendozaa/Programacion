#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkCounts(vector <int>& letterCount, int k) {
  for (auto a : letterCount) {
    if (a != 0 && a < k) {
      return false;
    }
  }
  return true;
}

int longestSubstring(string s, int k) {
  if (k == 0 || k == 1) {
    return s.length();
  }
  int maxLength = 0;
  for (int i = 0 ; i < s.length() ; ++i) {
    for (int j = i + 1 ; j < s.length() ; ++j) {
      vector <int> letterCount(27, 0);
      for (int k = i ; k <= j ; ++k) {
        letterCount[s[k] - 'a']++;
      }
      if (checkCounts(letterCount, k)) {
        maxLength = max(maxLength, j - i + 1);
      }
    }
  }
  return maxLength;
}

int main(void) {
  string input;
  int k;
  while (cin >> input) {
    cin >> k;
    cout << longestSubstring(input, k) << endl;
  }
  return 0;
}
