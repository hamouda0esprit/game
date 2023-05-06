#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_W 1710
#define SCREEN_H 962
#include "fonctionn.h"

  const int NUM_FRAMES = 13; // number of animation frames
	const int FRAME_DELAY = 50;
	const int NUM_FRAMESright = 11; // number of animation frames
	const int FRAME_DELAYright = 50;
	const int NUM_FRAMESleft = 11; // number of animation frames
	const int FRAME_DELAYleft = 50;
	int strStartsWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}
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
imge->pos_img_affiche.h=SCREEN_H;
imge->pos_img_affiche.w=SCREEN_W;
}
void afficher_image(SDL_Surface *screen, image imge)
{
SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);

}
SDL_Surface* load_image(const char* filename) {
    SDL_Surface* image = NULL;
    SDL_Surface* optimized = NULL;

    image = IMG_Load(filename);
    if (image != NULL) {
        // Set the color key for transparency
        Uint32 colorkey = SDL_MapRGB(image->format, 0, 0xFF, 0xFF);
        SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorkey);

        optimized = SDL_DisplayFormatAlpha(image);
        SDL_FreeSurface(image);
    }

    return optimized;
}
// FONCTIONS OF STOP
//------------------------------------------------
void update_animation(int *current_frame, Uint32 *last_frame_time,int NUM_FRAMES) {
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
}
void init_bullet(bullet *b){
        b->image = IMG_Load("bullet.png");
}
void affbullet(SDL_Surface *screen,bullet *b){
        SDL_BlitSurface(b->image,NULL,screen,&b->pos);
        b->pos.x+=20;
        
}



void render_animation(SDL_Surface *screen, SDL_Surface **frames, int current_frame,int x,int y) {
    // draw current animation frame to screen
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = frames[current_frame]->w;
    dest.h = frames[current_frame]->h;

    SDL_BlitSurface(frames[current_frame], NULL, screen, &dest);

    SDL_Flip(screen);
}
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
void update_animationright(int *current_frame, Uint32 *last_frame_time,int NUM_FRAMES) {
    // calculate time since last frame
    Uint32 current_time = SDL_GetTicks();
    Uint32 time_since_last_frame = current_time - *last_frame_time;

    // update animation frame if enough time has elapsed
    if (time_since_last_frame >= FRAME_DELAY) {
        (*current_frame)++;
        if (*current_frame == NUM_FRAMES) {
            *current_frame = 4;
        }

        *last_frame_time = current_time;
    }
}


void render_animationright(SDL_Surface *screen, SDL_Surface **frames, int current_frame,int x,int y) {
    // draw current animation frame to screen
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = frames[current_frame]->w;
    dest.h = frames[current_frame]->h;

    SDL_BlitSurface(frames[current_frame], NULL, screen, &dest);

    SDL_Flip(screen);
}

void player4(int* orientation,int* jump,int* dir,int* current_framess,Uint32* last_frame_time_stop_right,Uint32* last_frame_time_stop_left,Uint32* last_frame_time2,Uint32* last_frame_timess,Uint32* last_frame_timeleft ,Uint32* last_frame_timejump,int* current_framejump,int* current_frame_stop_right,int* current_frame_stop_left,int* current_frame2,int* current_frameleft,Personn *p,int* grav,int* velocity,int* stop,SDL_Surface *screen,SDL_Surface **frame_stop_right,SDL_Surface**frames_stop_left,SDL_Surface**framesright,SDL_Surface**framesleft,SDL_Surface**framesjump,SDL_Surface**framesss){
const int NUM_FRAME_stop_right = 13;
const int NUM_FRAMES_stop_left = 13;
const int NUM_FRAMESright = 13; 
const int NUM_FRAMESleft = 13;
const int NUM_FRAMESss = 6; 
const int NUM_FRAMESjump = 6;
//jump
 			if(p->cor.y<=(*grav)){
		     p->cor.y=p->cor.y+(*velocity);
		     if (p->cor.y!=(*grav)){
		     (*velocity)+=1;
		     }
		   } 
		   else{
		     p->cor.y=(*grav);
		     (*velocity)=0;
		     }    
		    // JUMP CONDITION
			//scrolling
	
				if((*dir)==1){
					p->cor.x+=4;}
				else if((*dir)==0){
					p->cor.x-=4;}
				if((*dir)==1 && (*jump) ==0){
					if ((*current_framejump)==5){
        			(*jump)==1;
        		}
					update_animation(current_framejump, last_frame_timejump, NUM_FRAMESss);
        			render_animationright(screen, framesjump, *current_framejump, p->cor.x, p->cor.y);
        		
        		}
        		else if((*dir) ==0&& (*jump) ==0){
					update_animation(current_framess, last_frame_timess, NUM_FRAMESss);
        			render_animationright(screen, framesss, *current_framess, p->cor.x, p->cor.y);
				}		
				else if((*dir)==0 &&(*jump)==1){
					update_animationright(current_frameleft, last_frame_timeleft,NUM_FRAMESleft);
        			render_animationright(screen, framesleft, *current_frameleft,p->cor.x,p->cor.y);       
				}
				else if((*dir)==1 && (*jump)==1 ){
					update_animationright(current_frame2, last_frame_time2,NUM_FRAMESright);
        			render_animationright(screen, framesright, *current_frame2,p->cor.x,p->cor.y);        			
        		}
				else if((*dir)==2 &&(*jump)==0&&(*orientation)==0){
				if ((*current_framejump)==5){
        			(*jump)==1;
        		}    
					update_animation(current_framejump, last_frame_timejump, NUM_FRAMESss);
        			render_animationright(screen, framesjump, *current_framejump, p->cor.x, p->cor.y);   
        			
				} 
				else if((*dir)==2 &&(*jump)==0&&(*orientation)==1){
					update_animation(current_framess, last_frame_timess, NUM_FRAMESss);
        			render_animationright(screen, framesss, *current_framess, p->cor.x, p->cor.y);      
				}        		
       		else if ((*stop)==1 && (*dir)==2 && (*orientation)==0){
        			update_animation(current_frame_stop_right, last_frame_time_stop_right,NUM_FRAME_stop_right);
        			render_animation(screen, frame_stop_right, *current_frame_stop_right,p->cor.x,p->cor.y);
        		}
       		else if ((*stop)==1 && (*dir)==2&&(*orientation)==1){
      			update_animation(current_frame_stop_left, last_frame_time_stop_left,NUM_FRAMES_stop_left);
       			render_animation(screen, frames_stop_left, *current_frame_stop_left,p->cor.x,p->cor.y);
        		}
        		
        		
        		}

