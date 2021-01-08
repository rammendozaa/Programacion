/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
  vector<vector<int>>& B) {
    if (A.size() == 0 || B.size() == 0) {
      return {};
    }
    int i = 0;
    int j = 0;
    vector <vector <int> > res;
    while (i < A.size() && j < B.size()) {
      if (A[i][1] == B[j][1]) {
        res.push_back({max(A[i][0], B[j][0]), A[i][1]});
        i++;
        j++;
      } else if ((A[i][0] <= B[j][0] && A[i][1] >= B[j][1]) || (B[j][0] <= A[i][0] && B[j][1] >= A[i][1])) {
        if ((A[i][0] < B[j][0] && A[i][1] >= B[j][1])) {
          res.push_back(B[j]);
          j++;
        } else {
          res.push_back(A[i]);
          i++;
        }
      } else if (A[i][1] < B[j][0] || B[j][1] < A[i][0]){
        if (A[i][1] < B[j][0]) {
          i++;
        } else {
          j++;
        }
      } else if ((A[i][1] > B[j][1] && A[i][0] > B[j][0]) || (A[i][1] < B[j][1] && A[i][0] < B[j][0])) {
        if ((A[i][1] > B[j][1] && A[i][0] > B[j][0])) {
          res.push_back({A[i][0], B[j][1]});
          j++;
        } else {
          res.push_back({B[j][0], A[i][1]});
          i++;
        }
      }
    }
    return res;
}

int main(void) {
  int a, b;
  cin >> a >> b;
  vector <vector <int> > A(a, vector <int>(2, 0));
  vector <vector <int> > B(b, vector <int>(2, 0));
  vector <vector <int> > res;
  for (int i = 0 ; i < a ; ++i) {
    cin >> A[i][0] >> A[i][1];
  }
  for (int i = 0 ; i < b ; ++i) {
    cin >> B[i][0] >> B[i][1];
  }
  /*
  for (auto a : A) {
    cout << a[0] << " " << a[1] << endl;
  }
  cout << endl;
  for (auto b : B) {
    cout << b[0] << " " << b[1] << endl;
  }
  cout << endl;
  */
  res = intervalIntersection(A, B);
  for (auto a : res) {
    cout << a[0] << " " << a[1] << endl;
  }
  return 0;
}
