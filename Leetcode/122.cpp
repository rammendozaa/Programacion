/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector <int>& prices) {
  int maxProfit = 0;
  int i = 0;
  int j;
  while (i < prices.size()) {
    j = i + 1;
    while (j < prices.size() && prices[j] > prices[j - 1]) {
      j++;
    }
    maxProfit += max(prices[j - 1] - prices[i], 0);
    i = j;
  }
  return maxProfit;
}

int main(void) {
  int n;
  cin >> n;
  vector <int> prices(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> prices[i];
  }
  cout << maxProfit(prices) << endl;
}
