void charBlock(int x, int y, char c);
void charLinePos(int x, int y, int r, char c);
void gotoxy(int x,int y);
void setColor(int farbe);
void zeichne_stein(int x, int y, int laenge, int breite, char zeichen, int farbe);
void ausgeben_feld();
void clear_feld();
void clrscr();
char pause(int &zeit);
int getKeyboardInput();
void endGame(bool *running);
void update(int *bx, int *by, bool *running);
void render(int *bx, int *by);

class View				//verwaltet die physikalische Ausgabe
{
private:
	char feld[60][60][2];	//****** Character-Feld zur Darstellung
public:
	View();
	void clear();		//initialisiere das Feld mit Leerzeichen
	void zeichne(int x, int y, char zeichen, int farbe);
						//zeichne an der Stelle (x,y) das Zeichen
						//mit der angegebenen Farbe
	void zeichne();		//gib den Inhalt des Feldes auf der Konsole aus
};

class Element			//Ein Element eines Steines oder auch Baustein
{
private:
	int x;				//x-Position
	int y;				//y-Position
	char zeichen;
	int farbe;
	Element *next;
public:
	Element(int _x, int _y, char _zeichen, int _farbe);
	~Element();
	Element(Element &e);
	void setX(int x);
	void setY(int y);
	void setFarbe(int farbe);
	void setZeichen(char zeichen);
	void setNext(Element *n);
	int getX();
	int getY();
	int getFarbe();
	char getZeichen();
	Element * getNext();
	void zeichne(View *v);	//zeichnet dieses Element auf einem View
};

class Stein
{
private:
	Element *liste;		//maximal 4 Elemente pro Stein
						//gelöschte Elemente werden aus der Liste entfernt
	char zeichen;		// Zeichen des Steins
public:
	Stein(char zeichen);		//Stein wird immer an der gleichen Position erzeugt
						//Wie der Stein aussieht (Form) wird hier im
						//Konstruktor eines Steins entschieden
						//Er besteht zunächst immer aus 4 Elementen
	~Stein();			//Destruktor für Stein, Löschen der Element-Liste
	Stein(Stein &s);
	void fallen();		//Stein fällt um eine Einheit nach unten
	void show(View *);	//Stein wird auf dem View visualisiert
};

