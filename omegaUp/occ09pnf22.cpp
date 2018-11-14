/* Accepted */
#include <iostream>
using namespace std;

int main()
{
	int matriz[3][3];
	int matrizaux[6][2];
	int mayor[6];
	int sumas[6];
	int sumamayor[6];
	int aux[6];
	int ayuda,aiuda;
	int suma1;
	int suma2;
	int suma3;
	int suma4;
	int suma5;
	int suma6;
	int k,l,m,n,o;
	int p=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>matriz[j][i];
		}
	}
	suma1=matriz[0][0]+matriz[1][0]+matriz[2][0];
	suma2=matriz[0][1]+matriz[1][1]+matriz[2][1];
	suma3=matriz[0][2]+matriz[1][2]+matriz[2][2];
	suma4=matriz[0][0]+matriz[0][1]+matriz[0][2];
	suma5=matriz[1][0]+matriz[1][1]+matriz[1][2];
	suma6=matriz[2][0]+matriz[2][1]+matriz[2][2];
	sumas[0]=suma1;
	sumas[1]=suma2;
	sumas[2]=suma3;
	sumas[3]=suma4;
	sumas[4]=suma5;
	sumas[5]=suma6;
	for(int j=0;j<6;j++)
	{
		matrizaux[j][1]=j+1;
	}
	for(int i=0;i<6;i++)
	{
		matrizaux[i][0]=sumas[i];
	}

	for(int a=0;a<5;a++)
	{
		for(int b=0;b<5-a;b++)
		{
			if(matrizaux[b][0]<matrizaux[b+1][0])
			{
				ayuda=matrizaux[b+1][0];
				aiuda=matrizaux[b+1][1];
				matrizaux[b+1][0]=matrizaux[b][0];
				matrizaux[b+1][1]=matrizaux[b][1];
				matrizaux[b][0]=ayuda;
				matrizaux[b][1]=aiuda;
			}
		}
	}
	int q=0;
	q=0;
	if(matrizaux[0][0]!=matrizaux[1][0])
	{
		int fin1=matrizaux[0][1];
		cout<<fin1;
		return 0;
	}
	int valor=1;
	while(q<6)
	{
		if(matrizaux[q][0]==matrizaux[q+1][0])
		{
			valor=valor+1;
			q=q+1;
		}
		else
			break;
	}
	int fin[valor];
	int qq=0;
	for(int i=0;i<valor;i++)
	{
		fin[i]=matrizaux[i][1];
	}
	while(qq<valor)
	{
		if(qq==valor-1)
			cout<<fin[qq];
		else
			cout<<fin[qq]<<" ";
		qq++;
	}
return 0;
}
