/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int main (void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  int m;
  int k;
  int Fedor;
  int friends;
  int difference;
  cin >> n >> m >> k;
  vector <int> players(m);
  for (int i = 0 ; i < m ; ++i) {
    cin >> players[i];
  }
  cin >> Fedor;
  friends = 0;
  for (auto a : players) {
    difference = 0;
    for (int i = 0 ; i <= n ; ++i) {
      if (((Fedor & (1 << i)) != 0 && (a & (1 << i)) == 0) || ((Fedor & (1 << i)) == 0 && (a & (1 << i)) != 0)) {
        difference++;
      }
    }
    if (difference <= k) {
      friends++;
    }
  }
  cout << friends << endl;

  return 0;
}
