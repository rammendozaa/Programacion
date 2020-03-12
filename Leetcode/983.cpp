/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int binaryFindNext(vector <int>& days, int day) {
  int ini = 0;
  int fin = days.size() - 1;
  int mid;
  while(ini <= fin) {
    mid = (ini + fin) >> 1;
    if (days[mid] < day) {
      ini = mid + 1;
    } else {
      if (mid - 1 == -1 || days[mid - 1] < day) {
        return mid;
      }
      fin = mid - 1;
    }
  }
  return -1;
}

int helperMinCostTickets(vector <int>& days, vector <int>& cost,
  vector <int>& DP, int index) {
    if (index == -1) {
      return 0;
    }
    if (DP[index] == -1) {
      int proxDay = binaryFindNext(days, days[index] + 1);
      int proxSevenDays = binaryFindNext(days, days[index] + 7);
      int proxMonth = binaryFindNext(days, days[index] + 30);
      int fOption = cost[0] + helperMinCostTickets(days, cost, DP, proxDay);
      int sOption = cost[1] + helperMinCostTickets(days, cost, DP, proxSevenDays);
      int tOption = cost[2] + helperMinCostTickets(days, cost, DP, proxMonth);
      DP[index] = min(fOption, min(sOption, tOption));
    }
    return DP[index];
}

int mincostTickets(vector <int>& days, vector <int>& cost) {
  vector <int> DP(days.size(), -1);
  return helperMinCostTickets(days, cost, DP, 0);
}

int main(void) {
  int days;
  cin >> days;
  vector <int> daysVec(days);
  vector <int> cost(3);
  for (int i = 0 ; i < days ; ++i) {
    cin >> daysVec[i];
  }
  for (int i = 0 ; i < 3 ; ++i) {
    cin >> cost[i];
  }
  cout << mincostTickets(daysVec, cost) << endl;
}
