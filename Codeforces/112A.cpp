/* Accepted */
#include <string>
#include <iostream>
using namespace std;

int main (void) {
  string one, two;
  int res = 0;
  cin >> one >> two;
  for (int i = 0 ; i < one.length() ; ++i) {
    if (tolower(one[i]) < tolower(two[i])) {
      res = -1;
      break;
    } else if (tolower(one[i]) > tolower(two[i])) {
      res = 1;
      break;
    }
  }
  cout << res << endl;
  return 0;
}
