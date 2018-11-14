/* Accepted */
#include <iostream>
using namespace std;

int main()
{
	long long int n;
	cin>>n;
	long long int a,b,c,d,e,f;
	long long int i=0;
	long long int j=0;
	long long int valores[6];
	cin >> a >> b >> c >> d >> e >> f;
	valores[0]=a;
	valores[1]=b;
	valores[2]=c;
	valores[3]=d;
	valores[4]=e;
	valores[5]=f;
	long long int aristas,vertices,caras,maristas,mvertices,mcaras;
	vertices=4;
	aristas=4*(n-1) + 4*(n-2);
	caras = 5*n*n-2*aristas-3*vertices;
	mcaras=100;
	mvertices=100;
	maristas=100;
	long long int auxma=-5;
	long long int aux;
	long long int resultado;
	if(n==1)
	{
		for(i=0;i<5;i++)
		{
		for(j=0;j<i-1;j++)
		{
			if(valores[j]>valores[j+1])
			{
				aux=valores[j];
				valores[j]=valores[j+1];
				valores[j+1]=aux;
			}
		}
		}
		resultado=valores[0]+valores[1]+valores[2]+valores[3]+valores[4];
	}
	else
	{
		for(i=0;i<6;i++)
		{
			mcaras=min(mcaras,valores[i]);
		}
		maristas=160;
		maristas=min(maristas,a+d);
		maristas=min(maristas,a+b );
		maristas=min(maristas,a+e );
		maristas=min(maristas,a+c );
		maristas=min(maristas,b+a );
		maristas=min(maristas,b+d );
		maristas=min(maristas,b+c );
		maristas=min(maristas,b+f );
		maristas=min(maristas,c+e );
		maristas=min(maristas,c+a );
		maristas=min(maristas,c+b );
		maristas=min(maristas,c+f );
		maristas=min(maristas,d+e );
		maristas=min(maristas,d+a );
		maristas=min(maristas,d+b );
		maristas=min(maristas,d+f );
		maristas=min(maristas,e+d );
		maristas=min(maristas,e+a );
		maristas=min(maristas,e+c );
		maristas=min(maristas,e+f );
		mvertices=160;
		mvertices=min(mvertices,e+d+a);
		mvertices=min(mvertices,a+d+b);
		mvertices=min(mvertices,e+c+a);
		mvertices=min(mvertices,a+c+b);
		mvertices=min(mvertices,d+b+f);
		mvertices=min(mvertices,c+b+f);
		mvertices=min(mvertices,e+c+f);
		mvertices=min(mvertices,e+d+f);
		resultado = caras*mcaras + aristas*maristas + vertices*mvertices;
	}
	cout<<resultado;
	return 0;
}
