/* Accepted */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	float area;
	float *v;
	v=malloc(3*sizeof(float));
	int i;
	for(i=0;i<3;i++)
	{
		scanf("%f",&v[i]);
	}
	area=((v[0]+v[1])/2.0f)*v[2];
	printf("%f",area);
	return 0;
}
