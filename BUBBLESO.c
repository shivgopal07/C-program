#include<stdio.h>
int main()
{
	int array[100],n,e,d,swap;
	printf("enter no of elements\n");
	scanf("%d",&n);
	printf("enter %din integer\n",n);

	for(e=0;e<n;e++)
		scanf("%d", &array[e]);
	for(e=0;e<n-1;e++)
	{
		for(d=0;d<n-e-1;d++)
		{
			if(array[d]>array[d+1])
			{
			swap=array[d];
			array[d]=array[d+1];
			array[d+1]=swap;
			}
		}
	}
	printf("sorted list in acsending orders:\n");

	for(e=0;e<e;e++)
		printf("%d\n",array[e]);
	return 0;
}
