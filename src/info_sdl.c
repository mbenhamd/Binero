#include "../include/info_sdl.h"

void info_setup(SDL_Surface* ecran)
{
    fond_info(ecran);
    SDL_Flip(ecran);
    pause_SDL(ecran);
}




