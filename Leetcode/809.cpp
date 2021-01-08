// Accepted
// Expressive Words - LeetCode
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> createGroups(string& str) {
    int i = 0;
    int n = str.length();
    vector <string> groups;
    while (i < n) {
        string repeat = "";
        char letter = str[i];
        while(i < n && str[i] == letter) {
            repeat += letter;
            i++;
        }
        groups.push_back(repeat);
    }
    return groups;
}

int findExpressiveWords(vector <string>& group, vector <vector <string> >& pals) {
    int total = 0;
    bool expressive = true;
    for (auto a : pals) {
      if (group.size() == a.size()) {
        for (int i = 0 ; i < group.size() ; i++) {
          if (group[i].length() == a[i].length() && group[i][0] == a[i][0]) {
            continue;
          } else if (group[i].length() < 3 || group[i][0] != a[i][0]) {
            expressive = false;
            break;
          }
        }
        if (expressive) {
          total++;
        } else {
          expressive = true;
        }

      }
    }
    return total;
}

int expressiveWords(string S, vector <string>& words) {
    if (S.length() == 0 || words.size() == 0) {
        return 0;
    }

    vector <string> groups = createGroups(S);
    vector <vector <string> > pals;
    for (auto a : words) {
        if (a.length() > 0 && a.length() <= S.length()) {
            vector <string> aux = createGroups(a);
            pals.push_back(aux);
        }
    }
    int res = findExpressiveWords(groups, pals);
    return res;
}

int main(void) {
  string S;
  cin >> S;
  int n;
  cin >> n;
  vector <string> str(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> str[i];
  }
  cout << expressiveWords(S, str) << endl;
}
