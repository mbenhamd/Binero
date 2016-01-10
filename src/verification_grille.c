#include "../include/verification_grille.h"

void affichageCoordonnes(Coordonnees variable)
{
	printf("(%d,%d)\n",variable.x,variable.y);
}

void affichagePile(Liste Pile)
{
	Liste Courant=Pile->pointeurs;
	while(Courant != NULL)
	{
		if ((Courant->data.y != -1) && (Courant->data.x != -1))
		{
			printf("(%d,%d)->",Courant->data.x,Courant->data.y);
		}
	Courant=Courant->pointeurs;
	}
	printf("NULL");
	printf("\n");
}


void affichageFile(Liste File)
{
	Liste Courant=File->pointeurs;

	while(Courant != NULL)
	{
		printf("(%d,%d)->",Courant->data.x,Courant->data.y);
		Courant=Courant->pointeurs;
	}
	printf("NULL");
	printf("\n");

}

Liste RechercheCaseVide()
{
	Liste File=init(File);
	Liste Test=File;
    int i,j,taille;
    SDL_Surface*  grille[taille][taille];
	for (i=0;i<taille;++i)
	{
		for (j=0;j<taille;++j)
		{
			if (grille[i][j]==-1)
			{
				File=enfiler(File,j,i);
			}
		}
	}
	return Test;
}

