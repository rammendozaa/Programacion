/* Accepted */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	float a,b,c,x;
	float x1,x2;
	float *v;
	v=malloc(3*sizeof(float));
	int i;
	for(i=0;i<3;i++)
	{
		scanf("%f",&v[i]);
	}
	x=((v[1]*v[1])-(4*v[0]*v[2]));
	if(x<0.00)
	{
		printf("NA");
	}
	else if(x==0.00)
	{
		x1=(-(v[1])/(2*v[0]));
		printf("%f",x1);
	}
	else if(x>0.00)
	{
		x1=((-(v[1])+sqrt(x))/(2*v[0]));
		x2=((-(v[1])-sqrt(x))/(2*v[0]));
		if(x1<x2)
		{
			printf("%f\n%f",x1,x2);
		}
		else
		{
			printf("%f\n%f",x2,x1);
		}
	}
	return 0;
}
