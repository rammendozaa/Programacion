#include <string>
#include <iostream>
using namespace std;

int main (void) {
  string one, two;
  cin >> one >> two;
  if (one.length() != two.length()) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0 ; i < one.length() ; ++i) {
    if (one[i] != two[one.length() - 1 - i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
