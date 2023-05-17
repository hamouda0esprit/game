#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
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
void initmap(minimap *m,int SCREEN_W,int SCREEN_H,char minimapNormal[] );
void afficherminimap (minimap m, SDL_Surface * screen,int SCREEN_W,int SCREEN_H);
void annimerMinimap(SDL_Rect posJoueur,SDL_Rect posEnemie,SDL_Rect posEnigme, minimap *m, int redimensionnement,int SCREEN_W,int SCREEN_H);
void affichertemps(SDL_Surface* screen, char tmp[], int SCREEN_W, int SCREEN_H);
int collisionPP(SDL_Rect p, SDL_Surface *Masque,SDL_Rect MasqueRect,int R,int G,int B);
void get_points(int x,int y,int w,int h,points *p); 
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y); 
void LibererMinimap (minimap * m);
void maj_map(minimap *m, SDL_Surface *screen,int SCREEN_W,int SCREEN_H,char minimapNormal[], char minimapEnemie[] , char minimapEnigme[] );
SDL_Surface* resizeSurface(SDL_Surface* surface, int width, int height);
void fullmap(minimap * m,int SCREEN_W,int SCREEN_H,char minimapNormal[] );
void smallmap(minimap * m,int SCREEN_W,int SCREEN_H,char minimapNormal[] );
void maj_fullmap(minimap *m,int SCREEN_W,int SCREEN_H,char minimapNormal[], char minimapEnemie[] , char minimapEnigme[] );
void afficherFULLminimap(minimap m, SDL_Surface *screen,int SCREEN_W,int SCREEN_H);
void miniMap(bool pressing_m,minimap *m,SDL_Rect pjr,SDL_Rect peg,SDL_Rect pen,SDL_Surface *screen,int SCREEN_W,int SCREEN_H, char minimapNormal[] , char minimapEnemie[] , char minimapEnigme[] );
