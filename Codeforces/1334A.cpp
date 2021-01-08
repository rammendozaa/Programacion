/* Accepted */
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void solve(vector <pair <int, int> >& plays) {
    int lastPlay;
    int lastClear;
    if (plays[0].second > plays[0].first) {
      cout << "NO\n";
      return;
    }
    for (int i = 1 ; i < plays.size() ; ++i) {
      lastPlay = plays[i - 1].first;
      lastClear = plays[i - 1].second;
      if ((plays[i].second - plays[i - 1].second > plays[i].first - plays[i - 1].first) || plays[i].second > plays[i].first || plays[i].first < lastPlay || plays[i].second < lastClear || (plays[i].first == lastPlay && plays[i].second > lastClear)) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    return;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int cases;
  cin >> cases;
  while (cases--) {
    int n;
    cin >> n;
    vector <pair <int, int> > plays;
    for (int i = 0 ; i < n ; ++i) {
      int a, b;
      cin >> a >> b;
      plays.push_back(make_pair(a, b));
    }
    solve(plays);
  }
}
