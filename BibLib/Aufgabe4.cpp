#include "BibLib.h"
#include <stdio.h>



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
			setColor(sfeld[j][i][1]);
			printf("%c", sfeld[j][i][0]);
		}
		printf("\n");
	}

}

int View::chkcoll()
{
	return 1;
}

void View::freeze(int x, int y, char zeichen, int farbe)
{
	sfeld[x][y][0] = zeichen;
	sfeld[x][y][1] = farbe;
}

void View::linecheck()
{
	for (int i = 0; i <= viewlaenge; i++)
	{
		for (int j = 0; j <= viewbreite; j++)
		{
			if (sfeld[j][i][0] == ' ')
				break;
			else if (j == viewbreite)
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
			if (j <= y)
			{
				sfeld[j][i][0] = sfeld[j][i-1][0];
				sfeld[j][i][1] = sfeld[j][i-1][1];
			}
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

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

Stein::Stein(char zeichen) 
{
	liste = NULL;
	switch(zeichen)
	{
	
	case 'I':
		{
		for (int i = 0; i < 4; i++)
		{
			Element *pb = new Element(viewbreite/2,i,'X',1);
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
		Element *pb1 = new Element(viewbreite/2,0,'X',2);
		pb1->setNext(NULL);
		liste = pb1;
		Element *pb2 = new Element(viewbreite/2,1,'X',2);
		pb2->setNext(liste);
		liste = pb2;
		Element *pb3 = new Element(viewbreite/2,2,'X',2);
		pb3->setNext(liste);
		liste = pb3;
		Element *pb4 = new Element((viewbreite/2)+1,2,'X',2);
		pb4->setNext(liste);
		liste = pb4;
		}
		break;
	case 'K':
		{
		Element *pb1 = new Element(viewbreite/2,0,'X',3);
		pb1->setNext(NULL);
		liste = pb1;
		Element *pb2 = new Element(viewbreite/2,1,'X',3);
		pb2->setNext(liste);
		liste = pb2;
		Element *pb3 = new Element(viewbreite/2,2,'X',3);
		pb3->setNext(liste);
		liste = pb3;
		Element *pb4 = new Element((viewbreite/2)-1,2,'X',3);
		pb4->setNext(liste);
		liste = pb4;
		}
		break;
	case 'Z':
		{
		Element *pb1 = new Element(viewbreite/2,0,'X',2);
		pb1->setNext(NULL);
		liste = pb1;
		Element *pb2 = new Element(viewbreite/2,1,'X',2);
		pb2->setNext(liste);
		liste = pb2;
		Element *pb3 = new Element(viewbreite/2-1,1,'X',2);
		pb3->setNext(liste);
		liste = pb3;
		Element *pb4 = new Element((viewbreite/2)-1,2,'X',2);
		pb4->setNext(liste);
		liste = pb4;
		}

		break;
	case 'S':
		{
		Element *pb1 = new Element(viewbreite/2,0,'X',2);
		pb1->setNext(NULL);
		liste = pb1;
		Element *pb2 = new Element(viewbreite/2,1,'X',2);
		pb2->setNext(liste);
		liste = pb2;
		Element *pb3 = new Element(viewbreite/2+1,1,'X',2);
		pb3->setNext(liste);
		liste = pb3;
		Element *pb4 = new Element((viewbreite/2)+1,2,'X',2);
		pb4->setNext(liste);
		liste = pb4;
		}

		break;
	case 'T':
		{
		Element *pb1 = new Element(viewbreite/2,0,'X',2);
		pb1->setNext(NULL);
		liste = pb1;
		Element *pb2 = new Element(viewbreite/2,1,'X',2);
		pb2->setNext(liste);
		liste = pb2;
		Element *pb3 = new Element(viewbreite/2+1,1,'X',2);
		pb3->setNext(liste);
		liste = pb3;
		Element *pb4 = new Element((viewbreite/2),2,'X',2);
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
	Element *pe = liste;
	while (pe != NULL)
	{
		int x = pe->getX();
		int y = pe->getY();
		x = x + xadd;
		y = y + yadd;
		pe->setX(x);
		pe->setY(y);
		pe = pe->getNext();
	}
}

void Stein::show(View *v)
{
	Element *pe = liste;
	while (pe != NULL)
	{
		pe->zeichne(v);
		pe = pe->getNext();
	}
}

