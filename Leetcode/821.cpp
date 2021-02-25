/* Accepted */
#include <vector>
#include <iostream>
using namespace std;

vector <int> shortestToChar(string s, char c) {
  int ini;
  int fin;
  int disLeft;
  int disRight;
  vector <int> dis (s.length(), 1e9);
  vector <int> index;
  for (int i = 0 ; i < s.length() ; ++i) {
    if (s[i] == c) {
      dis[i] = 0;
      index.push_back(i);
    }
  }
  for (auto a : index) {
    ini = a - 1;
    fin = a + 1;
    disLeft = 1;
    disRight = 1;
    while (ini >= 0 && s[ini] != c && dis[ini] > disLeft) {
      dis[ini] = disLeft;
      ini--;
      disLeft++;
    }
    while (fin < s.length() && s[fin] != c && dis[fin] > disRight) {
      dis[fin] = disRight;
      fin++;
      disRight++;
    }
  }
  return dis;
}

int main(void) {
  string s;
  char c;
  cin >> s >> c;
  vector <int> res = shortestToChar(s, c);
  for (auto a : res) {
    cout << a << " ";
  }
  cout << endl;
  return 0;
}
