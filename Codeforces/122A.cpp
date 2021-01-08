#include <iostream>
#include <vector>
using namespace std;

int main (void) {
  int n;
  cin >> n;
  vector <int> lucky = {4, 7, 47, 74, 447, 444, 477, 474, 744, 777, 774, 747};
  for (auto a : lucky) {
    if (n % a == 0) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
