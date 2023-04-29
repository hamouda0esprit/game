#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctionn.h"
 int FRAME_DELAY = 100;
void loadanimation(int numframes ,SDL_Surface **frames,char dest[],int SCREEN_WIDTH, int SCREEN_HEIGHT){
for (int i = 0; i < numframes; i++) {
        char filename[20];
        sprintf(filename, dest, i);
        //frames[i] = load_image(filename);
        Resize(&(frames[i]), filename, SCREEN_WIDTH/3, SCREEN_HEIGHT/1.4);
        
    }

}

SDL_Surface* load_image(const char* filename) {
    SDL_Surface* image = NULL;
    //SDL_Surface* optimized = NULL;

    image = IMG_Load(filename);
    /*if (image != NULL) {
        // Set the color key for transparency
        Uint32 colorkey = SDL_MapRGB(image->format, 0, 0xFF, 0xFF);
        SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorkey);

        optimized = SDL_DisplayFormatAlpha(image);
        SDL_FreeSurface(image);
    }*/

    //return optimized;
    return image;
}
// FONCTIONS OF STOP
//------------------------------------------------
void clear_animation(SDL_Surface **frames, int num_frames) {
    // free animation frames
    for (int i = 0; i < num_frames; i++) {
        SDL_FreeSurface(frames[i]);
    }
    free(frames);
}
//------------------------------------------------
// FONCTIONS OF right
//------------------------------------------------



void update_and_render_animation(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, Personn *p,int move,int SCREEN_WIDTH,int SCREEN_HEIGHT ) {
    // calculate time since last frame
    Uint32 current_time = SDL_GetTicks();
    Uint32 time_since_last_frame = current_time - *last_frame_time;

    // update animation frame if enough time has elapsed
    if (time_since_last_frame >= FRAME_DELAY) {
        (*current_frame)++;
        
        if (*current_frame == NUM_FRAMES) {
        if(move == 1){
            *current_frame = 4;}
        else if(move == 0) {
  				*current_frame = 0;}
        } 
             *last_frame_time = current_time;
    }
    

    SDL_BlitSurface(frames[*current_frame], NULL, screen, &p->R);
    SDL_Flip(screen);
}
void Resize(SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT){
	SDL_Surface *Buffer = IMG_Load(dir);
	
	// Create the resized surface
	*(Image) = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, Buffer->format->BitsPerPixel, Buffer->format->Rmask, Buffer->format->Gmask,  Buffer->format->Bmask, Buffer->format->Amask);

	// Scale the original surface to the new size
	SDL_SoftStretch(Buffer, NULL, *(Image), NULL);
	
	SDL_FreeSurface(Buffer);
}

/*void player(Personn *p,int SCREEN_HEIGHT, int* velocity,int* jump ,int* stop ,int* dir,SDL_Surface** frames,SDL_Surface** framesl,SDL_Surface** framesright,SDL_Surface** framesleft,SDL_Surface** framesjump,SDL_Surface *screen,int NUM_FRAMESstopleft,int NUM_FRAMESstopright, int NUM_FRAMESright,int NUM_FRAMESleft,int NUM_FRAMESjump,int* orientation,int* move ,int* current_framestopright,int* current_framestopleft,int* current_frame2,int* current_frameleft,int* current_framejump,Uint32* last_frame_timestopright,Uint32* last_frame_timestopleft,Uint32* last_frame_time2 , Uint32* last_frame_timeleft,Uint32* last_frame_timejump){



			if(p->R.y<=400){
		     (p->R.y)=(p->R.y)+(*velocity);
		     if (p->R.y<400){
		     	(*velocity)+=1;
		     }
		   } 
		     else{
		     p->R.y=400;
		     *velocity=0;
		     }    
		     
			if((*jump)==0){
			
				if(p->dir==1){
					(p->R.x)+=4;
				}else if(p->dir ==0){
					(p->R.x)-=4;
				}
				update_and_render_animation(screen, framesjump, current_framejump, last_frame_timejump, NUM_FRAMESjump, p,*move,SCREEN_WIDTH,SCREEN_HEIGHT);
			
			if((*current_framejump)>=5){
			(*jump)=1;
			}
			
			}
			else{
			if(p->dir==1 && *stop ==0){
						update_and_render_animation(screen, framesright, current_frame2, last_frame_time2, NUM_FRAMESright, p,*move,SCREEN_WIDTH,SCREEN_HEIGHT);
			
         (p->R.x)=(p->R.x)+4;
			
			}
			else if(p->dir==0 && *stop ==0){
			update_and_render_animation(screen, framesleft, current_frameleft, last_frame_timeleft, NUM_FRAMESleft, p,*move,SCREEN_WIDTH,SCREEN_HEIGHT);
			
         (p->R.x)=(p->R.x)-4;
			}
			       		
       else if (*stop==1 && p->dir==0){
       update_and_render_animation(screen, frames, current_framestopright, last_frame_timestopright, NUM_FRAMESstopright, p,*move,SCREEN_WIDTH,SCREEN_HEIGHT);
        
        }
          else if (*stop==1 && p->dir==1){
          update_and_render_animation(screen, framesl, current_framestopleft, last_frame_timestopleft, NUM_FRAMESstopleft, p,*move,SCREEN_WIDTH,SCREEN_HEIGHT);
        
        }}
}*/
