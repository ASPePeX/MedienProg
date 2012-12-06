#include <stdio.h>
#include <BibLib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>

int bx = 1;
int by = 1;
int mzeit = 0;
const int refreshRate = 200;
static bool running = true;


void main(void)
{
	View v = View();
	v.clear();
	//Element e1 = Element(1,1,'x',3);
	//Element e2 = Element(5,5,'y',4);
	//e1.zeichne(&v);
	//e2.zeichne(&v);
	Stein s1 = Stein('I');



	while(running)
	{
		Sleep(refreshRate);
		int keyIn = getKeyboardInput();
		if(keyIn != 0)
		{
			switch(keyIn)
			{
			case 27: // [ESC]
				endGame(&running);
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
		{
			*by = *by+1;
		}
		s1.show(&v);
		v.zeichne();
	}
}

