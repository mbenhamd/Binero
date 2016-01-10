#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "constantes.h"
#ifndef H_RESOLVE
#define H_RESOLVE 0

void L_Choix_EVOLUE(SDL_Surface* ecran);
void XL_Choix_EVOLUE(SDL_Surface* ecran);
void XXL_Choix_EVOLUE(SDL_Surface* ecran);
void Resolve_all(char**initial, char** grille, int taille);

#endif
