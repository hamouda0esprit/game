#ifndef LOT5_H
#define LOT5_H
#include <stdlib.h>
#include<stdio.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"






typedef struct {
image i;
SDL_Rect eni;
}enigmme;
typedef struct {
SDL_Rect r;
image ir;
}reponse;


void enigmefinal(int *enigme1,int*gamestate, int ref,reponse *r,reponse *r2,reponse *r3,reponse *r4,int *next,int *frame,int* currentframeenigme,int* current_framereponse,int* current_framereponse2,int* current_framereponse3,int* current_framereponse4,SDL_Surface *screen,enigmme *e1,int *e1_stage,SDL_Surface **framesattend,SDL_Surface **framesnumber1,SDL_Surface **framesnumber2,SDL_Surface **framesnumber3,SDL_Surface **framesnumber4,SDL_Surface **framefinal);
void afficherbackround(char dest[],int SCREEN_WIDTH,int SCREEN_HEIGHT,enigmme *e,SDL_Surface *screen);
void Resizeenigme(SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT);
void loadenigmenumbers(int numbers ,SDL_Surface **frames,char dest[],int SCREEN_WIDTH, int SCREEN_HEIGHT);
void afficherreponse(SDL_Surface *screen, SDL_Surface **frames,int *current_frame,int SCREEN_WIDTH,int SCREEN_HEIGHT,reponse *r);
void loadenigmeanswer(int numbers ,SDL_Surface **frames,char dest[],int SCREEN_WIDT, int SCREEN_HEIG);
#endif
