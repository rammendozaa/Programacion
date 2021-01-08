/* Accepted */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool mycomp(int a, int b) {
  return a > b;
}

int main (void) {
  int n;
  int sum = 0;
  cin >> n;
  vector <int> coins(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> coins[i];
    sum += coins[i];
  }
  double halfSum = (double)sum / (double)2;
  sort(coins.begin(), coins.end(), mycomp);
  int i = 0;
  int currSum = 0;
  while ((double)currSum <= halfSum && i < n) {
    currSum += coins[i];
    i++;
  }
  cout << i << endl;
  return 0;
}
