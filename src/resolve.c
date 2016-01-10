#include "../include/resolve.h"
#include "save_load.c"
#include "data_structure.c"
#include "play.c"


void L_Choix_EVOLUE(SDL_Surface* ecran)
{
    fond_level(ecran);
    char** carre;
    carre=initialisergrille_L();
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

    char** initial;

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

//    SDL_SetColorKey(Block_UN,SDL_SRCCOLORKEY,SDL_MapRGB(Block_UN->format,0,0,0));
  //  SDL_SetColorKey(Block_ZERO,SDL_SRCCOLORKEY,SDL_MapRGB(Block_ZERO->format,0,0,0));
    //SDL_SetColorKey(Block_CASEVIDE,SDL_SRCCOLORKEY,SDL_MapRGB(Block_CASEVIDE->format,0,0,0));

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
                    case SDLK_a:
                    	initial=CopieTableau(carre,L);
                        Resolve_all(initial,carre,L);
                    break;
                    default:
                        NULL;
                    break;
                }
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

void XL_Choix_EVOLUE(SDL_Surface* ecran)
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

    char** initial;

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

//    SDL_SetColorKey(Block_UN,SDL_SRCCOLORKEY,SDL_MapRGB(Block_UN->format,0,0,0));
  //  SDL_SetColorKey(Block_ZERO,SDL_SRCCOLORKEY,SDL_MapRGB(Block_ZERO->format,0,0,0));
    //SDL_SetColorKey(Block_CASEVIDE,SDL_SRCCOLORKEY,SDL_MapRGB(Block_CASEVIDE->format,0,0,0));


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
                  case SDLK_a:
                  		initial=CopieTableau(carre,XL);
                        Resolve_all(initial,carre,XL);
                    break;
                    default:
                        NULL;
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


void XXL_Choix_EVOLUE(SDL_Surface* ecran)
{
    fond_level(ecran);
    char **carre=initialisergrille_XXL();
    SDL_Rect position;
    int NbMauvaiseCoups=0;
		int erreur=0;
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
		Coordonnees Valeur;
		Liste CoordooneesEmpiler=initPile(CoordooneesEmpiler);

		char** initial;

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

//    SDL_SetColorKey(Block_UN,SDL_SRCCOLORKEY,SDL_MapRGB(Block_UN->format,0,0,0));
  //  SDL_SetColorKey(Block_ZERO,SDL_SRCCOLORKEY,SDL_MapRGB(Block_ZERO->format,0,0,0));
    //SDL_SetColorKey(Block_CASEVIDE,SDL_SRCCOLORKEY,SDL_MapRGB(Block_CASEVIDE->format,0,0,0));

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
                    case SDLK_a:
                    	initial=CopieTableau(carre,XXL);
                        Resolve_all(initial,carre,XXL);
                    break;
                    default:
                        NULL;
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


void Resolve_all(char**initial, char** grille, int taille)
{
    while(GrilleNonVide(grille,taille))
    {
    RempliDuoHorizontale(initial,grille,taille);
    RempliDuoVerticale(initial,grille,taille);
    MilieuHorizontale(initial,grille,taille);
    MilieuVerticale(initial,grille,taille);
    RechercheLigneUneSeuleCaseVide(grille,taille);
    RechercheColonneUneSeuleCaseVide(grille,taille);
    }
}














