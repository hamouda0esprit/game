#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctionn.h"
#include "fonction.h"
 int SCREEN_W = 1920;
	int SCREEN_H =  1080;

// FONCTIONS OF STOP
//------------------------------------------------
void initialiser_imageBACK(image *imge,char dest[])
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
imge->pos_img_affiche.h=1080;
imge->pos_img_affiche.w=1920;
}
void loadanimationcaractere(int numframes ,SDL_Surface **frames,char dest[],int SCREEN_WIDTH, int SCREEN_HEIGHT){
for (int i = 0; i < numframes; i++) {
        char filename[20];
        sprintf(filename, dest, i);
        //frames[i] = load_image(filename);
        Resizecaractere(&(frames[i]), filename, SCREEN_WIDTH/10,  SCREEN_WIDTH/7+SCREEN_WIDTH/40);
        
    }

}

void Resizecaractere(SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT){
	SDL_Surface *Buffer = IMG_Load(dir);
	
	// Create the resized surface
	*(Image) = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, Buffer->format->BitsPerPixel, Buffer->format->Rmask, Buffer->format->Gmask,  Buffer->format->Bmask, Buffer->format->Amask);

	// Scale the original surface to the new size
	SDL_SoftStretch(Buffer, NULL, *(Image), NULL);
	
	SDL_FreeSurface(Buffer);
}


void update_and_render_animationcaractere(int rep,SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, Personn *p,int SCREEN_WIDTH,int SCREEN_HEIGHT ) {
    // calculate time since last frame
    Uint32 current_time = SDL_GetTicks();
    Uint32 time_since_last_frame = current_time - *last_frame_time;

    // update animation frame if enough time has elapsed
    if (time_since_last_frame >= 100) {
        (*current_frame)++;
        
        if (*current_frame == NUM_FRAMES) {
  				*current_frame = rep;
        } 
             *last_frame_time = current_time;
    }

       aff_e(frames,current_frame,screen,p->cor);
}
//------------------------------------------------
// FONCTIONS OF right
//------------------------------------------------

