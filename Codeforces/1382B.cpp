/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

int main (void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cases;
  cin >> cases;
  while (cases--) {
    int n;
    int in;
    int howManyOnes = 0;
    cin >> n;
    vector <int> nums(n);
    for (int i = 0 ; i < n ; ++i) {
      cin >> nums[i];
    }
    int i = 0;
    while (i < n - 1) {
      if (nums[i] != 1) {
        break;
      }
      howManyOnes++;
      i++;
    }
    (howManyOnes % 2 == 0) ? cout << "First\n" : cout << "Second\n";
  }
  return 0;
}
