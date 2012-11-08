#include <stdio.h>
#include <BibLib.h>

const int cabreite = 10;
const int calaenge = 10;
static char ca[cabreite][calaenge];
static int cac[cabreite][calaenge];

void zeichne_stein(int x, int y, int laenge, int breite, char zeichen, int farbe)
{
	for (int i = y; i < y+laenge; i++)
	{
		for (int j = x; j < x+breite; j++)
		{
			if ((j < cabreite) && (i < calaenge))
				ca[j][i] = zeichen;
				cac[j][i] = farbe;
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
			setColor(cac[j][i]);
			printf("%c", ca[j][i]);
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
			ca[j][i] = ' ';
			cac[j][i] = -1;
		}
	}
}