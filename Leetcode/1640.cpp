/* Accepted */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool canFormArray(vector <int>& arr, vector <vector <int> >& pieces) {
  unordered_map <int, int> numToCount;
  unordered_map <int, int> numToIndexArr;
  for (int i = 0 ; i < arr.size() ; ++i) {
    numToCount[arr[i]]++;
    numToIndexArr[arr[i]] = i;
  }
  for (auto a : pieces) {
    for (auto b : a) {
      numToCount[b]++;
    }
  }
  for (auto a : numToCount) {
    if (a.second == 1) {
        return false;
    }
  }
  for (int ind = 0 ; ind < pieces.size() ; ++ind) {
    int starting = pieces[ind][0];
    int arrI = numToIndexArr[pieces[ind][0]];
    int j = 0;
    while (arrI < arr.size() && j < pieces[ind].size()) {
      if (arr[arrI] != pieces[ind][j]) {
        return false;
      }
      j++;
      arrI++;
    }
    if (j != pieces[ind].size()) {
      return false;
    }
  }
  return true;
}

int main(void) {
  int n;
  int m;
  int c;
  cin >> n;
  vector <int> arr(n, 0);
  for (int i = 0 ; i < n ; ++i) {
    cin >> arr[i];
  }
  cin >> m;
  vector <vector <int> > pieces(m);
  for (int i = 0 ; i < m ; ++i) {
    cin >> c;
    int auxI;
    for (int j = 0 ; j < c ; ++j) {
      cin >> auxI;
      pieces[i].push_back(auxI);
    }
  }
  cout << canFormArray(arr,pieces) << endl;
}
