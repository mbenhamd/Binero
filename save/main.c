#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <time.h>



int main(int argc, char const *argv[])
{
int i,j;
int** grille;
int taille=10;
char * nom_fichier="grille_1";
int variable;

    grille=(int**)malloc(taille*sizeof(int*));

    for (i=0;i<taille;++i)
    {
        grille[i]=(int*)malloc(sizeof(int)*taille);
    }
	
FILE* fichier=fopen(nom_fichier,"r");
 rewind(fichier);
        for (i = 0; i < 10; ++i)
            {
                for (j = 0; j < 10; ++j)
                    {
                        fscanf(fichier,"%d",&variable);
                        grille[i][j]=variable;
                        printf("%d",grille[i][j]);
                    }
                    printf("\n");
            }

fclose(fichier);
	
	return 0;
}