void player4(int *stopr,int *stopl,int* orientation,int *move,int* jump,int* dir,int* current_framess,Uint32* last_frame_time_stop_right,Uint32* last_frame_time_stop_left,Uint32* last_frame_time2,Uint32* last_frame_timess,Uint32* last_frame_timeleft ,Uint32* last_frame_timejump,int* current_framejump,int* current_frame_stop_right,int* current_frame_stop_left,int* current_frame2,int* current_frameleft,Personn *p,int* grav,int* velocity,int* stop,SDL_Surface *screen,SDL_Surface **frame_stop_right,SDL_Surface**frames_stop_left,SDL_Surface**framesright,SDL_Surface**framesleft,SDL_Surface**framesjump,SDL_Surface**framesss, int SCREEN_HEIGHT, int SCREEN_WIDTH){
const int NUM_FRAME_stop_right = 13;
const int NUM_FRAMES_stop_left = 13;
const int NUM_FRAMESright = 13; 
const int NUM_FRAMESleft = 13;
const int NUM_FRAMESss = 6; 
const int NUM_FRAMESjump = 6;


//-------------CONDITIONS FOR MOUVEMENTS------------------			
if((*stopr)==1&&(*stopl)==1){
(*stop)=1;
}
if((*stopr)==0&&(*stopl)==0){
(*stop)=0;
}
if((*stopr)!=(*stopl)){
(*stop)=0;
}
if((*stopl)==0 && (*dir)==2){
(*dir)=0;
}
if((*stopr)==0 && (*dir)==2){
(*dir)=1;
}
//--------------------------VELOCITY UP
 			if(p->cor.y<=(*grav)){
		     p->cor.y=p->cor.y+(*velocity);
		     if (p->cor.y!=(*grav)){
		     (*velocity)+=1;
		     }
		   } 
		   else{
		     p->cor.y=(*grav);
		     (*velocity)=0;
		     (*jump)=1;
		     }    
		    
			
	//-----------------------RIGHT AND lEFT------------------
				if((*dir)==1){
					//p->cor.x+=SCREEN_WIDTH/40;
					p->cor.x+=20;
					printf("test");}
				else if((*dir)==0){
					//p->cor.x-=SCREEN_WIDTH/40;
					p->cor.x-=20;}
	//-----------------------JUMP ANIMATION------------------
				if((*dir)==1 && (*jump) ==0&& (*velocity)!=0){
					     update_and_render_animationcaractere(0,screen, framesjump, current_framejump, last_frame_timejump, NUM_FRAMESss, p,SCREEN_W,SCREEN_H);      			
        		
        		}
        			 if((*stop)==1 &&(*jump)==0&&(*orientation)==0&& (*velocity)!=0){
        			 update_and_render_animationcaractere(0,screen, framesjump,current_framejump, last_frame_timejump, NUM_FRAMESss, p,SCREEN_W,SCREEN_H);   
        	
				} 
				 if((*stop)==1 &&(*jump)==0&&(*orientation)==1&&(*velocity)!=0){
				
        	update_and_render_animationcaractere(0,screen, framesss, current_framess, last_frame_timess, NUM_FRAMESss, p,SCREEN_W,SCREEN_H);
         	
				}
        		 if((*dir) ==0 && (*jump) ==0&&(*velocity)!=0){	
        		 		
        			update_and_render_animationcaractere(0,screen, framesss, current_framess, last_frame_timess, NUM_FRAMESss, p,SCREEN_W,SCREEN_H);  
        		}
			//-----------------------RIGHT AND LEFT AND STOP------------------	
				 if((*dir)==0 && (*velocity)==0){
							
        			        update_and_render_animationcaractere(4,screen, framesleft, current_frameleft, last_frame_timeleft, NUM_FRAMESleft, p,SCREEN_W,SCREEN_H);   	      
				}
				 if((*dir)==1 && (*velocity)==0){
						
        			    update_and_render_animationcaractere(4,screen, framesright, current_frame2, last_frame_time2, NUM_FRAMESright, p,SCREEN_W,SCREEN_H);   	
        		}
        		 if((*dir)==0 && (*velocity)!=0&& (*jump) ==1){
							
        			        update_and_render_animationcaractere(4,screen, framesleft, current_frameleft, last_frame_timeleft, NUM_FRAMESleft, p,SCREEN_W,SCREEN_H);   	      
				}
				 if((*dir)==1 && (*velocity)!=0&& (*jump) ==1){
						
        			    update_and_render_animationcaractere(4,screen, framesright, current_frame2, last_frame_time2, NUM_FRAMESright, p,SCREEN_W,SCREEN_H);   	
        		}
        		
			
				//----------------STOP CONDITION-----------------        		
       		 if ((*stop)==1 &&  (*orientation)==0&& (*velocity)==0&& (*dir)==2){
        	update_and_render_animationcaractere(0,screen, frame_stop_right, current_frame_stop_right, last_frame_time_stop_right, NUM_FRAME_stop_right, p,SCREEN_W,SCREEN_H);
        		}
        		if ((*stop)==1 &&  (*orientation)==0&& (*velocity)!=0&& (*dir)==2&& (*jump) ==1){
        	update_and_render_animationcaractere(0,screen, frame_stop_right, current_frame_stop_right, last_frame_time_stop_right, NUM_FRAME_stop_right, p,SCREEN_W,SCREEN_H);
        		}
       		if ((*stop)==1 && (*orientation)==1&& (*velocity)==0&& (*dir)==2){
      	update_and_render_animationcaractere(0,screen, frames_stop_left, current_frame_stop_left, last_frame_time_stop_left, NUM_FRAMES_stop_left, p,SCREEN_W,SCREEN_H);
        		}
        		if ((*stop)==1 && (*orientation)==1&& (*velocity)!=0&& (*dir)==2&& (*jump) ==1){
      	update_and_render_animationcaractere(0,screen, frames_stop_left, current_frame_stop_left, last_frame_time_stop_left, NUM_FRAMES_stop_left, p,SCREEN_W,SCREEN_H);
        		}
        		
        		
        		}
