#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonctionn.h"
#include "fonction.h"
//#include "fonction.c"
#include "background.h"
//#include "background.h"
#define HEALTHBAR_WIDTH 300
#define HEALTHBAR_HEIGHT 30
#define SCORE_POSITION_X 10
#define SCORE_POSITION_Y 10
#include "Link.h"
#include "lot5.h"
#include "minimap.h"



void main_2()
{

//Uint32 start_time = SDL_GetTicks();
int level=1;

int xp_map;
int SCREEN_W = 1710;
int SCREEN_WIDTH = 1710;
int SCREEN_H = (float)(SCREEN_W / 1.7777777777777777);
int SCREEN_HEIGHT = (float)(SCREEN_W / 1.7777777777777777);

int lvl_depl1 = 0;
int lvl_depl2 = 0;

//Background task

//Variables

	
	SDL_Surface * enigme = NULL;
    SDL_Rect eg = {SCREEN_W/4, SCREEN_H/2, 50, 100};


       background bg;
       bg.R.x = 0;
       bg.R.y = 0;

	int anim_frame=0;
	int anim_frame_time=0;
	initBack(&bg, SCREEN_W, SCREEN_H);
	
	
	int trigger;
	
	Uint32 move_interval = 5;
	Uint32 last_move_time = SDL_GetTicks();
	
	player P;
	P.score =0;
	
	int limit = 0;
	
	int x2;
	int y2;
	
	int game_ended=0;
	int g_e_a=0;
	
	int Button_Clicked=0;
Personn p;
p.viep=4;

//---------------------------------------------------
int pvieref=0;
SDL_Rect dest;
 int y=1;
   int x;
int i,bigx,bigy;
int hitt=0;
bullett b1;
int movex=2000;
Ennemi e;
e.direction=0;
int ok=0;
e.dest.x=2000;
int hit3=0;
int xp=0;
int yp=1;
int xp2=0;
int yp2=1;
Uint32 last_frame_time1 = 0;
int current_frame1 = 0;
int current_framel1 = 0;
Uint32 last_frame_time21 = 0;
int current_frame21 = 3;
Uint32 last_frame_timeleft1 = 0;
int current_frameleft1 = 3;
int vie_counter=49;
int vie_counter2=49;
e.vie=1;
e.STATE=0;

//----------------------enemy2------------------------
Ennemi e2;

e2.vie=1;
e2.STATE=0;



int bullet_counter = 0,bullet_counter2 = 0;

//--------------------------------------------------------------

// NUMBER OF FRAMES OF MOUVEMENTS
int POSY=0;
//stop
const int NUM_FRAMESstopright = 13;
    Uint32 last_frame_time_stop_right = 0;
    int current_frame = 0;
    const int NUM_FRAMESstopleft = 13;
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
int hitready2=1;
 int hitready3=1;
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
int orientation2=0,xm2=100,ym2,jump2=1,dir2=2,velocity2,stop2=1,verif2,grav2=SCREEN_H-20,hit2=0;
Personn p2;
bullett b2;
p2.cor.x=100;
p2.cor.y=grav2;
//----------------------------------------------------------------------------------
//REST OF PROGRAM
p.cor.w=SCREEN_WIDTH/10;
p.cor.h=SCREEN_WIDTH/7+SCREEN_WIDTH/40;

int orientation=0,verif=0,jump=1,dir=2,velocity,stop=1,grav=600,hit=0;
int boucle=1;
int bigx2;
SDL_Event event;
SDL_Surface *screen;
image imge;
bullett b;
p.cor.x=SCREEN_W/2;
p.cor.y=grav;
e.dest.y=grav;
int tee;


minimap  m;
initmap(&m,SCREEN_W,SCREEN_H,"Assets/bg/bg0.png");


//printf("aaaaa %d \n",ms_to_sec(start_time));
char temps[20];


SDL_Surface* framesenemy[NUM_FRAMESstopright],*frameslenemy[NUM_FRAMESstopleft],*framesrightenemy[NUM_FRAMESright],*framesleftenemy[NUM_FRAMESleft],*framesjumpenemy[NUM_FRAMESjump],*framesssenemy[NUM_FRAMESss]; 
SDL_Surface* framescarac[NUM_FRAMESstopright],*frameslcarac[NUM_FRAMESstopleft],*framesrightcarac[NUM_FRAMESright],*framesleftcarac[NUM_FRAMESleft],*framesjumpcarac[NUM_FRAMESjump],*framessscarac[NUM_FRAMESss];
 
 int stopl=1,stopr=1,move=0;
 
  /*if(!Arduino_connect(SERIAL_PORT, 9600))
        exit(EXIT_FAILURE);  */
if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
}

