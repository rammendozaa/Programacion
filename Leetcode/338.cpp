/* Accepted */
#include <vector>
#include <iostream>
using namespace std;

vector <int> countBits(int num) {
  vector <int> res(num + 1, 0);
  for (int i = 0 ; i <= num ; ++i) {
    res[i] = res[i / 2] + (i % 2);
  }
  return res;
}

/*
vector <int> countBits(int num) {
  if (num == 0) {
    return {0};
  }
  if (num == 1) {
    return {0, 1};
  }
  if (num == 2) {
    return {0, 1, 1};
  }
  vector <int> res(num + 1);
  int lowerBound = 2;
  res[0] = 0;
  res[1] = 1;
  res[2] = 1;
  for (int i = 3 ; i <= num ; ++i) {
    if (lowerBound * 2 == i) {
      res[i] = 1;
      lowerBound *= 2;
    } else {
      res[i] = 1 + res[(i - lowerBound)];
    }
  }
  return res;
}
*/
int main (void) {
  int n;
  cin >> n;
  vector <int> res = countBits(n);
  for (auto a : res) {
    cout << a << " ";
  }
  cout << endl;
}
