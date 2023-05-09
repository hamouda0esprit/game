#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctionn.h"
#include "fonction.h"
#include "fonction.c"
#define HEALTHBAR_WIDTH 300
#define HEALTHBAR_HEIGHT 30
#define SCORE_POSITION_X 10
#define SCORE_POSITION_Y 10


#define SCREEN_W 1710
#define SCREEN_H 962


int main(int argc, char* argv[])
{

//---------------------------------------------------

bullet b1;

SDL_Rect dest;

int i,bigx,bigy;
int hitt=0;

int movex=1000;
Ennemi e;
e.direction=0;
int ok=0;
dest.x=1000;
dest.y=700;



Uint32 last_frame_time1 = 0;
int current_frame1 = 0;
int current_framel1 = 0;
Uint32 last_frame_time21 = 0;
int current_frame21 = 3;
Uint32 last_frame_timeleft1 = 0;
int current_frameleft1 = 3;


e.vie=3;
e.STATE=0;








//--------------------------------------------------------------

// NUMBER OF FRAMES OF MOUVEMENTS

//stop
const int NUM_FRAMES = 13;
	Uint32 last_frame_time_stop_right = 0;
    int current_frame = 0;
    const int NUM_FRAMESl = 13;
	Uint32 last_frame_time_stop_left = 0;
    int current_framel = 0;
//right
const int NUM_FRAMESright = 13; 
Uint32 last_frame_time3 = 0;
    int current_frame3 = 3;
    const int NUM_FRAMESss = 6; 
Uint32 last_frame_timess = 0;
    int current_framess = 3;
//left
const int NUM_FRAMESleft = 13;
Uint32 last_frame_timeleft = 0;
int current_frameleft = 3;
//jump
const int NUM_FRAMESjump = 6;
Uint32 last_frame_timejump = 0;
int current_framejump = 0;
//---------------------------------PLAYER 2----------------------------------------
//stop

	Uint32 last_frame_time_stop_right2 = 0;
    int current_frame2 = 0;
   
	Uint32 last_frame_time_stop_left2 = 0;
    int current_framel2 = 0;
//right

Uint32 last_frame_time22 = 0;
    int current_frame22 = 3;
   
Uint32 last_frame_timess2 = 0;
    int current_framess2 = 3;
//left
Uint32 last_frame_timeleft2 = 0;
int current_frameleft2 = 3;
//jump
int hitenemy=0;;
Uint32 last_frame_timejump2 = 0;
int current_framejump2 = 0;
int orientation2=0,xm2=100,ym2,jump2=1,dir2=2,velocity2,stop2=1,verif2,grav2=700,hit2=0;
Personn p2;
bullett b2;
p2.cor.x=100;
p2.cor.y=grav2;
//----------------------------------------------------------------------------------
//REST OF PROGRAM
int orientation=0,verif=0,jump=1,dir=2,velocity,stop=1,grav=700,hit=0;
int boucle=1;
int bigx2;
SDL_Event event;
SDL_Surface *screen;
Personn p;
image imge;
bullett b;
p.cor.x=100;
p.cor.y=grav;
SDL_Surface* frames[NUM_FRAMES],*framesl[NUM_FRAMESl],*framesright[NUM_FRAMESright],*framesleft[NUM_FRAMESleft],*framesjump[NUM_FRAMESjump],*framesss[NUM_FRAMESss];  
 
  /*if(!Arduino_connect(SERIAL_PORT, 9600))
        exit(EXIT_FAILURE);  */
if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}

screen=SDL_SetVideoMode(SCREEN_W, SCREEN_H, 0,SDL_RESIZABLE);
//-------------ennemi----------------------------

   int y=0;
   int x;
    

//----------------------------------------------------------------
/*DECLARATION OF ANIMATIONS
-----------------------------
stop
*/
   for (int i = 0; i < NUM_FRAMES; i++) {
        char filename[20];
        sprintf(filename, "stopr/stopr%d.png", i);
        frames[i] = load_image(filename);
    }
    for (int i = 0; i < NUM_FRAMESss; i++) {
        char filename[20];
        sprintf(filename, "stopp/stopaa%d.png", i);
        framesss[i] = load_image(filename);
    }
       for (int i = 0; i < NUM_FRAMESl; i++) {
        char filename[20];
        sprintf(filename, "stopl/stopl%d.png", i);
        framesl[i] = load_image(filename);
    }
// RIGHT
      for (int i = 0; i < NUM_FRAMESright; i++) {
        char filename[20];
        sprintf(filename, "right/right%d.png", i);
        framesright[i] = load_image(filename);
    }   
// LEFT 
      for (int i = 0; i < NUM_FRAMESleft; i++) {
        char filename[20];
        sprintf(filename, "left/left%d.png", i);
        framesleft[i] = load_image(filename);
    }
//jump
   for (int i = 0; i < NUM_FRAMESjump; i++) {
        char filename[20];
        sprintf(filename, "jump/jump%d.png", i);
        framesjump[i] = load_image(filename);
    }
