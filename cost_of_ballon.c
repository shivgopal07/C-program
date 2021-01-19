#include<stdio.h>
int main()
{
    int T, i, n, bg, bp,l,r1,r2, cost1=0, cost2=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d", &bg, &bp);
        scanf("%d",&n);
        for(l=0;l<n;l++)
        {
            scanf("%d %d",&r1,&r2);
            cost1 =cost1 + (bg*r1) + (r2*bp);
            cost2 =cost2 + (bp*r1) + (r2*bg);
        }
        if(cost1<cost2)
        {
            printf("%d\n",cost1);
        }
        else 
        { 
            printf("%d\n",cost2);
        }
        cost1= cost1 *0;
        cost2= cost2 *0;
    }
}
