//WELCOME TO TURBO C++ ON WINDOWS NOW RUN YOUR FIRST PROGRAM...!!!!

//Downloaded From www.turboc8.com coded by Yogendra Singh.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
clrscr();
int gdriver = DETECT,gmode;
int x,y,i;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	x=getmaxx()/2;
	y=getmaxy()/2;
	for(i=40;i<200;i++)
	{
		delay(100);
		setcolor(i/10);
		arc(x,y,0,180,i-10);
	}
getch();
}