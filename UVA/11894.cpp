#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <map>
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
    Punto rot90() const {
        if(y == 0)
            return Punto(0, x);
        else
            return Punto(-y, x);
    }

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

bool comparar(map <pair<int, int>, Punto> ini, map <pair<int, int>, Punto> checa)
{
    /*
    cout << "\n";
    for(auto a : ini)
        cout << a.second.x << " " << a.second.y << "\n";
    for(auto a : checa)
        cout << a.second.x << " " << a.second.y << "\n";
    cout << "\n";
    */
    for(auto a : ini)
        if(a.second.x != checa[{a.second.x, a.second.y}].x || a.second.y != checa[{a.second.x, a.second.y}].y)
            return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int pares;
    cin >> pares;
    while(pares--)
    {
        int puntos, auxX, auxY, rotX, rotY;
        Punto auxP;
        cin >> puntos;
        map <pair<int, int>, Punto > entrada;
        map <pair<int, int>, Punto> checar;
        map <pair<int ,int>, Punto> checar90;
        map <pair<int ,int>, Punto> checar180;
        map <pair<int ,int>, Punto> checar270;
        for(int i = 0 ; i < puntos ; i++)
        {
            cin >> auxX >> auxY;
            entrada[{auxX, auxY}] = Punto(auxX, auxY);
        }
        for(int i = 0 ; i < puntos ; i++)
        {
            cin >> auxX >> auxY;
            checar[{auxX, auxY}] = Punto(auxX, auxY);
        }
        for(auto a : checar)
        {
            auxP = a.second.rot90();
            checar90[{auxP.x, auxP.y}] = auxP;
        }
        for(auto a : checar90)
        {
            auxP = a.second.rot90();
            checar180[{auxP.x, auxP.y}] = auxP;
        }
        for(auto a : checar180)
        {
            auxP = a.second.rot90();
            checar270[{auxP.x, auxP.y}] = auxP;
        }
        Punto izqEntrada, cero, noventa, cien, dos;
        pair<int, int> dif0, dif90, dif180, dif270;
        izqEntrada = entrada.begin() -> second;
        cero = checar.begin() -> second;
        noventa = checar90.begin() -> second;
        cien = checar180.begin() -> second;
        dos = checar270.begin() -> second;
        dif0.first = izqEntrada.x - cero.x;
        dif0.second = izqEntrada.y - cero.y;
        dif90.first = izqEntrada.x - noventa.x;
        dif90.second = izqEntrada.y - noventa.y;
        dif180.first = izqEntrada.x - cien.x;
        dif180.second = izqEntrada.y - cien.y;
        dif270.first = izqEntrada.x - dos.x;
        dif270.second = izqEntrada.y - dos.y;
        map <pair<int, int>, Punto > aux;
        bool encontrado = false;
        for(auto a : checar)
            aux[{a.second.x + dif0.first, a.second.y + dif0.second}] = Punto(a.second.x + dif0.first, a.second.y + dif0.second);
        encontrado = comparar(entrada, aux);
        aux.clear();
        if(!encontrado)
        {
            for(auto a : checar90)
                aux[{a.second.x + dif90.first, a.second.y + dif90.second}] = Punto(a.second.x + dif90.first, a.second.y + dif90.second);
            encontrado = comparar(entrada, aux);
            aux.clear();
        }
        if(!encontrado)
        {
            for(auto a : checar180)
                aux[{a.second.x + dif180.first, a.second.y + dif180.second}] = Punto(a.second.x + dif180.first, a.second.y + dif180.second);
            encontrado = comparar(entrada, aux);
            aux.clear();
        }
        if(!encontrado)
        {
            for(auto a : checar270)
                aux[{a.second.x + dif270.first, a.second.y + dif270.second}] = Punto(a.second.x + dif270.first, a.second.y + dif270.second);
            encontrado = comparar(entrada, aux);
        }
        if(encontrado)
            cout << "MATCHED\n";
        else
            cout << "NOT MATCHED\n";
    }

    return 0;
}
