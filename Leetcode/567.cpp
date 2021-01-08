/* Accepted */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool compareVectors (vector <int>& one, vector <int>& two) {
  for (int i = 0 ; i < one.size() ; ++i) {
    if (one[i] != two[i]) {
      return false;
    }
  }
  return true;
}

bool checkInclusion(string one, string two) {
  if (one.length() > two.length()) {
    return false;
  }

  vector <int> oneVec (27, 0);
  vector <int> twoVec (27, 0);

  for (auto a : one) {
    oneVec[a - 97]++;
  }

  for (int i = 0 ; i < one.length() ; ++i) {
    twoVec[two[i] - 97]++;
  }

  if (compareVectors(oneVec, twoVec)) {
    return true;
  }

  for (int i = 1 ; i <= (two.length() - one.length()) ; ++i) {
    twoVec[two[i - 1] - 97]--;
    twoVec[two[i + one.length() - 1] - 97]++;
    if (compareVectors(oneVec, twoVec)) {
      return true;
    }
  }
  return false;
}

int main (void) {
  string one, two;
  cin >> one >> two;
  cout << checkInclusion(one, two) << endl;
}
