#ifndef H_MAIN_SDL
#define H_MAIN_SDL 0

SDL_Surface* init();
void icone_menu(SDL_Surface* ecran);
void icone_play(SDL_Surface* ecran);
void icone_info(SDL_Surface* ecran);
void icone_load(SDL_Surface* ecran);
void icone_parametres(SDL_Surface* ecran);
void icone_score(SDL_Surface* ecran);
void icone_exit(SDL_Surface* ecran);
void pause_SDL(SDL_Surface* ecran);
void menu(SDL_Surface* ecran);
void icone_musique(SDL_Surface* ecran);
void icone_musique_control(SDL_Surface* ecran,int continuer_musique);
void Fond(SDL_Surface* ecran);
void icone_previous(SDL_Surface* ecran);
void icone_load_save(SDL_Surface* ecran);

#endif



