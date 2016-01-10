#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

#ifndef H_LEVEL_SDL
#define H_LEVEL_SDL

void level_setup(SDL_Surface* ecran);
void configuration(SDL_Surface* ecran);
void pauseConfiguration(SDL_Surface* ecran);
void L_Choix(SDL_Surface* ecran);
void XL_Choix(SDL_Surface* ecran);
void XXL_Choix(SDL_Surface* ecran);
void icone_exit_level(SDL_Surface* ecran);
void icone_menu_level(SDL_Surface* ecran);


#endif
