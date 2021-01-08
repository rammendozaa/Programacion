/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int main (void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int cases, sizeOne, sizeTwo, input, res;
  bool inside = false;
  cin >> cases;
  while (cases--) {
    cin >> sizeOne >> sizeTwo;
    res = 1e9;
    inside = false;
    vector <int> one(1001, 0);
    vector <int> two(1001, 0);
    for (int i = 0 ; i < sizeOne ; ++i) {
      cin >> input;
      one[input]++;
    }
    for (int i = 0 ; i < sizeTwo ; ++i) {
      cin >> input;
      two[input]++;
    }
    for (int i = 0 ; i < 1001 ; ++i) {
      if (one[i] > 0 && two[i] > 0) {
        inside = true;
        cout << "YES\n1 " << i << endl;
        break;
      }
    }
    if (!inside) {
      cout << "NO\n";
    }
  }
  return 0;
}
