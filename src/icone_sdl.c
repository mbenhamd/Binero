#include <SDL/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "../include/icone_sdl.h"
#include "../include/constantes.h"



void fond_main(SDL_Surface* ecran)
{
    SDL_Surface *imageDeFond;
    SDL_Rect positionFond;
    SDL_Rect positionText;
    positionFond.x = 0;
    positionFond.y = 0;
    positionText.x=CENTRAGE_ECRAN_X-40;
    positionText.y=CENTRAGE_ECRAN_Y*3-50;
    imageDeFond=SDL_LoadBMP("image/menu.bmp");
    SDL_BlitSurface(imageDeFond, NULL,ecran, &positionFond);
    TTF_Font *police=TTF_OpenFont("font/font.ttf",100);
    SDL_Color couleurNoire= {0,0,0};
    SDL_Surface* text=TTF_RenderText_Blended(police,"Welcome to the Binero Game !",couleurNoire);
    SDL_BlitSurface(text,NULL,ecran,&positionText);
    icone_menu(ecran);
    icone_play(ecran);
    icone_info(ecran);
    icone_musique(ecran);
    icone_exit(ecran);
}

void fond_level(SDL_Surface* ecran)
{
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDL_Surface *imageDeFond;
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    imageDeFond=SDL_LoadBMP("image/menu.bmp");
    SDL_BlitSurface(imageDeFond, NULL,ecran, &positionFond);
    icone_musique(ecran);
    icone_previous(ecran);
    icone_menu_level(ecran);
    icone_exit_level(ecran);
    icone_load_save(ecran);
    SDL_Flip(ecran);
}


void icone_menu_level(SDL_Surface* ecran)
{
    SDL_Surface *icone_home;
    SDL_Rect positionFond;
    positionFond.x = ICONE_HOME_X;
    positionFond.y = ICONE_HOME_Y;
    icone_home=SDL_LoadBMP("image/menu/home/home.bmp");
    SDL_SetColorKey(icone_home,SDL_SRCCOLORKEY,SDL_MapRGB(icone_home->format,0,0,0));
    SDL_SetAlpha(icone_home,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_home,NULL,ecran,&positionFond);

}


void icone_exit_level(SDL_Surface* ecran)
{
    SDL_Surface *icone_exit;
    SDL_Rect positionFond;
    positionFond.x = ICONE_EXIT_X;
    positionFond.y = ICONE_EXIT_Y;
    icone_exit=SDL_LoadBMP("image/menu/home/exit.bmp");
    SDL_SetColorKey(icone_exit,SDL_SRCCOLORKEY,SDL_MapRGB(icone_exit->format,0,0,0));
    SDL_SetAlpha(icone_exit,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_exit,NULL,ecran,&positionFond);
}

void icone_previous(SDL_Surface* ecran)
{
    SDL_Surface *icone_exit;
    SDL_Rect positionFond;
    positionFond.x = CENTRAGE_LOGO_X_PREVIOUS;
    positionFond.y = CENTRAGE_LOGO_Y_PREVIOUS;
    icone_exit=SDL_LoadBMP("image/previous.bmp");
    SDL_SetColorKey(icone_exit,SDL_SRCCOLORKEY,SDL_MapRGB(icone_exit->format,0,0,0));
    SDL_SetAlpha(icone_exit,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_exit,NULL,ecran,&positionFond);
}

void icone_load_save(SDL_Surface* ecran)
{
    SDL_Surface* Save;
    SDL_Surface* Load;
    SDL_Rect icone_save;
    SDL_Rect icone_load;
    icone_save.x=ICONE_SAVE_X;
    icone_save.y=ICONE_SAVE_Y;
    icone_load.x=ICONE_LOAD_X;
    icone_load.y=ICONE_LOAD_Y;
    Load=SDL_LoadBMP("image/menu/games/in_game/reload_grille.bmp");
    Save=SDL_LoadBMP("image/menu/games/in_game/save_in_game.bmp");
    SDL_SetColorKey(Save,SDL_SRCCOLORKEY,SDL_MapRGB(Save->format,0,0,0));
    SDL_SetColorKey(Load,SDL_SRCCOLORKEY,SDL_MapRGB(Load->format,0,0,0));
    SDL_BlitSurface(Load,NULL,ecran,&icone_load);
    SDL_BlitSurface(Save,NULL,ecran,&icone_save);

}

void icone_menu(SDL_Surface* ecran)
{
    SDL_Surface *icone_home;
    SDL_Rect positionFond;
    positionFond.x = CENTRAGE_LOGO_X;
    positionFond.y = CENTRAGE_LOGO_Y;
    icone_home=SDL_LoadBMP("image/menu/home/home.bmp");
    SDL_SetColorKey(icone_home,SDL_SRCCOLORKEY,SDL_MapRGB(icone_home->format,0,0,0));
    SDL_SetAlpha(icone_home,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_home,NULL,ecran,&positionFond);

}


void icone_play(SDL_Surface* ecran)
{
    SDL_Surface *icone_play;
    SDL_Rect positionFond;
    positionFond.x = CENTRAGE_LOGO_X+ECART_ICONE;
    positionFond.y = CENTRAGE_LOGO_Y;
    icone_play=SDL_LoadBMP("image/menu/home/play.bmp");
    SDL_SetColorKey(icone_play,SDL_SRCCOLORKEY,SDL_MapRGB(icone_play->format,0,0,0));
    SDL_SetAlpha(icone_play,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_play,NULL,ecran,&positionFond);

}

