#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"
#define HEALTHBAR_WIDTH 300
#define HEALTHBAR_HEIGHT 30
#define SCORE_POSITION_X 10
#define SCORE_POSITION_Y 10

int main()
{
bullet b;
int SCREEN_W = 640;
int SCREEN_H = (SCREEN_W/1.77777777777777777777);
SDL_Rect dest;

int i,bigx,bigy;
int hit=0;
int boucle=1;
SDL_Event event;
SDL_Surface *screen;
image IMAGE;
Ennemi e;
e.direction=0;
int ok=0;
int xm=100,ym=100;

const int NUM_FRAMES = 13;
Uint32 last_frame_time = 0;
int current_frame = 0;
int current_framel = 0;
Uint32 last_frame_time2 = 0;
int current_frame2 = 3;
Uint32 last_frame_timeleft = 0;
int current_frameleft = 3;

bool running = true;
 bool moving_left = false;
 bool moving_right = false;

screen=SDL_SetVideoMode(SCREEN_W, SCREEN_H, 0,SDL_RESIZABLE);
SDL_Surface* frames[NUM_FRAMES],* framesl[NUM_FRAMES],*framesright[NUM_FRAMES],*framesleft[NUM_FRAMES];

if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}


SDL_Surface * player = NULL;
    SDL_Rect jr = {500, 150, 50, 100};
plyr p;
p.jr = jr;
p.player = player;
p.STATE=0;
p.vie=3;
e.vie=3;
e.STATE=0;
 

initialiser_imageBACK(&IMAGE,"final.jpg");
init_ennemi(&e, NUM_FRAMES, frames,framesl,framesright,framesleft);



p.player = IMG_Load("player.png");
 SDL_BlitSurface(p.player, NULL, screen, &p.jr);

   
while(boucle)
{
init_bullet(&b);
afficher_image(screen,IMAGE);
afficherEnnemi(e,screen);
SDL_BlitSurface(p.player, NULL, screen, &p.jr);
       
       
       IA(&e, &p,&dest);
   if(e.STATE==0)       {move_waiting(screen,frames,framesl,framesleft,framesright,NUM_FRAMES,&xm,ym,&ok,&e,&dest,&current_frame,&last_frame_time,&current_frameleft,&last_frame_timeleft,&current_frame2,&last_frame_time2);
    }
       if(e.STATE==1)
      {e.direction=1;
      move_following(screen, framesright, &current_frame2, &last_frame_time2,NUM_FRAMES,&xm,ym,&dest,p.jr,&e);
 }
   if(e.STATE==4)
      {e.direction=-1;
      move_following(screen, framesleft, &current_frameleft, &last_frame_timeleft,NUM_FRAMES,&xm,ym,&dest,p.jr,&e);
 }
    if(e.STATE==5)       {
                         b.pos.x=p.jr.x+20;
                          b.pos.y=p.jr.y+30;
                         hit=1;
                          
    dest = animate_place(screen, frames, &current_frame, &last_frame_time, NUM_FRAMES, xm, ym);
    }
 printf("%d \n",e.STATE);
 printf("%d \n %d",dest.x,p.jr.x);
       
while(SDL_PollEvent(&event))
{
	switch(event.type)
	{
		case SDL_QUIT:
		boucle=0;
		break;
		 case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_q && p.jr.x + 50 +  p.jr.w >= 0){
                        moving_left = true;
                    }
                    if(event.key.keysym.sym == SDLK_d &&  p.jr.x + 50 +  p.jr.w <= 640){
                        moving_right = true;
                    }
                     if(event.key.keysym.sym == SDLK_SPACE ){
                           b.pos.x=p.jr.x+20;
                          b.pos.y=p.jr.y+30;
                          bigx= b.pos.x;
                         hit=1;
                        }
                    break;
                case SDL_KEYUP:
                    if(event.key.keysym.sym == SDLK_q){
                        moving_left = false;
                    }
                    if(event.key.keysym.sym == SDLK_d){
                        moving_right = false;
                    }
		
       }


} if(hit==1&&  b.pos.x<bigx+200)
        {affbullet(screen,&b);
        }
if(moving_left &&  p.jr.x + 10 +  p.jr.w >= 0){
            p.jr.x -= 10;  
        }
        
        if(moving_right &&  p.jr.x +10+  p.jr.w <= 640){
            p.jr.x += 10;  
        }
        
       
        SDL_BlitSurface(p.player, NULL, screen, &p.jr);
       // printf("collision = %d \n",collisionBB(p.jr,dest));
        
        
//SDL_Flip(screen);
SDL_Delay(10);}
return 0;
}

