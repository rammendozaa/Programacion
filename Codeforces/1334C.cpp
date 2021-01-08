#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define lli long long int

void simulateShot(vector <pair <lli, lli> >& monsters, lli pos, lli damage) {
  int startingPos = pos;
  while (true) {
    pos = (pos + 1) % monsters.size();
    if (pos == startingPos || monsters[pos].first <= 0) {
      break;
    }
    monsters[pos].first -= damage;
    cout << monsters[pos].first << endl;
    if (monsters[pos].first <= 0) {
      damage = monsters[pos].second;
    } else {
      break;
    }
  }
}

int solveByDamage(vector <pair <lli, lli> > healthToDamage, priority_queue <pair <lli, lli> >& mostDamageQ) {
  int bullets = 0;
  int dam, pos;
  while (!mostDamageQ.empty()) {
    while (!mostDamageQ.empty() && healthToDamage[mostDamageQ.top().second].first <= 0) {
      mostDamageQ.pop();
    }
    if (mostDamageQ.empty()) {
      break;
    }
//    cout << healthToDamage[mostDamageQ.top().second].first << endl;
    bullets += healthToDamage[mostDamageQ.top().second].first;
    healthToDamage[mostDamageQ.top().second].first = 0;
    simulateShot(healthToDamage, mostDamageQ.top().second, healthToDamage[mostDamageQ.top().second].second);
    mostDamageQ.pop();
  }
  return bullets;
}

int main (void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cases;
  cin >> cases;
  while (cases--) {
    int howMany;
    lli health, damage, byDamage, byHealth, res;
    cin >> howMany;
    vector <pair <lli, lli> > healthToDamage(howMany);
    priority_queue <pair <lli, lli> > mostDamageQ;
    priority_queue <pair <lli, lli>, vector <pair <lli, lli> >, greater <pair <lli, lli> > > leastHealthQ;
    for (int i = 0 ; i < howMany ; ++i) {
      cin >> health >> damage;
      cout << health << " " << damage << endl;
      mostDamageQ.push(make_pair(damage, i));
      leastHealthQ.push(make_pair(health, i));
      healthToDamage[i].first = health;
      healthToDamage[i].second = damage;
    }
    byDamage = solveByDamage(healthToDamage, mostDamageQ);
    /*
    byHealth = solveByHealth(healthToDamage, leastHealthQ);
    res = min(byDamage, byHealth);
    cout << res << endl;
    */
    cout << byDamage << endl;
  }
}
