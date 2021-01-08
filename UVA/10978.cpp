/* Accepted */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int cards;
  int j;
  int totalCount;
  int currCount;
  string auxStr;
  while (cin >> cards && cards != 0) {
    vector <string> deck(cards);
    vector <int> size(cards);
    vector <string> newOrder(cards, "-");
    for (int i = 0 ; i < cards ; ++i) {
      cin >> deck[i] >> auxStr;
      size[i] = auxStr.length() - 1;
    }
    j = 0;
    for (int i = 0 ; i < cards ; ++i) {
      totalCount = size[i];
      currCount = 1;
      while (currCount <= totalCount) {
        if (newOrder[j][0] == '-') {
          currCount++;
        }
        j = ((j + 1) % cards);
      }
      while (newOrder[j][0] != '-') {
        j = ((j + 1) % cards);
      }
      newOrder[j] = deck[i];
      j = ((j + 1) % cards);
    }
    for (int i = 0 ; i < cards - 1 ; ++i) {
      cout << newOrder[i] << " ";
    }
    cout << newOrder[cards - 1] << endl;
  }
  return 0;
}
