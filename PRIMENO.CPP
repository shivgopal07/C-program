#include<stdio.h>

int  main()
{
	int n,i,p=0;
	printf("\n enter the number to check that it is prime number or not");
	scanf("%d",&n);

	for(i=2;i<=n/2;++i)
	{
		if(n%i==0)
		{
			p=1;
			break;
		}
	}
	if(n==1)
	{
	printf("1 is not a prime no. not a composite no.");
	}
	else
	{
		if(p==0)
		printf(" it is a prime number");
		else
		printf("it is a not prime number");
	}
	return(0);
}


