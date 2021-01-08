// Accepted
// Word Ladder - Leetcode
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

void addMissingLetterWords(string input, unordered_map <string, vector <string> >& missingLetterWords) {
  for (int i = 0 ; i < input.size() ; ++i) {
    string auxStr = input;
    auxStr[i] = '.';
    missingLetterWords[auxStr].push_back(input);
  }

}

int ladderLength(string iniWord, string endWord, vector <string>& words) {
  if (find(words.begin(), words.end(), endWord) == words.end()) {
    return 0;
  }
  unordered_map <string, vector <string> > missingLetterWords;
  for (auto a : words) {
    addMissingLetterWords(a, missingLetterWords);
  }
  unordered_map <string, bool> visited;
  visited[iniWord] = true;
  queue <pair <string, int> > q;
  q.push(make_pair(iniWord, 1));
  while (!q.empty()) {
    pair <string, int> auxQ = q.front();
    q.pop();
    for (int i = 0 ; i < auxQ.first.size() ; ++i) {
      string auxStr = auxQ.first;
      auxStr[i] = '.';
      for (auto a : missingLetterWords[auxStr]) {
        if (a.compare(endWord) == 0) {
          return auxQ.second + 1;
        }
        if (visited.find(a) == visited.end()) {
          visited[a] = true;
          q.push(make_pair(a, auxQ.second + 1));
        }
      }
    }
  }
  return 0;
}


int main(void) {
  string iniWord;
  string finWord;
  int n;
  cin >> iniWord >> finWord >> n;
  vector <string> words(n);
  for (int i = 0 ; i < n ; ++i) {
    cin >> words[i];
  }
  if (find(words.begin(), words.end(), finWord) == words.end()) {
    cout << 0 << endl;
  } else {
    cout << ladderLength(iniWord, finWord, words) << endl;
  }
  return 0;
}
