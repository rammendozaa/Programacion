/* Accepted */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int minDistance(string one, string two) {
  int n = one.length();
  int m = two.length();
  if (n == 0 || m == 0) {
    return max(n, m);
  }
  if (one == two) {
    return 0;
  }
  vector <vector <int> > dp(n + 1, vector <int> (m + 1, 0));

  for (int i = 0, k = m ; i < m ; ++i, --k) {
    dp[n][i] = k;
  }
  for (int i = 0, k = n ; i < n ; ++i, --k) {
    dp[i][m] = k;
  }

  for (int i = n - 1 ; i >= 0 ; --i) {
    for (int j = m - 1; j >= 0 ; --j) {
      if (one[i] == two[j]) {
          dp[i][j] = dp[i + 1][j + 1];
      } else {
        dp[i][j] = 1 + min(dp[i + 1][j + 1], min(dp[i][j + 1], dp[i + 1][j]));
      }
    }
  }
  return dp[0][0];
}

// Basically the same thing
/*
int minDistance(string one, string two) {
  int n = one.length();
  int m = two.length();
  if (n == 0 || m == 0) {
    return max(n, m);
  }
  vector <vector <int> > dp(n + 1, vector <int> (m + 1, 1e9));
  for (int i = 1 ; i <= m ; ++i) {
    dp[0][i] = i;
  }
  for (int i = 1 ; i <= n ; ++i) {
    dp[i][0] = i;
  }

  for (int i = 1 ; i <= n ; ++i) {
    for (int j = 1; j <= m ; ++j) {
      if (one[i - 1] != two[j - 1]) {
        dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
      } else {
        dp[i][j] = dp[i - 1][j - 1];
      }
    }
  }

  return dp[n][m];
}
*/

int main(void) {
  string one, two;
  cin >> one >> two;
  cout << minDistance(one, two) << "\n\n" << minDistance(two, one) << endl;
}
