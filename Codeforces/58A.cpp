/* Accepted */
#include <iostream>
#include <string>
using namespace std;

int main (void) {
  string in;
  cin >> in;
  string hello = "hello";
  int letters = 0;
  int first = 0;
  while (first < in.length() && in[first] != 'h') {
    first++;
  }
  if (first == in.length()) {
    cout << "NO\n";
    return 0;
  }
  letters++;
  for (int i = first ; i < in.length() ; ++i) {
    if (in[i] == 'e') {
      if (letters == 1) {
        letters++;
      }
    } else if (in[i] == 'l') {
      if (letters == 3 || letters == 2) {
        letters++;
      }
    } else if (in[i] == 'o') {
      if (letters == 4) {
        letters++;
        break;
      }
    }
  }
  (letters == 5) ? cout << "YES\n" : cout << "NO\n";
  return 0;
}
