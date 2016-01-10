#include "../include/level_sdl.h"
#include "../include/constantes.h"
#include "../include/data_structure.h"




void level_setup(SDL_Surface* ecran)
{
    SDL_Surface *imageDeFond;
    SDL_Rect positionFond;
    SDL_Rect positionText;
    positionFond.x=0;
    positionFond.y=0;
    positionText.x=MESSAGE_NIVEAU_DE_JEU_X;
    positionText.y=MESSAGE_NIVEAU_DE_JEU_Y;
    imageDeFond=SDL_LoadBMP("image/menu.bmp");
    SDL_BlitSurface(imageDeFond, NULL,ecran, &positionFond);
    TTF_Font *police=TTF_OpenFont("font/font.ttf",100);
    SDL_Color couleurNoire= {0,0,0};
    SDL_Surface* text=TTF_RenderText_Blended(police,"Niveau du jeu",couleurNoire);
    SDL_BlitSurface(text,NULL,ecran,&positionText);
    icone_menu(ecran);
    icone_exit(ecran);
    icone_musique(ecran);
    configuration(ecran);
    SDL_Flip(ecran);
}



void configuration(SDL_Surface* ecran)
{
    int continuer_musique=0;

    SDL_Rect positionTextBase;
    SDL_Rect positionTextEvolue;
    SDL_Rect positionTextUltime;


    positionTextBase.x=MESSAGE_NIVEAU_BASE_X;
    positionTextBase.y=MESSAGE_NIVEAU_BASE_Y;

    positionTextEvolue.x=MESSAGE_NIVEAU_EVOLUEE_X;
    positionTextEvolue.y=MESSAGE_NIVEAU_EVOLUEE_Y;

    positionTextUltime.x=MESSAGE_NIVEAU_ULTIME_X;
    positionTextUltime.y=MESSAGE_NIVEAU_ULTIME_Y;

    TTF_Font *police=TTF_OpenFont("font/font.ttf",100);
    SDL_Color couleurNoire= {0,0,0};


    SDL_Surface* textTailleBase=TTF_RenderText_Blended(police,"Version de base : L XL XXL",couleurNoire);
    SDL_BlitSurface(textTailleBase,NULL,ecran,&positionTextBase);

    SDL_Surface* TextEvolue=TTF_RenderText_Blended(police,"Version evoluee : L XL XXL",couleurNoire);
    SDL_BlitSurface(TextEvolue,NULL,ecran,&positionTextEvolue);

    SDL_Surface* TextUltime=TTF_RenderText_Blended(police,"Version ultime : L XL XXL",couleurNoire);
    SDL_BlitSurface(TextUltime,NULL,ecran,&positionTextUltime);

    icone_previous(ecran);

    SDL_Flip(ecran);
    pauseConfiguration(ecran);
}


