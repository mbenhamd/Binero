#include "../include/main_sdl.h"
#include "../include/play_sdl.h"
#include "../include/level_sdl.h"
#include "../include/icone_sdl.h"
#include "../include/info_sdl.h"
#include "../include/constantes.h"



SDL_Surface* init()
{
    printf("init0\n",stdout);
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    printf("init1\n",stdout);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    printf("init2\n",stdout);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16);
    printf("init3\n",stdout);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    printf("init4\n",stdout);
    SDL_Surface* ecran = SDL_SetVideoMode(HAUTEUR, LARGEUR, BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
    printf("init5\n",stdout);
    SDL_WM_SetCaption("Binero Game",NULL);
    printf("init6\n",stdout);
    return ecran;
}

void menu(SDL_Surface* ecran)
{
    printf("menu0\n",stdout);
    TTF_Init();
    printf("menu1\n",stdout);
    fond_main(ecran);
    printf("menu2\n",stdout);
    SDL_Flip(ecran);
    printf("menu3\n",stdout);
    pause_SDL(ecran);
    printf("menu4\n",stdout);
}

void pause_SDL(SDL_Surface* ecran)
{
    int continuer_fenetre = 1;
    int continuer_musique = 0;
    SDL_Event event;

    while (continuer_fenetre)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer_fenetre = 0;
                break;
             case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer_fenetre= 0 ;
                    break;
                }
            case SDL_MOUSEBUTTONUP:
                if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X+ECART_ICONE*6 && event.motion.x<=CENTRAGE_LOGO_X+ECART_ICONE*6+ECART_ICONE && event.motion.y>=CENTRAGE_LOGO_Y && event.motion.y<=CENTRAGE_LOGO_Y+ECART_ICONE)
                    {
                        continuer_fenetre=0;
                    }
                else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X+ECART_ICONE*5 && event.motion.x<=CENTRAGE_LOGO_X+ECART_ICONE*5+ECART_ICONE && event.motion.y>=CENTRAGE_LOGO_Y && event.motion.y<=CENTRAGE_LOGO_Y+ECART_ICONE)
                    {
                        continuer_fenetre=0;
                        info_setup(ecran);
                    }
                else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X+ECART_ICONE*4 && event.motion.x<=CENTRAGE_LOGO_X+ECART_ICONE*4+ECART_ICONE && event.motion.y>=CENTRAGE_LOGO_Y && event.motion.y<=CENTRAGE_LOGO_Y+ECART_ICONE)
                    {
                        continuer_fenetre=0;
                        info_setup(ecran);
                    }
                else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X+ECART_ICONE*3 && event.motion.x<=CENTRAGE_LOGO_X+ECART_ICONE*3+ECART_ICONE && event.motion.y>=CENTRAGE_LOGO_Y && event.motion.y<=CENTRAGE_LOGO_Y+ECART_ICONE)
                    {
                        continuer_fenetre=0;
                        info_setup(ecran);
                    }
                else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X+ECART_ICONE*2 && event.motion.x<=CENTRAGE_LOGO_X+ECART_ICONE*2+ECART_ICONE && event.motion.y>=CENTRAGE_LOGO_Y && event.motion.y<=CENTRAGE_LOGO_Y+ECART_ICONE)
                    {
                        continuer_fenetre=0;
                        info_setup(ecran);
                    }
                else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X+ECART_ICONE && event.motion.x<=CENTRAGE_LOGO_X+ECART_ICONE+ECART_ICONE && event.motion.y>=CENTRAGE_LOGO_Y && event.motion.y<=CENTRAGE_LOGO_Y+ECART_ICONE)
                    {
                        continuer_fenetre=0;
                        level_setup(ecran);
                    }
                else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X && event.motion.x<=CENTRAGE_LOGO_X+ECART_ICONE+ECART_ICONE && event.motion.y>=CENTRAGE_LOGO_Y && event.motion.y<=CENTRAGE_LOGO_Y+ECART_ICONE)
                    {
                        continuer_fenetre=0;
                        menu(ecran);
                    }
                else if (event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X_MUSIQUE  && event.motion.x<=CENTRAGE_LOGO_X_MUSIQUE +ECART_ICONE && event.motion.y>=CENTRAGE_LOGO_Y_MUSIQUE && event.motion.y<=CENTRAGE_LOGO_Y_MUSIQUE+ECART_ICONE)
                {
                     if(continuer_musique==1)
                     {
                        continuer_musique=0;
                     }
                     else
                    {
                        continuer_musique=1;
                    }
                    icone_musique_control(ecran,continuer_musique);
                }
                break;
            default:
                break;
        }
    }
}
