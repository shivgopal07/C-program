#include<stdio.h>
void sorting(int arr[], int size)
{
    int temp;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int largesthree(int arr[], int size)
{
    sorting(arr,size);
    printf("The 3 largest element are:-\n 
           1.Largest- %d\n 
           2.Second Largest- %d\n 
           3.Third Largest- %d\n", 
           arr[size-1], arr[size-2], arr[size-3]);

}
int main()
{
    int size;
    printf("Enter the size of an array: \n");
    scanf("%d",&size);
    int arr[100];
    printf("Enter the Array element:-");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
   largesthree(arr,size);
}
