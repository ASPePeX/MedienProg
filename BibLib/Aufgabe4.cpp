#include "BibLib.h"
#include <stdio.h>


View::View() {}
void View::clear()
{
	for (int i = 0; i < viewlaenge; i++)
	{
		for (int j = 0; j < viewbreite; j++)
		{
			feld[j][i][0] = ' ';
			feld[j][i][1] = -1;
		}
	}
}
void View::clearfreeze()
{
	for (int i = 0; i < viewlaenge; i++)
	{
		for (int j = 0; j < viewbreite; j++)
		{
			sfeld[j][i][0] = 0;
			sfeld[j][i][1] = -1;
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
	for (int i = 0; i < viewlaenge; i++)
	{
		printf("#");
		for (int j = 0; j < viewbreite; j++)
		{
			if (sfeld[j][i][0] != 0)
			{
			setColor(sfeld[j][i][1]);
			printf("%c", sfeld[j][i][0]);
			}
			else
			{
			setColor(feld[j][i][1]);
			printf("%c", feld[j][i][0]);
			}
		}
		printf("#\n");
	}

}

int View::checkcol(int x, int y, View *v)
{
	//v->zeichne(x,y+1,'+',6);
	if (sfeld[x][y+1][0] != 0)
		return 1;
	else
		return 0;
}

void View::freeze(int x, int y, char zeichen, int farbe)
{
	sfeld[x][y][0] = zeichen;
	sfeld[x][y][1] = farbe;
}

void View::linecheck()
{
	for (int i = 0; i < viewlaenge; i++)
	{
		for (int j = 0; j < viewbreite; j++)
		{
			if (sfeld[j][i][0] != 0)
				sfeld[j][i][1] = 8;
			if (sfeld[j][i][0] == 0)
				break;
			else if (j >= viewlaenge-1)
				dropline(i);
		}
	}
}

void View::dropline(int y)
{
	for (int i = viewlaenge; i >= 1; i--)
	{
		for (int j = viewbreite; j >= 1; j--)
		{
		//sfeld umsortieren
		}
	}

}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

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

void Element::zeichne(View *v, int xadd, int yadd)
{
	v->zeichne(x+xadd, y+yadd, zeichen, farbe);
}
void Element::freeze(View *v, int xadd, int yadd)
{
	v->freeze(x+xadd, y+yadd, zeichen, farbe);
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

Stein::Stein(char zeichen) 
{
	x = 5;
	y = 2;
	liste = NULL;
	switch(zeichen)
	{
	
	case 'I':
		{
		for (int i = -1; i < 3; i++)
		{
			Element *pb = new Element(0,i,'X',2);
			if (liste != NULL)
			{
				pb->setNext(liste);
			}
			else
			{
				pb->setNext(NULL);
			}
			liste = pb;
		}
		}
		break;
	case 'L':
		{
		Element *pb1 = new Element(0,-1,'X',2);
		pb1->setNext(NULL);
		liste = pb1;
		Element *pb2 = new Element(0,0,'X',2);
		pb2->setNext(liste);
		liste = pb2;
		Element *pb3 = new Element(0,1,'X',2);
		pb3->setNext(liste);
		liste = pb3;
		Element *pb4 = new Element(1,1,'X',2);
		pb4->setNext(liste);
		liste = pb4;
		}
		break;
	case 'K':
		{
		Element *pb1 = new Element(0,-1,'X',3);
		pb1->setNext(NULL);
		liste = pb1;
		Element *pb2 = new Element(0,0,'X',3);
		pb2->setNext(liste);
		liste = pb2;
		Element *pb3 = new Element(0,1,'X',3);
		pb3->setNext(liste);
		liste = pb3;
		Element *pb4 = new Element(-1,1,'X',3);
		pb4->setNext(liste);
		liste = pb4;
		}
		break;
	case 'Z':
		{
		Element *pb1 = new Element(0,-1,'X',2);
		pb1->setNext(NULL);
		liste = pb1;
		Element *pb2 = new Element(0,0,'X',2);
		pb2->setNext(liste);
		liste = pb2;
		Element *pb3 = new Element(-1,0,'X',2);
		pb3->setNext(liste);
		liste = pb3;
		Element *pb4 = new Element(-1,1,'X',2);
		pb4->setNext(liste);
		liste = pb4;
		}

		break;
	case 'S':
		{
		Element *pb1 = new Element(0,-1,'X',2);
		pb1->setNext(NULL);
		liste = pb1;
		Element *pb2 = new Element(0,0,'X',2);
		pb2->setNext(liste);
		liste = pb2;
		Element *pb3 = new Element(1,0,'X',2);
		pb3->setNext(liste);
		liste = pb3;
		Element *pb4 = new Element(1,1,'X',2);
		pb4->setNext(liste);
		liste = pb4;
		}

		break;
	case 'T':
		{
		Element *pb1 = new Element(0,-1,'X',2);
		pb1->setNext(NULL);
		liste = pb1;
		Element *pb2 = new Element(0,0,'X',2);
		pb2->setNext(liste);
		liste = pb2;
		Element *pb3 = new Element(1,0,'X',2);
		pb3->setNext(liste);
		liste = pb3;
		Element *pb4 = new Element(0,1,'X',2);
		pb4->setNext(liste);
		liste = pb4;
		}

	break;
	}
}

Stein::~Stein() 
{
	Element *pe = liste;
	Element *pen = liste;

	while (pe != NULL)
	{
		pen = pe->getNext();
		delete  pe;
		pe = pen->getNext();
	}
}

Stein::Stein(Stein &s)
{
	//copy constructor
}

void Stein::move(int xadd, int yadd)
{
	int x = this->getX();
	int y = this->getY();
	x = x + xadd;
	y = y + yadd;
	this->setX(x);
	this->setY(y);
}

void Stein::rotate()
{
	Element *pe = liste;
	while (pe != NULL)
	{
		int x = pe->getX();
		int y = pe->getY();
		pe->setX(y*-1);
		pe->setY(x);
		pe = pe->getNext();
	}

}

void Stein::show(View *v)
{
	Element *pe = liste;
	while (pe != NULL)
	{
		pe->zeichne(v,this->getX(),this->getY());
		pe = pe->getNext();
	}
}

void Stein::freeze(View *v)
{
	Element *pe = liste;
	while (pe != NULL)
	{
		pe->freeze(v,this->getX(),this->getY());
		pe = pe->getNext();
	}

}

int Stein::checkcol(View *v)
{
	Element *pe = liste;
	while (pe != NULL)
	{
		int x = pe->getX() + this->getX();
		int y = pe->getY() + this->getY();

		if (y == viewlaenge-1)
			return 1;
		else if (v->checkcol(x,y,v))
			return 1;

		pe = pe->getNext();
	}
	return 0;
}

void Stein::setX(int _x)
{
	x = _x;
}

void Stein::setY(int _y)
{
	y = _y;
}

int Stein::getX()
{
	return x;
}

int Stein::getY()
{
	return y;
}
