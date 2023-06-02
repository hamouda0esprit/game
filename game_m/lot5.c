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
int SCREEN_WIDT = 1710;
int SCREEN_HEIG = 960;


void Resizeenigme(SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT){
	SDL_Surface *Buffer = IMG_Load(dir);
	
	// Create the resized surface
	*(Image) = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, Buffer->format->BitsPerPixel, Buffer->format->Rmask, Buffer->format->Gmask,  Buffer->format->Bmask, Buffer->format->Amask);

	// Scale the original surface to the new size
	SDL_SoftStretch(Buffer, NULL, *(Image), NULL);
	SDL_FreeSurface(Buffer);
}
void loadenigmenumbers(int numbers ,SDL_Surface **frames,char dest[],int SCREEN_WIDT, int SCREEN_HEIG){
for (int i = 1; i <= numbers; i++) {
        char filename2[20];
        sprintf(filename2, dest, i);
        //frames[i] = load_image(filename);
        Resizeenigme(&(frames[i]), filename2, SCREEN_WIDT,  SCREEN_HEIG);
        
    }

}
void loadenigmeanswer(int numbers ,SDL_Surface **frames,char dest[],int SCREEN_WIDT, int SCREEN_HEIG){
for (int i = 1; i <= numbers; i++) {
        char filename[20];
        sprintf(filename, dest, i);
        //frames[i] = load_image(filename);
        Resizeenigme(&(frames[i]), filename, SCREEN_WIDT,  SCREEN_HEIG);
        
    }}
//------------------------------------------------
void enigmefinal(int *enigme1,int*gamestate, int ref,reponse *r,reponse *r2,reponse *r3,reponse *r4,int *next,int *frame,int* currentframeenigme,int* current_framereponse,int* current_framereponse2,int* current_framereponse3,int* current_framereponse4,SDL_Surface *screen,enigmme *e1,int *e1_stage,SDL_Surface **framesattend,SDL_Surface **framesnumber1,SDL_Surface **framesnumber2,SDL_Surface **framesnumber3,SDL_Surface **framesnumber4,SDL_Surface **framefinal){
if(*next==0){
e1->eni.x=0;
e1->eni.y=0;
aff_e(framesattend,e1_stage,screen,e1->eni);}
 if(*e1_stage==5){
 if(*next==1){
 ref=(*e1_stage)+1;
 aff_e(framesattend,&ref,screen,e1->eni);
  if(*current_framereponse>9){
 *frame=1;
 }
 *current_framereponse=*frame;
 r->r.x=SCREEN_WIDT/4+200;
 r->r.y=SCREEN_HEIG/2+110;
 aff_e(framesnumber1,current_framereponse,screen,r->r);
 }
  if(*next==2){
  ref=(*e1_stage)+2;
 aff_e(framesattend,&ref,screen,e1->eni);
  if(*current_framereponse2>9){
 *frame=1;
 }
  *current_framereponse2=*frame;
 r2->r.x=SCREEN_WIDT/4+270;
 r2->r.y=SCREEN_HEIG/2+110;
 
 aff_e(framesnumber1,current_framereponse,screen,r->r);
 aff_e(framesnumber2,current_framereponse2,screen,r2->r);
 
 }
 if(*next==3){
 ref=(*e1_stage)+3;
 aff_e(framesattend,&ref,screen,e1->eni);
 if(*current_framereponse3>9){
 *frame=1;
 }
  *current_framereponse3=*frame;
 r3->r.x=SCREEN_WIDT/4+340;
 r3->r.y=SCREEN_HEIG/2+110;
 
 aff_e(framesnumber1,current_framereponse,screen,r->r);
 aff_e(framesnumber2,current_framereponse2,screen,r2->r);
 aff_e(framesnumber3,current_framereponse3,screen,r3->r);
 
 }
   if(*next==4){
   ref=(*e1_stage)+4;
 *current_framereponse4=*frame;
 r4->r.x=SCREEN_WIDT/4+410;
 r4->r.y=SCREEN_HEIG/2+110;
 aff_e(framesattend,&ref,screen,e1->eni);
 aff_e(framesnumber1,current_framereponse,screen,r->r);
 aff_e(framesnumber2,current_framereponse2,screen,r2->r);
 aff_e(framesnumber3,current_framereponse3,screen,r3->r);
 aff_e(framesnumber4,current_framereponse4,screen,r4->r);
 if(*current_framereponse4>9){
 *frame=1;
 }
 

 }
 if(*next==5){
 if(*current_framereponse==1&&*current_framereponse2==8&&*current_framereponse3==7&&*current_framereponse4==3){
 *currentframeenigme=3;
 aff_e(framefinal,currentframeenigme,screen,e1->eni);
 *enigme1=1;
 *gamestate=1;
 }
 else{
 *currentframeenigme=4;
 aff_e(framefinal,currentframeenigme,screen,e1->eni);
 }}
 if(*next==6){
 
 *gamestate=1;
 
 }
 }
 }











