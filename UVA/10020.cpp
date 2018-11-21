/* Minimal Coverage */
/* Accepted */
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(void)
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        int M, izq, der, auxI, auxD;
        cin >> M;
        vector <pair<int, int> > izqDers;
        bool encontrado = false, neg = false;
        while(cin >> izq >> der && (izq != 0 || der != 0))
            izqDers.push_back(make_pair(izq,der));
            /*
            if(izq <= 0 && der >= M)
            {
                auxI = izq;
                auxD = der;
                encontrado = true;
            }
            if(izq <= 0)
                neg = true;
            */
        /*
        if(!neg)
            cout << "0" << "\n";
        else if(encontrado)
            cout << "1\n" << auxI << " " << auxD << "\n";
        */
            encontrado = false;
            vector <pair<int, int> > pedazos;
            sort(izqDers.begin(), izqDers.end());
            int pivoteIzq = 0, agregarPos, limDer;
            bool agregarValores = true;
            int i = 0;
            while(agregarValores)
            {
                limDer = pivoteIzq;
                agregarValores = false;
                while(i < izqDers.size() && izqDers[i].first <= pivoteIzq)
                {
                    if(izqDers[i].second > limDer)
                    {
                        agregarPos = i;
                        limDer = izqDers[i].second;
                        agregarValores = true;
                    }
                    i++;
                }
                pivoteIzq = limDer;
                if(agregarValores)
                    pedazos.push_back(izqDers[agregarPos]);
                if(limDer >= M)
                {
                    encontrado = true;
                    agregarValores = false;
                    break;
                }
            }
            if(!encontrado)
                cout << "0\n";
            else
            {
                cout << pedazos.size() << "\n";
                sort(pedazos.begin(), pedazos.end());
                for(auto a : pedazos)
                    cout << a.first << " " << a.second << "\n";
            }


        if(cases > 0)
            cout << "\n";
    }
}