void pauseConfiguration(SDL_Surface* ecran)
{
    int continuer_fenetre = 1;
    int continuer_musique = 0;
    SDL_Event eventSuivant;

    while(continuer_fenetre)
    {
        SDL_WaitEvent(&eventSuivant);
        switch(eventSuivant.type)
        {
            case SDL_QUIT:
                continuer_fenetre=0;
                break;
            case SDL_MOUSEBUTTONUP:
                if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CHOIX_L_BASE_X  && eventSuivant.motion.x<=CHOIX_L_BASE_X+LONGUEUR_L_X && eventSuivant.motion.y>=CHOIX_L_BASE_Y && eventSuivant.motion.y<=CHOIX_L_BASE_Y+LARGEUR_L_Y)
                    {
                        continuer_fenetre=0;
                        L_Choix(ecran);
                    }
                else if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CHOIX_XL_BASE_X  && eventSuivant.motion.x<=CHOIX_XL_BASE_X+LONGUEUR_XL_X && eventSuivant.motion.y>=CHOIX_XL_BASE_Y && eventSuivant.motion.y<=CHOIX_XL_BASE_Y+LARGEUR_XL_Y)
                    {
                        continuer_fenetre=0;
                        XL_Choix(ecran);
                    }
                else if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CHOIX_XXL_BASE_X  && eventSuivant.motion.x<=CHOIX_XXL_BASE_X+LONGUEUR_XXL_X && eventSuivant.motion.y>=CHOIX_XXL_BASE_Y && eventSuivant.motion.y<=CHOIX_XXL_BASE_Y+LARGEUR_XXL_Y)
                    {
                        continuer_fenetre=0;
                        XXL_Choix(ecran);
                    }
                else if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CHOIX_L_EVOLUE_X  && eventSuivant.motion.x<=CHOIX_L_EVOLUE_X+LONGUEUR_L_X && eventSuivant.motion.y>=CHOIX_L_EVOLUE_Y && eventSuivant.motion.y<=CHOIX_L_EVOLUE_Y+LARGEUR_XXL_Y)
                    {
                        continuer_fenetre=0;
                        L_Choix(ecran);
                    }
                else if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CHOIX_XL_EVOLUE_X  && eventSuivant.motion.x<=CHOIX_XL_EVOLUE_X+LONGUEUR_XL_X && eventSuivant.motion.y>=CHOIX_XL_EVOLUE_Y && eventSuivant.motion.y<=CHOIX_XL_EVOLUE_Y+LARGEUR_XL_Y)
                    {
                        continuer_fenetre=0;
                        XL_Choix(ecran);
                    }
                else if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CHOIX_XXL_EVOLUE_X  && eventSuivant.motion.x<=CHOIX_XXL_EVOLUE_X+LONGUEUR_XXL_X && eventSuivant.motion.y>=CHOIX_XXL_EVOLUE_Y && eventSuivant.motion.y<=CHOIX_XXL_EVOLUE_Y+LARGEUR_XXL_Y)
                    {
                        continuer_fenetre=0;
                        XXL_Choix(ecran);
                    }
                else if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CHOIX_L_ULTIME_X  && eventSuivant.motion.x<=CHOIX_L_ULTIME_X+LONGUEUR_L_X && eventSuivant.motion.y>=CHOIX_L_ULTIME_Y && eventSuivant.motion.y<=CHOIX_L_ULTIME_Y+LARGEUR_L_Y)
                    {
                        continuer_fenetre=0;
                        L_Choix_EVOLUE(ecran);
                    }
                else if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CHOIX_XL_ULTIME_X  && eventSuivant.motion.x<=CHOIX_XL_ULTIME_X+LONGUEUR_XL_X && eventSuivant.motion.y>=CHOIX_XL_ULTIME_Y && eventSuivant.motion.y<=CHOIX_XL_ULTIME_Y+LARGEUR_XL_Y)
                    {
                        continuer_fenetre=0;
                        XL_Choix_EVOLUE(ecran);
                    }
                else if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CHOIX_XXL_ULTIME_X  && eventSuivant.motion.x<=CHOIX_XXL_ULTIME_X+LONGUEUR_XXL_X && eventSuivant.motion.y>=CHOIX_XXL_ULTIME_Y && eventSuivant.motion.y<=CHOIX_XXL_ULTIME_Y+LARGEUR_XXL_Y)
                    {
                        continuer_fenetre=0;
                        XXL_Choix_EVOLUE(ecran);
                    }
                else if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CENTRAGE_LOGO_X  && eventSuivant.motion.x<=CENTRAGE_LOGO_X+BLOC*2 && eventSuivant.motion.y>=CENTRAGE_LOGO_Y && eventSuivant.motion.y<=CENTRAGE_LOGO_Y+BLOC*2)
                    {
                        continuer_fenetre=0;
                        menu(ecran);
                    }
                else if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CENTRAGE_LOGO_X_MUSIQUE  && eventSuivant.motion.x<=CENTRAGE_LOGO_X_MUSIQUE +ECART_ICONE && eventSuivant.motion.y>=CENTRAGE_LOGO_Y_MUSIQUE && eventSuivant.motion.y<=CENTRAGE_LOGO_Y_MUSIQUE+ECART_ICONE)
                    if(continuer_musique==1)
                     {
                        continuer_musique=0;
                     }
                     else
                    {
                        continuer_musique=1;
                    }
                    icone_musique_control(ecran,continuer_musique);
                 if(eventSuivant.button.button==SDL_BUTTON_LEFT && eventSuivant.motion.x>=CENTRAGE_LOGO_X+ECART_ICONE*6 && eventSuivant.motion.x<=CENTRAGE_LOGO_X+ECART_ICONE*6+ECART_ICONE && eventSuivant.motion.y>=CENTRAGE_LOGO_Y && eventSuivant.motion.y<=CENTRAGE_LOGO_Y+ECART_ICONE)
                    {
                        continuer_fenetre=0;
                    }
                break;
        }
    }
}

