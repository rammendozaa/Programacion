/* Accepted */
#include <string>
#include <iostream>
using namespace std;

int main (void) {
  int cases;
  cin >> cases;
  while (cases--) {
    string input;
    cin >> input;
    if (input.length() <= 10) {
      cout << input << endl;
    } else {
      cout << input[0] + to_string(input.length() - 2) + input[input.length() - 1] << endl;
    }
  }
  return 0;
}
