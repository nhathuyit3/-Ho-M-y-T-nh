#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i,j,k,l,m,b[14000],n,s,f,d,aa,ab,ac,ad,ae,afg,x,c[80][23];
	char ch;
	textcolor(0);
	textbackground(7);
	clrscr();
	i=5;
	j=5;
	m=1;
	for(i=4; i<76; i++)
	{
		for(j=3; j<23; j++)
		{
			c[i][j] = 0;
		}
	}
	clrscr();
	gotoxy(35,15);
	printf("Welcome to snake mania");
	getch();
	clrsrc();
	gotoxy(35,14);
	printf("instruction");
	gotxy(35,15);
	printf("Press W - up");
	gotoxy(42,16);
	printf("s-down");
	gotoxy(42,17);
	print("a-left");
	gotoxy(42,18);
	printf("d-right");
	gotoxy(42,19);
	printf("q-qiut");
	start:
	clrscr();
	gotoxy(35,14);
	printf("Choose number to select level");
	gotoxy(38,16);
	printf("1)Easy");
	gotoxy(38,17;
	printf("1)Medium");
	gotoxy(38,18);
	printf("1)Hard");
	gotoxy(38,19);
	printf("1)Professional");
	ch = getch();
	if(ch == '1')
	{
		s = 400;
	}else if(ch == '2')
	{
		s = 300;
	}else if(ch == '3')
	{
		s = 100;
	}else if(ch == '4')
	{
		s = 75;
	}
	else {
		goto start;
	}
	clrscr();
	for(i = 4; i < 76; i++)
	{
		gotoxy(i,3);
		printf("-");
		gotoxy(i,23);
		printf("-");
	}
	for(j = 3; j <= 23; j++)
	{
		gotoxy(3,j);
		printf("|");
		gotoxy(76,j);
		printf("|");
	}
	
}
