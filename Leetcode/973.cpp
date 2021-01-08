/* Accepted */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  if (points.size() == 1) {
    return points;
  }
  priority_queue <pair <int, vector <int> >, vector <pair <int, vector <int> > >, greater <pair <int, vector <int> > > > closest;
  vector <vector <int> > res;
  for (auto a : points) {
    closest.push(make_pair((a[0] * a[0] + a[1] * a[1]), a));
  }
  while (k > 0) {
    res.push_back(closest.top().second);
    k--;
    closest.pop();
  }
  return res;
}

int main(void) {
  int n, k;
  cin >> n >> k;
  vector <vector <int> > points(n, vector <int>(2, 0));
  vector <vector <int> > res;
  for (int i = 0 ; i < n ; ++i) {
    cin >> points[i][0] >> points[i][1];
  }
  res = kClosest(points, k);
  for (auto a : res) {
    cout << a[0] << " " << a[1] << endl;
  }
  return 0;
}
