// Accepted
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int n;
  int k;
  cin >> n >> k;
  vector <int> luck;
  int input;
  int important;
  int sumLuck = 0;
  for (int i = 0 ; i < n ; ++i) {
    cin >> input >> important;
    if (important == 0) {
      sumLuck += input;
    } else {
      luck.push_back(input);
    }
  }
  sort(luck.begin(), luck.end());
  int numberSubtract = luck.size() - k;
  int i = 0;
  while (i < numberSubtract) {
    sumLuck -= luck[i];
    i++;
  }
  while (i < luck.size()) {
    sumLuck += luck[i];
    i++;
  }
  cout << sumLuck << endl;

}
