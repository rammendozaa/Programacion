/* Accepted */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

static class mycomparison
{
  vector <vector <int> > myMatrix;
public:
  mycomparison(vector <vector <int> >& matrix) {
    myMatrix = matrix;
  }
  bool operator() (const pair<int, int>& left, const pair<int, int>&right) const
  {
    return (myMatrix[left.first][left.first] > myMatrix[right.first][right.second]);
  }
};

int kthSmallest(vector <vector <int> >& matrix, int k) {
  int n = matrix.size();
  // value, then pair of index (i, j)
  typedef priority_queue <pair <int, int> , vector <pair <int, int> >, mycomparison> myqueue;
  myqueue q(matrix);
  for (int i = 0 ; i < n ; ++i) {
    q.push(make_pair(i, 0));
  }
  int number = -1e9;
  while (!q.empty() && k > 0) {
    int i = q.top().first;
    int j = q.top().second;
    q.pop();
    number = matrix[i][j];
    if (j + 1 < n) {
      q.push(make_pair(i, j + 1));
    }
    k--;
  }
  return number;
  /*
  priority_queue <pair <int, pair <int, int> >, vector <pair <int, pair <int, int> >>, greater <pair <int, pair <int, int> >> > q;
  for (int i = 0 ; i < n ; ++i) {
    pair <int, pair <int, int> > valueToIndices;
    q.push(make_pair(matrix[i][0], make_pair(i, 0)));
  }
  int i = 1;
  int number = -1e9;
  while (!q.empty() && k > 0) {
    pair <int, pair <int, int> > auxP = q.top();
    int value = auxP.first;
    int indexI = auxP.second.first;
    int indexJ = auxP.second.second;
    number = value;
    q.pop();
    if (indexJ + 1 < n) {
      q.push(make_pair(matrix[indexI][indexJ + 1], make_pair(indexI, indexJ + 1)));
    }
    k--;
  }
  return q.top().first;
  */
//  return number;
}

int main(void) {
  int n;
  int k;
  cin >> n >> k;
  vector <vector <int> > matrix(n, vector <int> (n));
  for (int i = 0 ; i < n ; ++i) {
    for (int j = 0 ; j < n ; ++j) {
      cin >> matrix[i][j];
    }
  }
  cout << kthSmallest(matrix, k) << endl;
}
