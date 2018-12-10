/* Accepted */
#include <vector>
#include <iostream>
using namespace std;

int pot2[20] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
int modu;
struct Matriz{
    long long int mat[2][2];
};

Matriz multMatriz(Matriz mat1, Matriz mat2)
{
    int i, j, k;
    Matriz matrizRes;
    for(i = 0 ; i < 2 ; i++)
        for(j = 0 ; j < 2 ; j++)
            for(matrizRes.mat[i][j] = k = 0 ; k < 2 ; k++)
                matrizRes.mat[i][j] += (mat1.mat[i][k] % modu * mat2.mat[k][j] % modu) % modu;
    return matrizRes;
}

Matriz fibo(Matriz base, long long int p)
{
    Matriz res;
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 2 ; j++)
            res.mat[i][j] = (i == j);
    while(p)
    {
        if(p & 1)
            res = multMatriz(res, base);
        base = multMatriz(base, base);
        p >>= 1;
    }
    return res;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int fiboN, expo;
    while(cin >> fiboN >> expo)
    {
        Matriz resultado;
        resultado.mat[0][1] = 1;
        resultado.mat[1][0] = 1;
        resultado.mat[0][0] = 1;
        resultado.mat[1][1] = 0;
        long long int fib;
        modu = pot2[expo];
        resultado = fibo(resultado, fiboN);
        cout << resultado.mat[0][1] % modu << "\n";
    }
    return 0;
}