void icone_info(SDL_Surface* ecran)
{
    SDL_Surface *icone_info;
    SDL_Rect positionFond;
    positionFond.x = CENTRAGE_LOGO_X+ECART_ICONE*5;
    positionFond.y = CENTRAGE_LOGO_Y;
    icone_info=SDL_LoadBMP("image/menu/home/info.bmp");
    SDL_SetColorKey(icone_info,SDL_SRCCOLORKEY,SDL_MapRGB(icone_info->format,0,0,0));
    SDL_SetAlpha(icone_info,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_info,NULL,ecran,&positionFond);
}

void icone_load(SDL_Surface* ecran)
{
    SDL_Surface *icone_load;
    SDL_Rect positionFond;
    positionFond.x = CENTRAGE_LOGO_X+ECART_ICONE*2;
    positionFond.y = CENTRAGE_LOGO_Y;
    icone_load=SDL_LoadBMP("image/menu/home/load.bmp");
    SDL_SetColorKey(icone_load,SDL_SRCCOLORKEY,SDL_MapRGB(icone_load->format,0,0,0));
    SDL_SetAlpha(icone_load,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_load,NULL,ecran,&positionFond);
}

void icone_parametres(SDL_Surface* ecran)
{
    SDL_Surface *icone_parametres;
    SDL_Rect positionFond;
    positionFond.x = CENTRAGE_LOGO_X+ECART_ICONE*3;
    positionFond.y = CENTRAGE_LOGO_Y;
    icone_parametres=SDL_LoadBMP("image/menu/home/parametres.bmp");
    SDL_SetColorKey(icone_parametres,SDL_SRCCOLORKEY,SDL_MapRGB(icone_parametres->format,0,0,0));
    SDL_SetAlpha(icone_parametres,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_parametres,NULL,ecran,&positionFond);
}

void icone_score(SDL_Surface* ecran)
{
    SDL_Surface *icone_score;
    SDL_Rect positionFond;
    positionFond.x = CENTRAGE_LOGO_X+ECART_ICONE*4;
    positionFond.y = CENTRAGE_LOGO_Y;
    icone_score=SDL_LoadBMP("image/menu/home/score.bmp");
    SDL_SetColorKey(icone_score,SDL_SRCCOLORKEY,SDL_MapRGB(icone_score->format,0,0,0));
    SDL_SetAlpha(icone_score,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_score,NULL,ecran,&positionFond);
}

void icone_exit(SDL_Surface* ecran)
{
    SDL_Surface *icone_exit;
    SDL_Rect positionFond;
    positionFond.x = CENTRAGE_LOGO_X+ECART_ICONE*6;
    positionFond.y = CENTRAGE_LOGO_Y;
    icone_exit=SDL_LoadBMP("image/menu/home/exit.bmp");
    SDL_SetColorKey(icone_exit,SDL_SRCCOLORKEY,SDL_MapRGB(icone_exit->format,0,0,0));
    SDL_SetAlpha(icone_exit,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_exit,NULL,ecran,&positionFond);
}

void icone_musique(SDL_Surface* ecran)
{
    SDL_Surface *icone_musique;
    SDL_Rect positionFond;

    positionFond.x = CENTRAGE_LOGO_X_MUSIQUE;
    positionFond.y = CENTRAGE_LOGO_Y_MUSIQUE;
    icone_musique=SDL_LoadBMP("image/menu/options/no_sound.bmp");
    SDL_SetColorKey(icone_musique,SDL_SRCCOLORKEY,SDL_MapRGB(icone_musique->format,0,0,0));
    SDL_SetAlpha(icone_musique,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_musique,NULL,ecran,&positionFond);

}


void icone_musique_control(SDL_Surface* ecran,int continuer_musique)
{
    SDL_Surface *icone_musique;
    SDL_Rect positionFond;

    positionFond.x = CENTRAGE_LOGO_X_MUSIQUE;
    positionFond.y = CENTRAGE_LOGO_Y_MUSIQUE;

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_Music *musique;
    musique = Mix_LoadMUS("sound/music_one.mp3");

    if(continuer_musique==0)
    {
    Mix_HaltMusic();
    icone_musique=SDL_LoadBMP("image/menu/options/no_sound.bmp");
    SDL_SetColorKey(icone_musique,SDL_SRCCOLORKEY,SDL_MapRGB(icone_musique->format,0,0,0));
    SDL_SetAlpha(icone_musique,SDL_SRCALPHA,190);
    SDL_BlitSurface(icone_musique,NULL,ecran,&positionFond);
    SDL_UpdateRect(ecran,0,0,0,0);

    }
    else
    {
        Mix_PlayMusic(musique, -1);
        icone_musique=SDL_LoadBMP("image/menu/options/sound.bmp");
        SDL_SetColorKey(icone_musique,SDL_SRCCOLORKEY,SDL_MapRGB(icone_musique->format,0,0,0));
        SDL_SetAlpha(icone_musique,SDL_SRCALPHA,190);
        SDL_BlitSurface(icone_musique,NULL,ecran,&positionFond);
        SDL_UpdateRect(ecran,0,0,0,0);

    }
}

void fond_info(SDL_Surface* ecran)
{
    SDL_Surface *imageDeFond;
    SDL_Rect positionFond;
    positionFond.x=0;
    positionFond.y=0;
    imageDeFond=SDL_LoadBMP("image/info.bmp");
    SDL_BlitSurface(imageDeFond, NULL,ecran, &positionFond);
    icone_menu(ecran);
    icone_exit(ecran);
    icone_musique(ecran);
}
