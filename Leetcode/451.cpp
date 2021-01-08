/* Accepted */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

string frequencySort(string s) {
  string res = "";
  vector <pair <int, char>> chars(300);
  for (char a : s) {
    chars[int(a)].first++;
    chars[int(a)].second = a;
  }
  sort(chars.begin(), chars.end());
  for (int i = 299 ; i >= 0 ; --i) {
    while (chars[i].first--) {
      res.push_back(chars[i].second);
    }
  }
  return res;
}

int main (void) {
  string s;
  cin >> s;
  cout << frequencySort(s) << endl;
}
