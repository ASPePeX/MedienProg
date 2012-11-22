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
	while(running)
	{
		Sleep(refreshRate);
		update(&bx,&by, &running);
		render(&bx,&by);
	}
}

