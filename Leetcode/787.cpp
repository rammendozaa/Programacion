/* To do */
#include <vector>
#include <iostream>
using namespace std;

void bfs(int currK, int K, int currNode, int finalNode, int currSum, int& minSum,
  vector <vector <int> >& adj, vector <vector <int> >& prices) {
    cout << currK << " " << currNode << " " << currSum << endl;
    if (currK > K) {
      return;
    }
    if (currK <= K && currNode == finalNode) {
      minSum = min(minSum, currSum);
      return;
    }
    for (auto a : adj[currNode]) {
      bfs(currK + 1, K, a, finalNode, currSum + (prices[currNode][a]), minSum, adj, prices);
    }
}

int findCheapestPrice(int n, vector <vector <int> >& flights, int src, int dst, int K) {
  if (flights.size() == 0) {
    return -1;
  }
  int minSum = 1e9;
  vector <vector <int> > adj(n);
  vector <vector <int> > prices(n, vector <int> (n, 0));
  for (auto a : flights) {
    adj[a[0]].push_back(a[1]);
    prices[a[0]][a[1]] = a[2];
  }
  bfs(-1, K, src, dst, 0, minSum, adj, prices);
  return (minSum == 1e9) ? -1 : minSum;
}

int main (void) {
  int n, m, src, dst, k;
  cin >> n >> m >> src >> dst >> k;
  vector <vector <int> > flights(m, vector <int> (3, 0));
  for (int i = 0 ; i < m ; ++i) {
    cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
  }
  cout << findCheapestPrice(n, flights, src, dst, k) << endl;
}
