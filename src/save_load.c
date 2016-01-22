#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/save_load.h"


void Affichegrille_L(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][L],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE)
{
int i,j;
SDL_Rect position;
position.x=CENTRAGE_JEU_L_X;
position.y=CENTRAGE_JEU_L_Y;

for (i=0;i<L;i++)
    {
        for (j=0;j<L;j++)
        {

            if (carre[i][j]==UN)
            {
                grille[i][j]=Block_UN;
                SDL_BlitSurface(grille[i][j], NULL,ecran,&position);
                position.x+=BLOC;
            }
            else if (carre[i][j]==ZERO)
            {
                grille[i][j]=Block_ZERO;
                SDL_BlitSurface(grille[i][j], NULL,ecran,&position);
                position.x+=BLOC;
            }
            else if (carre[i][j]==CASEVIDE)
            {
                grille[i][j]=Block_CASEVIDE;
                SDL_BlitSurface(grille[i][j], NULL,ecran,&position);
                position.x+=BLOC;

            }
        }
        position.x=CENTRAGE_JEU_L_X;
        position.y+=BLOC;
    }
SDL_Flip(ecran);
}

void Affichegrille_L_Empty(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][L],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE)
{
int i,j;
SDL_Rect position;
position.x=CENTRAGE_JEU_L_X;
position.y=CENTRAGE_JEU_L_Y;

for (i=0;i<L;i++)
    {
        for (j=0;j<L;j++)
        {
                carre[i][j]=CASEVIDE;
                grille[i][j]=Block_CASEVIDE;
                SDL_BlitSurface(Block_CASEVIDE, NULL,ecran,&position);
                position.x+=BLOC;

        }
        position.x=CENTRAGE_JEU_L_X;
        position.y+=BLOC;
    }
SDL_Flip(ecran);
}

void Affichegrille_XL_Empty(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][XL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE)
{
int i,j;
SDL_Rect position;
position.x=CENTRAGE_JEU_XL_X;
position.y=CENTRAGE_JEU_XL_Y;

for (i=0;i<XL;i++)
    {
        for (j=0;j<XL;j++)
        {
                carre[i][j]=CASEVIDE;
                grille[i][j]=Block_CASEVIDE;
                SDL_BlitSurface(Block_CASEVIDE, NULL,ecran,&position);
                position.x+=BLOC;

        }
        position.x=CENTRAGE_JEU_XL_X;
        position.y+=BLOC;
    }
SDL_Flip(ecran);
}

void Affichegrille_XXL_Empty(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][XXL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE)
{
int i,j;
SDL_Rect position;
position.x=CENTRAGE_JEU_XXL_X;
position.y=CENTRAGE_JEU_XXL_Y;

for (i=0;i<XXL;i++)
    {
        for (j=0;j<XXL;j++)
        {
                carre[i][j]=CASEVIDE;
                grille[i][j]=Block_CASEVIDE;
                SDL_BlitSurface(Block_CASEVIDE, NULL,ecran,&position);
                position.x+=BLOC;

        }
        position.x=CENTRAGE_JEU_XXL_X;
        position.y+=BLOC;
    }
SDL_Flip(ecran);
}


void Affichegrille_XL(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][XL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE)
{
int i,j;
SDL_Rect position;
position.x=CENTRAGE_JEU_XL_X;
position.y=CENTRAGE_JEU_XL_Y;

for (i=0;i<XL;i++)
    {
        for (j=0;j<XL;j++)
        {

            if (carre[i][j]==UN)
            {
                grille[i][j]=Block_UN;
                SDL_BlitSurface(grille[i][j], NULL,ecran,&position);
                position.x+=BLOC;
            }
            else if (carre[i][j]==ZERO)
            {
                grille[i][j]=Block_ZERO;
                SDL_BlitSurface(grille[i][j], NULL,ecran,&position);
                position.x+=BLOC;
            }
            else if (carre[i][j]==CASEVIDE)
            {
                grille[i][j]=Block_CASEVIDE;
                SDL_BlitSurface(grille[i][j], NULL,ecran,&position);
                position.x+=BLOC;

            }
        }
        position.x=CENTRAGE_JEU_XL_X;
        position.y+=BLOC;
    }
SDL_Flip(ecran);
}


void Affichegrille_XXL(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][XXL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE)
{
int i,j;
SDL_Rect position;
position.x=CENTRAGE_JEU_XXL_X;
position.y=CENTRAGE_JEU_XXL_Y;

for (i=0;i<XXL;i++)
    {
        for (j=0;j<XXL;j++)
        {

            if (carre[i][j]==UN)
            {
                grille[i][j]=Block_UN;
                SDL_BlitSurface(grille[i][j], NULL,ecran,&position);
                position.x+=BLOC;
            }
            else if (carre[i][j]==ZERO)
            {
                grille[i][j]=Block_ZERO;
                SDL_BlitSurface(grille[i][j], NULL,ecran,&position);
                position.x+=BLOC;
            }
            else if (carre[i][j]==CASEVIDE)
            {
                grille[i][j]=Block_CASEVIDE;
                SDL_BlitSurface(grille[i][j], NULL,ecran,&position);
                position.x+=BLOC;

            }
        }
        position.x=CENTRAGE_JEU_XXL_X;
        position.y+=BLOC;
    }
SDL_Flip(ecran);
}

