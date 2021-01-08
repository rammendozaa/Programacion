/* Accepted */
#include <string>
#include <iostream>
using namespace std;

int main (void) {
  string one;
  getline(cin, one);
  int i = one.length() - 2;
  while (i >= 0 && one[i] == ' ') {
    i--;
  }
  if (one[i] == 'a' || one[i] == 'e' || one[i] == 'i' || one[i] == 'o' || one[i] == 'u' || one[i] == 'y' || one[i] == 'Y' || one[i] == 'A' || one[i] == 'E' || one[i] == 'I' || one[i] == 'O' || one[i] == 'U') {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
