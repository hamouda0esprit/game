#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>

#define SCREEN_W 1280
#define SCREEN_H 720

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
    int state;
    score score;
    int doit_animer;
} Ennemi;

typedef struct  {
   image image_personne;
    HealthBar health;
    int speed;
    int direction;
    int state;
} personne;


typedef struct  {
    SDL_Rect jr;
    SDL_Surface * player;
} plyr;








typedef struct{
    SDL_Surface * image_miniature;
    SDL_Rect positionMinimap;
    SDL_Surface * bonhomm;
    SDL_Rect positionBonhomme;
    SDL_Surface * enigme;
    SDL_Rect positionEnigme;
    SDL_Surface * enemi;
    SDL_Rect positionEnemi;
}minimap;

typedef struct{
    
    int p1x;
    int p2x;
    int p3x;
    int p4x;
    int p5x;
    int p6x;
    int p7x;
    int p8x;
    
    int p1y;
    int p2y;
    int p3y;
    int p4y;
    int p5y;
    int p6y;
    int p7y;
    int p8y;
}points;




int ms_to_sec(int milliseconds);
void format_time(int seconds, char time_str[]);
void initmap( minimap * m);
void afficherminimap (minimap m, SDL_Surface * screen);
void annimerMinimap(SDL_Rect posJoueur,SDL_Rect posEnemie,SDL_Rect posEnigme, minimap *m, SDL_Rect camera, int redimensionnement);
void affichertemps(int start_time, SDL_Surface* screen, char tmp[]);
int collisionPP(SDL_Rect p, SDL_Surface *Masque); 
void get_points(int x,int y,int w,int h,points *p); 
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y); 
void LibererMinimap (minimap * m);
void maj_map(minimap *m, SDL_Surface *screen);
void Resize(SDL_Surface *screen, SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT);
void fullmap(minimap * m);
void smallmap(minimap * m);
void maj_fullmap(minimap *m, SDL_Surface *screen);
void afficherFULLminimap(minimap m, SDL_Surface *screen);
void miniMap(bool pressing_m,minimap *m,SDL_Rect pjr,SDL_Rect peg,SDL_Rect pen,SDL_Surface *screen,SDL_Rect camera);


