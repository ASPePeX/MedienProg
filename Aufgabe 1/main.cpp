#include <stdio.h>
#include <BibLib.h>


int bx = 1;
int by = 1;
int mzeit = 0;

void main(void)
{
	while(char button = pause(mzeit))
	{
		
	clear_feld();
	setColor(-1);
	zeichne_stein(bx,by,2,2,'A',3);
	ausgeben_feld();
			
		if (button == 'a')
			bx = bx-1;
		else if (button == 's')
			bx = bx+1;
		else if (button == 'x')
			by = by+1;
	}
}