void L_Choix(SDL_Surface* ecran)
{
    fond_level(ecran);
    char **carre=initialisergrille_L();
    int continuer_musique;
    int erreur=0;
    int NbMauvaiseCoups=0;
    int deja_ecrit=0;
    SDL_Rect position;
    SDL_Surface* Block_ZERO;
    SDL_Surface* Block_UN;
    SDL_Surface* Block_CASEVIDE;
    SDL_Surface* Erreur;
    SDL_Surface* grille_L[L][L];
    SDL_Rect postionecriture;
    Coordonnees Valeur;
    Liste CoordooneesEmpiler=initPile(CoordooneesEmpiler);

    TTF_Init();
    SDL_Rect positionText;
    positionText.x=MESSAGE_ERREUR_BASE_X;
    positionText.y=MESSAGE_ERREUR_BASE_Y;


    SDL_Rect positionCompteurTOTAL;
    SDL_Rect positionCompteurERREUR;

        positionCompteurTOTAL.x=MESSAGE_COMPTEUR_TOTAL_X;
        positionCompteurTOTAL.y=MESSAGE_COMPTEUR_TOTAL_Y;

        positionCompteurERREUR.x=MESSAGE_COMPTEUR_ERREUR_X;
        positionCompteurERREUR.y=MESSAGE_COMPTEUR_ERREUR_Y;


    int continuer=1;
    int NbCoups=0;
    SDL_Event event;

    Erreur=SDL_LoadBMP("image/error.bmp");
    Block_ZERO=SDL_LoadBMP("image/menu/games/grille/blue/block_blue_32_0.bmp");
    Block_UN=SDL_LoadBMP("image/menu/games/grille/blue/block_blue_32_1.bmp");
    Block_CASEVIDE=SDL_LoadBMP("image/menu/games/grille/blanck/block_white_32.bmp");

    SDL_SetColorKey(Block_UN,SDL_SRCCOLORKEY,SDL_MapRGB(Block_UN->format,0,0,0));
    SDL_SetColorKey(Block_ZERO,SDL_SRCCOLORKEY,SDL_MapRGB(Block_ZERO->format,0,0,0));
    SDL_SetColorKey(Block_CASEVIDE,SDL_SRCCOLORKEY,SDL_MapRGB(Block_CASEVIDE->format,0,0,0));

    position.x=0;
    position.y=0;

    Affichegrille_L_Empty(carre,ecran,grille_L,Block_ZERO,Block_UN,Block_CASEVIDE);

    TTF_Font *police=TTF_OpenFont("font/font.ttf",60);
    SDL_Color couleurNoire= {0,0,0};
    SDL_Surface* text=TTF_RenderText_Blended(police,"Il y a une erreur !",couleurNoire);

    char CompteurTtotalTexte[100];
    char CompteurTErreurTexte[100];

    icone_previous(ecran);
    icone_menu_level(ecran);
    icone_exit_level(ecran);
    icone_load_save(ecran);

    SDL_Flip(ecran);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer=0;
            break;
            case SDL_MOUSEBUTTONUP:
                 if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_EXIT_X  && event.motion.x<=ICONE_EXIT_X+ECART_ICONE && event.motion.y>=ICONE_EXIT_Y && event.motion.y<=ICONE_EXIT_Y+ECART_ICONE)
                    {
                        continuer=0;
                    }
                    else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_HOME_X && event.motion.x<=ICONE_HOME_X+ECART_ICONE && event.motion.y>=ICONE_HOME_Y && event.motion.y<=ICONE_HOME_Y+ECART_ICONE)
                    {
                        continuer=0;
                        menu(ecran);
                    }
                    else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X_PREVIOUS && event.motion.x<=CENTRAGE_LOGO_X_PREVIOUS+BLOC*2 && event.motion.y>=CENTRAGE_LOGO_Y_PREVIOUS && event.motion.y<=CENTRAGE_LOGO_Y_PREVIOUS+BLOC*2)
                    {
                        continuer=0;
                        level_setup(ecran);
                    }
                    else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_SAVE_X && event.motion.x<=ICONE_SAVE_X+BLOC*2 && event.motion.y>=ICONE_SAVE_Y && event.motion.y<=ICONE_SAVE_Y+BLOC*2)
                    {
                        Save_NewGame_L(carre);
                    }
                    else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_LOAD_X && event.motion.x<=ICONE_LOAD_X+BLOC*2 && event.motion.y>=ICONE_LOAD_Y && event.motion.y<=ICONE_LOAD_Y+BLOC*2)
                    {
                        Load_Game_L(carre,ecran,grille_L,Block_ZERO,Block_UN,Block_CASEVIDE);
                        NbCoups=0;NbMauvaiseCoups=0;
                        fond_level(ecran);
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

            break;
            case SDL_MOUSEBUTTONDOWN:
                if( event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_JEU_L_X && event.motion.x<=CENTRAGE_JEU_L_X+BLOC*L && event.motion.y>=CENTRAGE_JEU_L_Y && event.motion.y<=CENTRAGE_JEU_L_Y+BLOC*L)
                {
                if (CaseImpossible(carre,L)==0 || GrilleVide(carre,L)==0 )
                {
                    postionecriture.x=event.motion.x-CENTRAGE_JEU_L_X;
                    postionecriture.y=event.motion.y-CENTRAGE_JEU_L_Y;
                }
                }
            break;
                case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_1:
                        fond_level(ecran);
                        NbCoups++;
			carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=UN;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=UN;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_0:
                        fond_level(ecran);
                        NbCoups++;
						carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=ZERO;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=ZERO;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_KP0:
                        fond_level(ecran);
                        NbCoups++;
						carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=ZERO;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=ZERO;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_KP1:
                        fond_level(ecran);
                        NbCoups++;
						carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=UN;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=UN;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_ESCAPE:
                        continuer=0;
                    break;
                    case SDLK_DELETE:
                        fond_level(ecran);
						CoordooneesEmpiler=Pop(CoordooneesEmpiler,&Valeur);
                        carre[Valeur.y][Valeur.x]=CASEVIDE;
                        NbCoups++;
                        NbMauvaiseCoups++;
                    break;
                    case SDLK_r:
                        Load_Game_L(carre,ecran,grille_L,Block_ZERO,Block_UN,Block_CASEVIDE);
                    break;
                    case SDLK_s:
                        Save_NewGame_L(carre);
                    break;
                    case SDLK_c:
                        cleargrille_L(carre);
                    break;
                    default:
                        break;
                }
            break;
                    default:
                        break;
        }
          if (CaseImpossible(carre,L)==1 && NbCoups>0 && deja_ecrit==0)
                {
                     SDL_BlitSurface(text,NULL,ecran,&positionText);
                     deja_ecrit=1;
                }
           else if(CaseImpossible(carre,L)==0 && NbCoups>0 && deja_ecrit==1)
           {
            deja_ecrit=0;
           }
           Affichegrille_L(carre,ecran,grille_L,Block_ZERO,Block_UN,Block_CASEVIDE);
            sprintf(CompteurTtotalTexte,"Nombre de Coups Total : %d ",NbCoups);
            sprintf(CompteurTErreurTexte,"Nombre de Coups Erreur : %d",NbMauvaiseCoups);
            SDL_Surface* TextCTOTAL=TTF_RenderText_Blended(police,CompteurTtotalTexte,couleurNoire);
            SDL_Surface* TextCErreur=TTF_RenderText_Blended(police,CompteurTErreurTexte,couleurNoire);
           SDL_BlitSurface(TextCTOTAL,NULL,ecran,&positionCompteurTOTAL);
           SDL_BlitSurface(TextCErreur,NULL,ecran,&positionCompteurERREUR);
       SDL_Flip(ecran);

    }


}


