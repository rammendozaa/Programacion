/* Accepted */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDeletions(string s) {
  if (s.length() == 0 || s.length() == 1) {
    return 0;
  }

  vector <int> alphabet(26, 0);
  vector <int> letterFrequency;
  for (auto a : s) {
    alphabet[a - 'a']++;
  }
  for (auto a : alphabet) {
    if (a > 0) {
      letterFrequency.push_back(a);
    }
  }
  if (letterFrequency.size() == 1) {
    return 0;
  }
  if (letterFrequency.size() == 2) {
    return (letterFrequency[0] == letterFrequency[1]) ? 1 : 0;
  }
  bool needsChange = false;
  sort(letterFrequency.begin(), letterFrequency.end());
  for (int i = 0 ; i < letterFrequency.size() - 1 ; ++i) {
    if (letterFrequency[i] == letterFrequency[i + 1]) {
      needsChange = true;
      break;
    }
  }
  if (!needsChange) {
    return 0;
  }
  int i = letterFrequency.size() - 2;
  int totalDeleted = 0;
  for (auto a : letterFrequency) {
    cout << a << " ";
  }
  cout << endl;
  while (i >= 0) {
    if (letterFrequency[i + 1] == 0) {
      totalDeleted += letterFrequency[i];
      letterFrequency[i] = 0;
    } else if (letterFrequency[i] >= letterFrequency[i + 1]) {
      totalDeleted += (letterFrequency[i] - letterFrequency[i + 1] + 1);
      letterFrequency[i] = max(letterFrequency[i + 1] - 1, 0);
    }
    i--;
  }
  for (auto a : letterFrequency) {
    cout << a << " ";
  }
  return totalDeleted;
}

int main(void) {
  string input;
  while (cin >> input) {
    cout << minDeletions(input) << endl;
  }
  return 0;
}
