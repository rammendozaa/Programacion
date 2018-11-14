/* Longest Common Subsequence */
/* Accepted */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string cadenaA, cadenaB;

int lcs(string A, string B, int tamA, int tamB)
{
    vector <vector<int> > DP(tamA + 1, vector <int>(tamB + 1, -1));
    long long int resultado;
    for(int i = 0 ; i <= tamA ; i++)
    {
        for(int j = 0 ; j <= tamB ; j++)
        {
            if(i == 0 || j == 0)
                DP[i][j] = 0;
            else if(A[i - 1] == B[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }
    return DP[tamA][tamB];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int res;
    cin >> cadenaA >> cadenaB;
    res = lcs(cadenaA, cadenaB, cadenaA.length(), cadenaB.length());
    cout << res << "\n";

    return 0;
}
