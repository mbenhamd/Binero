#include <stdio.h>
#include <stdlib.h>
#include "../include/data_structure.h"
#include "../include/constantes.h"

void CompleterColonne(char** grille, int taille, int colonne, Coordonnees changer)
{
	int i;
	int cpt=0;

	for (i=0;i<taille; ++i)
	{
		if (grille[i][colonne]==ZERO)
		{
			cpt++;
		}
		else if (grille[i][colonne]==UN)
		{
				cpt--;
		}
	}

	if (cpt>0)
	{
		grille[changer.x][changer.y]=UN;
	}
	else
	{
		grille[changer.x][changer.y]=ZERO;
	}
};

void CompleterLigne(char** grille, int taille, int ligne, Coordonnees changer)
{
	int i;
	int cpt=0;

	for (i=0;i<taille; ++i)
	{
		if (grille[ligne][i]==ZERO)
		{
			cpt++;
		}
		else if (grille[ligne][i]==UN)
		{
				cpt--;
		}
	}

	if (cpt>0)
	{
		grille[changer.x][changer.y]=UN;
	}
	else
	{
		grille[changer.x][changer.y]=ZERO;
	}
};

void RechercheColonneUneSeuleCaseVide(char** grille, int taille)
{
	int i,j;
	int compteur_CASEVIDE=0;
	Coordonnees changer;

	for (i=0;i<taille; ++i)
	{
		for (j=0;j<taille;++j)
		{
			if (grille[j][i]==CASEVIDE)
			{
				compteur_CASEVIDE++;
				changer.x=j;
				changer.y=i;
			}
		}
		if (compteur_CASEVIDE==UN)
		{
			CompleterColonne(grille,taille,i,changer);
		}
		compteur_CASEVIDE=0;
	}
};
int ModificationInterieur(char** initial, char** grille, int i,int j,int taille)
{

	if (initial[i][j+1] == CASEVIDE && grille[i][j+1]!=CASEVIDE)
	{
		grille[i][j+1]=CASEVIDE;
	}
	else if ( j>=1 && initial[i][j-1] == CASEVIDE && grille[i][j-1]!=CASEVIDE)
	{
		grille[i][j-1]=CASEVIDE;
	}

	else if ( i>=1 && initial[i-1][j] == CASEVIDE && grille[i-1][j]!=CASEVIDE)
	{
		grille[i-1][j]=CASEVIDE;
	}
	else if ( i<taille-1 && initial[i+1][j] == CASEVIDE && grille[i+1][j]!=CASEVIDE)
	{
		grille[i+1][j]=CASEVIDE;
	}
	else if ( i<taille-2 && initial[i+2][j] == CASEVIDE && grille[i+2][j]!=CASEVIDE)
	{
		grille[i+2][j]=CASEVIDE;
	}
	else if ( i>=2 && initial[i-2][j] == CASEVIDE && grille[i-2][j]!=CASEVIDE)
	{
		grille[i-2][j]=CASEVIDE;
	}
	else if (i>=2 && initial[i][j+2] == CASEVIDE && grille[i][j+2]!=CASEVIDE)
	{
		grille[i][j+2]=CASEVIDE;
	}
	else if (j<taille-2 && initial[i][j-2] == CASEVIDE && grille[i][j-2]!=CASEVIDE)
	{
		grille[i][j-2]=CASEVIDE;
	}
	return 0;
};

void RechercheLigneUneSeuleCaseVide(char** grille, int taille)
{
	int i,j;
	int compteur=0;
	Coordonnees changer;

	for (i=0;i<taille; ++i)
	{
		for (j=0;j<taille;++j)
		{
			if (grille[i][j]==CASEVIDE)
			{
				compteur++;
				changer.x=i;
				changer.y=j;
			}
		}
		if (compteur==UN)
		{
			CompleterLigne(grille,taille,i,changer);
		}
		compteur=0;
	}
};

int RechercheAutrePossibiliteDeCoups(char** initial, char** grille, int taille)
{
	int i,j;

	for(i=2;i<taille-2;i++)
	{
		for(j=2;j<taille-2;j++)
		{

			if (initial[i][j]==CASEVIDE)
			{
			if (grille[i+1][j] != grille[i+2][j] && grille[i-1][j]!=grille[i-2][j] && grille[i][j-1]!=grille[i][j-2] && grille[i][j+1]!=grille[i][j+2] && grille[i+1][j]!=grille[i-1][j] && grille[i][j+1]!=grille[i][j-1] )
			{
				grille[i][j]=((grille[i][j]+1)%POSSIBILITES);
			}
			}
		}
	}
	return 0;
};

