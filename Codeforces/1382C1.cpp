/* Accepted */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void flipStr(string& str, int pos) {
  int i = 0;
  int j = pos;
  while (i <= j) {
    str[i] = (str[i] == '0') ? '1' : '0';
    if (j != i) {
      str[j] = (str[j] == '0') ? '1' : '0';
    }
    swap(str[i], str[j]);
    i++;
    j--;
  }
}

int findSimilar(string& one, string& two, int index) {
  while (index >= 0 && one[index] == two[index]) {
    index--;
  }
  return (index < 0) ? -1 : index;
}

vector <int> solve(string& start, string& end) {
  vector <int> moves;
  int findIndex = start.length() - 1;
  int currIndex = start.length() - 1;
  int i = 0;
  while (currIndex >= 0) {
    if (start[0] != end[currIndex]) {
      flipStr(start, currIndex);
      moves.push_back(currIndex + 1);
    } else {
      while (findIndex >= 0 && start[findIndex] != end[currIndex]) {
        findIndex--;
      }
      flipStr(start, findIndex);
      moves.push_back(findIndex + 1);
      flipStr(start, currIndex);
      moves.push_back(currIndex + 1);
    }
    currIndex = findSimilar(start, end, currIndex);
    findIndex = currIndex;
    i++;
  }
  return moves;
}

int main (void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int cases;
  cin >> cases;
  while (cases--) {
    int n;
    string one, two;
    vector <int> res;
    cin >> n;
    cin >> one >> two;
    if (one == two) {
      cout << 0 << endl;
    } else {
      res = solve(one, two);
      cout << res.size();
      for (auto a : res) {
        cout << " " << a;
      }
      cout << endl;
    }
  }
  return 0;
}
