#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>
using namespace std;

// -1 means not found
// if both are not found then add them at the end
// if only one is found then add the one not found to the one pos of found one
// if theyre both found
//  if theyre in the same, then nothing to do
//  if theyre differen then add the map to the other one and delete the smallest map in the vector pos
// i, j are the position of the map where a and b are found, i -> a and j -> b

void switchMaps(unordered_map <int, bool>& one, unordered_map <int, bool>& two) {
  for (auto a : one) {
    two[a.first] = true;
  }
}

pair <int, int> findInCircles(int a, int b, vector <unordered_map <int, bool> >&
  circles) {
    pair <int, int> pos;
    int n = circles.size();
    int posA = -1;
    int posB = -1;
    for (int i = 0 ; i < n ; ++i) {
      if (circles[i].find(a) != circles[i].end()) {
        posA = i;
      }
      if (circles[i].find(b) != circles[i].end()) {
        posB = i;
      }
    }
    pos.first = posA;
    pos.second = posB;
    return pos;
}


int main(void) {
  int q;
  int a;
  int b;
  cin >> q;
  vector <unordered_map <int, bool> > circles;
  int maxSize = -1;
  for (int i = 0 ; i < q ; i++) {
    cin >> a >> b;
    //findInCircles
    pair <int, int> posNums = findInCircles(a, b, circles);
    // -1 means not found
    // if both are not found then add them at the end
    // if only one is found then add the one not found to the one pos of found one
    // if theyre both found
    //  if theyre in the same, then nothing to do
    //  if theyre differen then add the map to the other one and delete the smallest map in the vector pos
    // i, j are the position of the map where a and b are found, i -> a and j -> b
    if (posNums.first == -1 && posNums.second == -1) {
      unordered_map <int, bool> newMap;
      newMap[a] = true;
      newMap[b] = true;
      circles.push_back(newMap);
      maxSize = max(maxSize, (int)newMap.size());
    } else if (posNums.first == -1 && posNums.second != -1) {
      circles[posNums.second][a] = true;
      maxSize = max(maxSize, (int)circles[posNums.second].size());
    } else if (posNums.first != -1 && posNums.second == -1) {
      circles[posNums.first][b] = true;
      maxSize = max(maxSize, (int)circles[posNums.first].size());
    } else if (posNums.first != -1 && posNums.second != -1) {
      if (posNums.first != posNums.second) {
        int smallMap = min(posNums.first, posNums.second);
        if (smallMap != posNums.first) {
          swap(posNums.first, posNums.second);
        }
        // so that the small map is in posNums.first

        //circles.erase() the vector at posNums.first
        circles[posNums.second].insert(circles[posNums.first].begin(), circles[posNums.first].end());
//        switchMaps(circles[posNums.first], circles[posNums.second]);
        maxSize = max(maxSize, (int)circles[posNums.second].size());
        circles.erase(circles.begin() + posNums.first);
      }
    }
    cout << maxSize << endl;
  }

}