void AfficheLigneNonEquilibre(char** grille,int taille)
{
	int i,j;
	int cpt=0;


	for (i=0;i<taille; ++i)
	{
		for (j = 0; j < taille; ++j)
		{
			if (grille[i][j]==UN)
			{
				cpt++;
			}
		}

		if (cpt!=(taille/POSSIBILITES))
		{
			printf("Ligne %d \n",i);
		}
		cpt=0;
	}
};

void AfficheColonneNonEquilibre(char** grille,int taille)
{
	int i,j;
	int cpt=0;


	for (i=0;i<taille;++i)
	{
		for (j=0;j<taille;++j)
		{
			if (grille[j][i]==UN)
			{
				cpt++;
			}
		}

		if(cpt!=(taille/POSSIBILITES))
		{
			printf("Colonne %d \n",i);
		}
		cpt=0;
	}
};

int RemplacementTrioParCaseAutreCase(char** initial, char** grille, int taille)
{
	int i,j;

	for (i=1; i < taille-1; ++i)
	{

		if (initial[ZERO][i]==CASEVIDE)
		{
		if (grille[ZERO][i]==grille[ZERO][i-1] && grille[ZERO][i]==grille[ZERO][i+1] && grille[ZERO][i] != CASEVIDE )
		{
			grille[ZERO][i]=((grille[ZERO][i-1]+1)%POSSIBILITES);
		}
		}
	}

	for (i=1; i < taille-1; ++i)
	{
		if (initial[taille-UN][i]==CASEVIDE)
		{
		if (grille[taille-UN][i]==grille[taille-UN][i-1] && grille[taille-UN][i]==grille[taille-UN][i+1] && grille[taille-UN][i] != CASEVIDE)
		{
			grille[taille-UN][i]=((grille[taille-UN][i-1]+1)%POSSIBILITES);
		}
		}
	}

	for (i=1; i <taille-1; ++i)
	{
		if (initial[i][ZERO]==CASEVIDE)
		{
		if (grille[i][ZERO]==grille[i-1][ZERO] && grille[i+1][ZERO]==grille[i][ZERO] && grille[i][ZERO] != CASEVIDE )
		{
			grille[i][ZERO]=((grille[i-1][ZERO]+1)%POSSIBILITES);
		}
		}
	}

	for (i=1; i <taille-1; ++i)
	{
		if (initial[i][taille-UN]==CASEVIDE)
		{
		if (grille[i][taille-UN]==grille[i-1][taille-UN] && grille[i][taille-UN]==grille[i+1][taille-UN] && grille[i][taille-UN] != CASEVIDE )
		{
			grille[i][taille-UN]=((grille[i-1][taille-UN]));
		}
		}
	}

	for(i=1;i<taille-1;i++)
	{
		for(j=1;j<taille-1;j++)
		{

			if (initial[i][j]==CASEVIDE)
			{
			if ((grille[i+1][j] == grille[i-1][j]) && (grille[i][j]==grille[i-1][j]))
			{
				grille[i][j]=((grille[i+1][j]+1)%POSSIBILITES);
			}
			if((grille[i][j+1]==grille[i][j-1]) && (grille[i][j-1]==grille[i][j]))
			{
				grille[i][j-1]=((grille[i][j-1]+1)%POSSIBILITES);
			}
			}
		}
	}

	return 0;
};

void cleargrille(char** initial, char** grille, int taille)
{
	int i,j;
	for (i = 0; i < taille; ++i)
	{
		for (j = 0; j < taille; ++j)
		{
			if (initial[i][j]==CASEVIDE)
				{
					grille[i][j]=CASEVIDE;
				}
		}
	}
}

int Compteur(char** grille, int taille, int ligne)
{
	int i;
	int cpt=0;
	for (i = 0; i < taille; ++i)
	{
		if (grille[ligne][i]==0)
			{
				cpt++;
			}
		else if (grille[ligne][i]==1)
		{
			cpt--;
		}

	}
	if (cpt>0)
	{
		return UN;
	}
	else if (cpt<0)
	{
		return ZERO;
	}
	else
	{
		return 0;
	}

};

