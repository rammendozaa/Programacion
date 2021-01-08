/* Accepted */
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int coinChangeRec(vector <int>& dp, int amount, vector <int>& coins) {
  if (amount < 0) {
    return 1e9;
  }
  int minV = 1e9;
  if (dp[amount] == -1) {
    for (auto a : coins) {
      minV = min(minV, coinChangeRec(dp, amount - a, coins));
    }
    dp[amount] = minV + 1;
  }
  return dp[amount];
}

int coinChange(vector <int>& coins, int amount) {
  if (amount == 0) {
    return 0;
  }
  vector <int> dp(amount + 1, -1);
  dp[0] = 0;
  int res = coinChangeRec(dp, amount, coins);
  return (res == (1e9 + 1)) ? -1 : res;
}

int main(void) {
  int n, am;
  cin >> n >> am;
  vector <int> coins(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> coins[i];
  }
  cout << coinChange(coins, am) << endl;
}