void XL_Choix(SDL_Surface* ecran)
{
    fond_level(ecran);
    int continuer_musique;
    char **carre=initialisergrille_XL();
    SDL_Rect position;
		int deja_ecrit=0;
    SDL_Surface* Block_ZERO;
    SDL_Surface* Block_UN;
    SDL_Surface* Block_CASEVIDE;
    SDL_Surface* Save;
    SDL_Surface* Load;
    SDL_Surface* grille_XL[XL][XL];
    SDL_Rect postionecriture;
    int  NbMauvaiseCoups=0;
    Liste CoordooneesEmpiler=initPile(CoordooneesEmpiler);
    int NbCoups=0;
    Coordonnees Valeur;
    char CompteurTErreurTexte[100];
    char CompteurTtotalTexte[100];

		TTF_Init();
    SDL_Rect positionText;
    positionText.x=MESSAGE_ERREUR_BASE_X;
    positionText.y=MESSAGE_ERREUR_BASE_Y;

    SDL_Rect positionCompteurTOTAL;
    SDL_Rect positionCompteurERREUR;

    int continuer=1;
    SDL_Event event;

    Block_ZERO=SDL_LoadBMP("image/menu/games/grille/blue/block_blue_32_0.bmp");
    Block_UN=SDL_LoadBMP("image/menu/games/grille/blue/block_blue_32_1.bmp");
    Block_CASEVIDE=SDL_LoadBMP("image/menu/games/grille/blanck/block_white_32.bmp");

    SDL_SetColorKey(Block_UN,SDL_SRCCOLORKEY,SDL_MapRGB(Block_UN->format,0,0,0));
    SDL_SetColorKey(Block_ZERO,SDL_SRCCOLORKEY,SDL_MapRGB(Block_ZERO->format,0,0,0));
    SDL_SetColorKey(Block_CASEVIDE,SDL_SRCCOLORKEY,SDL_MapRGB(Block_CASEVIDE->format,0,0,0));


    position.x=0;
    position.y=0;


    positionCompteurTOTAL.x=MESSAGE_COMPTEUR_TOTAL_X;
        positionCompteurTOTAL.y=MESSAGE_COMPTEUR_TOTAL_Y;

        positionCompteurERREUR.x=MESSAGE_COMPTEUR_ERREUR_X;
        positionCompteurERREUR.y=MESSAGE_COMPTEUR_ERREUR_Y;


    Affichegrille_XL_Empty(carre,ecran,grille_XL,Block_ZERO,Block_UN,Block_CASEVIDE);
    icone_previous(ecran);
    icone_menu_level(ecran);
    icone_exit_level(ecran);
	icone_load_save(ecran);

	TTF_Font *police=TTF_OpenFont("font/font.ttf",60);
    SDL_Color couleurNoire= {0,0,0};
    SDL_Surface* text=TTF_RenderText_Blended(police,"Il y a une erreur !",couleurNoire);

    SDL_Flip(ecran);


    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer=0;
            break;
            case SDL_MOUSEBUTTONUP:
                   if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X && event.motion.x<=CENTRAGE_LOGO_X+ECART_ICONE+ECART_ICONE && event.motion.y>=CENTRAGE_LOGO_Y && event.motion.y<=CENTRAGE_LOGO_Y+ECART_ICONE)
                    {
                        continuer=0;
                        menu(ecran);
                    }
                    else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X_PREVIOUS && event.motion.x<=CENTRAGE_LOGO_X_PREVIOUS+BLOC*2 && event.motion.y>=CENTRAGE_LOGO_Y_PREVIOUS && event.motion.y<=CENTRAGE_LOGO_Y_PREVIOUS+BLOC*2)
                    {
                        continuer=0;
                        level_setup(ecran);
                    }
                    else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_SAVE_X && event.motion.x<=ICONE_SAVE_X+BLOC*2 && event.motion.y>=ICONE_SAVE_Y && event.motion.y<=ICONE_SAVE_Y+BLOC*2)
                    {
                        Save_NewGame_XL(carre);
                    }
                     else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_LOAD_X && event.motion.x<=ICONE_LOAD_X+BLOC*2 && event.motion.y>=ICONE_LOAD_Y && event.motion.y<=ICONE_LOAD_Y+BLOC*2)
                    {
                        Load_Game_XL(carre,ecran,grille_XL,Block_ZERO,Block_UN,Block_CASEVIDE);
                        NbCoups=0;NbMauvaiseCoups=0;
                        fond_level(ecran);
                    }
                     else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_EXIT_X  && event.motion.x<=ICONE_EXIT_X+ECART_ICONE && event.motion.y>=ICONE_EXIT_Y && event.motion.y<=ICONE_EXIT_Y+ECART_ICONE)
                    {
                        continuer=0;
                    }
                    else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_HOME_X && event.motion.x<=ICONE_HOME_X+ECART_ICONE && event.motion.y>=ICONE_HOME_Y && event.motion.y<=ICONE_HOME_Y+ECART_ICONE)
                    {
                        continuer=0;
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

            break;
            case SDL_MOUSEBUTTONDOWN:
                if( event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_JEU_XL_X && event.motion.x<=CENTRAGE_JEU_XL_X+BLOC*XL && event.motion.y>=CENTRAGE_JEU_XL_Y && event.motion.y<=CENTRAGE_JEU_XL_Y+BLOC*XL)
                {
                if (CaseImpossible(carre,XL)==0)
                {
                    postionecriture.x=event.motion.x-CENTRAGE_JEU_XL_X;
                    postionecriture.y=event.motion.y-CENTRAGE_JEU_XL_Y;
                }
                }
            break;
                case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_1:
                        fond_level(ecran);
                        NbCoups++;
			carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=UN;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=UN;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_0:
                        fond_level(ecran);
                        NbCoups++;
						carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=ZERO;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=ZERO;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_KP0:
                        fond_level(ecran);
                        NbCoups++;
						carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=ZERO;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=ZERO;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_KP1:
                        fond_level(ecran);
                        NbCoups++;
						carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=UN;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=UN;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_ESCAPE:
                        continuer=0;
                    break;
                    case SDLK_DELETE:
                        fond_level(ecran);
						CoordooneesEmpiler=Pop(CoordooneesEmpiler,&Valeur);
                        carre[Valeur.y][Valeur.x]=CASEVIDE;
                        NbCoups++;
                        NbMauvaiseCoups++;
                    break;
                    case SDLK_r:
                        Load_Game_XL(carre,ecran,grille_XL,Block_ZERO,Block_UN,Block_CASEVIDE);
                    break;
                    case SDLK_s:
                        Save_NewGame_XL(carre);
                    break;
                    case SDLK_c:
                        cleargrille_XL(carre);
                    break;
                    default:
                        break;
                }
            break;
        }
        if (CaseImpossible(carre,XL)==1 && NbCoups>0 && deja_ecrit==0)
                {
                     SDL_BlitSurface(text,NULL,ecran,&positionText);
                     deja_ecrit=1;
                }
           else if(CaseImpossible(carre,XL)==0 && NbCoups>0 && deja_ecrit==1)
           {
            fond_level(ecran);
            deja_ecrit=0;
           }
       Affichegrille_XL(carre,ecran,grille_XL,Block_ZERO,Block_UN,Block_CASEVIDE);
       sprintf(CompteurTtotalTexte,"Nombre de Coups Total : %d ",NbCoups);
            sprintf(CompteurTErreurTexte,"Nombre de Coups Erreur : %d",NbMauvaiseCoups);
            SDL_Surface* TextCTOTAL=TTF_RenderText_Blended(police,CompteurTtotalTexte,couleurNoire);
            SDL_Surface* TextCErreur=TTF_RenderText_Blended(police,CompteurTErreurTexte,couleurNoire);
           SDL_BlitSurface(TextCTOTAL,NULL,ecran,&positionCompteurTOTAL);
           SDL_BlitSurface(TextCErreur,NULL,ecran,&positionCompteurERREUR);
       SDL_Flip(ecran);
    }
}


