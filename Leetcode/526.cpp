/* Accepted */
#include <vector>
#include <iostream>
using namespace std;

void helper(int curr, int next, int n, vector <bool>& vis, vector <vector <int> >& div,
  int& count) {
    if (next > n) {
      count++;
      return;
    }
    for (auto a : div[next]) {
      if (!vis[a]) {
        vis[a] = true;
        helper(a, next + 1, n, vis, div, count);
        vis[a] = false;
      }
    }
  }

int countArrangement(int n) {
  vector <bool> vis (n + 1, false);
  vector <vector <int> > divi (n + 1);
  for (int i = 1 ; i <= n ; i++) {
    for (int j = 1 ; j <= n ; ++j) {
      if (i % j == 0 || j % i == 0) {
        divi[i].push_back(j);
      }
    }
  }
  int count = 0;
  for (auto a : divi[1]) {
    vis[a] = true;
    helper(a, 2, n, vis, divi, count);
    vis[a] = false;
  }
  return count;
}

int main(void) {
  int n;
  while (cin >> n) {
    cout << countArrangement(n) << endl;
  }
  return 0;
}
