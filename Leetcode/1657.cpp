/* Accepted */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool closeStrings(string word1, string word2) {
  if (word1.length() != word2.length()) {
    return false;
  }
  vector <int> one (26, 0);
  vector <int> two (26, 0);
  for (auto a : word1) {
    one[a - 'a']++;
  }
  for (auto a : word2) {
    two[a - 'a']++;
  }
  for (int i = 0 ; i < 26 ; ++i) {
    if ((one[i] == 0 && two[i] != 0) || (one[i] != 0 && two[i] == 0)) {
      return false;
    }
  }
  sort(one.begin(), one.end());
  sort(two.begin(), two.end());
  for (int i = 0 ; i < one.size() ; ++i) {
    if (one[i] != two[i]) {
      return false;
    }
  }
  return true;
}

int main (void) {
  string one;
  string two;
  cin >> one >> two;
  cout << closeStrings(one, two) << endl;
  return 0;
}
