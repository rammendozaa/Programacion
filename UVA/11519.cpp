#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

typedef long double Double;
typedef long long Long;
typedef pair<int, int> pii;

const Double INF = 1ll << 60;
const Double ERROR = 1e-9;
const Double M_2PI = 2.0 * M_PI;

// Tolerancia a flotantes
#define EQ(a, b) (fabs((a) - (b)) < ERROR)

// Punto en 2D.
struct Punto {
  Double x, y;
  Punto() : x(), y() {}
  Punto(Double X, Double Y) : x(X), y(Y) {}
  // Izquierda a derecha, abajo a arriba.
  bool operator<(const Punto& q) const {
    if (!EQ(x, q.x)) return x < q.x;
    return EQ(y, q.y)? false: y < q.y;
  }
  bool operator==(const Punto& q) const {
    return EQ(x, q.x) && EQ(y, q.y);
  }

    //Sumar los vectores actual y q.
    Punto operator +(const Punto& p)const { return Punto(x+p.x, y+p.y); }
    //Restar los vectores (o trasladarlos), tomando p como el origen.
    Punto operator -(const Punto& p)const { return Punto(x-p.x, y-p.y); }
    //Obtener el vector opuesto.
    Punto operator -() const { return Punto(-x, -y); }
    //Obtener el vector por un escalar.
    Punto operator*( Double c ) const { return Punto( x*c, y*c ); }
    //Obtener el vector dividido por un escalar.
    Punto operator/( Double c ) const { return Punto( x/c, y/c ); }
    //Magnitud del vector.
    Double Abs() const { return hypot(x, y); }
    //Magnitud elevada al cuadrado del vector.
    Double Norm() const{ return x*x + y*y; }
    //Distancia entre el punto actual y q.
    Double Dist( const Punto& q ) const { return (*this - q ).Abs(); }
    //Distancia elevada al cuadrado entre el punto actual y q.
    Double Dist2(const Punto& q ) const { return ( *this - q).Norm(); }
    //Producto punto entre el punto actual y q.
    Double Dot( const Punto& q ) const { return x*q.x + y*q.y; }
    //Producto cruz entre el punto actual y q.
    Double Cruz( const Punto& q ) const { return x*q.y - y*q.x; }

    //Rotar 90 grados en CCW.
    Punto rot90() const { return Punto(-y, x); }

    //Rotar t radianes en cw respecto al origen.
    Punto RotarCW(const Double& t) const {
      return Punto( x*cos(t) + y*sin(t),
              y*cos(t) - x*sin(t));
}

//Rotar t radianes en ccw respecto al origen.
Punto RotarCCW(const Double& t) const {
  return Punto( x*cos(t) - y*sin(t),
          y*cos(t) + x*sin(t));
}
};

//Conversion de grados a radianes.
Double GradARad(Double grd) {
return (grd * M_PI) / 180.0;
}

// Conversion de radianes a grados.
Double RadAGrad(Double rad) {
return (rad * 180.0) / M_PI;
}

//Angulo mas chico formado por los puntos aob en radianes.
Double Angulo(const Punto& a, const Punto& o, const Punto& b){
  Punto u(a - o), v(b - o);
  return acos( u.Dot(v) / (u.Abs() * v.Abs()));
}

int prove(vector <pair<string, int> > instrucciones)
{
    Punto inicial = Punto(0,0), recorrido = Punto(0,0);
    for(auto a : instrucciones)
    {
        if(a.first[0] == 'f')
        {
            recorrido = recorrido + Punto(a.second,0);
        }
        else if(a.first[0] == 'l')
        {
            recorrido = recorrido.RotarCCW(GradARad(a.second));
        }
        else if(a.first[0] == 'r')
        {
            recorrido = recorrido.RotarCW(GradARad(a.second));
        }
        else if(a.first[0] == 'b')
        {
            recorrido = recorrido + Punto(-a.second,0);
        }
//        cout << recorrido.x << " | " << recorrido.y << "\n";
    }
    return (int)round(recorrido.Dist(inicial));
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cases, gradosAux, distancia, auxI;
    string auxS, instruS;
    cin >> cases;
    while(cases--)
    {
        Punto inicial = Punto(0,0), recorrido = Punto(0,0), dondeMuere;
        int contador = 0, indiceDondeMuere, instru;
        cin >> auxI;
        vector <pair<string, int> > instrucciones;
        bool distOnly = false;
        while(auxI--)
        {
            cin >> auxS;
            if(auxS[0] == 'f')
            {
                cin >> instruS;
                if(instruS == "?")
                {
                    instru = 0;
                    distOnly = true;
                }
                else
                    instru = stoi(instruS);
                instrucciones.push_back(make_pair(auxS, instru));
                recorrido = recorrido + Punto(instru,0);
            }
            else if(auxS[0] == 'l')
            {
                cin >> instruS;
                if(instruS == "?")
                {
                    instru = 0;
                    indiceDondeMuere = contador;
                    dondeMuere = recorrido;
                }
                else
                    instru = stoi(instruS);
                instrucciones.push_back(make_pair(auxS, instru));
                recorrido = recorrido.RotarCCW(GradARad(instru));
            }
            else if(auxS[0] == 'r')
            {
                cin >> instruS;
                if(instruS == "?")
                {
                    instru = 0;
                    indiceDondeMuere = contador;
                    dondeMuere = recorrido;
                }
                else
                    instru = stoi(instruS);
                instrucciones.push_back(make_pair(auxS, instru));
                recorrido = recorrido.RotarCW(GradARad(instru));
            }
            else if(auxS[0] == 'b')
            {
                cin >> instruS;
                if(instruS == "?")
                {
                    distOnly = true;
                    instru = 0;
                }
                else
                    instru = stoi(instruS);
                instrucciones.push_back(make_pair(auxS, instru));
                recorrido = recorrido + Punto(-instru,0);
            }
            contador++;
        }
        if(distOnly)
            cout << (int)round(recorrido.Dist(inicial)) << "\n";
        else
        {
            int respuesta;
            for(int i = 0 ; i < 360 ; i++)
            {
                instrucciones[indiceDondeMuere].second = i;
                if(prove(instrucciones) == 0)
                {
                    respuesta = i;
                    break;
                }
            }
            cout << respuesta << "\n";
        }
    //    cout << 180 - (RadAGrad(Angulo(recorrido, Punto(100,0), Punto(0,0)))) << "\n";
    }

}
