#include<stdio.h>

int main()
{
	int a,b,i,gcd;
	printf("\n enter the two integer\n");
	scanf("%d%d",&a,&b);
	for(i=1;i<=a && i<=b;++i)
	{
		if(i%a==0 && i%b==0);
		gcd=1;
	}
	printf("gcd of %d and %d is %d",a,b,gcd);
	return(0);
}