void XXL_Choix(SDL_Surface* ecran)
{
    fond_level(ecran);
    char **carre=initialisergrille_XXL();
    SDL_Rect position;
    int NbMauvaiseCoups=0;
    int erreur=0;
    Coordonnees Valeur;
    int deja_ecrit=0;
    int continuer_musique;
    SDL_Surface* Block_ZERO;
    SDL_Surface* Block_UN;
    SDL_Surface* Block_CASEVIDE;
    SDL_Surface* Save;
    SDL_Surface* Load;
    SDL_Surface* grille_XXL[XXL][XXL];
    SDL_Rect postionecriture;
    char CompteurTErreurTexte[100];
    char CompteurTtotalTexte[100];

		Liste CoordooneesEmpiler=initPile(CoordooneesEmpiler);

		 TTF_Init();
    SDL_Rect positionText;
    positionText.x=MESSAGE_ERREUR_BASE_X;
    positionText.y=MESSAGE_ERREUR_BASE_Y;

    SDL_Rect positionCompteurTOTAL;
    SDL_Rect positionCompteurERREUR;

    int NbCoups=0;

    int continuer=1;
    SDL_Event event;

    Block_ZERO=SDL_LoadBMP("image/menu/games/grille/blue/block_blue_32_0.bmp");
    Block_UN=SDL_LoadBMP("image/menu/games/grille/blue/block_blue_32_1.bmp");
    Block_CASEVIDE=SDL_LoadBMP("image/menu/games/grille/blanck/block_white_32.bmp");

   SDL_SetColorKey(Block_UN,SDL_SRCCOLORKEY,SDL_MapRGB(Block_UN->format,0,0,0));
    SDL_SetColorKey(Block_ZERO,SDL_SRCCOLORKEY,SDL_MapRGB(Block_ZERO->format,0,0,0));
    SDL_SetColorKey(Block_CASEVIDE,SDL_SRCCOLORKEY,SDL_MapRGB(Block_CASEVIDE->format,0,0,0));

    position.x=0;
    position.y=0;

    positionCompteurTOTAL.x=MESSAGE_COMPTEUR_TOTAL_X;
        positionCompteurTOTAL.y=MESSAGE_COMPTEUR_TOTAL_Y;

        positionCompteurERREUR.x=MESSAGE_COMPTEUR_ERREUR_X;
        positionCompteurERREUR.y=MESSAGE_COMPTEUR_ERREUR_Y;

    TTF_Font *police=TTF_OpenFont("font/font.ttf",60);
    SDL_Color couleurNoire= {0,0,0};
    SDL_Surface* text=TTF_RenderText_Blended(police,"Il y a une erreur !",couleurNoire);


    Affichegrille_XXL_Empty(carre,ecran,grille_XXL,Block_ZERO,Block_UN,Block_CASEVIDE);
    icone_previous(ecran);
    icone_menu_level(ecran);
    icone_exit_level(ecran);
		icone_load_save(ecran);


    SDL_Flip(ecran);


    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            continuer=0;
            break;
            case SDL_MOUSEBUTTONUP:
                 if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_SAVE_X && event.motion.x<=ICONE_SAVE_X+BLOC && event.motion.y>=ICONE_LOAD_Y && event.motion.y<=ICONE_LOAD_Y+BLOC)
                    {
                       Save_NewGame_XXL(carre);
                    }
                    else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_LOGO_X_PREVIOUS && event.motion.x<=CENTRAGE_LOGO_X_PREVIOUS+BLOC*2 && event.motion.y>=CENTRAGE_LOGO_Y_PREVIOUS && event.motion.y<=CENTRAGE_LOGO_Y_PREVIOUS+BLOC*2)
                    {
                        continuer=0;
                        level_setup(ecran);
                    }
                    else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_SAVE_X && event.motion.x<=ICONE_SAVE_X+BLOC*2 && event.motion.y>=ICONE_SAVE_Y && event.motion.y<=ICONE_SAVE_Y+BLOC*2)
                    {
                        Save_NewGame_XXL(carre);
                    }
                     else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_LOAD_X && event.motion.x<=ICONE_LOAD_X+BLOC*2 && event.motion.y>=ICONE_LOAD_Y && event.motion.y<=ICONE_LOAD_Y+BLOC*2)
                    {
                        Load_Game_XXL(carre,ecran,grille_XXL,Block_ZERO,Block_UN,Block_CASEVIDE);
                        NbCoups=0;NbMauvaiseCoups=0;
                        fond_level(ecran);
                    }
                     else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_EXIT_X  && event.motion.x<=ICONE_EXIT_X+ECART_ICONE && event.motion.y>=ICONE_EXIT_Y && event.motion.y<=ICONE_EXIT_Y+ECART_ICONE)
                    {
                        continuer=0;
                    }
                    else if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=ICONE_HOME_X && event.motion.x<=ICONE_HOME_X+ECART_ICONE && event.motion.y>=ICONE_HOME_Y && event.motion.y<=ICONE_HOME_Y+ECART_ICONE)
                    {
                        continuer=0;
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

            break;
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button==SDL_BUTTON_LEFT && event.motion.x>=CENTRAGE_JEU_XXL_X && event.motion.x<=CENTRAGE_JEU_XXL_X+BLOC*XXL && event.motion.y>=CENTRAGE_JEU_XXL_Y && event.motion.y<=CENTRAGE_JEU_XXL_Y+BLOC*XXL)
                {
                 if (CaseImpossible(carre,XXL)==0)
                {
                    postionecriture.x=event.motion.x-CENTRAGE_JEU_XXL_X;
                    postionecriture.y=event.motion.y-CENTRAGE_JEU_XXL_Y;
                }
                }
            break;
                case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_1:
                        fond_level(ecran);
                        NbCoups++;
			carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=UN;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=UN;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_0:
                        fond_level(ecran);
                        NbCoups++;
						carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=ZERO;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=ZERO;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_KP0:
                        fond_level(ecran);
                        NbCoups++;
						carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=ZERO;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=ZERO;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_KP1:
                        fond_level(ecran);
                        NbCoups++;
						carre[postionecriture.y/BLOC][postionecriture.x/BLOC]=UN;
						Valeur.x=postionecriture.x/BLOC;
						Valeur.y=postionecriture.y/BLOC;
						Valeur.contient=UN;
                        CoordooneesEmpiler=Push(CoordooneesEmpiler,Valeur);
                    break;
                    case SDLK_ESCAPE:
                        continuer=0;
                    break;
                    case SDLK_DELETE:
                        fond_level(ecran);
						CoordooneesEmpiler=Pop(CoordooneesEmpiler,&Valeur);
                        carre[Valeur.y][Valeur.x]=CASEVIDE;
                        NbCoups++;
                        NbMauvaiseCoups++;
                    break;
                    case SDLK_r:
                        Load_Game_XXL(carre,ecran,grille_XXL,Block_ZERO,Block_UN,Block_CASEVIDE);
                    break;
                    case SDLK_s:
                        Save_NewGame_XXL(carre);
                    break;
                    case SDLK_c:
                        cleargrille_XXL(carre);
                    break;
                    default:
                        break;
                }
            break;
        }
        if (CaseImpossible(carre,XXL)==1 && NbCoups>0 && deja_ecrit==0)
                {
                     SDL_BlitSurface(text,NULL,ecran,&positionText);
                     deja_ecrit=1;
                }
           else if(CaseImpossible(carre,XXL)==0 && NbCoups>0 && deja_ecrit==1)
           {
            fond_level(ecran);
            deja_ecrit=0;
           }
       Affichegrille_XXL(carre,ecran,grille_XXL,Block_ZERO,Block_UN,Block_CASEVIDE);
       sprintf(CompteurTtotalTexte,"Nombre de Coups Total : %d ",NbCoups);
            sprintf(CompteurTErreurTexte,"Nombre de Coups Erreur : %d",NbMauvaiseCoups);
            SDL_Surface* TextCTOTAL=TTF_RenderText_Blended(police,CompteurTtotalTexte,couleurNoire);
            SDL_Surface* TextCErreur=TTF_RenderText_Blended(police,CompteurTErreurTexte,couleurNoire);
           SDL_BlitSurface(TextCTOTAL,NULL,ecran,&positionCompteurTOTAL);
           SDL_BlitSurface(TextCErreur,NULL,ecran,&positionCompteurERREUR);
       SDL_Flip(ecran);
    }
}


