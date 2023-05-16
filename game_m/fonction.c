#include "fonction.h"
#include "fonctionn.h"
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int SCREEN_WI=1080;
      int SCREEN_HEI=1920;

     
void init_bullet(bullet *b){
			
        b->image = IMG_Load("bullet.png");
}
void affbullet(SDL_Surface *screen,bullet *b){
        
        SDL_BlitSurface(b->image,NULL,screen,&b->pos);
        b->pos.x+=40;

}
void affbulletleft(SDL_Surface *screen,bullet *b){
           
        SDL_BlitSurface(b->image,NULL,screen,&b->pos);
        b->pos.x-=40;
        
}
void afficher_image(SDL_Surface *screen, image imge)
{
SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);

}
void update_and_render_animationenemy(int rep,SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES,Ennemi *e,int SCREEN_WIDTH,int SCREEN_HEIGHT ) {
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
    

    //SDL_BlitSurface(frames[*current_frame], NULL, screen, &e->dest);
    
}
int collisionBB(SDL_Rect posp, SDL_Rect pose) {
      
       
    if ((posp.x + posp.w/1.5>= pose.x+pose.w) && (posp.x <= pose.x+pose.w)&& posp.y <= pose.y && posp.y + posp.h >= posp.y + posp.h) {       
        return 1;
    } else {
        return 0;
    }
}

void IA(Ennemi *ennemi, Personn *P) {
        // Player is attacking
     
        if ((ennemi->dest.x - P->cor.x < 0) && (ennemi->dest.x - P->cor.x > -800)) {
            ennemi->STATE = 1;} // Enemy is following the player
           
       
        if ((ennemi->dest.x - P->cor.x >= 0) && (ennemi->dest.x - P->cor.x < 800)) {
             ennemi->STATE = 4; // Enemy is following the player
        }
        if((ennemi->dest.x - P->cor.x>800)){
        ennemi->STATE=0; 
        }
               
        if((ennemi->dest.x - P->cor.x<-800))
               ennemi->STATE=0; 
      if( ennemi->vie==0){
     		 ennemi->STATE=6;
      }
   // UpdateEnnemi(ennemi);
}


void move_waiting(int* movex,SDL_Surface* screen, SDL_Surface** frames,SDL_Surface** framesl, SDL_Surface** framesleft, SDL_Surface** framesright, int NUM_FRAMES,  int* ok, Ennemi* e,int* current_frameleft, int* last_frame_timeleft, int* current_frame2, int* last_frame_time2)

{
   	if((e->dest.x)>=(*movex))
        { 
         (*ok)=1;
        e->direction=-1;
        }
        
      if((e->dest.x)<=(*movex)-200){
        (*ok)=2;
        e->direction=1;
        }
       if (e->direction==-1)
          {update_and_render_animationenemy(4,screen,framesleft,current_frameleft,last_frame_timeleft,NUM_FRAMES,e,SCREEN_WI,SCREEN_HEI );
          aff_e(framesleft,current_frameleft,screen,e->dest);
     			e->dest.x+=e->direction*5;
     			
        }
        if((e->direction==1))
          {
          
     			update_and_render_animationenemy(4,screen,framesright,current_frame2,last_frame_time2,NUM_FRAMES,e,SCREEN_WI,SCREEN_HEI );
     			aff_e(framesright,current_frame2,screen,e->dest);
     			 e->dest.x+=e->direction*5;
     			      			
        //animate(screen, framesright, current_frame2, last_frame_time2, NUM_FRAMES,&dest);
        //aff_e(framesright,current_frame2,screen,*dest);
        //move(e,dest);
        }
          
          }



void move_following(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES,Ennemi *e)
{    update_and_render_animationenemy(4,screen,frames,current_frame,last_frame_time,NUM_FRAMES,e,SCREEN_WI,SCREEN_HEI );
	aff_e(frames,current_frame,screen,e->dest);
     			      		
       e->dest.x+=e->direction*10;
}
