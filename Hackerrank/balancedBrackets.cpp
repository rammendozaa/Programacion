#include<iostream>
#include <string>
#include "stack.h"
using namespace std;

string isBalanced(string s) {
    Stack<char> *stacka = new Stack<char> ();
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] == '}')
        {
            if(stacka -> esVacia() || stacka -> top() != '{')
                return "NO";
            else
                stacka -> pop();
        }
        else if(s[i] == ']')
        {
            if(stacka -> esVacia() || stacka -> top() != '[')
                return "NO";
            else
                stacka -> pop();
        }
        else if(s[i] == ')')
        {
            if(stacka -> esVacia() || stacka -> top() != '(')
                return "NO";
            else
                stacka -> pop();
        }
        else
            stacka -> push(s[i]);
    }
    if(stacka -> esVacia())
        return "YES";
    else
        return "NO";
}

int main(void)
{
    string entrada;
    int cases;
    cin >> cases;
    while(cases--)
    {
        cin >> entrada;
        string res = isBalanced(entrada);
        cout << res << "\n";
    }
}
