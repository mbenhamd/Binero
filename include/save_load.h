#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <constantes.h>

#ifndef H_SAVE_LOAD
#define H_SAVE_LOAD 0

char** initialisergrille_XXL();
char** initialisergrille_XL();
char** initialisergrille_L();
void cleargrille_L(char **grille);
void cleargrille_XL(char **grille);
void cleargrille_XXL(char **grille);
void Load_Game_L(char **carre,SDL_Surface* ecran,SDL_Surface* grille_L[][L],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE);
void Load_Game_XL(char **carre,SDL_Surface* ecran,SDL_Surface* grille_XL[][XL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE);
void Load_Game_XXL(char **carre,SDL_Surface* ecran,SDL_Surface* grille_XXL[][XXL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE);
void Save_NewGame_L(char **grille);
void Save_NewGame_XL(char **grille);
void Save_NewGame_XXL(char **grille);
void Affichegrille_L(char **carre,SDL_Surface* ecran,SDL_Surface* grille_L[][L],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE);
void Affichegrille_XL(char **carre,SDL_Surface* ecran,SDL_Surface* grille_XL[][XL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE);
void Affichegrille_XXL(char **carre,SDL_Surface* ecran,SDL_Surface* grille_XXL[][XXL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE);
void Affichegrille_XXL_Empty(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][XXL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE);
void Affichegrille_XL_Empty(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][XL],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE);
void Affichegrille_L_Empty(char **carre,SDL_Surface* ecran,SDL_Surface* grille[][L],SDL_Surface* Block_ZERO,SDL_Surface* Block_UN,SDL_Surface* Block_CASEVIDE);



#endif
