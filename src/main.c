#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "../include/constantes.h"
#include "main_sdl.c"
#include "help_binero.c"
#include "resolve.c"
#include "play_sdl.c"
#include "level_sdl.c"
#include "icone_sdl.c"
#include "info_sdl.c"


int main(int argc, char *argv[])
{
  
    printf("0\n",stdout);
    SDL_Surface* fenetre=init();
    printf("1\n",stdout);
    menu(fenetre);
    printf("2",stdout);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}
