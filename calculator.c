#include<stdio.h>
#include<stdlib.h>
int k=0,result=0;
int menu()
{
    int ch;
    printf("\n   |=SIMPLE_CALCULATOR=|  \n");
    printf("Result %d",result);
    printf("\n 1. Addition");
    printf("\n 2. Subtraction");
    printf("\n 3. Multiplication");
    printf("\n 4. Divison");
    printf("\n 5. Reminder");
    printf("\n 6. Clear");
    printf("\n 7. Exit");
    printf("\n -->Enter Your Choice:- ");
    scanf("%d",&ch);
    return(ch);
}
void addition()
{
    int a,b;
    if(k)
    {
        printf("\n Enter a Number= ");
        scanf("%d",&a);
        result+=a;
        printf("\n Result= %d",result);
    }
    else
    {
        printf("\n Enter two number= ");
        scanf("%d %d",&a,&b);
        result = a+b;
        printf("\n Result= %d",result);
    }
    k=1;
}
void Subtraction()
{
    int a,b;
    if(k)
    {
        printf("\n Enter a Number= ");
        scanf("%d",&a);
        result-=a;
        printf("\n Result= %d",result);
    }
    else
    {
        printf("\n Enter two number= ");
        scanf("%d %d",&a,&b);
        result = a-b;
        printf("\n Result= %d",result);
    }
    k=1;
}

void Multiplication()
{
    int a,b;
    if(k)
    {
        printf("\n Enter a Number= ");
        scanf("%d",&a);
        result*=a;
        printf("\n Result= %d",result);
    }
    else
    {
        printf("\n Enter two number= ");
        scanf("%d %d",&a,&b);
        result = a*b;
        printf("\n Result= %d",result);
    }
    k=1;
}
void Division()
{
    int a,b;
    if(k)
    {
        printf("\n Enter a Number= ");
        scanf("%d",&a);
        result/=a;
        printf("\n Result= %d",result);
    }
    else
    {
        printf("\n Enter two number= ");
        scanf("%d %d",&a,&b);
        result = a/b;
        printf("\n Result= %d",result);
    }
    k=1;
}
void Reminder()
{
    int a,b;
    if(k)
    {
        printf("\n Enter a Number= ");
        scanf("%d",&a);
        result%=a;
        printf("\n Result= %d",result);
    }
    else
    {
        printf("\n Enter two number= ");
        scanf("%d %d",&a,&b);
        result = a%b;
        printf("\n Result= %d",result);
    }
    k=1;
}
void clear()
{
    result=0;
    k=0;
    printf("****Old Values are Cleared****\n");
}

int main()
{
    while(1)
    {
    switch(menu())
    {
        case 1:
                addition();
                break;
        case 2:
            Subtraction();
            break;
        case 3:
            Multiplication();
            break;
        case 4:
            Division();
            break;
        case 5:
            Reminder();
            break;
        case 6:
            clear();
            break;
        case 7:
            printf("Thank you");
            exit(0);

        default:
            printf("^^^^Enter valid choice^^^^^\n");
    }
  }
}