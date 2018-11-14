#include <iostream>
#include <vector>
using namespace std;

bool metCourses(vector <int> taken, vector <int> needed, int minimum)
{
    int counter = 0;
    for(auto a : needed)
        for(auto b : taken)
            if(a == b)
                counter++;
    if(minimum > counter)
        return false;
    else
        return true;
}

int main(void)
{
    int courses, categories;
    while(cin >> courses && courses != 0)
    {
        cin >> categories;
        bool cumplido;
        vector <int> cursosT, minimo, clases;
        int auxI, numC, minC;
        for(int i = 0 ; i < courses ; i++)
        {
            cin >> auxI;
            cursosT.push_back(auxI);
        }
        cumplido = true;
        for(int j = 0 ; j < categories ; j++)
        {
            cin >> numC >> minC;
            clases.clear();
            for(int i = 0 ; i < numC ; i++)
            {
                cin >> auxI;
                clases.push_back(auxI);
            }
            if(!metCourses(cursosT, clases, minC))
                cumplido = false;
        }
        if(cumplido)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