int ModificationCoupsImpossible(char**initial, char** grille, int taille)
{

int i,j;
	for (i=1;i<taille-1; ++i)
	{
		for (j=1;j<taille-1; ++j)
		{
			if (grille[i][j]==CASEVIDE && (CASEVIDE != (grille[i+1][j]==grille[i+2][j])) && (CASEVIDE != (grille[i][j+1]==grille[i][j+2])))
			{
				ModificationInterieur(initial,grille,i,j,taille);
			}
		}
	}

};


char** initialisergrille(int taille)
{
	int i;
	char** grille;
	grille=(char**)malloc(sizeof(char*)*taille);

	for (i = 0; i < taille; ++i)
	{
		grille[i]=(char*)malloc(sizeof(char)*taille);
	}

	return grille;

};

void liregrille(char** grille, int taille)
{
	FILE* fichier = NULL;
		int i, j;
    	int caractereActuel;

    	fichier = fopen("save/grille1.txt", "r");
    	if (fichier != NULL)
    		caractereActuel = 10;
    	{
        	for (i = 0; i != taille; ++i)
        	{
        		for (j = 0; j != taille; ++j)
        		{
        		caractereActuel = fgetc(fichier);
        		if (caractereActuel=='0')
        		{
        			grille[i][j]=0;
        		}
        		else if (caractereActuel=='1')
        		{
        			grille[i][j]=1;
        		}
        		else if (caractereActuel=='2')
        		{
        			grille[i][j]=-1;
        		}
        		else{
        			printf("Erreur !\n");
        		}
        		}
        	}
        fclose(fichier);
    	}
};



void AuHasard(char** grille, int taille)
{
	int i,j;
	for (i = 2; i < taille-2; ++i)
	{
		for (j = 2; j < taille-2; ++j)
		{
			if (grille[i][j]==CASEVIDE && grille[i-1][j]!=grille[i+1][j] && grille[i][j-1]!=grille[i][j+1] && grille[i-2][j]!=grille[i+2][j] && grille[i][j-2]!=grille[i][j+2])
			{
				grille[i][j]=rand()%2;
			}
		}
	}
};




int RemplacementTrioParCaseVide(char** initial, char** grille, int taille)
{
	int i,j;

	for(i=1;i<taille-1;i++)
	{
		for(j=1;j<taille-1;j++)
		{

			if ((grille[i+1][j] == grille[i-1][j]) && (grille[i][j]==grille[i-1][j]))
			{
				if (initial[i][j]!=CASEVIDE)
				{
					ModificationInterieur(initial,grille,i,j,taille);
				}
				else
				{
				grille[i][j]=CASEVIDE;
				}
			}
			else if((grille[i][j+1]==grille[i][j-1]) && (grille[i][j-1]==grille[i][j]))
			{
				if (initial[i][j]!=CASEVIDE)
				{
					ModificationInterieur(initial,grille,i,j,taille);
				}
				else
				{
				grille[i][j]=CASEVIDE;
				}
			}
			}
	}

		for (i=1; i < taille-1; ++i)
	{

		if (grille[ZERO][i]==grille[ZERO][i-1] && grille[ZERO][i]==grille[ZERO][i+1] && grille[ZERO][i] != CASEVIDE )
		{
			if (initial[ZERO][i]!=CASEVIDE)
				{
					ModificationInterieur(initial,grille,ZERO,i,taille);
				}
				else
				{
				grille[ZERO][i]=CASEVIDE;
				}
		}
		}

	for (i=1; i < taille-1; ++i)
	{
		if (initial[taille-UN][i]==CASEVIDE)
		{
		if (grille[taille-UN][i]==grille[taille-UN][i-1] && grille[taille-UN][i]==grille[taille-UN][i+1] && grille[taille-UN][i] != CASEVIDE )
		{
			if (initial[taille-UN][i]!=CASEVIDE)
				{
					ModificationInterieur(initial,grille,taille-UN,i,taille);
				}
				else
				{
				grille[taille-UN][i]=CASEVIDE;
				}
		}
		}
	}

	for (i=1; i <taille-1; ++i)
	{

		if (grille[i][ZERO]==grille[i-1][ZERO] && grille[i+1][ZERO]==grille[i][ZERO] && grille[i][ZERO] != CASEVIDE )
		{
			if (initial[i][ZERO]!=CASEVIDE)
				{
					ModificationInterieur(initial,grille,i,ZERO,taille);
				}
				else
				{
				grille[i][ZERO]=CASEVIDE;
				}
		}
		}

	for (i=1; i <taille-1; ++i)
	{
		if (grille[i][taille-UN]==grille[i][taille-UN] && grille[i][taille-UN]==grille[i][taille-UN] && grille[i][taille-UN] != CASEVIDE )
		{
			if (initial[i][taille-UN]!=CASEVIDE)
				{
					ModificationInterieur(initial,grille,i,taille-UN,taille);
				}
				else
				{
				grille[i][taille-UN]=CASEVIDE;
				}
		}
	}
	return 0;
};


