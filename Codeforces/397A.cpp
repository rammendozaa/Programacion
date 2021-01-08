#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  int start, finish;
  cin >> n;
  cin >> start >> finish;
  n--;
  if (n == 0) {
    cout << finish - start << endl;
    return 0;
  }
  vector <vector <int> > ranges(n, vector <int> (2, 0));
  vector <vector <int> > newRanges;
  for (int i = 0 ; i < n ; ++i) {
    int ini, fin;
    cin >> ini >> fin;
    if (ini > finish || fin < start) {
      continue;
    }
    if (fin > finish) {
      fin = finish;
    }
    if (ini < start) {
      ini = start;
    }
    vector <int> aux;
    aux.push_back(ini);
    aux.push_back(fin);
    ranges.push_back(aux);
  }

  sort(ranges.begin(), ranges.end());
  newRanges.push_back(ranges[0]);

  int i = 0;
  int sum = finish - start;
  while (i < ranges.size()) {
    if (ranges[i][0] <= newRanges.back()[1]) {
      newRanges.back()[1] = max(ranges[i][1], newRanges.back()[1]);
    } else {
      newRanges.push_back(ranges[i]);
    }
    i++;
  }

  for (auto a : newRanges) {
    sum -= (a[1] - a[0]);
  }

  cout << sum << endl;
  return 0;
}
