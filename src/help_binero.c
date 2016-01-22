#include "../include/data_structure.h"
#include "../include/help_binero.h"
#include "../include/constantes.h"

int TestLignesPleine(char** grille,int ordonnee, int taille)
{
	int i;
	for (i=0; i < taille; ++i)
	{
		if (grille[i][ordonnee]==CASEVIDE)
		{
			return 1;
		}
	}
	return 0;
};

int TestColonnePleine(char** grille,int abscisse, int taille)
{
	int i;

	for (i=0; i < taille; ++i)
	{
		if (grille[abscisse][i]==CASEVIDE)
		{
			return 1;
		}
	}
	return 0;
};


void Remplacer(char** grille,int ordonnee, int abscisse,int valeur)
{
	grille[ordonnee][abscisse]=valeur;
};


int GrilleAvecIdentiqueLigneColonne(char** grille, int taille)
{
	int i;
	for(i=0;i<taille;i++)
	{
		if (TestColonnePleine(grille,i,taille)==0 || TestLignesPleine(grille,i,taille)==0)
		{
			if(DeuxColonnesIdentiques(grille,i,taille)==UN || DeuxLignesIdentiques(grille,i,taille)==UN)
				{
				return 1;
				}
		}
	}
	return 0;
};

int GrilleNonVide(char** grille, int taille)
{
	int i,j;

	for (i=0; i<taille; ++i)
	{
		for (j=0; j<taille; ++j)
		{
			if (grille[i][j]==CASEVIDE)
			{
				return UN;
			}
		}
	}
	return ZERO;
};

int TriplonsCoordonnesAffichage(char** grille, int taille)
{
	int i,j;

	for (i=1; i < taille-1; ++i)
	{

		if (grille[ZERO][i]==grille[ZERO][i-1] && grille[ZERO][i]==grille[ZERO][i+1] && grille[ZERO][i] != CASEVIDE )
		{
			return 1;
		}
	}

	for (i=1; i < taille-1; ++i)
	{
		if (grille[taille-UN][i]==grille[taille-UN][i-1] && grille[taille-UN][i]==grille[taille-UN][i+1] && grille[taille-UN][i] != CASEVIDE)
		{
			return 1;
		}
	}

	for (i=1; i <taille-1; ++i)
	{
		if (grille[i][ZERO]==grille[i-1][ZERO] && grille[i+1][ZERO]==grille[i][ZERO] && grille[i][ZERO] != CASEVIDE )
		{
			return 1;
		}
	}

	for (i=1; i <taille-1; ++i)
	{
		if (grille[i][taille-UN]==grille[i-1][taille-UN] && grille[i][taille-UN]==grille[i+1][taille-UN] && grille[i][taille-UN] != CASEVIDE )
		{
			return 1;
		}
	}

	for(i=1;i<taille-1;i++)
	{
		for(j=1;j<taille-1;j++)
		{
			if ((grille[i+1][j] == grille[i-1][j]) && (grille[i][j]==grille[i-1][j]) && grille[i][j]!=CASEVIDE)
			{
				return 1;
			}
			if((grille[i][j+1]==grille[i][j-1]) && (grille[i][j-1]==grille[i][j]) && grille[i][j]!=CASEVIDE)
			{
				return 1;
			}
		}
	}

	return 0;
};

int DeuxLignesIdentiques(char** grille,int lignes, int taille)
{
	int i,j,identique=0;

	for(j=0;j<taille; ++j)
	{
		if(j != lignes)
		{
			identique=1;
			for (i=0;i<taille;++i)
			{
				if(grille[j][i]!=grille[lignes][i])
				{
					identique=0;
					break;
				}
			}
			if (identique==1)
			{
				return 1;
			}
		}
	}
	return 0;
};

int DeuxColonnesIdentiques(char** grille,int colonne, int taille)
{
	int i,j,identique=0;

	for(j=0;j<taille; ++j)
	{
		if(j != colonne)
		{
			identique=1;
			for (i=0;i<taille;++i)
			{
				if (grille[i][j]!=grille[i][colonne])
				{
					identique=0;
					break;
				}
			}
			if(identique==1)
			{
				return 1;
			}
		}
	}
	return 0;
};

int CaseImpossible(char** grille, int taille)
{
	if( GrilleNonVide(grille,taille)==ZERO || TriplonsCoordonnesAffichage(grille,taille)==UN  || GrilleAvecIdentiqueLigneColonne(grille,taille)==UN )
		{
			return UN;
		}
	return ZERO;
};


/*void Message_Erreur(SDL_Surface* ecran)
{
NULL;
}*/

int GrilleVide(char** grille, int taille)
{
	int i,j;

	for (i=0; i<taille; ++i)
	{
		for (j=0; j<taille; ++j)
		{
			if (grille[i][j]!=CASEVIDE)
			{
				return UN;
			}
		}
	}
	return ZERO;
};