int MilieuHorizontale(char** initial,char** grille, int taille)
{
	int i,j;
	int changement=0;

	for (i = 0; i < taille; ++i)
	{
		for (j = 1; j <= taille-1 ; ++j)
		{
			if ((initial[i][j]==CASEVIDE) && (grille[i][j]==CASEVIDE))
			{
			if ((grille[i][j-1]==grille[i][j+1]) && grille[i][j+1]!=CASEVIDE )
			{
					grille[i][j]=(grille[i][j-1]+1)%POSSIBILITES;
					changement=1;

			}
			}
		}
	}
	return changement;
};


int RemplissageEquivalent(char** initial,char** grille, int taille)
{
	int i,j;
	int cpt=0;


	for (i = 0; i < taille; ++i)
	{
		for (j = 1; j <= taille-1 ; ++j)
		{
			if (grille[i][j]==ZERO)
			{
				cpt++;
			}
			else if (grille[i][j]==UN)
			{
				cpt--;
			}
		}
	}
	return 0;
};


int MilieuVerticale(char** initial,char** grille, int taille)
{
	int i,j;
	int changement=0;

	for (j = 0; j < taille; ++j)
	{
		for (i = 1; i < taille-1 ; ++i)
		{
			if ((initial[i][j]==CASEVIDE) && (grille[i][j]==CASEVIDE))
			{
			if ((grille[i-1][j]==grille[i+1][j]) && grille[i-1][j] != CASEVIDE)
			{
					grille[i][j]=(grille[i-1][j]+1)%POSSIBILITES;
					changement=1;
			}
			}
		}
	}
	return changement;
};


int RempliDuoHorizontale(char** initial,char** grille, int taille)
{
	int i,j;
	int changement=0;

	for (i = 0; i < taille; ++i)
	{
		for (j = 0; j < taille-1; ++j)
		{
			if ((grille[i][j]==grille[i][j+1]) && (grille[i][j]!=CASEVIDE))
			{
				if (j==0)
				{
					if (initial[i][j+2]==CASEVIDE)
					{
						grille[i][j+2]=(grille[i][j]+1)%POSSIBILITES;
						changement=1;
					}
				}
				else if (j==taille-2)
				{
					if (initial[i][j-1]==CASEVIDE)
					{

						grille[i][j-1]=(grille[i][j]+1)%POSSIBILITES;
						changement=1;

					}
				}
				else
				{
					if (initial[i][j-1]==CASEVIDE)
					{
						grille[i][j-1]=(grille[i][j]+1)%POSSIBILITES;
					}
					if (initial[i][j+2]==CASEVIDE)
					{
						grille[i][j+2]=(grille[i][j]+1)%POSSIBILITES;
					}
				}
			}
			}
			}
		return changement;
};


int RempliDuoVerticale(char**initial,char** grille, int taille)
{
	int i,j;
	int changement=0;

	for (i= 0; i < taille-1; ++i)
	{
		for (j = 0; j < taille; ++j)
		{
			if ((grille[i][j]==grille[i+1][j]) && (grille[i][j]!=CASEVIDE))
			{
				if (i==0)
				{
					if (initial[i+2][j]==CASEVIDE)
					{
						grille[i+2][j]=(grille[i][j]+1)%POSSIBILITES;
						changement=1;
					}
				}
				else if (i==taille-2)
				{
					if (initial[i-1][j]==CASEVIDE)
					{
					grille[i-1][j]=(grille[i][j]+1)%POSSIBILITES;
					changement=1;
					}
				}
				else
				{
					if (initial[i-1][j]==CASEVIDE)
					{
						grille[i-1][j]=(grille[i][j]+1)%POSSIBILITES;
					}
					if (initial[i+2][j]==CASEVIDE)
					{
						grille[i+2][j]=(grille[i][j]+1)%POSSIBILITES;
					}
				}
			}
		}
		}
		return changement;
};

