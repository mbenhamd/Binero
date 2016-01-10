#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/constantes.h"
#include "../include/play_sdl.h"


void Print_Grille(SDL_Surface* ecran)
{
	SDL_Surface* grille[L][L];
	int i,j;
	SDL_Rect position;

	SDL_Surface* Block_ZERO;
	SDL_Surface* Block_UN;
	SDL_Surface* Block_CASEVIDE;

	Block_ZERO=SDL_LoadBMP("image/menu/games/grille/blue/block_blue_32_0.bmp");
	Block_UN=SDL_LoadBMP("image/menu/games/grille/blue/block_blue_32_1.bmp");
    Block_CASEVIDE=SDL_LoadBMP("image/menu/games/grille/blanck/block_white_32.bmp");

//    SDL_SetColorKey(Block_UN,SDL_SRCCOLORKEY,SDL_MapRGB(Block_UN->format,0,0,0));
  //  SDL_SetColorKey(Block_ZERO,SDL_SRCCOLORKEY,SDL_MapRGB(Block_ZERO->format,0,0,0));
    //SDL_SetColorKey(Block_CASEVIDE,SDL_SRCCOLORKEY,SDL_MapRGB(Block_CASEVIDE->format,0,0,0));

    position.x=DEPART_BLOC_X;
    position.y=DEPART_BLOC_Y;

    for (i=0;i<L;i++)
    {
        for (j=0;j<L;j++)
        {
            	grille[i][j]=Block_UN;
            	position.x+=BLOC;
            	SDL_BlitSurface(grille[i][j], NULL, ecran, &position);
        }
        position.x=DEPART_BLOC_X;
        position.y+=BLOC;
    }
    SDL_Flip(ecran);
}

void menu_sans_icone(SDL_Surface* ecran)
{
    SDL_Surface *imageDeFond;
    SDL_Rect positionFond;
    SDL_Rect positionText;
    positionFond.x=0;
    positionFond.y=0;
    positionText.x=0;
    positionText.y=0;
    imageDeFond=SDL_LoadBMP("image/menu.bmp");
    SDL_BlitSurface(imageDeFond, NULL,ecran, &positionFond);
    TTF_Font *police=TTF_OpenFont("font/font.ttf",100);
    SDL_Color couleurNoire= {0,0,0};
    SDL_Surface* text=TTF_RenderText_Blended(police,"Play ! : ",couleurNoire);
    SDL_BlitSurface(text,NULL,ecran,&positionText);
    Print_Grille(ecran);
    icone_menu(ecran);
    icone_play(ecran);
    icone_load(ecran);
    icone_parametres(ecran);
    icone_score(ecran);
    icone_info(ecran);
    icone_exit(ecran);
    SDL_Flip(ecran);
}
