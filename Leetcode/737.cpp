#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int find(vector <int>& parent, int u) {
  if (u == parent[u]) {
    return u;
  }
  parent[u] = find(parent, parent[u]);
  return parent[u];
}

void union(vector <int>& parent, int u, int v) {
  int parent_u = find(parent, u);
  int parent_v = find(parent, v);
  parent[u] = parent_v;
}

bool areSentencesSimilarTwo(vector <string>& words1, vector <string>& words2,
  vector <vector <string> >& pairs) {
    if (words1.size() != words2.size() || words1.size() == 0 || words2.size() == 0 ||
      pairs.size() == 0) {
      return false;
    }
    int i = 0;
    unordered_map <string, int> words;
    unordered_map <string, set <string> > similar;
    for (auto a : pairs) {
      similar[a[0]].insert(a[1]);
      similar[a[1]].insert(a[0]);
      if (words.find(a[0]) == words.end()) {
        words[a[0]] = i;
        i++,
      }
      if (words.find(a[1]) == words.end()) {
        words[a[1]] = i;
        i++,
      }
    }
    vector <int> palabras(i + pairs.size());
    for (int j = 0 ; j < i + pairs.size() ; ++j) {
      palabras[j] = j;
    }
    for (int j = 0 ; j < pairs.size() ; ++j) {
      union(palabras, words[pairs[j][0]], j + i);
      union(palabras, words[pairs[j][1]], j + i);
    }
    // the part about how many sets is missing
  
}

int main(void) {
  int numW;
  cin >> numW;
  vector <int> wordsOne(numW);
  vector <int> wordsTwo(numW);
  for (int i = 0 ; i < numW ; ++i) {
    cin >> wordsOne[i];
  }
  for (int i = 0 ; i < numW ; ++i) {
    cin >> wordsTwo[i];
  }
  int numPairs;
  cin >> numPairs;
  vector <vector <string> >& pairs(numPairs, vector <string> (2, ""));
  for (int i = 0 ; i < numPairs ; ++i) {
    cin >> pairs[0] >> pairs[1];
  }
}
