
#include <stdio.h>
#include <Windows.h>

void setColor(int farbe)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, farbe | FOREGROUND_INTENSITY);
}

void charBlock(int x, int y, char c)
{
	int xcnt = 1;
	int ycnt = 1;
	while (y >= ycnt)
	{
		while (x >= xcnt)
		{
			printf("%c",c);
			xcnt++;
		}
		xcnt = 1;
		printf("\n");
		ycnt++;
	}
}

void gotoxy(int x,int y)
{
	COORD cur={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cur);
} 

void charLinePos(int x, int y, int r, char c)
{
	gotoxy(x,y);
	charBlock(r, 1, c);
	gotoxy(0,0);
}

void clrscr()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {0, 0};
	DWORD count;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);

	FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

	SetConsoleCursorPosition(hStdOut, coord);
}

