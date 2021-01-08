/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string one, string two) {
  int n = one.length() + 1;
  int m = two.length() + 1;
  vector <vector <int> > dp(n, vector <int>(m, 0));
  for (int i = 1 ; i < n ; ++i) {
    for (int j = 1 ; j < m ; ++j) {
      if (one[i - 1] == two[j - 1]) {
        dp[i][j] = min(i, max(dp[i][j - 1], 1 + dp[i - 1][j - 1]));
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[one.length()][two.length()];
}

int main(void) {
  string one, two;
  cin >> one >> two;
  cout << longestCommonSubsequence(one, two) << endl;
}
