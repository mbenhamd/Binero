#ifndef H_DATA_STRUCTURE
#define H_DATA_STRUCTURE 0


typedef struct Coordonnees Coordonnees;

struct Coordonnees
{
	int x;
	int y;
	int contient;
};

typedef struct Element Element;

struct Element
{
    Coordonnees data;
    Element *pointeurs;
};

typedef struct Element* Liste;

Liste initPile();
Liste Push(Liste Type, Coordonnees valeur);
Liste Pop(Liste Type, Coordonnees* valeur);
Liste copie(Liste src,Liste dest);
Liste enfiler(Liste File,int abscisse, int ordonnees);

Liste initFile(Liste File);

Coordonnees Defiler(Liste File);

#endif





