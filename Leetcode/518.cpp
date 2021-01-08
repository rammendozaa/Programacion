/* Accepted */
#include <vector>
#include <iostream>
using namespace std;

//recursive - mine (i think its better and more understandable)
int coinChangeRec(int index, int amount, vector <int>& coins, vector <vector <int> >& dp) {
  if (amount == 0) {
    return 1;
  }
  if (amount < 0 || index >= coins.size()) {
    return 0;
  }
  // take or not this coin - add the result of taking it and not doing so
  if (dp[index][amount] == -1) {
    int sumWith = coinChangeRec(index, amount - coins[index], coins, dp);
    int sumWithout = coinChangeRec(index + 1, amount, coins, dp);
    dp[index][amount] = (sumWith + sumWithout);
  }
  return dp[index][amount];
}

//iterative
int coinChangeRec(vector <int>& coins, vector <vector <int> >& dp, int amount) {
  dp[0][0] = 1;
  for (int i = 1 ; i <= coins.size() ; ++i) {
    dp[i][0] = 1;
    for (int j = 1 ; j <= amount ; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - coins[i - 1] >= 0) {
        dp[i][j] += dp[i][j - coins[i - 1]];
      }
    }
  }
  return dp[coins.size()][amount];
}

int change(vector <int>& coins, int amount) {
  if (amount == 0) {
    return 1;
  }
  vector <vector <int> > dp(coins.size() + 1, vector <int> (amount + 1, 0));
  int res = coinChangeRec(coins, dp, amount);
  for (auto a : dp) {
    for (auto b : a) {
      cout << b << " ";
    }
    cout << endl;
  }
  return res;
}

int main(void) {
  int n, am;
  cin >> n >> am;
  vector <int> coins(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> coins[i];
  }
  cout << change(coins, am) << endl;
}
