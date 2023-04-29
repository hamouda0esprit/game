#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_W 1920
#define SCREEN_H 1080
#include "lot5.h"
  const int NUM_FRAMES = 4; // number of animation frames
	const int FRAME_DELAY = 100;

void initialiser_image_enigme(image *imge,char dest[])
{
imge->url=dest;
imge->img=IMG_Load(imge->url);
if (imge->img == NULL){
	printf("unable to load background image %s \n",SDL_GetError()); 
	return ;}
imge->pos_img_ecran.x=0;
imge->pos_img_ecran.y=0;
imge->pos_img_affiche.x=0;
imge->pos_img_affiche.y=0; 
imge->pos_img_affiche.h=SCREEN_H;
imge->pos_img_affiche.w=SCREEN_W;
}
void initialiser_image_reponse(image *imge,char dest[])
{
imge->url=dest;
imge->img=IMG_Load(imge->url);
if (imge->img == NULL){
	printf("unable to load background image %s \n",SDL_GetError()); 
	return ;}
imge->pos_img_ecran.x=0;
imge->pos_img_ecran.y=0;
imge->pos_img_affiche.x=0;
imge->pos_img_affiche.y=0; 
imge->pos_img_affiche.h=SCREEN_H;
imge->pos_img_affiche.w=SCREEN_W;
}



void afficherEnigme(enigme e,SDL_Surface *screen)
{
SDL_BlitSurface(e.i.img, &e.i.pos_img_affiche, screen, &e.i.pos_img_ecran);

}
void afficherreponse(reponse r,SDL_Surface *screen)
{
SDL_BlitSurface(r.r.img, &r.r.pos_img_affiche, screen, &r.r.pos_img_ecran);

}





//------------------------------------------------
void animation(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES) {
    // calculate time since last frame
    Uint32 current_time = SDL_GetTicks();
    Uint32 time_since_last_frame = current_time - *last_frame_time;

    // update animation frame if enough time has elapsed
    if (time_since_last_frame >= FRAME_DELAY) {
        (*current_frame)++;
        
        if (*current_frame == NUM_FRAMES) {
       
            *current_frame = 0;
  
        } 
             *last_frame_time = current_time;
    }
    SDL_Rect dest;
    dest.x = 200;
    dest.y = 200;
    dest.w = frames[*current_frame]->w;
    dest.h = frames[*current_frame]->h;

    SDL_BlitSurface(frames[*current_frame], NULL, screen, &dest);
    SDL_Flip(screen);
}
