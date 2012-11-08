// Aufgabe 1.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <stdio.h>
#include <BibLib.h>




void main(void)
{
clear_feld();
setColor(-1);
zeichne_stein(2,1,3,5,'C',5);
zeichne_stein(5,4,2,2,'A',3);
ausgeben_feld();
}

