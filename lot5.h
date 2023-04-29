
#ifndef LOT5_H
#define LOT5_H
#include <stdlib.h>
#include<stdio.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


typedef struct
{
char *url;
SDL_Rect pos_img_affiche; 
SDL_Rect pos_img_ecran;
SDL_Surface *img;
}image;



typedef struct {

image i;

}enigme;
typedef struct {
image r;
}reponse;




void initialiser_image_enigme(image *imge,char dest[]);
void initialiser_image_reponse(image *imge,char dest[]);

void afficherreponse(reponse r,SDL_Surface *screen);


void afficherEnigme(enigme e,SDL_Surface *screen);

void genererEnigme(enigme *e,char *nomfichier);
void animation(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES);
/*void sauvegarder(personne p,background b,char *nomfichier);
void animerEnigme(Enigme *e);*/
#endif

