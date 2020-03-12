/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int lastNegative(vector <int>& vec) {
  int posN = vec.size() - 1;
  int posP = vec.size() - 1;
  while(posN >= 0 && vec[posN] <= 0) {
    posN--;
  }
  int end = posN;
  if (posN < 0) {
    return -1;
  }
  for (int i = posN - 1 ; i >= 0 ; --i) {
    if (vec[i] <= 0) {
      swap(vec[i], vec[end]);
      end--;
    }
  }
  return end;
}

int firstMissingPositive(vector <int>& vec) {
  int j = lastNegative(vec);
  if (j == -1) {
    return 1;
  }
  for (int i = 0 ; i <= j ; ++i) {
    if (vec[i] - 1 <= j && vec[vec[i] - 1] > 0) {
      vec[abs(vec[i]) - 1] *= -1;
    }
  }
  for (int i = 0 ; i <= j ; ++i) {
    if (vec[i] > 0) {
      return i + 1;
    }
  }
  return j + 2;
}

int main(void) {
  int n;
  cin >> n;
  vector <int> vec(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> vec[i];
  }
  cout << firstMissingPositive(vec) << endl;
}
