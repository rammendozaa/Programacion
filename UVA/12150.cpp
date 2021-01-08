/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int cars;
  bool isPossible;
  while (cin >> cars && cars != 0) {
    vector <vector <int> > newOrder(cars, vector <int> (2));
    vector <int> startingOrder(cars, -1);
    isPossible = true;
    for (int i = 0 ; i < cars ; ++i) {
      cin >> newOrder[i][0] >> newOrder[i][1];
    }
    for (int i = 0 ; i < cars ; ++i) {
      if (((newOrder[i][1] + i) >= cars) || ((newOrder[i][1] + i) < 0) || startingOrder[newOrder[i][1] + i] != -1) {
        isPossible = false;
        break;
      }
      startingOrder[i + newOrder[i][1]] = newOrder[i][0];
    }
    if (isPossible) {
      for (int i = 0 ; i < cars - 1 ; ++i) {
        cout << startingOrder[i] << " ";
      }
      cout << startingOrder[cars - 1] << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