void Save_NewGame_L(char **grille)
{
FILE* fichier;
int a,b;

int i=0;
char nom_fichier[100];

sprintf(nom_fichier,"save/grille_%d_L",i);

while(access(nom_fichier,F_OK)!=-1)
{
	i++;
	sprintf(nom_fichier,"save/grille_%d_L",i);
}

fichier=fopen(nom_fichier,"w+");
rewind(fichier);

for (a =0; a < L; ++a)
{
	for (b =0; b <L ; ++b)
	{
		fprintf(fichier,"%c",grille[a][b]);
	}
}
fclose(fichier);
}
void Save_NewGame_XL(char **grille)
{
FILE* fichier;
int a,b;

int i=0;
char nom_fichier[100];

sprintf(nom_fichier,"save/grille_%d_XL",i);

while(access(nom_fichier,F_OK)!=-1)
{
    i++;
    sprintf(nom_fichier,"save/grille_%d_XL",i);
}

fichier=fopen(nom_fichier,"w+");
rewind(fichier);

for (a =0; a < XL; ++a)
{
    for (b =0; b <XL ; ++b)
    {
        fprintf(fichier,"%c",grille[a][b]);
    }
}
fclose(fichier);
}

void Save_NewGame_XXL(char **grille)
{
FILE* fichier;
int a,b;

int i=0;
char nom_fichier[100];

sprintf(nom_fichier,"save/grille_%d_XXL",i);

while(access(nom_fichier,F_OK)!=-1)
{
    i++;
    sprintf(nom_fichier,"save/grille_%d_XXL",i);
}

fichier=fopen(nom_fichier,"w+");
rewind(fichier);

for (a =0; a < XXL; ++a)
{
    for (b =0; b <XXL ; ++b)
    {
        fprintf(fichier,"%c",grille[a][b]);
    }
}
fclose(fichier);
}

void Load_Game_L(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][L],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE)
{
int i,j;
char nom_fichier[100];

FILE* fichier;

i=1;

sprintf(nom_fichier,"save/grille_%d_L",i);

while(access(nom_fichier,F_OK)!=-1)
{
    i++;
    sprintf(nom_fichier,"save/grille_%d_L",i);
}

j=rand()%i;

sprintf(nom_fichier,"save/grille_%d_L",j);

fichier=fopen(nom_fichier,"r");
rewind(fichier);
for (i=0;i<L;i++)
    {
        for (j=0;j<L;j++)
        {
            carre[i][j]=fgetc(fichier);
        }
    }
fclose(fichier);

}
void Load_Game_XL(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][XL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE)
{
int i,j;
char nom_fichier[100];

FILE* fichier;

i=1;

sprintf(nom_fichier,"save/grille_%d_XL",i);

while(access(nom_fichier,F_OK)!=-1)
{
    i++;
    sprintf(nom_fichier,"save/grille_%d_XL",i);
}

j=rand()%i;

sprintf(nom_fichier,"save/grille_%d_XL",j);

fichier=fopen(nom_fichier,"r");
rewind(fichier);
for (i=0;i<XL;i++)
    {
        for (j=0;j<XL;j++)
        {
            carre[i][j]=fgetc(fichier);
        }
    }
fclose(fichier);
}


void Load_Game_XXL(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][XXL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE)
{
int i,j;
char nom_fichier[100];

FILE* fichier;

i=1;

sprintf(nom_fichier,"save/grille_%d_XXL",i);

while(access(nom_fichier,F_OK)!=-1)
{
    i++;
    sprintf(nom_fichier,"save/grille_%d_XXL",i);
}

j=rand()%i;

sprintf(nom_fichier,"save/grille_%d_XXL",j);

fichier=fopen(nom_fichier,"r");
rewind(fichier);
for (i=0;i<XXL;i++)
    {
        for (j=0;j<XXL;j++)
        {
            carre[i][j]=fgetc(fichier);
        }
    }
fclose(fichier);
}



void cleargrille_L(char **grille)
{
    int i,j;
    for (i = 0; i < L; ++i)
    {
        for (j = 0; j < L; ++j)
        {
            grille[i][j]=CASEVIDE;
        }
    }
}

void cleargrille_XL(char **grille)
{
    int i,j;
    for (i = 0; i < XL; ++i)
    {
        for (j = 0; j < XL; ++j)
        {
            grille[i][j]=CASEVIDE;
        }
    }
}


void cleargrille_XXL(char **grille)
{
    int i,j;
    for (i = 0; i < XXL; ++i)
    {
        for (j = 0; j < XXL; ++j)
        {
            grille[i][j]=CASEVIDE;
        }
    }
}


char** initialisergrille_L()
{
    int i;
    char** grille;
    grille=(char**)malloc(sizeof(char*)*L);

    for (i = 0; i < L; ++i)
    {
        grille[i]=(char*)malloc(sizeof(char)*L);
    }

    return grille;
};

char** initialisergrille_XL()
{
    int i;
    char **grille;
    grille=(char**)malloc(sizeof(char*)*XL);

    for (i = 0; i < XL; ++i)
    {
        grille[i]=(char*)malloc(sizeof(char)*XL);
    }

    return grille;
};

char** initialisergrille_XXL()
{
    int i;
    char **grille;
    grille=(char**)malloc(sizeof(char*)*XXL);

    for (i = 0; i < XXL; ++i)
    {
        grille[i]=(char*)malloc(sizeof(char)*XXL);
    }

    return grille;

};
