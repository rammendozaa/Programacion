#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool areArraysEqual(vector <int>& arrayOne, vector <int>& arrayTwo) {
  for (int i = 0 ; i < 27 ; ++i) {
    if (arrayOne[i] != arrayTwo[i]) {
      return false;
    }
  }
  return true;
}

vector <int> findAnagrams (string& s, string& p) {
  vector <int> pArray(27, 0);
  vector <int> sArray(27, 0);
  vector <int> res;
  if (s.length() < p.length()) {
    return {};
  }

  for (int i = 0 ; i < p.length() ; ++i) {
    sArray[s[i] - 97]++;
    pArray[p[i] - 97]++;
  }
  if (areArraysEqual(sArray, pArray)) {
    res.push_back(0);
  }

  for (int i = 1 ; i <= (s.length() - p.length()) ; ++i) {
    sArray[s[i - 1] - 97]--;
    sArray[s[i + p.length() - 1] - 97]++;
    if (areArraysEqual(sArray, pArray)) {
      res.push_back(i);
    }
  }

  return res;
}

int main (void) {
  string p, s;
  cin >> s >> p;
  vector <int> res = findAnagrams(s, p);
  for (auto a : res) {
    cout << a << " ";
  }
  cout << endl;
}
