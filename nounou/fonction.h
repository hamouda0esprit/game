#ifndef FONCTION_H
#define FONCTION_H
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdbool.h>
typedef struct  {
    SDL_Rect jr;
    SDL_Surface * player;
} plyr;
  
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
    int speed;
    int direction;
    score score;
} Ennemi;


void loadanimation(int numframes ,SDL_Surface **frames,char dest[]);
void initialiser_imageBACK(image *imge,char dest[]);
void afficher_image(SDL_Surface *screen, image imge);
void init_ennemi(Ennemi *e, int numframes, SDL_Surface **frames, SDL_Surface **framesl, SDL_Surface **framesright, SDL_Surface **framesleft);			
void afficherEnnemi(Ennemi e, SDL_Surface * screen);			
SDL_Rect animate(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, int x, int y) ;
SDL_Rect animate_place(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, int x, int y) ;			
void move( Ennemi * e,int *xm);			
int collisionBB(SDL_Rect posp, SDL_Rect pose); 
SDL_Surface* load_image(const char* filename);



#endif
