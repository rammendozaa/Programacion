/* Accepted */
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
using namespace std;

// detect cycle based on visited nodes and adjacency vector
bool isCycle(vector <int>& visited, vector <vector <int> >& adjacent, int currNode) {
  if (visited[currNode] == 1) {
    return true;
  }
  if (visited[currNode] == 0) {
    visited[currNode] = 1;
    for (auto a : adjacent[currNode]) {
      if (isCycle(visited, adjacent, a)) {
        return true;
      }
    }
  }
  visited[currNode] = -1;
  return false;
}

bool canFinish(int numCourses, vector <vector <int> >& pre) {
  if (pre.size() == 0) {
    return true;
  }
  vector <int> visited(numCourses, 0);
  vector <vector <int> > adjacent(numCourses);
  for (auto a : pre) {
    adjacent[a[1]].push_back(a[0]);
  }
  for (int i = 0 ; i < numCourses ; ++i) {
    if (isCycle(visited, adjacent, i)) {
      return false;
    }
  }

  return true;
}

/*
bool canFinish(int numCourses, vector <vector <int> >& pre) {
  if (pre.size() < 1) {
    return true;
  }

  int currPath = 1;
  int startingPos;
  int currPos;
  vector <pair <queue <int>, map <int, bool> > > graph(numCourses);

  for (auto a : pre) {
    graph[a[1]].first.push(a[0]);
  }
  // solution by "painting" the current path
  startingPos = 0;
  while (startingPos < numCourses) {
    currPos = startingPos;
    while (!graph[currPos].first.empty()) {
      graph[currPos].second[currPath] = true;
      int auxPos = graph[currPos].first.front();
      graph[currPos].first.pop();
      currPos = auxPos;
      if (graph[currPos].second.find(currPath) != graph[currPos].second.end()) {
        return false;
      }
      graph[currPos].second[currPath] = true;
    }
    currPath++;
    if (graph[startingPos].first.empty()) {
      startingPos++;
    }
  }

  return true;
}
*/

int main(void) {
  int courses, n;
  cin >> n >> courses;
  vector <vector <int> > pre(n, vector <int>(2, 0));
  for (int i = 0 ; i < n ; ++i) {
    cin >> pre[i][0] >> pre[i][1];
  }
  cout << canFinish(courses, pre) << endl;
}
