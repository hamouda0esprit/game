#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include "fonctionn.h"
#include "background.h" 

int main()
{background bg;
	int SCREEN_WIDTH = 800;
	int SCREEN_HEIGHT =  (float)(SCREEN_WIDTH / 1.7777777777777777);
	
		//Animation
	char ch[20];
	int anim_frame=0;
	int anim_frame_time=0;
	int trigger;
	Uint32 move_interval = 5;
	Uint32 last_move_time = SDL_GetTicks();
	int game_ended=0;
	int g_e_a=0;
	player_2 P2;
	button B1;
	initButton(&B1, SCREEN_WIDTH);
	int Button_Clicked=0;
// NUMBER OF FRAMES OF MOUVEMENTS

//stopright
int NUM_FRAMESstopright = 13;
Uint32 last_frame_timestopright = 0;
int current_framestopright = 0;

//stopleft
int NUM_FRAMESstopleft = 13;;
Uint32 last_frame_timestopleft  = 0;
int current_framestopleft  = 0;

//right
int NUM_FRAMESright = 13; 
Uint32 last_frame_time2 = 0;
int current_frame2 = 3;

//left
int NUM_FRAMESleft = 13;
Uint32 last_frame_timeleft = 0;
int current_frameleft = 3;

//jump
int NUM_FRAMESjump = 6;
Uint32 last_frame_timejump = 0;
int current_framejump = 0;

int orientation,jump=1,dir=2,velocity=-14,stop=1,right=0,left=0;
int boucle=1,move=0;
SDL_Event event;
SDL_Surface *screen;

image IMAGE;
SDL_Surface* frames[NUM_FRAMESstopright],*framesl[NUM_FRAMESstopleft],*framesright[NUM_FRAMESright],*framesleft[NUM_FRAMESleft],*framesjump[NUM_FRAMESjump];
Personn p; 
p.dir=0;   
    
if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}
screen= SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
Uint32 color = SDL_MapRGB(screen->format, 255, 0, 0);
//LOADING PICTURES 
   loadanimation(NUM_FRAMESstopleft,frames,"stopr/stopr%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
   loadanimation(NUM_FRAMESstopright,framesl,"stopl/stopl%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
   loadanimation(NUM_FRAMESright,framesright,"right/right%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
   loadanimation(NUM_FRAMESleft,framesleft,"left/left%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
   loadanimation(NUM_FRAMESjump,framesjump,"jump/jump%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
p.R.y=100;
while(boucle)
{

while(SDL_PollEvent(&event))
{
	switch(event.type)
	{
		case SDL_QUIT:
		boucle=0;
		break;
	    case SDL_KEYDOWN:
							 if(event.key.keysym.sym == SDLK_a){
										printf("\nGAME ENDED !\n");
										game_ended=1;
									}
                    if (event.key.keysym.sym == SDLK_RIGHT) {
                       dir=1; 
                       stop=0;
                       right=1;
                   		move=1;
                       
							}
			
            
                    else if (event.key.keysym.sym == SDLK_LEFT) {
                        dir=0;
                        stop=0;
                        left=1;
                        move=1;
                        
                    }
                    else if (event.key.keysym.sym == SDLK_UP) {
                        jump=0;
                        if(p.R.y+p.R.h>=SCREEN_HEIGHT*.97){
                        
                        velocity=-14;}
                        
                    }
                    break;
        case SDL_KEYUP:
                    if (event.key.keysym.sym == SDLK_RIGHT) {
                    		right=0;
                    
                    if(left==0){
                    		move=0;
                        stop=1;
                        p.dir=0;}  
                    }
                    else   if (event.key.keysym.sym == SDLK_LEFT) {
                    		left=0;
                    
                     if(right==0){
                     	move=0;
                        stop=1;
                        p.dir=1;        }
                    }
                    
                    break;
               
						
		                    
		     
}}
                        
                
run_game(&bg, &P2, &B1, &(p.R), screen, SCREEN_WIDTH, SCREEN_HEIGHT, color, &g_e_a, &anim_frame, &anim_frame_time, move_interval, last_move_time, &game_ended, &trigger);
		p.R.w = SCREEN_WIDTH/3;
    	p.R.h = SCREEN_HEIGHT/1.5;
			if(p.R.y + p.R.h<=SCREEN_HEIGHT*.96){
		     p.R.y=p.R.y+velocity;
		     
		     	velocity+=1;
		     
		   } 
		     else{
		     p.R.y=SCREEN_HEIGHT*.96-p.R.h;
		     velocity=0;
		     }    
		     printf("\nvelocity = %d",velocity);
			if(!jump){
			
				if(dir==1){
					p.R.x+=4;
				}else if(dir ==0){
					p.R.x-=4;
				}
				update_and_render_animation(screen, framesjump, &current_framejump, &last_frame_timejump, NUM_FRAMESjump, &p,move,SCREEN_WIDTH,SCREEN_HEIGHT);
			
			if(current_framejump>=5){
			jump=1;
			}
			
			}
			else{
			if(dir==1 && stop ==0){
						update_and_render_animation(screen, framesright, &current_frame2, &last_frame_time2, NUM_FRAMESright, &p,move,SCREEN_WIDTH,SCREEN_HEIGHT);
			
         (p.R.x)=(p.R.x)+4;
			
			}
			else if(dir==0 && stop ==0){
			update_and_render_animation(screen, framesleft, &current_frameleft, &last_frame_timeleft, NUM_FRAMESleft, &p,move,SCREEN_WIDTH,SCREEN_HEIGHT);
         (p.R.x)=(p.R.x)-4;
			}
			       		
       else if (stop==1 && p.dir==0){
       update_and_render_animation(screen, frames, &current_framestopright, &last_frame_timestopright, NUM_FRAMESstopright, &p,move,SCREEN_WIDTH,SCREEN_HEIGHT);
        
        }
          else if (stop==1 && p.dir==1){
          update_and_render_animation(screen, framesl, &current_framestopleft, &last_frame_timestopleft, NUM_FRAMESstopleft, &p,move,SCREEN_WIDTH,SCREEN_HEIGHT);
        
        }}
printf("\n trigger : %d", trigger);
SDL_Flip(screen);
SDL_Delay(5);
SDL_FreeSurface(bg.S);
}

return 0;
}
