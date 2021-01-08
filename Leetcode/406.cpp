/* Accepted */
#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool sortPeople(vector <int>& a, vector <int>& b) {
  return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] > b[0]);
}

vector <vector <int> > reconstructQueue(vector <vector <int> >& people) {
  if (people.size() == 0 || people.size() == 1) {
    return people;
  }
  int height, ahead, pos;
  list <pair <int, int> > l;
  list <pair <int, int> >::iterator it;
  vector <vector <int> > res;
  sort(people.begin(), people.end(), sortPeople);
  for (int i = 0 ; i < people.size() ; ++i) {
    pos = min(people[i][1], (int)l.size());
    it = l.begin();
    advance(it, pos);
    l.insert(it, make_pair(people[i][0], people[i][1]));
  }
  for (auto a : l) {
    res.push_back({a.first, a.second});
  }
  return res;
}

int main(void) {
  int n;
  cin >> n;
  vector <vector <int> > res;
  vector <vector <int> > people(n, vector <int> (2, 0));
  for (int i = 0 ; i < n ; ++i) {
    cin >> people[i][0] >> people[i][1];
  }
  res = reconstructQueue(people);
  for (auto a : res) {
    cout << a[0] << " " << a[1] << endl;
  }
}
