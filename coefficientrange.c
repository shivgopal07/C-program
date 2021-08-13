//Given an array arr of integer elements, the task is to 
//find the range and coefficient of range of the given array where: 
#include<stdio.h>
int Display(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int sorting(int arr[], int n)
{
    int temp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int range(int arr[], int n)
{
    sorting(arr, n);
    int max=arr[n-1],min=arr[0];
    float range = max-min;
    printf("\n\tThe range is = %.2f", range);
    float coeff = range/(max+min);
    printf("\n\tthe coefficent is %f\n\n", coeff);
}
int main()
{
   int arr[] = {15, 16, 10, 9, 6, 7, 17} ;
   int n = sizeof(arr)/sizeof(int);
   printf("Before sorting: ");
    Display(arr, n);
    printf("After sorting: ");
    Display(arr, n);
    printf("\n\tThe Range and Co-efficient of the sorted array is\n\t");
    range(arr, n);
return 0;
}
