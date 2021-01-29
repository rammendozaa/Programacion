//TLE
#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;


/*
int removeabba(string &s, vector <int>& index, int points) {
  string aux = "";
  int ind = 0;
  int totalP = 0;
  for (int i = 0 ; i < s.length() ; ) {
    if (ind < index.size() && (index[ind] == i)) {
      ind++;
      totalP += points;
      i += 2;
    } else {
      aux.push_back(s[i]);
      i++;
    }
  }
  s = aux;
  return totalP;
}

bool findab(string& s, vector <int>& index, bool& found) {
  for (int i = 0 ; i < s.length() - 1 ; ++i) {
    if (s[i] == 'a' && s[i + 1] == 'b') {
      index.push_back(i);
      found = true;
    }
  }
  return found;
}

bool findba(string& s, vector <int>& index, bool& found) {
  for (int i = 0 ; i < s.length() - 1 ; ++i) {
    if (s[i] == 'b' && s[i + 1] == 'a') {
      index.push_back(i);
      found = true;
    }
  }
  return found;
}


int maximumGain(string s, int x, int y) {
  //x -> ab
  //y -> ba
  //remove both
  //first ab
  string sAb = s;
  string sBa = s;
  int remAb = 0;
  bool foundAb;
  bool foundBa;
  vector <int> indexAb;
  vector <int> indexBa;
  while (true) {
    foundBa = false;
    foundAb = false;
    while (findab(sAb, indexAb, foundAb)) {
      remAb += removeabba(sAb, indexAb, x);
      foundAb = false;
      indexAb.clear();
    }
    while (findba(sAb, indexBa, foundBa)) {
      remAb += removeabba(sAb, indexBa, y);
      foundBa = false;
      indexBa.clear();
    }
    if (!foundAb && !foundBa) {
      break;
    }
  }

  int remBa = 0;
  while (true) {
    foundBa = false;
    foundAb = false;
    while (findba(sBa, indexBa, foundBa)) {
      remBa += removeabba(sBa, indexBa, y);
      foundBa = false;
      indexBa.clear();
    }
    while (findab(sBa, indexAb, foundAb)) {
      remBa += removeabba(sBa, indexAb, x);
      foundAb = false;
      indexAb.clear();
    }
    if (!foundAb && !foundBa) {
      break;
    }
  }

  return max(remAb, remBa);
}
*/

int foundabba(string& s, int points, bool& found, string auxS) {
  deque <char> one;
  deque <char> two;
  int sizeBefore = 0;
  int sizeAfter = 0;
  int totalP = 0;
  char curr = '_';
  for (auto a : s) {
    one.push_back(a);
  }
  while (true) {
    if (!one.empty() && two.empty()) {
      sizeBefore = one.size();
      while (!one.empty()) {
        curr = one.front();
        one.pop_front();
        if (curr == auxS[0] && !one.empty() && one.front() == auxS[1]) {
          one.pop_front();
          found = true;
          totalP += points;
          if (!one.empty()) {
            curr = one.front();
            one.pop_front();
          } else {
            curr = '_';
          }
        }
        if (curr != '_') {
          two.push_back(curr);
        }
      }
      sizeAfter = two.size();
    } else if (one.empty() && !two.empty()) {
      sizeBefore = two.size();
      while (!two.empty()) {
        curr = two.front();
        two.pop_front();
        if (curr == auxS[0] && !two.empty() && two.front() == auxS[1]) {
          two.pop_front();
          found = true;
          totalP += points;
          if (!two.empty()) {
            curr = two.front();
            two.pop_front();
          } else {
            curr = '_';
          }
        }
        if (curr != '_') {
          one.push_back(curr);
        }
      }
      sizeAfter = one.size();
    }
    if (!found || sizeBefore == sizeAfter) {
      break;
    }
  }
  string helperStr = "";
  while (!two.empty()) {
    helperStr.push_back(two.front());
    two.pop_front();
  }
  while (!one.empty()) {
    helperStr.push_back(one.front());
    one.pop_front();
  }cout<< helperStr << endl;
  s = helperStr;
  return totalP;
}

int maximumGain(string s, int x, int y) {
  bool foundAb = false;
  bool foundBa = false;
  int pointsBa = 0;
  int pointsAb = 0;
  string baF = s;
  string abF = s;
  while (true) {
    foundAb = false;
    foundBa = false;
    pointsBa += foundabba(baF, y, foundBa, "ba");
    pointsBa += foundabba(baF, x, foundAb, "ab");
    if (!foundAb && !foundBa) {
      break;
    }
  }
  while (true) {
    foundAb = false;
    foundBa = false;
    pointsAb += foundabba(abF, x, foundAb, "ab");
    pointsAb += foundabba(abF, y, foundBa, "ba");
    cout << pointsAb << endl;
    if (!foundAb && !foundBa) {
      break;
    }
  }

  return max(pointsBa, pointsAb);
}

int main(void) {
  string s;
  int x;
  int y;
  while (cin >> s) {
    cin >> x;
    cin >> y;
    cout << maximumGain(s, x, y) << endl;
  }
  return 0;
}
