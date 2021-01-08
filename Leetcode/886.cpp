/* Accepted */
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool validColor(int node, vector <vector <int> >& graph, unordered_map <int, int>& colorMap, int color) {
  if (colorMap.find(node) != colorMap.end()) {
    return (colorMap[node] == color);
  }
  colorMap[node] = color;
  for (auto child : graph[node]) {
    if (!validColor(child, graph, colorMap, color ^ 1)) {
      return false;
    }
  }
  return true;
}

bool possibleBipartition(int n, vector <vector <int> >& dislikes) {
  if (n == 1 || dislikes.size() == 0) {
    return true;
  }
  vector <vector <int> > graph(n + 1);
  unordered_map <int, int> colorMap;

  for (auto a : dislikes) {
    graph[a[0]].push_back(a[1]);
    graph[a[0]].push_back(a[1]);
  }
  int color;
  for (int i = 1 ; i <= n ; ++i) {
    if (colorMap.find(i) != colorMap.end()) {
      color = colorMap[i];
    } else {
      color = 1;
    }
    if (!validColor(i, graph, colorMap, color)) {
      return false;
    }
  }
  return true;
}

int main(void) {
  int n, d;
  cin >> n >> d;
  vector <vector <int> > dislikes(d, vector <int> (2, 0));
  for (int i = 0 ; i < d ; ++i) {
    cin >> dislikes[i][0] >> dislikes[i][1];
  }
  cout << possibleBipartition(n, dislikes) << endl;
}
