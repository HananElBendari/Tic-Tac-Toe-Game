#include <conio.h>
#include <stdio.h>

char menu[9]={'1','2','3','4','5','6','7','8','9'};

void finres(int i3)
   {
	  clrscr();
	  gotoxy(5,5);
	  if(menu[i3]=='x')
		 printf("player one win");
	  else if(menu[i3]=='o')
		 printf("player two win");

	  gotoxy(37,12);
	  printf("game over");

	  getch();
   }

int res()
   {
	  int i1=0,i2=0,f=0;
	  for(i1=0;i1<9;i1++)
		 {
			if((menu[i1]==menu[i1+1])&&(menu[i1+1]==menu[i1+2]))
			   {
				  finres(i1);
				  f=1; break;
			   }
			i1+=2;
		 }

	  for(i2=0;i2<3;i2++)
		 {
			if((menu[i2]==menu[i2+3])&&(menu[i2+3]==menu[i2+6]))
			   {
				  finres(i2); f=1;
				  break;
			   }
		 }

	  if((menu[0]==menu[4])&&(menu[4]==menu[8]))
		 {
			finres(0); f=1;
		 }
	  else if((menu[2]==menu[4])&&(menu[4]==menu[6]))
		 {
			finres(2);f= 1;
		 }

	  return f;
   }


int main()
   {
	  char cc,c;
	  int p=0,i,j,n=5,n1=0;
	  int flag=0,flag3=1,flagr=0;

	  clrscr();
	  gotoxy(37,5);
	  printf("xo game");
	  gotoxy(15,8);
	  printf("to play enter any char");
	  gotoxy(15,10);
	  printf("to exit enter esc ....\n");
	  cc=getch();
	  if(cc==27)
		 flag=1;
	  while(flag==0)
		 {
			clrscr();
			gotoxy(37,5);
			printf("xo game");
			gotoxy(15,8);
			printf("player one can use x");
			gotoxy(15,10);
			printf("player two can use o");

			getch();
			do{
				 clrscr();
				 for(i=0;i<9;i++)
					{
					   if(i==p)
						  textattr(0x30);
					   if((i==0)||(i==3)||(i==6))
						  {
							 n+=2;
							 if(i!=0)
								{
								   gotoxy(7,n-1);
								   printf(". . . . . . . ");
								}
							 gotoxy(10,n);
							 n1=0;
						  }
					   else
						  {
							 n1+=3;
							 for(j=0;j<3;j++)
								{
								   gotoxy(9+n1,n+j-1);
								   printf(".");
								}
							 gotoxy(10+n1,n);
						  }
					   cprintf("%c",menu[i]);
					   textattr(0x07);
					}
				 n1=0;n=5;
				 gotoxy(30,4);
				 printf("xo game");
				 gotoxy(10,18);
				 printf("use cursor right,left,up and down for move");
				 if(flag3==1)
					{
					   gotoxy(5,5);
					   printf("player one turn");
					}
				 else
					{
					   gotoxy(5,5);
					   printf("player two turn");
					}
				 c=getch();
				 switch(c)
					{
					   case 'x':
						  if((menu[p]!='x')&&(menu[p]!='o')&&(flag3==1)&&(c!='o'))
							 {
								menu[p]='x';
								flag3=2;
								flag=res();
								flagr++;
							 }
					   break;
					   case 'o':
						  if((menu[p]!='x')&&(menu[p]!='o')&&(flag3==2)&&(c!='x'))
							 {
								menu[p]='o';
								flag3=1;
								flag= res();
								flagr++;
							 }
					   break;
					   case NULL:
						  c=getch();
						  switch(c)
							 {
								case 71:
								   p=0;
								break;
								case 80:
								   p+=3;
								   if(p>=9)
									  p=0;
								break;
								case 72:
								   p-=3;
								   if(p<0)
									  p=9;
								break;
								case 75:
								   p--;
								   if(p<0)
									  p=9;
								break;
								case 79:
								   p=9;
								break;
								case 77:
								   p++;
								   if(p>9)
									  p=0;
								break;
							 }
					   break;
					   case 27:
						  flag=1;
						  clrscr();
						  gotoxy(37,12);
						  printf("game over");
						  getch();
					   break;
					}

				 if((flagr==9)&&(res()==0))
					{
					   clrscr();
					   gotoxy(5,5);
					   printf("draw");
					   gotoxy(37,12);
					   printf("game over");
					   /*gotoxy(34,13);
					   printf("for play again enter any char");
					   gotoxy(30,14);
					   printf("for exit enter esc");*/
					   cc=getch();
					  if(cc==27)
						 {
							flag=1;
						 }
					  else
						 {
							flag=1;
						 }
					  getch();
					}

			  }while(flag==0);
		 }

	  getch();
	  return 0;
   }