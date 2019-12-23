// Accepted
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(void) {
  int cases;
  cin >> cases;
  while(cases--) {
    int money;
    int n;
    cin >> money >> n;
    vector <pair<int, int>> prices;
    for (int i = 0 ; i < n ; ++i) {
      int value;
      cin >> value;
      prices.push_back(make_pair(value, i));
    }
    sort(prices.begin(), prices.end());
    int i = 0;
    int j = n - 1;
    while (i < j) {
      if (prices[i].first + prices[j].first == money) {
        int small;
        int big;
        small = prices[i].second;
        big = prices[j].second;
        if (big < small) {
          swap(big, small);
        }
        cout << small + 1 << " " << big + 1 << endl;
        break;
      }
      if (prices[i].first + prices[j].first < money) {
        i++;
      } else {
        j--;
      }
    }
  }
}
