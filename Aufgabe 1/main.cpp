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
	v.clearfreeze();
	Stein *s1 = new Stein('I');

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
					s1->move(-1,0);
					break;
				case 77: // [->]
					s1->move(1,0);
					break;
				case 80: // [ v ]
					s1->rotate();
					break;
				}
				break;
			}
		}
		else
		{
			s1->move(0,1);
		}
		s1->show(&v);
		if (s1->checkcol(&v) == 1)
		{
			s1->freeze(&v);
			delete s1;
			s1 = new  Stein('L');
		}
		v.zeichne();
		v.linecheck();
	}
}