int VerificationCaseModifiable(char** initial,int i,int j)
{
	return initial[i][j] == CASEVIDE;
}

int TriplonsExtremites(char** initial,char** grille,int taille)
{
	int i;

	for (i=1; i < taille-1; ++i)
	{
		if (grille[ZERO][i]==grille[ZERO][i-1] && grille[ZERO][i]==grille[ZERO][i+1] )
		{
			if (VerificationCaseModifiable(initial,ZERO,i))
					{
						grille[ZERO][i]=(grille[ZERO][i]+1)%POSSIBILITES;
					}
			else if (VerificationCaseModifiable(initial,ZERO,i-1))
			{
				grille[ZERO][i-1]=(grille[ZERO][i-1]+1)%POSSIBILITES;
			}
			else if (VerificationCaseModifiable(initial,ZERO,i+1))
			{
				grille[ZERO][i+1]=(grille[ZERO][i+1]+1)%POSSIBILITES;
			}
		}
	}

	for (i=1; i < taille-1; ++i)
	{
		if (grille[taille-UN][i]==grille[taille-UN][i-1] && grille[taille-UN][i]==grille[taille-UN][i+1])
		{
			if(VerificationCaseModifiable(initial,taille-UN,i))
					{
						grille[taille-UN][i]=(grille[i][taille-UN]+1)%POSSIBILITES;
					}
			else if (VerificationCaseModifiable(initial,taille-UN,i-1))
			{
				grille[taille-UN][i]=(grille[taille-UN][i-1]+1)%POSSIBILITES;
			}
			else if (VerificationCaseModifiable(initial,taille-UN,i+1))
			{
				grille[taille-UN][i]=(grille[taille-UN][i+1]+1)%POSSIBILITES;
			}
		}
	}

	for (i=taille-UN; i != 1; --i)
	{
		if (grille[i][taille-UN]==grille[i-1][taille-UN] && grille[i+1][taille-UN]==grille[i][taille-UN])
		{
			if(VerificationCaseModifiable(initial,i,taille-UN))
					{
						grille[i][taille-UN]=(grille[i][taille-UN]+1)%POSSIBILITES;
					}
			else if (VerificationCaseModifiable(initial,i-1,taille-UN))
			{
				grille[i-1][taille-UN]=(grille[i-1][taille-UN]+1)%POSSIBILITES;
			}
			else if (VerificationCaseModifiable(initial,i+1,taille-UN))
			{
				grille[i+1][taille-UN]=(grille[i+1][taille-UN]+1)%POSSIBILITES;
			}
		}
	}

	for (i=taille-UN; i !=1; --i)
	{
		if (grille[ZERO][i]==grille[ZERO][i-1] && grille[ZERO][i]==grille[ZERO][i+1])
		{
			if(VerificationCaseModifiable(initial,ZERO,i))
					{
						grille[ZERO][i]=(grille[ZERO][i]+1)%POSSIBILITES;
					}
			else if (VerificationCaseModifiable(initial,ZERO,i-1))
			{
				grille[ZERO][i-1]=(grille[ZERO][i-1]+1)%POSSIBILITES;
			}
			else if (VerificationCaseModifiable(initial,ZERO,i+1))
			{
				grille[ZERO][i+1]=(grille[ZERO][i+1]+1)%POSSIBILITES;
			}
		}
	}
};

void affichegrille(char** grille, int taille)
{
	int i;
	int j;
	for (i = 0; i < taille; ++i)
	{
		printf(" __");
	}
	NL;
	for (i = 0; i < taille; ++i)
	{
		for (j = 0; j < taille; ++j)
		{
			if (grille[i][j]==CASEVIDE)
			{
				printf("|__");
			}
			else{
				printf("|_%d", grille[i][j]);
			}
		}
		printf("|");
		NL;
	}
	NL;NL;
};

char** CopieTableau(char**src, int taille)
{
	int i,j;
	char** dest;

	dest=(char**)malloc(sizeof(int*)*taille);

	for (i=0; i < taille; ++i)
	{
		dest[i]=(char*)malloc(sizeof(char)*taille);
	}

	for (i=0;i<taille;++i)
	{
		for (j=0;j<taille;++j)
		{
			dest[i][j]=src[i][j];
		}
	}
	return dest;
};


