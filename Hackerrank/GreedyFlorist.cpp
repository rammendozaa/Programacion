// Accepted
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int n;
  int k;
  cin >> n >> k;
  int remaining = (n % k);
  vector <int> cost(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> cost[i];
  }
  //sort(cost.begin(), cost.end());
  int sumCost = 0;
  int groupNumber = 0;
  for (int i = n - 1 ; i >= k - 1 ; i -= k, groupNumber++) {
    for (int j = i ; j > i - k; --j) {
      sumCost += (groupNumber + 1) * cost[j];
    }
  }
  for (int i = 0 ; i < remaining ; ++i) {
    sumCost += cost[i] * (groupNumber + 1);
  }
  cout << sumCost << endl;
}
