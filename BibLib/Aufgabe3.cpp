#include <stdio.h>
#include <BibLib.h>
#include <Windows.h>
#include <conio.h>


const int cabreite = 10;
const int calaenge = 10;
const int MAXZEIT = 60;
static char ca[cabreite][calaenge][2];

void zeichne_stein(int x, int y, int laenge, int breite, char zeichen, int farbe)
{
	for (int i = y; i < y+laenge; i++)
	{
		for (int j = x; j < x+breite; j++)
		{
			if ((j < cabreite) && (i < calaenge))
				ca[j][i][0] = zeichen;
				ca[j][i][1] = farbe;
		}
	}

}

void ausgeben_feld()
{
	clrscr();
	for (int i = 0; i <= calaenge; i++)
	{
		for (int j = 0; j <= cabreite; j++)
		{
			setColor(ca[j][i][1]);
			printf("%c", ca[j][i][0]);
		}
		printf("\n");
	}
}

void clear_feld()
{
	for (int i = 0; i <= calaenge; i++)
	{
		for (int j = 0; j <= cabreite; j++)
		{
			ca[j][i][0] = ' ';
			ca[j][i][1] = -1;
		}
	}
}

char pause(int &zeit)
{
	char taste='x';
	fflush(stdin);
	 
	for(int i=zeit;i < MAXZEIT;i++)
	{
		if(_kbhit()==0)
		{
			Sleep(1);
			char taste='x';
			continue;
		}

		else
		{
			taste=_getch();
			zeit=i;
			return taste;
		}
	}
	zeit=0;
	return taste;
}