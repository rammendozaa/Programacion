/* Longest Common Subsequence */
/* Not Accepted */
#include <iostream>
#include <string>
using namespace std;

long long int lcs(string A, string B, int tamA, int tamB)
{
    if(tamA == 0 || tamB == 0)
        return 0;
    if(A[tamA - 1] == B[tamB - 1])
        return (1 + lcs(A, B, tamA - 1, tamB - 1));
    else
        return max(lcs(A, B, tamA, tamB - 1),lcs(A, B, tamA - 1, tamB));
}

int main(void)
{
    string cadenaA, cadenaB;
    long long int res;
    cin >> cadenaA >> cadenaB;
    res = lcs(cadenaA, cadenaB, cadenaA.length(), cadenaB.length());
    cout << res << "\n";

    return 0;
}
