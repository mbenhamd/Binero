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
    // TODO: A
    SDL_Surface* fenetre=init();
    menu(fenetre);
    TTF_Quit();
    SDL_Quit();
    return EXIT_SUCCESS;
}