void Conformite(char** initial,char** grille,int taille)
{
	int i,j;
	for (i=0;i<taille; ++i)
	{
		for (j=0; j<taille; ++j)
		{
			if (initial[i][j] != CASEVIDE)
			{
				grille[i][j]=initial[i][j];
			}
		}
	}
};

void EradiquerLesTrios(char**initial,char** grille, int n)
{
	int i,j;

	for (i = 1; i < n-1; ++i)
	{
		for (j = 1; j < n-1; ++j)
		{
			if (((grille[i+1][j]==grille[i-1][j]) || (grille[i][j-1]==grille[i][j+1]) ) == ZERO)
			{
				if(VerificationCaseModifiable(initial,i,j))
				{
					grille[i][j]=UN;
				}

			}
			else if (((grille[i+1][j]==grille[i-1][j]) || (grille[i][j-1]==grille[i][j+1]) ) == UN)
			{
				if(VerificationCaseModifiable(initial,i,j))
				{
					grille[i][j]=ZERO;
				}
			}
			}
		}
};


int TriplonsCoordonnes(char** initial,char** grille, int taille)
{
	int i,j;

	for(i=1;i<taille-1;i++)
	{
		for(j=1;j<taille-1;j++)
		{
			if (initial[i][j]==CASEVIDE)
			{
			if ((grille[i+1][j] == grille[i-1][j]) && (grille[i][j]==grille[i-1][j]))
			{
				if(VerificationCaseModifiable(initial,i,j));
					{
						grille[i][j]=((grille[i][j]+1)%POSSIBILITES);
					}
			}
			 if((grille[i][j+1]==grille[i][j-1]) && (grille[i][j-1]==grille[i][j]))
			{
				if(VerificationCaseModifiable(initial,i,j));
					{
						grille[i][j]=((grille[i][j]+1)%POSSIBILITES);
					}
			}
			}
		}
	}

	for (i=1; i < taille-1; ++i)
	{
		if (grille[ZERO][i]==grille[ZERO][i-1] && grille[ZERO][i]==grille[ZERO][i+1] && grille[ZERO][i] != CASEVIDE )
		{
		printf("(%d,%d)\n",ZERO,i);
		}
	}

	for (i=1; i < taille-1; ++i)
	{
		if (grille[taille-UN][i]==grille[taille-UN][i-1] && grille[taille-UN][i]==grille[taille-UN][i+1] && grille[taille-UN][i] != CASEVIDE )
		{
		printf("(%d,%d)\n",taille-UN,i);
		}
	}

	for (i=taille-2; i != 1; --i)
	{
		if (grille[i][taille-UN]==grille[i-1][taille-UN] && grille[i+1][taille-UN]==grille[i][taille-UN] && grille[i][taille-UN] != CASEVIDE )
		{
			printf("(%d,%d)\n",i,taille-UN);
		}
	}

	for (i=taille-2; i !=1; --i)
	{
		if (grille[ZERO][i]==grille[ZERO][i-1] && grille[ZERO][i]==grille[ZERO][i+1] && grille[ZERO][i] != CASEVIDE )
		{
			printf("(%d,%d)\n",ZERO,i);
		}
	}
};

int RechercheCaseVide(char** grille,int taille)
{
	int i,j;

	for (i=0;i<taille; ++i)
	{
		for (j=0; j < taille; ++j)
		{
				if (grille[i][j]==CASEVIDE)
					{
						printf("(%d,%d)\n",i,j);
					}
		}
	}
	return 0;
};

void Temps(SDL_Surface* ecran)
{
    SDL_Surface* texte;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    int continuer = 1;
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0;
    char temps[200] = "";

    police = TTF_OpenFont("angelina.ttf", 65);
    tempsActuel = SDL_GetTicks();
    sprintf(temps, "Temps : %d", compteur);
     texte = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche);

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent >= 0)
        {
            compteur += 100;
            sprintf(temps, "Temps : %d", compteur);
            SDL_FreeSurface(texte);
            texte = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche); /* On écrit la chaîne temps dans la SDL_Surface */
            tempsPrecedent = tempsActuel;
        }
        position.x = 180;
        position.y = 210;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_Flip(ecran);
}



int EquilibreChiffre(char** grille, int taille)
{
	int i,j;

	for (i=0;i<taille; ++i)
	{
		for (j = 0; j<taille; ++j)
		{
			if(grille[i][j]==CASEVIDE)
				{
					grille[i][j]=Compteur(grille,taille,i);
				}
		}
	}
};
