/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int minOperationsMaxProfit(vector <int>& cust, int board, int run) {
  vector <int> profitV(1, 0);
  int profit;
  int waiting = 0;
  for (int i = 0 ; i < cust.size() ; ++i) {
    waiting += cust[i];
    profit = (board * min(4, waiting) - run);
    int back = profitV.back();
    profitV.push_back(back + profit);
    waiting -= min(4, waiting);
  }
  while (waiting > 0) {
    profit = (board * min(4, waiting) - run);
    int back = profitV.back();
    profitV.push_back(back + profit);
    waiting -= min(4, waiting);
  }
  int maxProfit = 0;
  int index = -1;
  for (int i = 0 ; i < profitV.size() ; ++i) {
    if (maxProfit < profitV[i]) {
      maxProfit = profitV[i];
      index = i;
    }
  }
  return (maxProfit <= 0) ? -1 : index;
}

int main(void) {
  int board, run, n;
  cin >> board >> run;
  vector <int> cust;
  while (cin >> n) {
    cust.push_back(n);
  }
  for (auto a : cust) {
    cout << a << " ";
  }
  cout << endl;
  cout << minOperationsMaxProfit(cust, board, run) << endl;
}
