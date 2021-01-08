/* Accepted */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void printArray(vector <int>& array) {
  if (array.size() == 0) {
    cout << endl;
    return;
  }
  cout << " ";
  for (int i = 0 ; i < array.size() - 1 ; ++i) {
    cout << array[i] << " ";
  }
  cout << array[array.size() - 1] << endl;
}

void printEquals(vector <vector <int> >& solved) {
  vector <int> print;
  int sizeOne, sizeTwo, sizeThree, maxSize;
  sizeOne = solved[0].size();
  sizeTwo = solved[1].size();
  sizeThree = solved[2].size();
  maxSize = max(sizeOne, max(sizeTwo, sizeThree));
  for (int i = 0 ; i < 3 ; ++i) {
    if (solved[i].size() == maxSize) {
      print.push_back(i);
    }
  }
  for (int i = 0 ; i < print.size() ; ++i) {
    cout << to_string(print[i] + 1) << " " << solved[print[i]].size();
    printArray(solved[print[i]]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int cases;
  int caseNo = 1;
  cin >> cases;
  while (cases--) {
    cout << "Case #" << caseNo << ":\n";
    caseNo++;
    vector <set <int> > problems(10001);
    vector <vector <int> > solved(3);
    set <int> answered;
    int friendOne, friendTwo, friendThree, auxP;
    cin >> friendOne;
    for (int i = 0 ; i < friendOne ; ++i) {
      cin >> auxP;
      problems[auxP].insert(0);
      answered.insert(auxP);
    }
    cin >> friendTwo;
    for (int i = 0 ; i < friendTwo ; ++i) {
      cin >> auxP;
      problems[auxP].insert(1);
      answered.insert(auxP);
    }
    cin >> friendThree;
    for (int i = 0 ; i < friendThree ; ++i) {
      cin >> auxP;
      problems[auxP].insert(2);
      answered.insert(auxP);
    }
    for (auto a : answered) {
      if (problems[a].size() == 1) {
        solved[*problems[a].begin()].push_back(a);
      }
    }
    if (solved[0].size() > solved[1].size() && solved[0].size() > solved[2].size()) {
      cout << 1 << " " << solved[0].size();
      printArray(solved[0]);

    } else if (solved[1].size() > solved[0].size() && solved[1].size() > solved[2].size()) {
      cout << 2 << " " << solved[1].size();
      printArray(solved[1]);
    } else if (solved[2].size() > solved[0].size() && solved[2].size() > solved[1].size()) {
      cout << 3 << " " << solved[2].size();
      printArray(solved[2]);
    } else {
      printEquals(solved);
    }
  }
  return 0;
}
