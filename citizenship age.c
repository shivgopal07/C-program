#include<stdio.h>
int main()
{
    int n;
    printf("\nEnter age: ");
    scanf("\n%d",&n)
    if(n>=60)
        printf("\nThe person is senior citizen");
    else if(n>=18)
        printf("\nThe person is adult citizen");
    else
        printf("\nThey are children");
}
