/* Accepted */
#include <iostream>
#include <string>
using namespace std;

int main (void) {
  int cases;
  int howMany;
  cin >> cases;
  while (cases--) {
    int howMany;
    int input;
    string str (200, 'a');
    cin >> howMany;
    char currChar;
    int nextCharPos;
    for (int i = 0 ; i < howMany ; ++i) {
      cin >> input;
      cout << str << "\n";
      currChar = str[input];
      nextCharPos = ((currChar - 97) + 1) % 26;
      if (nextCharPos == 0) {
        nextCharPos++;
      }
      str[input] = (char)(nextCharPos + 97);
    }
    cout << str << endl;
  }
  return 0;
}