initialiser_imageBACK(&imge,"1.png");
init_ennemi(&e, NUM_FRAMES, frames,framesl,framesright,framesleft);
init_bullet(&b1);
init_bullet(&b2);
while(boucle)
{
afficher_image(screen,imge);
//----------------------------------------------------
x = collisionBB(dest,b1.pos);



//---------------------------------------------
while(SDL_PollEvent(&event))
{
	switch(event.type)
	{
		case SDL_QUIT:
		boucle=0;
		break;
	    case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_RIGHT) {    
                       dir=1; 
                       stop=0;
            }
                    if (event.key.keysym.sym == SDLK_LEFT) {
                        dir=0; 
                        stop=0;
                    }
                    if (event.key.keysym.sym == SDLK_UP) {
                        jump=0;
                        if(p.cor.y==grav)
                        velocity=-14;
                              } 
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        b1.pos.x=p.cor.x+100;
                        b1.pos.y=p.cor.y+100;
                        bigx= b1.pos.x;
                        hit=1; }  
                    if (event.key.keysym.sym == SDLK_d) {
                       dir2=1; 
                       }
			
            
                    if (event.key.keysym.sym == SDLK_q) {
                        dir2=0; 
                    }
                    if (event.key.keysym.sym == SDLK_z) {
                        jump2=0;
                        if(p2.cor.y==grav2)
                        velocity2=-14;
                              } 
                    if (event.key.keysym.sym == SDLK_f) {
                        b2.pos.x=p2.cor.x+100;
                        b2.pos.y=p2.cor.y+150;
                        
                        hit2=1; }                            
                    break;
                 
        case SDL_KEYUP:
                    if (event.key.keysym.sym == SDLK_RIGHT) {
                        orientation=0;
                        dir=2;
                        stop=1;
                         
                    }
                    if (event.key.keysym.sym == SDLK_LEFT) {
                        orientation=1;
                        dir=2;
                        stop=1;
                        
                   }
                    if (event.key.keysym.sym == SDLK_UP) {
                        jump=1;
                      
                  }
                  if (event.key.keysym.sym == SDLK_d) {
                        orientation2=0;
                        dir2=2;
                        stop2=1;
                         
                    }
                    if (event.key.keysym.sym == SDLK_q) {
                        orientation2=1;
                        dir2=2;
                        stop2=1;
                        
                   }
                    if (event.key.keysym.sym == SDLK_z) {
                        jump2=1;
                      
                  }
                   
                    break;
		                    
		     
}}
//----------------------BULLET----------------- SHOOT    
if(hit==1&&b1.pos.x<bigx+300 &&b1.pos.x<dest.x+70){
			affbullet(screen,&b1);
	}		
if(hitenemy==1){
			affbullet(screen,&b2);
			verif=0;
	}		
	//----------------------mouvement----------------- PLAYER      	
	player4(&orientation,&jump,&dir,&current_framess,&last_frame_time_stop_right,&last_frame_time_stop_left,&last_frame_time3,&last_frame_timess,&last_frame_timeleft ,&last_frame_timejump,&current_framejump,&current_frame,&current_framel,&current_frame3,&current_frameleft,&p,&grav,&velocity,&stop,screen,frames,framesl,framesright,framesleft,framesjump,framesss);///player4(&orientation2,&jump2,&dir2,&current_framess2,&last_frame_time_stop_right2,&last_frame_time_stop_left2,&last_frame_time22,&last_frame_timess2,&last_frame_timeleft2 ,&last_frame_timejump2,&current_framejump2,&current_frame2,&current_framel2,&current_frame22,&current_frameleft2,&p2,&grav2,&velocity2,&stop2,screen,frames,framesl,framesright,framesleft,framesjump,framesss);
 
     //----------------------COLLISION----------------- carac / ENEMY 
     if(x==0){
      	y = collisionBB(dest,b1.pos);
     
      	}
      if(x!=y){
     		 e.vie--;
     		 y=1;
 //----------------------mouvement----------------- ENEMY      	
      }  
IA(&e, &p,&dest,&b1);
if(e.STATE!=6){
   if(e.STATE==0)       { move_waiting(&movex,screen,frames,framesl,framesleft,framesright,NUM_FRAMES,&ok,&e,&dest,&current_frame1, &current_framel1,&last_frame_time1,&current_frameleft1,&last_frame_timeleft1,&current_frame21,&last_frame_time21);
    }
       if(e.STATE==1)
      {e.direction=1;
      move_following(screen, framesright, &current_frame21, &last_frame_time21,NUM_FRAMES,&dest,p.cor,&e);
      if(dest.x-p.cor.x<=-200){
          e.STATE=0;
          movex=dest.x;}
 }
   if(e.STATE==4)
      {e.direction=-1;
      move_following(screen, framesleft, &current_frameleft1, &last_frame_timeleft1,NUM_FRAMES,&dest,p.cor,&e);
      if(dest.x-p.cor.x>=200){
          e.STATE=0;
          movex=dest.x+200;}
 }
 if(e.STATE==5)
 {dest=animate_place(screen,frames,&current_frame1, &last_frame_time1,NUM_FRAMES,dest.x,dest.y);
 hitenemy=1;
 if (verif==0){
 b2.pos.x=dest.x+100;
 b2.pos.y=dest.y+100;
 verif=1;
 }}}
 

SDL_Flip(screen);

SDL_Delay(10);
}



    return EXIT_SUCCESS;
}
