/* Accepted */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortByDif(vector <int>& one, vector <int>& two) {
  return (one[0] - one[1] < two[0] - two[1]);
}

int twoCitySchedCost(vector <vector <int> >& costs) {
  if (costs.size() == 0) {
    return 0;
  }
  int sumOne = 0;
  int sumTwo = 0;
  sort(costs.begin(), costs.end(), sortByDif);
  int i = 0;
  int j = costs.size() - 1;
  while (i < j) {
    sumOne += costs[i][0];
    sumTwo += costs[j][1];
    i++;
    j--;
  }
  return (sumOne + sumTwo);
}

int main(void) {
  int n;
  cin >> n;
  vector <vector <int> > costs(n, vector <int> (2, 0));
  for (int i = 0 ; i < n ; ++i) {
    cin >> costs[i][0] >> costs[i][1];
  }
  cout << twoCitySchedCost(costs) << endl;
}
