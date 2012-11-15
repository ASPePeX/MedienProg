#include "BibLib.h"

View::View() {}
void View::clear() {}
void View::zeichne(int x, int y, char zeichen, int farbe) {}
void View::zeichne() {}

Element::Element(int x, int y, char zeichen, int farbe) {}
void Element::setX(int x) {}
void Element::setY(int y) {}
void Element::setFarbe(int farbe) {}
void Element::setZeichen(char zeichen) {}
int Element::getX() {}
int Element::getY() {}
int Element::getFarbe() {}
char Element::getZeichen() {}
void Element::zeichne(View *v) {}

Stein::Stein(char zeichen) {}
Stein::~Stein() {}
void Stein::fallen() {}
void Stein::show(View *) {}

