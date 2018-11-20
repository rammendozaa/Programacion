/* Bacterias */
/* Accepted */

#include <iostream>
#include <vector>
using namespace std;

int M, N, auxI;

int caminoMenor(vector <vector<int> > DP, vector <vector<int> > quimico)
{
    for(int i = 1 ; i < M ; i++)
        for(int j = 1 ; j < N ; j++)
            DP[i][j] = quimico[i][j] + min(DP[i - 1][j], DP[i][j - 1]);
    return DP[M - 1][N - 1];

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> M >> N;
    vector <vector <int> > compuestoQ(M, vector <int> (N, 0));
    vector <vector <int> > DP(M, vector <int> (N));
    int res;
    for(int i = 0 ; i < M ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            cin >> auxI;
            compuestoQ[i][j] = auxI;
        }
    }
    DP[0][0] = compuestoQ[0][0];
    for(int i = 1 ; i < M ; i++)
        DP[i][0] = DP[i - 1][0] + compuestoQ[i][0];
    for(int i = 1 ; i < N ; i++)
        DP[0][i] = DP[0][i - 1] + compuestoQ[0][i];
    res = caminoMenor(DP, compuestoQ);
    cout << res << "\n";
}
