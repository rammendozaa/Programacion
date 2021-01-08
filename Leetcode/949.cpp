#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void addZeroes(string& hour) {
  while (hour.size() < 4) {
    hour.insert(0, 1, '0');
  }
}

bool validHour(vector <int>& A) {
  return (A[0] == 2) ? A[1] <= 3 && A[2] <= 5 : A[0] <= 1 && A[2] <= 5;
}

int turnToDigit(vector <int>& A) {
  return (A[0] * 1000 + A[1] * 100 + A[2] * 10 + A[3]);
}

string largestTimeFromDigits(vector <int>& A) {
  int maxHour = -1;
  sort(A.begin(), A.end());
  do {
    if (validHour(A)) {
      maxHour = max(maxHour, turnToDigit(A));
    }
  } while (next_permutation(A.begin(), A.end()));
  string maxHourStr = to_string(maxHour);
  addZeroes(maxHourStr);
  maxHourStr.insert(2, 1, ':');
  return (maxHourStr == "-1:") ? "" : maxHourStr;
}

int main(void) {
  vector <int> A(4);
  for (int i = 0 ; i < 4 ; ++i) {
    cin >> A[i];
  }

  cout << largestTimeFromDigits(A) << endl;
}