screen=SDL_SetVideoMode(SCREEN_W, SCREEN_H, 0,SDL_RESIZABLE);

  int t;
  int det_black = 0;
  int det_green = 0;
  int det_red = 0;
  int det_blue = 0;
  int e1_stage = 0 ;

//----------------------------------------------------------------
/*DECLARATION OF ANIMATIONS
-----------------------------
stop
*/
loadanimationcaractere(NUM_FRAMESstopleft,framescarac,"stopr/stopr%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(NUM_FRAMESstopright,frameslcarac,"stopl/stopl%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(NUM_FRAMESright,framesrightcarac,"right/right%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(NUM_FRAMESjump,framesjumpcarac,"jump/jump%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(NUM_FRAMESleft,framesleftcarac,"left/left%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(NUM_FRAMESjump,framessscarac,"stopp/stopaa%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(13,framesrightenemy,"rightROBOT/right%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(13,framesleftenemy,"leftROBOT/left%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);

init_bullett(&b1);
init_bullet(&b2);

e.dest.w=p.cor.w;
e.dest.h=p.cor.h;
b1.pos.x=-6000;
				b1.pos.y=-6000;
 points p_points;					
SDL_Surface framesattend[10],framesnumber1[9],framesnumber2[9],framesnumber3[9],framesnumber4[9],framefinal[4],viecaractere[4];;
loadenigmenumbers(10,framesattend,"numbers/r%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadenigmeanswer(9,framesnumber1,"answer/%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadenigmeanswer(9,framesnumber2,"answer/%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadenigmeanswer(9,framesnumber3,"answer/%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadenigmeanswer(9,framesnumber4,"answer/%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadenigmenumbers(4,framefinal,"final2/a%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadenigmenumbers(4,framefinal,"lives/live%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
reponse r,r2,r3,r4; 
		
srand(time(0));
int alea=rand()%(4)+1; 
int gamestate=1;
int currentframeenigme=1,int currentframelive=1;
int current_framereponse=0,current_framereponse2=0,current_framereponse3=0,current_framereponse4=0;
int next=0;
int frame;
int ref;
enigmme e1;
int enigme1 = 0;
int verifshoot=1;
int orr_b = 0;
b1.pos.w=0;
b1.pos.h=65535;
while(boucle)
{      
x = collisionBB(e.dest,b1.pos);
//printf("\nplayer w & h : %d %d",p.cor.w,p.cor.h);

       x2 = event.button.x;
	y2 = event.button.y;
//afficher_image(screen,imge);
//----------------------------------------------------

//printf(" x=%d || y=%d || xenemy=%d ||  p.vie=%d",p.cor.x,p.cor.y,e.dest.x,p.viep);
bool pressing_m = false;
//---------------------------------------------
while(SDL_PollEvent(&event))
{
	switch(event.type)
	{
		case SDL_QUIT:
		boucle=0;
		break;
	    case SDL_KEYDOWN:
		       if(event.key.keysym.sym == SDLK_p){
				printf("\nGAME ENDED !\n");
				game_ended=1;
			}
                    if (event.key.keysym.sym == SDLK_RIGHT) {    
                       dir=1; 
                       stopr=0;
            }
                    if (event.key.keysym.sym == SDLK_LEFT) {
                        dir=0; 
                        stopl=0;
                    }
                    if (event.key.keysym.sym == SDLK_UP) {
                        jump=0;
                        if(p.cor.y==grav)
                        velocity=-20;
                              } 
                    if (event.key.keysym.sym == SDLK_SPACE && verifshoot==1) {
                        b1.pos.x=p.cor.x+100;
                        b1.pos.y=p.cor.y+100;
                        bigx= b1.pos.x;
                        hit=1; 
                        orr_b = orientation;
                        verifshoot=0;}  
                     if (event.key.keysym.sym == SDLK_RETURN && e1_stage!=0) {
                       gamestate=2;
                       next=0;
                    }   
                 if (event.key.keysym.sym == SDLK_ESCAPE && e1_stage!=0) {
                 gamestate=1;
                 next=0;
                      }  
                 if (event.key.keysym.sym == SDLK_UP && e1_stage==5 && gamestate==2) {
                 frame++;
                      }
                 if (event.key.keysym.sym == SDLK_RIGHT && e1_stage==5 && gamestate==2) {
                    next++;
                    frame=1;
          
                    } 
                      if (event.key.keysym.sym == SDLK_LEFT && e1_stage==5 && gamestate==2) {
                    next--;
              
                    }       
					if(event.key.keysym.sym == SDLK_TAB){
                        pressing_m = true;
                        printf("m yes\n");
                    }                             
                    break;
                 
        case SDL_KEYUP:
					if(event.key.keysym.sym == SDLK_TAB){
                        pressing_m = false;
                        printf("m no\n");
                    }
                    if (event.key.keysym.sym == SDLK_RIGHT) {
                        orientation=0;
                        dir=2;
                        stopr=1;
                         
                    }
     
                    if (event.key.keysym.sym == SDLK_LEFT) {
                        orientation=1;
                        dir=2;
                        stopl=1;
                        
                   }
                    if (event.key.keysym.sym == SDLK_UP) {
                        jump=1;
                      
                  }
                 
                  
                  
                    break;
            
		     
}}
if (level == 1){
	t=collisionPP(p.cor,bg.M[0],bg.R,251, 220, 156);
	det_green=collisionPP(p.cor,bg.M[0],bg.R,40, 200, 40);
}
if (level == 3){
	lvl_depl2++;
	t=collisionPP(p.cor,bg.M[1],bg.R,251, 220, 156);
	det_black=collisionPP(p.cor,bg.M[1],bg.R,40, 40, 40);
	det_green=collisionPP(p.cor,bg.M[1],bg.R,40, 200, 40);
	det_red=collisionPP(p.cor,bg.M[1],bg.R,200, 40, 40);
	det_blue=collisionPP(p.cor,bg.M[1],bg.R,40, 40, 200);
}
if (lvl_depl2==1){
	bg.R.x = 0;
	bg.R.y = -SCREEN_HEIGHT*.85;
	p.cor.x = SCREEN_WIDTH/2+p.cor.w/2;
}
if (enigme1==1){
	lvl_depl1++;
	if (lvl_depl1 == 1){
		SDL_FreeSurface(bg.S[0]);
		bg.S[0] = IMG_Load("Assets/bg/bg0.png");
	}
}
if(gamestate==1){

run_game(&bg, &P, &p.cor, screen, SCREEN_W, SCREEN_H, &g_e_a, 180, &anim_frame, &anim_frame_time, move_interval, last_move_time, &game_ended, &trigger, &boucle, &e.dest, &b1, &b2, &limit, &level, &movex, t, det_green, det_red, det_blue, det_black, &e1_stage, &enigme1);
//printf("\n movex : %d",movex);
//affichertemps(start_time,screen,temps,SCREEN_W,SCREEN_H);
//printf("\nt = %d\n",start_time);
//printf("\ne1_stage = %d",e1_stage);

affichertemps(screen,temps,SCREEN_W,SCREEN_H);
//printf("\nt = %d\n",start_time);
//printf("\nbg pos = %d",bg.R.x);
//printf("\ncol = %d",t);

xp_map=p.cor.x-bg.R.x;
SDL_Rect RP;
RP = p.cor;
RP.x = xp_map;

//miniMap(pressing_m,&m,RP,eg,dest,screen,SCREEN_W,SCREEN_H,"Assets/bg/bg0.png","Assets/bg/bg0.png","Assets/bg/bg0.png");

if(t==3 && verif==1){
grav=p.cor.y;
verif=0;}
if(t==0 && verif ==0){
	grav=SCREEN_H-p.cor.h*1.4;
	verif=1;
}



//printf("col = %d\n",collisionPP(p->cor,bg->M,bg->R));
//miniMap(pressing_m,&m,RP,eg,dest,screen,SCREEN_W,SCREEN_H,"Assets/bg/bg0.png","Assets/bg/bg0.png","Assets/bg/bg0.png");
/*dest.x-=SCREEN_W/40;
movex-=SCREEN_W/40;*/
//printf("\nenemy pos x : %d", dest.x);
//printf("\nmovex : %d", movex);
//printf("\n player pos : %d | %d",p.cor.x,p.cor.y);
//printf("\n");
//----------------------SHOOTING CARACTERE--------------------
//----------------------SHOOTING CARACTERE--------------------


if(t==3 && verif==1){
grav=p.cor.y;
verif=0;}
if(t==0 && verif ==0){
	grav=SCREEN_H-p.cor.h*1.4;
	verif=1;
}

				if(hit==1&&b1.pos.x<bigx+500  && orr_b==0 ){		
						aff_b(b1,screen);
						b1.pos.x+=10;
				}
				else if(hit==1&&b1.pos.x>bigx-500  && orr_b==1){
						aff_b(b1,screen);
						b1.pos.x-=10;
				}
				else{
				hit=0;
				b1.pos.x=-6000;
				b1.pos.y=-6000;
				verifshoot=1;
				}
				if(p.viep>0)
			player4(&stopr,&stopl,&orientation,&move,&jump,&dir,&current_framess,&last_frame_time_stop_right,&last_frame_time_stop_left,&last_frame_time3,&last_frame_timess,&last_frame_timeleft ,&last_frame_timejump,&current_framejump,&current_frame,&current_framel,&current_frame3,&current_frameleft,&p,&grav,&velocity,&stop,screen,framescarac,frameslcarac,framesrightcarac,framesleftcarac,framesjumpcarac,framessscarac,SCREEN_HEIGHT,SCREEN_WIDTH);	
//----------------------COLLISION----------------- carac  ENEMY 
    			
     			if(x==0)
      				y = collisionBB(e.dest,b1.pos);
      	
      		       if(x!=y){
     		 			e.vie--;
     		 			y=1;}
     //-------------------------BLINKING + VIE -------------------------------
     				//-BLINKING-
    			/* if(pvieref>p.viep){
      			if(vie_counter%3==0 ){
    						verif=1;}
     				if(vie_counter%3==1){
     						verif=1;}		
     				if(vie_counter%3==2){
     						verif=0;}
     				if(vie_counter>10){
     						pvieref=p.viep;}}*/
    			if(xp==0 && vie_counter>10){
     				 	p.viep--;
     		 			vie_counter=0;}
     		 			
     		 			
    		
     
     	//-------------------------SENDING BULLET TO LEFT ------------------------------- 
     			if(e.vie>0){
     			if (bg.R.y<0){
      			if(e.direction<0){
     							if(xp==1)
    							 	vie_counter++;
      						if (hitready2==0)
      							bullet_counter2++;
      	 		
     				 if (!(p.cor.x + p.cor.w/1.5 >= b2.pos.x + b2.pos.w && p.cor.x <= b2.pos.x && p.cor.y <= b2.pos.y && p.cor.y + p.cor.h >= b2.pos.y + b2.pos.h)&& hit2 == 1 && hitready2==0 && bullet_counter2>50){
      					
      					affbulletleft(screen,&b2);
      					xp=1;}	
       				
       				else{
       					       if(p.cor.x + p.cor.w/1.5 >= b2.pos.x + b2.pos.w && p.cor.x <= b2.pos.x && p.cor.y <= b2.pos.y && p.cor.y + p.cor.h >= b2.pos.y + b2.pos.h){
       					       xp=0;}
       					       b2.pos.x=e.dest.x+100;
							b2.pos.y=e.dest.y+100;
						if (bullet_counter2>50){
							hitready2=1;
							bullet_counter2=0;}
							}
						
							
      				if (b2.pos.x<=p.cor.x-200){
      				                     b2.pos.x=e.dest.x+100;
							b2.pos.y=e.dest.y+100;
						if (bullet_counter2>50){
							hitready2=1;
							bullet_counter2=0;}}
							
							
						}
						//-------------------- Bullet to the right------------
						if(xp2==0 && vie_counter2>50){
     		 			pvieref=p.viep;
     				 	p.viep--;
     		 			vie_counter2=0;}
						if(e.direction>0){
					
					if(xp2==1){
					vie_counter2++;
					}
    							 
				       if (hitready2==1){
      				       bullet_counter++;
      					} 								   
      				//-WHILE NOT COLLIDED-
     					
     					 if (!(p.cor.x + p.cor.w/1.5 >= b2.pos.x + b2.pos.w && p.cor.x <= b2.pos.x && p.cor.y <= b2.pos.y && p.cor.y + p.cor.h >= b2.pos.y + b2.pos.h)&& hit2 == 1 && hitready2==1 && bullet_counter>50){
      				affbullet(screen,&b2);
      				xp2=1;}	
       				//-WHILE  COLLIDED-
      				 else{
     		 					
     		 					if(p.cor.x + p.cor.w/1.5 >= b2.pos.x + b2.pos.w && p.cor.x <= b2.pos.x && p.cor.y <= b2.pos.y && p.cor.y + p.cor.h >= b2.pos.y + b2.pos.h){
     		 						xp2=0;}
     		 						
								b2.pos.x=e.dest.x+100;
								b2.pos.y=e.dest.y+100;
								if (bullet_counter>50){
									hitready2=0;
									bullet_counter=0;}
									
								}
						
     					if (b2.pos.x>=p.cor.x+200){
								b2.pos.x=dest.x+100;
								b2.pos.y=dest.y+100;
								if (bullet_counter>50){
									hitready2=0;
									bullet_counter=0;}}}
						
     					
     					
						
						
     
    //---------------------------------------------COLLISION ENEMY/BULLET  TO LEFT-------------------------------   
      			

    		
     	 					IA(&e, &p);
     	 					
   							if(e.STATE==0){
   								hit2 = 0;
   								hit3 = 0;
								move_waiting(&movex,screen,framesenemy,frameslenemy,framesleftenemy,framesrightenemy,13,&ok,&e,&current_frameleft1,&last_frame_timeleft1,&current_frame21,&last_frame_time21);	
    							}
   							if(e.STATE==1){
      							e.direction=1;
      							hit2=1;
      							move_following(screen,framesrightenemy, &current_frameleft1, &last_frame_timeleft1,13,&e);
       							if(hitready2==0){
       								b2.pos.x=e.dest.x+100;
       								b2.pos.y=e.dest.y+100;
       								hit2=1;
     	 								hitready2=1;}}     									
  								if(e.STATE==4){
      							e.direction=-1;
      							hit2=1;
      							move_following(screen,framesleftenemy, &current_frame21, &last_frame_time21,13,&e);
      							if(hitready2==1){
       								b2.pos.x=e.dest.x+100;
      							 	b2.pos.y=e.dest.y+100;
      							 	bigx2=b2.pos.x;
       								hit2=1;
     	 								hitready2=0;
      							}}}}}
 								
 
 if(gamestate==2){
enigmefinal(&enigme1,&gamestate,ref,&r,&r2,&r3,&r4,&next,&frame,&currentframeenigme,&current_framereponse,&current_framereponse2,&current_framereponse3,&current_framereponse4,screen,&e1,&e1_stage,framesattend,framesnumber1,framesnumber2,framesnumber3,framesnumber4,framefinal);


 }
//-----------------------------------------------END-----------------------------------        
 

//printf("\nxp_map : %d",xp_map);
SDL_Flip(screen);

SDL_Delay(10);
}
}

void aff_e(SDL_Surface **framesright,int *current_frame21,SDL_Surface *screen,SDL_Rect dest){
       SDL_BlitSurface(framesright[*current_frame21], NULL, screen, &dest);
}
void aff_b(bullett b,SDL_Surface *screen){
       SDL_BlitSurface(b.image, NULL, screen, &b.pos);
}

