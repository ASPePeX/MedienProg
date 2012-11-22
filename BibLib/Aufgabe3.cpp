#include <stdio.h>
#include <BibLib.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>

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

int getKeyboardInput()
{
	 fflush(stdin);
	 int returnVal = 0;
	 if(_kbhit() != 0)
	 {
		returnVal=_getch();
		if(returnVal==0)
			returnVal=256+_getch();
	}
	return returnVal;
}

void endGame(bool *running)
{
	*running = false;
}


void update(int *bx, int *by, bool *running)
{
	int keyIn = getKeyboardInput();
	if(keyIn != 0)
	{
		switch(keyIn)
		{
		case 27: // [ESC]
			endGame(running);
			break;
		case 224: // Special key
			int keyIn2= getKeyboardInput();
			switch(keyIn2)
			{
			case 75: // [<-]
				*bx = *bx-1;
				break;
			case 77: // [->]
				*bx = *bx+1;
				break;
			case 80: // [ v ]
				*by = *by+1;
				break;
			}
			break;
		}
	}
	else
		*by = *by+1;
}

void render(int *bx, int *by)
{
	clear_feld();
	setColor(-1);
	zeichne_stein(*bx,*by,2,2,'A',3);
	ausgeben_feld();
}