#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void color(int warna)
{
	HANDLE hConsole;
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, warna);
} 

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void skor()
{
    system("cls");
    gotoxy(66,3);
    color(7);
    printf("SCORE : ");
    color(4);
    gotoxy(75,3);
    printf("0");
    gotoxy(1,16);
    color(9);
    for(int x=0;x<79;x++)
    printf("\xB0");
    gotoxy (6,16);
    color(10);
    printf("\xB0\xB0");
}
 
int t,speed=40;
void jump(int jump=0)
{
    static int a=1;
    if(jump==0)
    {
        t=0;
    }
    else if(jump==2)
    {
        t--;
    }
    else t++;
	gotoxy(6,14-t);
    printf("  ");
    gotoxy(6,15-t);
    color(10);
    printf("лл");
    gotoxy(6,16-t);
    if(jump!=0)
	{
      printf("  ");
    }
    else
    {     
      color(10);
      printf("\xB0\xB0");
    }
    delay(speed);
}

void play()
{
    static int x=0,scr=0;
    if(x==71 && t<4)
    {
      scr=-1;
      speed=100;
      gotoxy(24,8);
      color (11);
      printf("Press 'any key' to play again");
      getch();
      gotoxy(24,8);
      printf("                             ");
      color(12);
      gotoxy(75,3);
      printf("0");
    }
    int c;
    gotoxy(78-x,15);
    printf("    ");
    for(c=10;c<15;c++)
    {
      delay(10);
      gotoxy(78-x,15);
      color(c);
      printf("лл ");
    }      
      gotoxy (2,15);
      printf ("  ");
      x++;
    if(x==77)
    {
      x=0;
      scr++;
      gotoxy(75,3);
      printf("     ");
      gotoxy(75,3);
      color(12);
      printf("%d",scr);
      if(speed>1)
	  {
      speed--;
      }
    }
}

int main()
{
	system("mode con: lines=29 cols=82");
	int i, j, o, u;
	char kode;
	int huruf[11][6][6]={
	{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	},
	{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	},
	{
		{1, 0, 0, 0, 1},
		{0, 1, 0, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 1, 0, 1, 0},
		{1, 0, 0, 0, 1},
	},
		{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 1, 1},
		{1, 0, 1, 0, 0},
		{1, 0, 0, 1, 1},
	},
	{
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	},
	{
		{1, 0, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 0, 1, 1},
		{1, 0, 0, 0, 1},
	},
	{
		{1, 0, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 0, 1, 1},
		{1, 0, 0, 0, 1},
	},
	{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
	},
	{
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 1, 1},
		{1, 0, 1, 0, 0},
		{1, 0, 0, 1, 1},
	},

	};

	menu:
	u=4;
	for(j=0;j<6;j++)
	{
		gotoxy(12, u);
		color(3);
		for(i=0;i<10;i++)
		{
			for(o=0;o<6;o++)
			{
				if(huruf[i][j][o]!=0)
					putchar('\xDB');
				else
					putchar(' ');
			}
		}
		printf("\n");
		u++;
	}
	
	int atas, kiri, kanan, bawah;
	gotoxy(29, 12);
	color(12);
	printf("\xDA");
	atas=30;
	while(atas<=46)
	{
		gotoxy(atas, 12);
		printf("\xC4");
		atas++;
	}
	gotoxy(47, 12);
	printf("\xBF");
	kiri=13;
	while(kiri<=15)
	{
		gotoxy(29, kiri);
		printf("\xB3");
		kiri++;
	}
	kanan=13;
	while(kanan<=15)
	{
		gotoxy(47, kanan);
		printf("\xB3");
		kanan++;
	}
	
	gotoxy(29, 16);
	printf("\xC0");
	bawah=30;
	while(bawah<=46)
	{
		gotoxy(bawah, 16);
		printf("\xC4");
		bawah++;
	}
	gotoxy(47, 16);
	printf("\xD9");
	
	color(15);
	gotoxy(32,13);
	printf ("PLAY GAME (Y) \n");
	gotoxy(31,14);
	printf ("HOW TO PLAY (H)\n");
	gotoxy(32,15);
	printf ("EXIT GAME(N)");
	fflush(stdin);
	kode=getch();
		
	switch (kode)
	{
     case 'h' :
  	 haha:
	 system ("cls");
	 
	color(12);
	gotoxy(26, 7);
  	printf("\xDA");
   	atas=27;
	while(atas<=50)
	{
		gotoxy(atas, 7);
		printf("\xC4");
		atas++;
	}
	
	gotoxy(51, 7);
	printf("\xBF");
	kiri = 8;
	while(kiri<=11)
	{
		gotoxy(26, kiri);
		printf("\xB3");
		kiri++;
	}
	
	gotoxy(26, 12);
	printf("\xC0");
	kanan=8;
	while(kanan<=11)
	{
		gotoxy(51, kanan);
		printf("\xB3");
		kanan++;
	}
	
	gotoxy(51, 12);
	printf("\xD9");
	bawah=27;
	while(bawah<=50)
	{
		gotoxy(bawah, 12);
		printf("\xC4");
		bawah++;
	}


  		gotoxy (36,8);
  		color(6);
  		printf ("Button ");
  		gotoxy (28,10);
  		color(5);
  		printf ("Space  :  Jump");
  		gotoxy (28,11);
  		color(5);
  		printf ("  X    :  Back to menu");
  		char kembali;
  		kembali=getch();
  		
		if(kembali=='x')
		{
  			//system ("cls");
  			goto menu;
	    }
		else if(kembali!='x')
		{
			goto haha;
		}
		
  	case 'n':
		quit:
		//system ("cls");
		gotoxy (29,8);
		color(12);
		printf ("Are you sure? Y/N \n");
		char back;
		back=getch();
		
		if(back=='n')
		{
			//system("cls");
			goto menu;
		}
		else if(back=='y')
		{
			system("cls");
			color(12);
			gotoxy(34,7);
			printf("GOOD BYE!!!\n\n");
			getch();
			break;
		}
		else if(back!='y'||back!='n')
		{
			system("cls");
			goto quit;
		}
	case 'y':
		char ch;
		int i;
		skor();
		while(true)
		{
		  while(!kbhit())
          {
           jump();
           play();
          }
          ch=getch();
          if(ch==' ')
          {
		    for(i=0;i<6;i++)
            {
              jump(1);
              play();
            }
             for(i=0;i<6;i++)
            {
              jump(2);
              play();
            }
          }
          else if (ch=='x')
		  {
            color(7);
            gotoxy(35, 5);
		    printf("-------------");
		    color(7);
		    gotoxy(37, 6);
		    printf("-LOADING-");
		    color(7);
		    gotoxy(35, 7);
		    printf("-------------");
            delay(2000);
		    //system("cls");
		    goto menu;
	      }
		    else if(ch!='x'||ch!=' ')
		    continue;
	    }
	     default:
		 goto menu;
	}
	return 0;
}
