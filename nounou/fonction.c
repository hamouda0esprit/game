#include "fonction.h"
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_W 640
#define SCREEN_H 410
#define HEALTHBAR_WIDTH 300
#define HEALTHBAR_HEIGHT 30
#define SCORE_POSITION_X 10
#define SCORE_POSITION_Y 10
     


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
     e->health.bgImage = IMG_Load("h.png");
    if (!e->health.bgImage) {
        printf("Erreur de chargement de l'image du background de la healthbar : %s\n", IMG_GetError());
    }
    TTF_Init();
    e->health.hb_pos.x = SCREEN_W - HEALTHBAR_WIDTH - 50;
    e->health.hb_pos.y = SCREEN_H - HEALTHBAR_HEIGHT - 520;
    e->health.hb_pos.w = HEALTHBAR_WIDTH;
    e->health.hb_pos.h = HEALTHBAR_HEIGHT;
    e->health.maxHealth = 100;
    e->health.currentHealth = 100;
    e->health.fgImage = NULL;
 
    e->score.police = TTF_OpenFont("Helvetica-Bold.ttf", 45);
    e->score.currentScore = 0;
    	e->score.color_txt.r = 255;
		e->score.color_txt.g = 255;
		e->score.color_txt.b = 0;

    e->score.pos_txt.x = SCORE_POSITION_X;
    e->score.pos_txt.y = SCORE_POSITION_Y;
    e->score.txt = TTF_RenderText_Blended(e->score.police, "Score: 0", e->score.color_txt); 
    SDL_BlitSurface (e->score.txt, NULL, screen, &e->score.pos_txt);
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
SDL_Rect animate(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, int x, int y) {
    
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

    
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = frames[*current_frame]->w;
    dest.h = frames[*current_frame]->h;

    SDL_BlitSurface(frames[*current_frame], NULL, screen, &dest);

    SDL_Flip(screen);
    return dest;
}

SDL_Rect animate_place(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, int x, int y) {
    
    const int FRAME_DELAY = 100;
    Uint32 current_time = SDL_GetTicks();
    Uint32 time_since_last_frame = current_time - *last_frame_time;

 
    if (time_since_last_frame >= FRAME_DELAY) {
        (*current_frame)++;
        if (*current_frame == NUM_FRAMES) {
            *current_frame = 0;
        }

        *last_frame_time = current_time;
    }

    
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = frames[*current_frame]->w;
    dest.h = frames[*current_frame]->h;

    SDL_BlitSurface(frames[*current_frame], NULL, screen, &dest);

    SDL_Flip(screen);
    return dest;
}



void move(Ennemi *e,int *xm)
{
    
           (*xm)+=e->direction*2;   
    
    
}

//---------------------------------------------------------------------------------------------
int collisionBB(SDL_Rect posp, SDL_Rect pose) {
      
       
    if ((posp.x + posp.w/2 >= pose.x) && (posp.x <= pose.x+pose.w/2)  && (posp.y + posp.h/2 >= pose.y) && (posp.y <= pose.y + pose.h/2)) {       
        return 1;
    } else {
        return 0;
    }
}
/*void IA (ennemi ennemi, plyr P, x1, x2)
{
if ((ennemi.position.x-P.position.x<x2)&&(ennemi.position.x-P.position.x>x1)&&(ennemi.STATE==WAITING))
		{
			ennemi.STATE=FOLLOWING;
			
		}
		else if ((ennemi.position.x-P.position.x>x2)&&(ennemi.STATE==FOLLOWING))
		{
			ennemi.STATE=WAITING;
			
		}
		else if ((ennemi.position.x-P.position.x<x1)&&(ennemi.STATE==FOLLOWING))
		{
			ennemi.STATE=ATTACKING;
			P.vie--;
			
		}
		else if ((ennemi.position.x-P.position.x>x2)&&(P.vie==0)&&(ennemi.STATE==ATTACKING))
		{	
			ennemi.STATE=WAITING;
			
		}
		else if ((ennemi.position.x-P.position.x<x2)&&(ennemi.position.x-P.position.x>x1)&&(ennemi.STATE==ATTACKING))
		{	
			ennemi.STATE=FOLLOWING;
			
		}
		UpdateEnnemi(&ennemi, P);
}*/


