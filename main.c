#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "lot5.h"
#define SCREEN_W 1920
#define SCREEN_H 1080
#include <time.h>

int main()
{
int NUM_FRAMES = 3;
Uint32 last_frame_time = 0;
int current_frame = 0;
int verif=1,verif2=2;
int boucle=1;
SDL_Event event;
SDL_Surface* frames[NUM_FRAMES];
SDL_Surface *screen, *image1, *image2, *image3;
image IMAGE;
enigme e;
reponse r; 
srand(time(0));
int alea=rand()%(2) +1;
if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}
screen=SDL_SetVideoMode(SCREEN_W, SCREEN_H, 0,SDL_RESIZABLE);
initialiser_image_enigme(&e.i,"back_1.png");
int i=0,j=1,next=1;
// uplaod aniamtion  
for (int k = 0; k < NUM_FRAMES; k++) {
        char filename[20];
        sprintf(filename, "win%d.png", k);
        frames[k] = IMG_Load(filename);
    }
// deuxieme chiifre
    image2 = IMG_Load("1.png");
	SDL_Rect dest_rect2;
    dest_rect2.x = 60;
    dest_rect2.y = 0;
//riddle aleatoire
if (alea == 1){
initialiser_image_enigme(&e.i,"back_1.png");}
else if (alea ==2){
initialiser_image_enigme(&e.i,"back_3.png");
}
else{
initialiser_image_enigme(&e.i,"back_5.png");}
SDL_BlitSurface(image2, NULL, screen, &dest_rect2);
int num1=1;
int num2=2;



  
while(boucle)
{
afficherEnigme(e,screen);
afficherreponse(r,screen);

if(verif==0){SDL_BlitSurface(image2, NULL, screen, &dest_rect2);}
while(SDL_PollEvent(&event))
{
	switch(event.type)
	{
		case SDL_QUIT:
		boucle=0;
		break;
	
        case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT && event.button.x > SCREEN_W/2+300 && event.button.y > SCREEN_H/4-50 && event.button.x < SCREEN_W/2+400 && event.button.y < SCREEN_H/4+50 )
                    {
                        initialiser_image_enigme(&e.i,"back_2.png");
			next++;}

			
                         if (event.button.button == SDL_BUTTON_LEFT && event.button.x > 650 && event.button.y > 500 && event.button.x < 700 && event.button.y < 550 )
                    {


                      

                         
                    }
                    if (event.button.button == SDL_BUTTON_LEFT && event.button.x > 500 && event.button.y > 300 && event.button.x <700  && event.button.y < 500 )
                    {
                        //boucle=0;
			if (next==1){
			i++;
			if(i>3 ){
			i=1;}
			char filename[20];
        		sprintf(filename, "%d.png", i);
  			initialiser_image_reponse(&r.r,filename);}
			if (next==2){
			j++;
			if(j>3)
			j=1;
			char filename2[20];
        		sprintf(filename2, "%d.png", j);
			image2 = IMG_Load(filename2);
  			SDL_BlitSurface(image2, NULL, screen, &dest_rect2);
verif=0;
verif2=1;}}
                    break;
        
		                    
		     
}}		// afficher animation wi	
		if (next == 3 && j==num2 && i ==num1){
animation(screen, frames, &current_frame, &last_frame_time,NUM_FRAMES);}
		
/*if (verif2<2){
int alea=rand()%(2) +1;
if (alea == 1){
initialiser_image_enigme(&e.i,"back_1.png");}
else if (alea ==2){
initialiser_image_enigme(&e.i,"back_3.png");
}
else{
initialiser_image_enigme(&e.i,"back_5.png");}
verif2=2;}}*/


		

SDL_Flip(screen);
SDL_Delay(10);}

return 0;
}

