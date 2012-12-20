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
	Stein s1 = Stein('T');

	while(running)
	{
		Sleep(refreshRate);
		v.clear();
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
					s1.move(-1,0);
					break;
				case 77: // [->]
					s1.move(1,0);
					break;
				case 80: // [ v ]
					s1.move(0,1);
					break;
				}
				break;
			}
		}
		else
		{
			s1.move(0,1);
		}
		s1.show(&v);
		v.zeichne();
	}
}

