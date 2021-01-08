/* Accepted */
#include <iostream>
#include <vector>
using namespace std;

bool validDFS(int node, vector <vector <int> >& adj, vector <int>& vis) {
  if (vis[node] == 1) {
    return false;
  }
  if (vis[node] == 0) {
    vis[node] = 1;
    for (auto edge : adj[node]) {
      if (!validDFS(edge, adj, vis)) {
        return false;
      }
    }
  }
  vis[node] = -1;
  return true;
}

bool checkForCycle(int courses, vector <vector <int> >& adj) {
  vector <int> vis(courses, 0);
  for (int i = 0 ; i < courses ; ++i) {
    if (!validDFS(i, adj, vis)) {
      return true;
    }
  }
  return false;
}

//https://www.geeksforgeeks.org/topological-sorting/
void topologicalSort(int node, vector <int>& vis, vector <vector <int> >& edges, vector <int>& res) {
  if (vis[node] == 1) {
    return;
  }
  if (vis[node] == 0) {
    vis[node] = 1;
    for (auto edge : edges[node]) {
      topologicalSort(edge, vis, edges, res);
    }
  }
  res.push_back(node);
}

vector <int> findOrder(int courses, vector <vector <int> >& pre) {
  if (pre.size() == 0) {
    return {};
  }

  bool isCycle = false;
  vector <int> res;
  vector <int> vis(courses);
  vector <vector <int> > adj(courses);

  for (auto a : pre) {
    if (a[0] != a[1]) {
      adj[a[1]].push_back(a[0]);
    }
  }

  isCycle = checkForCycle(courses, adj);
  if (isCycle) {
    return {};
  }

  for (int i = 0 ; i < courses ; ++i) {
    topologicalSort(i, vis, adj, res);
  }

  reverse(res.begin(), res.end());
  return res;
}

int main(void) {
  int c, n;
  cin >> c >> n;
  vector <vector <int> > pre(n, vector <int> (2, 0));
  vector <int> res;
  for (int i = 0 ; i < n ; ++i) {
    cin >> pre[i][0] >> pre[i][1];
  }
  res = findOrder(c, pre);
  for (auto a : res) {
    cout << a << " ";
  }
  cout << endl;

  return 0;
}
