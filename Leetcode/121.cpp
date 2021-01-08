/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector <int>& prices) {
  if (prices.size() == 0 && prices.size() == 1) {
    return 0;
  }
  int minP = 1e9;
  int maxP = -1e9;
  int maxProfit = 0;
  for (auto a : prices) {
    if (a < minP) {
      minP = a;
      maxP = a;
      continue;
    }
    if (a > maxP) {
      maxP = a;
    }
    maxProfit = max(maxProfit, maxP - minP);
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
