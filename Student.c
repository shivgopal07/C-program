#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert_record();
void display_record();
void search_record();
void del_record();
void update_record();
void sort_record();

struct student
{
    int roll;
    char sec[10];
    char name[40];
    int marks;
    float grade;
};
    struct student s;
void main()
{
    int ch;
    while(ch!=7)
    {
    printf("\n***********************************************\n");
    printf("\n WELCOME TO STUDENT MANAGEMENT PROGRAM\n");
    printf("\n***********************************************\n\n\n");

        printf("\t**** AVAILABLE FUNCTIONALITIES ****\n\n");
        printf("\t1: Insert student record\n");
        printf("\t2: Display student record\n");
        printf("\t3: Search student record\n");
        printf("\t4: Delete student record\n");
        printf("\t5: Update student record\n");
        printf("\t6: Sort student record\n");
        printf("\t7: Exit\n\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert_record();
                break;
            case 2:
                display_record();
                break;

            case 3:
                search_record();
                break;

            case 4:
                del_record();
                break;
            case 5:
                update_record();
                break;
            case 6:
                sort_record();
                break;
            case 7:
                exit(1);
            default:
                printf("\nWrong choice Entered");
        }
        printf("\nPress any key to continue ");
        getch();
       }
}

void insert_record()
{
    FILE *fp;

    fp=fopen("stu.txt","ab+");

    if(fp==NULL)
    {
        printf("\nError: Cannot Open the File!!!");
        return;
    }
    printf("\n **** Previous Stored Data ****");
    display_record();

    printf("\n**** ENTER NEW STUDENT DATA ****\n");
    printf("\nEnter Student Roll Number: ");
    scanf("%d",&s.roll);
    fflush(stdin);
    printf("\nEnter Student Name: ");
    gets(s.name);
    printf("\nEnter Student Section: ");
    gets(s.sec);
    printf("\nEnter Student Total marks: ");
    scanf("%d",&s.marks);
    printf("\nEnter Student Grade: ");
    scanf("%f",&s.grade);
    fwrite(&s,sizeof(s),1,fp);

    {
        printf("\n\n !!! Student Record Inserted Sucessfully\n");
    }
    fclose(fp);
    printf("\n Updated Record !!\n");
    display_record();

}

void display_record()
{
    FILE *fp;
    fp=fopen("stu.txt","rb");

    if(fp==NULL)
    {
        printf("\nError : Cannot open the File !!!");
        return;
    }

    printf("\n\n **** Students Details Are As Follows ****\n");
    printf("Roll.No\t\tName of Student\t\tSection\t\tMarks\t\tGrade\n\n");
    //printf("a.students roll number\t b.student name\t c.student section\t d.student marks\t e.student grade");
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        printf("%d\t%s\t%s \t\t%d\t\t%f\n",s.roll,s.name,s.sec,s.marks,s.grade);
    }
    fclose(fp);
}

void search_record()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("stu.txt","rb");
    if(fp==NULL)
    {
        printf("\nError: Cannot Open the File!!!");
        return;
    }
    printf("\n\nEnter Student Roll Number Which You Want To Search: ");
    scanf("%d",&ro);
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.roll==ro)
        {
        flag=1;
        printf("\n\nSearch Sucessfull And Student Records Is as Follows: \n\n");
        printf("Roll.No\tName of Student\t\tSection\tMarks\tGrade\n\n");
        printf("%d\t%s\t%s  \t%d\t%f\t",s.roll,s.name,s.sec,s.marks,s.grade);
        }
    }
    if(flag==0)
    {
    printf("\n\nNo Such Record Found !!!!!\n");
    }
fclose(fp);
}

void del_record()
{
    int ro,flag=0;
    FILE *fp,*ft;
    fp=fopen("stu.txt","rb");
    ft=fopen("stu1.txt","ab+");
    if(fp==NULL)
    {
         printf("\nError: Cannot Open the File!!!");
        return;
    }
    printf("\n **** Previous Stored Data ****");
    display_record();
    printf("\n\nEnter Student Roll Number Which You Want to Delete ");
    scanf("%d",&ro);
    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.roll==ro)
        {
        flag=1;
        printf("\nRecord Deleted Sucessfully \n");

        }
        else
        {
        fwrite(&s,sizeof(s),1,ft);
        }
    }
    if(flag==0)
    {
    printf("\n\nNo Such Record Found !!!");
    }
    fclose(fp);
    fclose(ft);
    remove("stu.txt");
    rename("stu1.txt","stu.txt");
    printf("\n Updated Record !!\n");
    display_record();
}

void update_record()
{
    int ro,flag=0;
    FILE *fp;
    fp=fopen("stu.txt","rb+");
    if(fp==NULL)
    {
        printf("\nError: Cannot Open the File!!!");
        return;
    }
    printf("\n\nEnter Roll Number of Student Whose Record You Want To Update: ");
    scanf("%d",&ro);
    printf("\n*** Previously Stored Record Of Given Roll Number ***");

    while(fread(&s,sizeof(s),1,fp)>0 && flag==0)
    {
        if(s.roll==ro)
        {
        flag=1;
        printf("\tRoll.No\tName of Student\tSection\tMarks\tGrade\n\n");
        printf("%d\t%s\t%s  \t%d\t%f\t",s.roll,s.name,s.sec,s.marks,s.grade);
        printf("\n*** Now Enter the New Record ***\n\n");

        printf("\n\nUpdated Student Roll Number: ");
        scanf("%d",&s.roll);
        fflush(stdin);
        printf("\nUpdated Student Name: ");
        gets(s.name);
        printf("\nUpdated Student Section: ");
        gets(s.sec);
        printf("\nUpdated Student Marks: ");
        scanf("%d",&s.marks);
        printf("\nUpdated Student Grade: ");
        scanf("%f",&s.grade);
        fseek(fp,-(long)sizeof(s),1);
        fwrite(&s,sizeof(s),1,fp);
        printf("\n\nRecord Updated Successfully Check The Display Section!!\n");
        }
    }
    if(flag==0)
    {
        printf("\n\nError : Something went wrong!!!");
    }
fclose(fp);
}
void sort_record()
{
    struct student temp;
    struct student arr[50];

    int i,j,k=0;
    FILE *fp;
    fp=fopen("stu.txt","rb");
    if(fp==NULL)
    {
        printf("\n\nError: Cannot Open File !!!\n");
    }
    i=0;

    while(fread(&arr[i],sizeof(arr[i]),1,fp)==1)
    {
         i++;k++;
    }

    for(i=0;i<k;i++)
        {
        for(j=0;j<k-i-1;j++)
         {
            if(arr[j].roll>arr[j+1].roll)
             {

               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
             }
          }
        }
        printf("\nAfter Sorting Student Details !!\n\n");
        for(i=0;i<k;i++)
        {
           printf("%d\t\t%s\t\t%s\t%d\t%f\n",arr[i].roll,arr[i].name,arr[i].sec,arr[i].marks,arr[i].grade);
        }
    fclose(fp);
}
