/* Accepted */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include "stack.h"
using namespace std;

int main() {
    int cases;
    cin >> cases;
    Stack<int> *nueva = new Stack<int> ();
    Stack<int> *borra = new Stack<int> ();
    map <int, int> borrados;
    priority_queue <int> maximos;
    while(cases--)
    {
        int entrada;
        cin >> entrada;
        if(entrada == 1)
        {
            int au;
            cin >> au;
            nueva -> push(au);
            maximos.push(au);
        }
        else if(entrada == 2)
        {
            borrados[nueva -> top()]++;
            nueva -> pop();
        }
        else
        {
            while(borrados[maximos.top()] > 0)
            {
                borrados[maximos.top()]--;
                maximos.pop();
            }
            cout << maximos.top() << "\n";
        }
    }
    return 0;
}
