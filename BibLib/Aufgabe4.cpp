#include "BibLib.h"
#include <stdio.h>;


const int viewbreite = 60;
const int viewlaenge = 60;

View::View() {}
void View::clear()
{
	for (int i = 0; i <= viewlaenge; i++)
	{
		for (int j = 0; j <= viewbreite; j++)
		{
			feld[j][i][0] = ' ';
			feld[j][i][1] = -1;
		}
	}
}

void View::zeichne(int x, int y, char zeichen, int farbe)
{
	feld[x][y][0] = zeichen;
	feld[x][y][1] = farbe;
}

void View::zeichne()
{
	clrscr();
	for (int i = 0; i <= viewlaenge; i++)
	{
		for (int j = 0; j <= viewbreite; j++)
		{
			setColor(feld[j][i][1]);
			printf("%c", feld[j][i][0]);
		}
		printf("\n");
	}

}


Element::Element(int _x, int _y, char _zeichen, int _farbe)
{
	x = _x;
	y = _y;
	zeichen = _zeichen;
	farbe = _farbe;
	next = NULL;
}
Element::~Element() {}
Element::Element(Element &e) {}
void Element::setX(int _x)
{
	x = _x;
}
void Element::setY(int _y)
{
	y = _y;
}
void Element::setFarbe(int _farbe)
{
	farbe = _farbe;
}
void Element::setZeichen(char _zeichen)
{
	zeichen = _zeichen;
}
void Element::setNext(Element *_n)
{
	next = _n;
}
int Element::getX()
{
	return x;
}
int Element::getY()
{
	return y;
}
int Element::getFarbe()
{
	return farbe;
}
char Element::getZeichen()
{
	return zeichen;
}
Element * Element::getNext()
{
	return next;
}
void Element::zeichne(View *v)
{
	v->zeichne(x, y, zeichen, farbe);
}

Stein::Stein(char zeichen) 
{
	switch(zeichen)
	{
	liste = NULL;
	case 'I':
		for (int i = 0; i < 4; i++)
		{
			Element *pb = new Element(0,0,'X',1);
			if (liste == NULL)
			{
				pb->setNext(liste);
			}
			liste = pb;
		}


		break;
	case 'L':
		//I
		break;
	case 'K':
		//inverse L
		break;
	case 'Z':
		//Z
		break;
	case 'S':
		//S
		break;
	case 'T':
		//T
		break;
	}
}
Stein::~Stein() {}
Stein::Stein(Stein &s) {}
void Stein::fallen() {}
void Stein::show(View *) {}

