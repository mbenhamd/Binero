#include <stdio.h>
#include <stdlib.h>
#include "../include/data_structure.h"

/*Dans ce fichier, vous trouverez les structures de données utilisées pour le binero.
Il y a une pile en pointeurs pour comptabilier les coordonnées du joueur.*/

Liste initPile()
{
	Liste Begin=(Liste)malloc(sizeof(Element));
	Begin->pointeurs=NULL;
	return Begin;
};

Liste Push(Liste Type,Coordonnees valeur)
{
	Liste Add=(Liste)malloc(sizeof(Element));
	Add->data=valeur;
	Add->pointeurs=Type;
	return Add;
};

Liste Pop(Liste Type, Coordonnees* valeur)
{
	Liste Remove;
	*valeur=Type->data;
	Remove=Type->pointeurs;
	return Remove;
};

Liste copie(Liste src,Liste dest)
{
	while(src->pointeurs!=NULL)
	{
		dest->pointeurs=memcpy(src,dest,sizeof(Liste));
	}
}

Liste initFile(Liste File)
{
	File=(Element*)malloc(sizeof(Element));
	File->pointeurs=NULL;
	return File;
};

Coordonnees Defiler(Liste File)
{
	Liste Courant=File->pointeurs;
	Coordonnees valeur=File->pointeurs->data;
	File->pointeurs=Courant->pointeurs;
	return valeur;
};

Liste enfiler(Liste File,int abscisse, int ordonnees)
{
	Liste Courant=(Element*)malloc(sizeof(Element));
	Courant=File->pointeurs;

	while (Courant != NULL)
	{
		Courant=Courant->pointeurs;
	}
		Courant=(Element*)malloc(sizeof(Element));
		Courant->data.x=abscisse;
		Courant->data.y=ordonnees;
		Courant->pointeurs=(Element*)malloc(sizeof(Element));
		Courant->pointeurs=NULL;

	File->pointeurs=Courant;
	return File->pointeurs;
};
