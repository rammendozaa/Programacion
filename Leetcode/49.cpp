/* Accepted */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void getStringFromLetterCount(unordered_map <string, vector <string> >& numberToWords,
  string str) {
  vector <int> letters (26, 0);
  for (auto a : str) {
    letters[a - 'a']++;
  }
  string auxStr = "";
  for (auto a : letters) {
    auxStr += (to_string(a) + '.');
  }
  numberToWords[auxStr].push_back(str);
}

vector <vector <string> > groupAnagrams(vector <string>& strs) {
  unordered_map <string, vector <string> > numberToWords;
  vector <vector <string> > res;
  for (auto a : strs) {
    getStringFromLetterCount(numberToWords, a);
  }

  for (auto a : numberToWords) {
    vector <string> auxV;
    for (auto b : a.second) {
      auxV.push_back(b);
    }
    res.push_back(auxV);
  }
  return res;
}

int main(void) {
  string s;
  vector <string> strs;
  vector <vector <string> > res;
  while (cin >> s) {
    strs.push_back(s);
  }
  res = groupAnagrams(strs);
  for (auto a : res) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  return 0;
}
