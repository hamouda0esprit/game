#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctionn.h"
#include "arduino.h"
#define SERIAL_PORT "/dev/ttyACM0"
#define SCREEN_W 1710
#define SCREEN_H 962
#define SERIAL_PORT_BUFFER_LENGTH   20

int main(int argc, char* argv[])
{
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

Uint32 last_frame_timejump2 = 0;
int current_framejump2 = 0;
int orientation2=0,xm2=100,ym2,jump2=1,dir2=2,velocity2,stop2=1,verif2,grav2=700,hit2=0;
Personn p2;
bullet b2;
p2.cor.x=100;
p2.cor.y=grav2;
//----------------------------------------------------------------------------------
//REST OF PROGRAM
int orientation=0,xm=100,ym,jump=1,dir=2,velocity,stop=1,verif,grav=700,hit=0;
int boucle=1;
SDL_Event event;
SDL_Surface *screen;
Personn p;
image imge;
bullet b;
p.cor.x=100;
p.cor.y=grav;
SDL_Surface* frames[NUM_FRAMES],*framesl[NUM_FRAMESl],*framesright[NUM_FRAMESright],*framesleft[NUM_FRAMESleft],*framesjump[NUM_FRAMESjump],*framesss[NUM_FRAMESss];  
 char serialPortBuffer[SERIAL_PORT_BUFFER_LENGTH] = {0};
    int serialPortReadDataLength = 0;   
  /*if(!Arduino_connect(SERIAL_PORT, 9600))
        exit(EXIT_FAILURE);  */
if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}

screen=SDL_SetVideoMode(SCREEN_W, SCREEN_H, 0,SDL_RESIZABLE);


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
while(boucle)
{
init_bullet(&b);
init_bullet(&b2);
afficher_image(screen,imge);
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
                       
                       
							}
			
            
                    if (event.key.keysym.sym == SDLK_LEFT) {
                        dir=0; 
                    }
                    if (event.key.keysym.sym == SDLK_UP) {
                        jump=0;
                        if(p.cor.y==grav)
                        velocity=-14;
                              } 
                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        b.pos.x=p.cor.x+100;
                        b.pos.y=p.cor.y+150;
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
if(hit==1){
			affbullet(screen,&b);
			SDL_FreeSurface(b.image);
			}
else if(hit2==1){
			affbullet(screen,&b2);
			SDL_FreeSurface(b2.image);
			}

serialPortReadDataLength = Arduino_read(serialPortBuffer, SERIAL_PORT_BUFFER_LENGTH);
serialPortBuffer[serialPortReadDataLength] = 0;
	if(serialPortReadDataLength > 0)
        {
            if(strStartsWith("f", serialPortBuffer))
            {dir=0; 
                 
            }
            if(strStartsWith("h", serialPortBuffer))
            {b.pos.x=p.cor.x+100;
                        b.pos.y=p.cor.y+70;
            hit=1; 
                 
            }
            if(strStartsWith("b", serialPortBuffer))
            {
             dir=1;
            }
            if(strStartsWith("r", serialPortBuffer))
            {
                jump=0;
                if(p.cor.y==grav)
                velocity=-14;
                              
            }
            if(strStartsWith("s", serialPortBuffer))
            {
               dir=2;
               stop=1;
               jump=1;
          
            }
            
        }
			
	/*		 if(p.cor.y<=grav){
		     p.cor.y=p.cor.y+velocity;
		     if (p.cor.y!=grav){
		     	velocity+=1;
		     }
		   } 
		     else{
		     p.cor.y=grav;
		     velocity=0;
		     }    
		    // JUMP CONDITION
			if(!jump){
			
				if(dir==1){
					p.cor.x+=9;
					update_animation(&current_framejump, &last_frame_timejump, NUM_FRAMESss);
        	render_animationright(screen, framesjump, current_framejump, p.cor.x, p.cor.y);
				}else if(dir ==0){
					p.cor.x-=9;
					update_animation(&current_framess, &last_frame_timess, NUM_FRAMESss);
        	render_animationright(screen, framesss, current_framess, p.cor.x, p.cor.y);
				}
				if 	(current_framess==5 || current_framejump==5){
				jump=1;
				}	
			}
			else if(jump==1){
			if(dir==1 && stop ==0){
		update_animationright(&current_frame2, &last_frame_time2,NUM_FRAMESright);
        render_animationright(screen, framesright, current_frame2,p.cor.x,p.cor.y);
        p.cor.x=(p.cor.x)+9;
        
			
			}
			else if(dir==0 && stop ==0){
			update_animationright(&current_frameleft, &last_frame_timeleft,NUM_FRAMESleft);
        render_animationright(screen, framesleft, current_frameleft,p.cor.x,p.cor.y);
         p.cor.x=(p.cor.x)-9;
        
			}
			       		
       else if (stop==1 && dir==1){
        update_animation(&current_frame, &last_frame_time,NUM_FRAMES);
        render_animation(screen, frames, current_frame,p.cor.x,p.cor.y);
        }
          else if (stop==1 && dir==0){
        update_animation(&current_framel, &last_frame_timel,NUM_FRAMESl);
        render_animation(screen, framesl, current_framel,p.cor.x,p.cor.y);
        }}
        
*/player4(&orientation,&jump,&dir,&current_framess,&last_frame_time_stop_right,&last_frame_time_stop_left,&last_frame_time3,&last_frame_timess,&last_frame_timeleft ,&last_frame_timejump,&current_framejump,&current_frame,&current_framel,&current_frame3,&current_frameleft,&p,&grav,&velocity,&stop,screen,frames,framesl,framesright,framesleft,framesjump,framesss);
player4(&orientation2,&jump2,&dir2,&current_framess2,&last_frame_time_stop_right2,&last_frame_time_stop_left2,&last_frame_time22,&last_frame_timess2,&last_frame_timeleft2 ,&last_frame_timejump2,&current_framejump2,&current_frame2,&current_framel2,&current_frame22,&current_frameleft2,&p2,&grav2,&velocity2,&stop2,screen,frames,framesl,framesright,framesleft,framesjump,framesss);
SDL_Flip(screen);
SDL_Delay(10);
}

 Arduino_disconnect();

    return EXIT_SUCCESS;
}
