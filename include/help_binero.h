#include <data_structure.h>
#ifndef H_HELP_BINERO
#define H_HELP_BINERO 0

int TriplonsCoordonnesAffichage(char** grille, int n);
int DeuxColonnesIdentiques(char** grille,int colonne, int taille);
int DeuxLignesIdentiques(char** grille,int lignes, int taille);
void Remplacer(char** grille,int ordonnee, int abscisse,int valeur);
int TestLignesPleine(char** grille,int ordonnee, int taille);
int TestColonnePleine(char** grille,int abscisse, int taille);
int GrilleNonVide(char** grille, int taille);
int GrilleAvecIdentiqueLigneColonne(char** grille, int taille);
int CaseImpossible(char** grille, int taille);
//void Message_Erreur(SDL_Surface* ecran);
int GrilleVide(char** grille, int taille);

#endif
