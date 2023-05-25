#ifndef FONCTION_H
#define FONCTION_H
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdbool.h>
#include "fonctionn.h"
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


typedef struct  {
   image image_ennemi;
    int STATE;
    int direction;
    int vie;
    SDL_Rect dest;
} Ennemi;


void initialiser_imageBACK(image *imge,char dest[]);

void afficher_image(SDL_Surface *screen, image imge);			
void afficherEnnemi(Ennemi e, SDL_Surface * screen);			
void update_and_render_animationenemy(int rep,SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES,Ennemi *e,int SCREEN_WIDTH,int SCREEN_HEIGHT );
int collisionBB(SDL_Rect posp, SDL_Rect pose); 
SDL_Surface* load_image(const char* filename);
void init_bullet(bullet *b);
void affbullet(SDL_Surface *screen,bullet *b,int speed);
void affbulletleft(SDL_Surface *screen,bullet *b,int speed);
void IA(Ennemi *ennemi, Personn *P);
void move_waiting(int* movex,SDL_Surface* screen, SDL_Surface** frames,SDL_Surface** framesl, SDL_Surface** framesleft, SDL_Surface** framesright, int NUM_FRAMES,  int* ok, Ennemi* e,int* current_frameleft, int* last_frame_timeleft, int* current_frame2, int* last_frame_time2);
void move_following(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES,Ennemi *e);
#endif
