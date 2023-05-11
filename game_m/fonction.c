#include "fonction.h"
#include "fonctionn.h"
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define HEALTHBAR_WIDTH 300
#define HEALTHBAR_HEIGHT 30
#define SCORE_POSITION_X 10
#define SCORE_POSITION_Y 10

     
void init_bullet(bullet *b){
			
        b->image = IMG_Load("bullet.png");
}
void affbullet(SDL_Surface *screen,bullet *b){
        
        SDL_BlitSurface(b->image,NULL,screen,&b->pos);
        b->pos.x+=15;
        SDL_Flip(screen);
}
void affbulletleft(SDL_Surface *screen,bullet *b){
           
        SDL_BlitSurface(b->image,NULL,screen,&b->pos);
        b->pos.x-=15;
        SDL_Flip(screen);
        
}




void afficher_image(SDL_Surface *screen, image imge)
{
SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);

}
void loadanimation(int numframes ,SDL_Surface **frames,char dest[]){
for (int i = 0; i < numframes; i++) {
        char filename[20];
        sprintf(filename, dest, i);
        frames[i] = load_image(filename);
    }

}
void init_ennemi(Ennemi *e, int numframes, SDL_Surface **frames, SDL_Surface **framesl, SDL_Surface **framesright, SDL_Surface **framesleft) {
	SDL_Surface *screen;
	
	loadanimation(numframes,frames,"stopr/stopr%d.png");
	loadanimation(numframes,framesl,"stopl/stopl%d.png");
       loadanimation(numframes,framesright,"right/right%d.png");
       loadanimation(numframes,framesleft,"left/left%d.png");
	
       e->direction=1;
    
}
void afficherEnnemi(Ennemi e, SDL_Surface *screen) {
    
    
    
    
    SDL_Surface *hb_bg = e.health.bgImage;
    
    
    if (hb_bg == NULL) {
        hb_bg = SDL_CreateRGBSurface(SDL_HWSURFACE, e.health.hb_pos.w, e.health.hb_pos.h, 32, 0, 0, 0, 0);
        SDL_FillRect(hb_bg, NULL, SDL_MapRGB(screen->format, 255, 0, 0));
    }
    
    
    SDL_Rect hb_pos_bg = {e.health.hb_pos.x, e.health.hb_pos.y, e.health.hb_pos.w, e.health.hb_pos.h};
    
    
    SDL_BlitSurface(hb_bg, NULL, screen, &hb_pos_bg);
    
    SDL_BlitSurface(e.score.txt, NULL, screen, &e.score.pos_txt);
}
SDL_Surface* load_image(const char* filename) {
    SDL_Surface* image = NULL;
    SDL_Surface* optimized = NULL;

    image = IMG_Load(filename);
    if (image != NULL) {
        
        Uint32 colorkey = SDL_MapRGB(image->format, 0, 0xFF, 0xFF);
        SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorkey);

        optimized = SDL_DisplayFormatAlpha(image);
        SDL_FreeSurface(image);
    }

    return optimized;
}
void animate(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, SDL_Rect *dest) {
    
    const int FRAME_DELAY = 100;
    
    Uint32 current_time = SDL_GetTicks();
    Uint32 time_since_last_frame = current_time - *last_frame_time;

   
    if (time_since_last_frame >= FRAME_DELAY) {
        (*current_frame)++;
        if (*current_frame == NUM_FRAMES) {
            *current_frame = 4;
        }

        *last_frame_time = current_time;
    }

    dest->w = frames[*current_frame]->w;
    dest->h = frames[*current_frame]->h;

    //SDL_Flip(screen);
    //return dest;
}


void move(Ennemi *e,SDL_Rect* dest)
{
    
           (dest->x)+=e->direction*2;   
    
    
}

int collisionBB(SDL_Rect posp, SDL_Rect pose) {
      
       
    if ((posp.x + posp.w/1.5>= pose.x+pose.w) && (posp.x <= pose.x+pose.w)&& posp.y <= pose.y && posp.y + posp.h >= posp.y + posp.h) {       
        return 1;
    } else {
        return 0;
    }
}

void IA(Ennemi *ennemi, Personn *P, SDL_Rect* dest,bullett *b) {
        // Player is attacking
     
        if ((dest->x - P->cor.x < 0) && (dest->x - P->cor.x > -500)) {
            ennemi->STATE = 1;} // Enemy is following the player
           
       
        else if ((dest->x - P->cor.x > 0) && (dest->x - P->cor.x < 500)) {
             ennemi->STATE = 4; // Enemy is following the player
        }
        else  if((dest->x - P->cor.x>500)){
        ennemi->STATE=0; 
        }
               
        else  if((dest->x - P->cor.x>-300))
               ennemi->STATE=0; 
        else if(dest->x - P->cor.x==0)
        ennemi->STATE=5; 
  
      if( ennemi->vie==0){
     		 ennemi->STATE=6;
      }
   // UpdateEnnemi(ennemi);
}


void move_waiting(int* movex,SDL_Surface* screen, SDL_Surface** frames,SDL_Surface** framesl, SDL_Surface** framesleft, SDL_Surface** framesright, int NUM_FRAMES,  int* ok, Ennemi* e, SDL_Rect* dest, int *current_frame, int *current_frame0, int* last_frame_time, int* current_frameleft, int* last_frame_timeleft, int* current_frame2, int* last_frame_time2)

{
   if((dest->x)>(*movex))
        { 
        
         (*ok)=1;
        e->direction=-1;
        move(e,dest);}
        
        if((dest->x)<=(*movex)-200){
        (*ok)=2;
        e->direction=1;
        move(e,dest);
       
        }
        else 
          {
          if (e->direction==-1)
          {
        animate(screen, framesleft, current_frameleft, last_frame_timeleft, NUM_FRAMES, &dest);
        //aff_e(framesleft,current_frameleft,screen,*dest);
        move(e,dest);
        }
          else 
          {
        animate(screen, framesright, current_frame2, last_frame_time2, NUM_FRAMES,&dest);
        //aff_e(framesright,current_frame2,screen,*dest);
        move(e,dest);}
          
          }

}
void move_following(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, SDL_Rect* dest,SDL_Rect posp,Ennemi *e)
{
    
       animate(screen, frames, current_frame, last_frame_time, NUM_FRAMES, dest);
       move(e,dest);


}











