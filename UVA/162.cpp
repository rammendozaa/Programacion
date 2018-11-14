#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
void calcularRes(int ganador, stack <string> nod, stack <string> d)
{
    int numCar = 0;
    if(ganador == 1)
        while(!d.empty())
        {
            d.pop();
            numCar++;
        }
    else
        while(!nod.empty())
        {
            nod.pop();
            numCar++;
        }
    cout << ganador << " "  << numCar << "\n";
}

int main(void)
{
    string carta;
    stack <string> deal, nodeal, aux, juega;
    bool termina = false, face = false;
    int turno = 2, numerocartas, contador = 1, ganador, cartasbajar, ultFace; //2 para nodeal 1 para deal
    while(cin >> carta && contador <= 52)
    {
        if(contador % 2 == 0)
            deal.push(carta);
        else
            nodeal.push(carta);
        contador++;
    }
    while(!termina)
    {
        if(turno == 2)
        {
            if(nodeal.empty())
            {
                ganador = 1;
                termina = true;
                calcularRes(ganador, nodeal, deal);
                return 0;
            }
            if(face)
            {
                for(int i = 0 ; i < cartasbajar ; i++)
                {
                    if(nodeal.empty())
                    {
                        ganador = 1;
                        termina = true;
                        calcularRes(ganador, nodeal, deal);
                        return 0;
                    }
                    else
                    {
                        juega.push(nodeal.top());
                        nodeal.pop();
                        if(juega.top()[1] == 'J')
                        {
                            face = true;
                            cartasbajar = 1;
                            turno = 1;
                            ultFace = 2;
                        }
                        else if(juega.top()[1] == 'Q')
                        {
                            face = true;
                            cartasbajar = 2;
                            turno = 1;
                            ultFace = 2;
                        }
                        else if(juega.top()[1] == 'K')
                        {
                            face = true;
                            cartasbajar = 3;
                            turno = 1;
                            ultFace = 2;
                        }
                        else if(juega.top()[1] == 'A')
                        {
                            face = true;
                            cartasbajar = 4;
                            turno = 1;
                            ultFace = 2;
                        }
                        else
                            face = false;
                    }
                }
                if(!face)
                {
                    while(!juega.empty())
                    {
                        aux.push(juega.top());
                        juega.pop();
                    }
                    while(!nodeal.empty())
                    {
                        juega.push(nodeal.top());
                        nodeal.pop();
                    }
                    while(!juega.empty())
                    {
                        aux.push(juega.top());
                        juega.pop();
                    }
                    nodeal = aux;
                }
            }
            else
            {
                juega.push(nodeal.top());
                nodeal.pop();
                if(juega.top()[1] == 'J')
                {
                    face = true;
                    cartasbajar = 1;
                    turno = 1;
                    ultFace = 2;
                }
                else if(juega.top()[1] == 'Q')
                {
                    face = true;
                    cartasbajar = 2;
                    turno = 1;
                    ultFace = 2;
                }
                else if(juega.top()[1] == 'K')
                {
                    face = true;
                    cartasbajar = 3;
                    turno = 1;
                    ultFace = 2;
                }
                else if(juega.top()[1] == 'A')
                {
                    face = true;
                    cartasbajar = 4;
                    turno = 1;
                    ultFace = 2;
                }
                else
                    face = false;
            }
            turno = 1;
        }
        else
        {
            if(deal.empty())
            {
                ganador = 2;
                termina = true;
                calcularRes(ganador, nodeal, deal);
                return 0;
            }
            if(face)
            {
                for(int i = 0 ; i < cartasbajar ; i++)
                {
                    if(deal.empty())
                    {
                        ganador = 2;
                        termina = true;
                        calcularRes(ganador, nodeal, deal);
                        return  0;
                    }
                    else
                    {
                        juega.push(deal.top());
                        deal.pop();
                        if(juega.top()[1] == 'J')
                        {
                            face = true;
                            cartasbajar = 1;
                            turno = 2;
                            ultFace = 1;
                        }
                        else if(juega.top()[1] == 'Q')
                        {
                            face = true;
                            cartasbajar = 2;
                            turno = 2;
                            ultFace = 1;
                        }
                        else if(juega.top()[1] == 'K')
                        {
                            face = true;
                            cartasbajar = 3;
                            turno = 2;
                            ultFace = 1;
                        }
                        else if(juega.top()[1] == 'A')
                        {
                            face = true;
                            cartasbajar = 4;
                            turno = 2;
                            ultFace = 1;
                        }
                        else
                            face = false;
                    }
                }
                if(!face)
                {
                    while(!juega.empty())
                    {
                        aux.push(juega.top());
                        juega.pop();
                    }
                    while(!deal.empty())
                    {
                        juega.push(deal.top());
                        deal.pop();
                    }
                    while(!juega.empty())
                    {
                        aux.push(juega.top());
                        juega.pop();
                    }
                    deal = aux;
                }
            }
            else
            {
                juega.push(deal.top());
                deal.pop();
                if(juega.top()[1] == 'J')
                {
                    face = true;
                    cartasbajar = 1;
                    turno = 2;
                    ultFace = 1;
                }
                else if(juega.top()[1] == 'Q')
                {
                    face = true;
                    cartasbajar = 2;
                    turno = 2;
                    ultFace = 1;
                }
                else if(juega.top()[1] == 'K')
                {
                    face = true;
                    cartasbajar = 3;
                    turno = 2;
                    ultFace = 1;
                }
                else if(juega.top()[1] == 'A')
                {
                    face = true;
                    cartasbajar = 4;
                    turno = 2;
                    ultFace = 1;
                }
                else
                    face = false;
            }
            turno = 2;
        }
    }
    return 0;
}
