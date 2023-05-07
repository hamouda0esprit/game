#ifndef FONCTION_H
#define FONCTION_H
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdbool.h>
#include "fonctionn.h"
typedef struct  {
    SDL_Rect jr;
    SDL_Surface * player;
    int STATE;
    int vie;
} plyr;
  typedef struct{
SDL_Rect pos;
SDL_Surface *image;
}bullet;
typedef struct
{
char *url;
SDL_Rect pos_img_affiche; 
SDL_Rect pos_img_ecran;
SDL_Surface *img;
}image;

typedef struct 
{
    SDL_Rect hb_pos; 
    SDL_Surface* bgImage; 
    SDL_Surface* fgImage; 
    int maxHealth; 
    int currentHealth; 
} HealthBar;
typedef struct
{
SDL_Surface *txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
int currentScore;
}score;

typedef struct  {
   image image_ennemi;
    HealthBar health;
    int STATE;
    int direction;
    score score;
    int vie;
} Ennemi;


void loadanimation(int numframes ,SDL_Surface **frames,char dest[]);
void initialiser_imageBACK(image *imge,char dest[]);
void afficher_image(SDL_Surface *screen, image imge);
void init_ennemi(Ennemi *e, int numframes, SDL_Surface **frames, SDL_Surface **framesl, SDL_Surface **framesright, SDL_Surface **framesleft);			
void afficherEnnemi(Ennemi e, SDL_Surface * screen);			
SDL_Rect animate(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, int x, int y) ;
SDL_Rect animate_place(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, int x, int y) ;			
void move( Ennemi * e,SDL_Rect* dest);			
int collisionBB(SDL_Rect posp, SDL_Rect pose); 
SDL_Surface* load_image(const char* filename);

void init_bullet(bullet *b);
void affbullet(SDL_Surface *screen,bullet *b);

void IA(Ennemi *ennemi, Personn *P, SDL_Rect* dest);
void UpdateEnnemi(SDL_Surface* screen, SDL_Surface** frames,SDL_Surface** framesl, SDL_Surface** framesleft, SDL_Surface** framesright, int NUM_FRAMES, int* xm, int ym, int* ok, Ennemi* e, SDL_Rect* dest, int *current_frame, int *current_frame0, int* last_frame_time, int* current_frameleft, int* last_frame_timeleft, int* current_frame2, int* last_frame_time2);


void move_waiting(int* movex,SDL_Surface* screen, SDL_Surface** frames,SDL_Surface** framesl, SDL_Surface** framesleft, SDL_Surface** framesright, int NUM_FRAMES, int* ok, Ennemi* e, SDL_Rect* dest, 
int *current_frame,int *current_frame0, int* last_frame_time, int* current_frameleft, int* last_frame_timeleft, int* current_frame2, int* last_frame_time2);

void move_following(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES,SDL_Rect* dest,SDL_Rect posp,Ennemi * e);

#endif
