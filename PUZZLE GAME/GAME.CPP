#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#define row 4
#define col 4
int i,j;
void display(int [][col]);
void operation(int [][col]);
void check(int [][col]);
void main()
{
clrscr();
int  a[row][col]={{6,14,10,8},{11,1,15,4},{13,3,5,12},{9,2,7,0}};
gotoxy(22,11);
cout<<"WELCOME TO THE PUZZLE GAME MADE BY SAURABH CSE 2nd YEAR"<<endl;
gotoxy(22,12);
cout<<"________________________________________________"<<endl;
gotoxy(22,13);
cout<<"PRESS ENTER TO DISPLAY THE RULES" <<endl;
cin.get();
clrscr();
cout<<"1: IT IS A PUZZLE GAME IN WHICH U HAVE TO ARRANGE THE NUMBER IN A SEQUENCE"<<endl;
cout<<" "<<endl;
cout<<"2: USE KEYS 5 , 2 , 3 , 1 INSTEAD OF ARROW KEYS UP , DOWN , RIGHT , LEFT"<<endl;
cout<<" "<<endl;
cout<<"3: 0 IS CONSIDER AS A BLANK WHICH IS LOCATED AT THE BOTTOM "<<endl;
cout<<" "<<endl;
cout<<"4: U CAN MOVE THE NUMBERS BY SWAPPING UP WITH 0"<<endl;
cout<<" "<<endl;
cout<<"6: YOU CAN PRESS 'E' AT ANY TIME TO EXIT THE GAME"<<endl;
cout<<" "<<endl;
cout<<"7: ALL THE BEST"<<endl;
cout<<" "<<endl;
gotoxy(22,13);
cout<<" PRESS ENTER TO PLAY THE GAME "<<endl;
cin.get();
clrscr();
display(a);
getch();
}

void display(int x[][col])
{
int t=1;
clrscr();
for(i=0;i<row;i++)
{       gotoxy(26,8+t);
	for(j=0;j<col;j++)
	{

	cout<<x[i][j]<<'\t';
	}
	t=t+2;
}
check(x);
//operation(x);
}

void operation(int x[][col])
{
char c;
c=getch();
switch(c)
{
	case 53:

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(x[i][j]==0)
			{
			if(i!=0)
			{
			int temp;
			temp = x[i][j];
			x[i][j]=x[i-1][j];
			x[i-1][j]=temp;
			}
			break;
			}
		}
	}
	display(x);
	break;

	case 51:
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(x[i][j]==0)
			{
			if(j!=3)
			{
			int temp;
			temp = x[i][j];
			x[i][j]=x[i][j+1];
			x[i][j+1]=temp;
			}
			break;
			}

		}
	}
	display(x);
	break;
	case 49:
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(x[i][j]==0)
			{
			if(j!=0)
			{
			int temp;
			temp = x[i][j];
			x[i][j]=x[i][j-1];
			x[i][j-1]=temp;
			}
			break;
			}

		}
	}
	display(x);
	break;
	case 50:
	int l=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
		if(l==0)
		{
			if(x[i][j]==0)
			{
			if(i!=3)
			{
			l++;
			int temp;
			temp = x[i][j];
			x[i][j]=x[i+1][j];
			x[i+1][j]=temp;
			}
			break;
			}
		}
		}
	}
	display(x);
	break;
	case 'E':
	exit(0);
	default:
	operation(x);
	break;

}
}
void check(int x[][col])
{
int l=1;
	for( i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if( (i!=3) || (j!=3) )
			{
			if(x[i][j] == l)
			{
				l++;
			}

			}
		}

	}

if(l == (row*col))
{
	sleep(1);
	clrscr();
	gotoxy(23,11);
	cout<<"CONGRATULATION YOU WON"<<endl;
	gotoxy(23,12);
	cout<<"_______________________"<<endl;
	gotoxy(23,13);
	cout<<" "<<endl;
	gotoxy(23,14);
	cout<<"THANKS FOR PLAYING THE GAME"<<endl;
	gotoxy(23,15);
	cout<<"REGARDS : SAURABH "<<endl;
}
else
{
operation(x);
}
}










