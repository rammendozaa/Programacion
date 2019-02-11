/* Accepted */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <long long int> encuentra(long long int entrada)
{
    long long int raiz = sqrt(entrada);
    vector <long long int> res;
    for(int i = 1 ; i <= raiz ; i++)
    {
        if(entrada % i == 0)
        {
            if(i * i == entrada)
                res.push_back(i);
            else
            {
                res.push_back(entrada / i);
                res.push_back(i);
            }
        }
    }
    return res;
}

long long int gcd(long long int a, long long int b)
{
	if(b == 0)
  	return a;
  else
  	gcd(b, a % b);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int left, right, x, y, res = 0, g, l;
    cin >> left >> right >> x >> y;
    vector <long long int> factores;
    factores = encuentra(y);
    for(auto a : factores)
    {
        for(auto b : factores)
        {
            g = gcd(a, b);
            l = (a * b) / g;
            if(left <= a && left <= b && a <= right && b <= right && g == x && l == y)
                res++;
        }
    }
    cout << res << "\n";
}
