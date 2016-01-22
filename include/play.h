#ifndef H_PLAY
#define H_PLAY 0


int VerificationCaseModifiable(char** initial,int i,int j);
void EradiquerLesTrios(char**initial,char**grille, int n);
void Conformite(char**initial,char**grille,int taille);
char** CopieTableau(char**src, int taille);
void affichegrille(char** grille, int taille);
int RempliDuoVerticale(char**initial,char**grille, int taille);
int RempliDuoHorizontale(char** initial,char**grille, int taille);
int MilieuVerticale(char** initial,char**grille, int taille);
int RemplissageEquivalent(char** initial,char**grille, int taille);
int MilieuHorizontale(char** initial,char**grille, int taille);
int RemplacementTrioParCaseVide(char** initial, char** grille, int taille);
int ModificationInterieur(char** initial, char** grille, int i,int j,int taille);
void AuHasard(char** grille, int taille);
void liregrille(char**grille, int taille);
char** initialisergrille(int taille);
int ModificationCoupsImpossible(char**initial, char**grille, int taille);
int Compteur(char**grille, int taille, int ligne);
int EquilibreChiffre(char** grille, int taille);
void cleargrille(char** initial, char**grille, int taille);
int RemplacementTrioParCaseAutreCase(char** initial, char** grille, int taille);
void AfficheColonneNonEquilibre(char**grille,int taille);
void AfficheLigneNonEquilibre(char**grille,int taille);
int RechercheAutrePossibiliteDeCoups(char** initial, char** grille, int taille);
void RechercheLigneUneSeuleCaseVide(char**grille, int taille);
void RechercheColonneUneSeuleCaseVide(char**grille, int taille);
void CompleterLigne(char**grille, int taille, int ligne, Coordonnees changer);
void CompleterColonne(char**grille, int taille, int colonne, Coordonnees changer);
int RechercheCaseVide(char**grille,int taille);
void Temps(SDL_Surface* ecran);



#endif


