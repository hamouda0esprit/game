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
#define SERIAL_PORT "/dev/ttyACM0"
#define SERIAL_PORT_BUFFER_LENGTH   20


void main_2()
{
int playerscount = 1;
//Uint32 start_time = SDL_GetTicks();
int level=1,level2=1,nour=0,nour1=0,nour2=0;;
Mix_Music *music,*music1,*music2;
Mix_Chunk *mus;
int xp_map;
int xe_map;
int yp_map;
int ye_map;
int SCREEN_W = 1710;
int SCREEN_WIDTH = 1710;
int SCREEN_W2 = 1710;
int SCREEN_H = (float)(SCREEN_W / 1.7777777777777777);
int SCREEN_HEIGHT = (float)(SCREEN_W / 1.7777777777777777);
int SCREEN_H2 = (float)(SCREEN_W / 1.7777777777777777);

SCREEN_HEIGHT = SCREEN_HEIGHT / 2;
SCREEN_WIDTH = SCREEN_WIDTH / 2;
SCREEN_H = SCREEN_H / 2;
SCREEN_W = SCREEN_W / 2;

int lvl_depl1 = 0;
int lvl_depl2 = 0;
int lvl_depl3 = 0;

int lvl2_depl1 = 0;
int lvl2_depl2 = 0;
int lvl2_depl3 = 0;

int map_W = 6952;
int map_H = 1608;

//Background task

//Variables

	
	SDL_Surface * enigme = NULL;
    SDL_Rect eg = {SCREEN_W/4, SCREEN_H/2, 50, 100};


	background bg;
   bg.R.x = 0;
   bg.R.y = 0;
   bg.R.w = 0;
   bg.R.h = 0;
   bg.R2.x = 0;
   bg.R2.y = 0;
   bg.R2.w = SCREEN_W*3.75;
   bg.R2.h = SCREEN_H2;
       
   background bg2;
   bg2.R.x = 0;
   bg2.R.y = 0;
   bg2.R.w = 0;
   bg2.R.h = 0;
   bg2.R2.x = 0;
   bg2.R2.y = 0;
   bg2.R2.w = SCREEN_W*3.75;
   bg2.R2.h = SCREEN_H2;

	int anim_frame=0, anim_frame2=0;
	int anim_frame_time=0, anim_frame_time2=0;
	initBack(&bg, SCREEN_W, SCREEN_H);
	initBack(&bg2, SCREEN_W, SCREEN_H);
	bg2.R.y=SCREEN_H/15;
	int trigger, trigger2;
	
	Uint32 move_interval = 5;
	Uint32 move_interval2 = 5;
	Uint32 last_move_time = SDL_GetTicks();
	Uint32 last_move_time2 = SDL_GetTicks();
	
	player P;
	P.score =0;
	
	int limit = 0, limit2 = 0;
	
   int t = 0;
   int det_black = 0;
   int det_green = 0;
   int det_red = 0;
   int det_blue = 0;
   
	int t2 = 0;
   int det_black2 = 0;
   int det_green2 = 0;
   int det_red2 = 0;
   int det_blue2 = 0;
	
	int x2;
	int y2;
	
	int game_ended=0;
	int g_e_a=0;
	
	int Button_Clicked=0;
minimap  m;
initmap(&m,SCREEN_W,SCREEN_H,"Assets/bg/bg0.png",map_W,map_H);
char temps[20];
//-------------------------manette-------------------
int right=0,left=0,up=0;
//-----------------------------------CARACTERE THINGS ------------------------------------
Uint32 last_frame_time_stop_right = 0;
int current_frame = 0;
Uint32 last_frame_time_stop_left = 0;
int current_framel = 0;
Uint32 last_frame_time3 = 0;
int current_frame3 = 3;
Uint32 last_frame_timess = 0;
int current_framess = 3;
Uint32 last_frame_timeleft = 0;
int current_frameleft = 3;
Uint32 last_frame_timejump = 0;
int current_framejump = 0;
SDL_Surface* framescarac[13],*frameslcarac[13],*framesrightcarac[13],*framesleftcarac[13],*framesjumpcarac[6],*framessscarac[6];
Personn p;
int orientation=0,verif=0,jump=1,dir=2,velocity,stop=1,grav=SCREEN_H-SCREEN_H/2.5,hit=0,bigx2,x,y=1,pvieref=0,stopl=1,stopr=1,move=0;
p.viep=7;
p.cor.w=SCREEN_WIDTH/10;
p.cor.h=SCREEN_WIDTH/7+SCREEN_WIDTH/40;
p.cor.x=SCREEN_W/4;
p.cor.y=grav;
bullett b1;
loadanimationcaractere(13,framescarac,"stopr/stopr%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(13,frameslcarac,"stopl/stopl%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(13,framesrightcarac,"right/right%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(6,framesjumpcarac,"jump/jump%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(13,framesleftcarac,"left/left%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(6,framessscarac,"stopp/stopaa%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
int vie_counter=49;
int vie_counter2=49;
int vie_countere2=49;
int vie_counter2e2=49;
b1.pos.x=-6000;
b1.pos.y=-6000;
init_bullett(&b1);
int verifshoot=1;
int orr_b = 0;
//---------------------------------PLAYER 2-----------------------------------------
Uint32 last_frame_time_stop_rightp2 = 0;
int current_framep2 = 0;
Uint32 last_frame_time_stop_leftp2 = 0;
int current_framelp2 = 0;
Uint32 last_frame_time3p2 = 0;
int current_frame3p2 = 3;
Uint32 last_frame_timessp2 = 0;
int current_framessp2 = 3;
Uint32 last_frame_timeleftp2 = 0;
int current_frameleftp2 = 3;
Uint32 last_frame_timejumpp2 = 0;
int current_framejumpp2 = 0;
SDL_Surface* framescaracp2[13],*frameslcaracp2[13],*framesrightcaracp2[13],*framesleftcaracp2[13],*framesjumpcaracp2[6],*framessscaracp2[6];
Personn p2;
int orientationp2=0,verifp2=0,jumpp2=1,dirp2=2,velocityp2,stopp2=1,gravp2=SCREEN_H2-SCREEN_H/2.1,hitp2=0,bigx2p2,xp2,yp2=1,pvierefp2=0,stoplp2=1,stoprp2=1,movep2=0;
p2.viep=7;
p2.cor.w=SCREEN_WIDTH/10;
p2.cor.h=SCREEN_WIDTH/7+SCREEN_WIDTH/40;
p2.cor.x=SCREEN_W/4;
p2.cor.y=gravp2;
bullett b1p2;
loadanimationcaractere(13,framescaracp2,"stopr/stopr%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(13,frameslcaracp2,"stopl/stopl%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(13,framesrightcaracp2,"right/right%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(6,framesjumpcaracp2,"jump/jump%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(13,framesleftcaracp2,"left/left%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(6,framessscaracp2,"stopp/stopaa%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
int vie_counterp2=49;
int vie_counter2p2=49;
int vie_countere2p2=49;
int vie_counter2e2p2=49;
b1p2.pos.x=-6000;
b1p2.pos.y=-6000;
init_bullett(&b1p2);
int verifshootp2=1;
int orr_bp2 = 0;


// -------------------------- ENEMY THINGS --------------------------
Ennemi e;
e.direction=0;
e.dest.x=SCREEN_W*3;
e.dest.y=grav;
e.vie=3;
e.STATE=0;
e.dest.w=p.cor.w;
e.dest.h=p.cor.h; 
SDL_Surface* framesenemy[13],*frameslenemy[13],*framesrightenemy[13],*framesleftenemy[13],*framesjumpenemy[6],*framesssenemy[6];
int bigx,movex=6000,ok=0,hit3=0,xp=0,xpp2=0,hitready2=1,bullet_counter = 0,bullet_counter2 = 0,hit2=0;
Uint32 last_frame_time1 = 0;
int current_frame1 = 0;
int current_framel1 = 0;
Uint32 last_frame_time21 = 0;
int current_frame21 = 3;
Uint32 last_frame_timeleft1 = 0;
int current_frameleft1 = 3;
Uint32 last_frame_timejump2 = 0;
int current_framejump2 = 0;
loadanimationcaractere(13,framesrightenemy,"rightROBOT/right%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(13,framesleftenemy,"leftROBOT/left%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
bullett b2;
init_bullet(&b2);
// -------------------------- ENEMY THINGS2 --------------------------
Ennemi e2;
e2.direction=0;
e2.dest.x=SCREEN_W*2;
e2.dest.y=grav;
e2.vie=3;
e2.STATE=0;
e2.dest.w=p.cor.w;
e2.dest.h=p.cor.h; 
SDL_Surface* framesenemy2[13],*frameslenemy2[13],*framesrightenemy2[13],*framesleftenemy2[13],*framesjumpenemy2[6],*framesssenemy2[6];
int bigxe2,movexe2=2300,oke2=0,hit3e2=0,xpe2=0,xp2e2=0,hitready2e2=1,bullet_counter2e2 = 0,bullet_countere22 = 0,hit2e2=0,xe2,ye2=1;
Uint32 last_frame_time12 = 0;
int current_frame12 = 0;
int current_framel12 = 0;
Uint32 last_frame_time212 = 0;
int current_frame212 = 3;
Uint32 last_frame_timeleft12 = 0;
int current_frameleft12 = 3;
Uint32 last_frame_timejump22 = 0;
int current_framejump22 = 0;
loadanimationcaractere(13,framesrightenemy2,"rightROBOT/right%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(13,framesleftenemy2,"leftROBOT/left%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
bullett b22;
init_bullet(&b22);

// -------------------------- ENEMY THINGS2 --------------------------
Ennemi e3;
e3.direction=0;
e3.dest.x=2000;
e3.dest.y=grav;
e3.vie=3;
e3.STATE=0;
e3.dest.w=p.cor.w;
e3.dest.h=p.cor.h; 
SDL_Surface* framesenemy3[13],*frameslenemy3[13],*framesrightenemy3[13],*framesleftenemy3[13],*framesjumpenemy3[6],*framesssenemy3[6];
int bigxe3,bigxp2,movexe3=2300,oke3=0,hit3e3=0,xpe3=0,xp2e3=0,hitready2e3=1,bullet_counter2e3 = 0,bullet_countere23 = 0,hit2e3=0,xe3,ye3=1;
Uint32 last_frame_time13 = 0;
int current_frame1e3 = 0;
int current_framel12e3 = 0;
Uint32 last_frame_time212e3 = 0;
int current_frame212e3 = 3;
Uint32 last_frame_timeleft12e3 = 0;
int current_frameleft12e3 = 3;
Uint32 last_frame_timejump22e3 = 0;
int current_framejump22e3 = 0;
loadanimationcaractere(13,framesrightenemy3,"rightROBOT/right%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadanimationcaractere(13,framesleftenemy3,"leftROBOT/left%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
bullett be3;
init_bullet(&be3);
//-------------------ENEMY THING 3-----------------------------
 //-------------------SDL THINGS-----------------------------
int boucle=1;
SDL_Event event;
SDL_Surface *screen;
image imge;
char serialPortBuffer[SERIAL_PORT_BUFFER_LENGTH] = {0};
    int serialPortReadDataLength = 0;   
  if(!Arduino_connect(SERIAL_PORT, 9600))
        //exit(EXIT_FAILURE); 
if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1)
{
printf("Could not initialize SDL: %s.\n", SDL_GetError());
}

screen=SDL_SetVideoMode(SCREEN_W2, SCREEN_H2, 0,SDL_HWSURFACE | SDL_DOUBLEBUF);

	int conteur=0;
//----------------------------------------------------------------
int shoott=0;

 points p_points;	
 //------------------------ ENIGME---------------------------------				
SDL_Surface framesattend[10],framesnumber1[10],framesnumber2[10],framesnumber3[10],framesnumber4[10],framefinal[4],viecaractere[4],vieenemy2[4],vieenemy[4],damage[12];
loadenigmenumbers(10,framesattend,"numbers/r%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadenigmeanswer(10,framesnumber1,"answer/%d.png",150,100);
loadenigmeanswer(10,framesnumber2,"answer/%d.png",150,100);
loadenigmeanswer(10,framesnumber3,"answer/%d.png",150,100);
loadenigmeanswer(10,framesnumber4,"answer/%d.png",150,100);
loadenigmenumbers(4,framefinal,"final2/a%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadenigmeanswer(4,viecaractere,"lives/live%d.png",220,90);
loadenigmeanswer(4,vieenemy,"livesenemy/live%d.png",220,70);
loadenigmeanswer(4,vieenemy2,"livesenemy/live%d.png",220,70);
loadenigmeanswer(12,damage,"damage/damage%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
reponse r,r2,r3,r4,r5,r6,r7,rectvieenemy2; 	
srand(time(0));
int alea=rand()%(4)+1; 
int e1_stage = 0;
int e1_stage_2 = 0;
int gamestate=1;
int currentframeenigme=1, currentframelive=4, currentframeliveenemy=4,currentframeliveenemy2=4,currentframedamage=1;
int current_framereponse=0,current_framereponse2=0,current_framereponse3=0,current_framereponse4=0;
int next=0;
int frame;
int ref;
enigmme e1;
int enigme1 = 0;
int enigme2 = 0;

int enigme1_2 = 0;
int enigme2_2 = 0;
b1.pos.w=0;
b1.pos.h=65535;
r5.r.x=50;
r5.r.y=150;
int suivant=0;
r7.r.x=0;
r7.r.y=0;
int test=0;
// -----------------ENIGME PLAYER2--------------------
SDL_Surface framesattendp2[10],framesnumber1p2[10],framesnumber2p2[10],framesnumber3p2[10],framesnumber4p2[10],framefinalp2[4],viecaracterep2[4],vieenemy2p2[4],vieenemyp2[4],damagep2[12];
loadenigmenumbers(10,framesattendp2,"numbers/r%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadenigmeanswer(10,framesnumber1p2,"answer/%d.png",150,100);
loadenigmeanswer(10,framesnumber2p2,"answer/%d.png",150,100);
loadenigmeanswer(10,framesnumber3p2,"answer/%d.png",150,100);
loadenigmeanswer(10,framesnumber4p2,"answer/%d.png",150,100);
loadenigmenumbers(4,framefinalp2,"final2/a%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
loadenigmeanswer(4,viecaracterep2,"lives/live%d.png",220,90);
loadenigmeanswer(4,vieenemyp2,"livesenemy/live%d.png",220,70);
loadenigmeanswer(4,vieenemy2p2,"livesenemy/live%d.png",220,70);
loadenigmeanswer(12,damagep2,"damage/damage%d.png",SCREEN_WIDTH,SCREEN_HEIGHT);
reponse rp2,r2p2,r3p2,r4p2,r5p2,r6p2,r7p2,rectvieenemy2p2; 	 
int gamestatep2=1;
int currentframeenigmep2=1, currentframelivep2=4, currentframeliveenemyp2=4,currentframeliveenemy2p2=4,currentframedamagep2=1;
int current_framereponsep2=0,current_framereponse2p2=0,current_framereponse3p2=0,current_framereponse4p2=0;
int nextp2=0;
int framep2;
int refp2;
enigmme e1p2;
int enigme1p2 = 0;
int enigme2p2 = 0;
b1p2.pos.w=0;
b1p2.pos.h=65535;
r5p2.r.x=50;
r5p2.r.y=150;
int suivantp2=0;
r7p2.r.x=0;
r7p2.r.y=0;
int testp2=0;
//----------condition du compteur de damage--------------
int round=0;
//-----------HINT AND CONTROLLS-----------------
SDL_Surface controlls[12],hint[6],help[2];
loadenigmeanswer(12,controlls,"controls/controls%d.png",1500,800);
loadenigmeanswer(6,hint,"hints/control%d.png",1500,800);
loadenigmeanswer(2,help,"help/help%d.png",700,300);
reponse contr,hints,helps;
Personn pcontrols;
contr.r.x=SCREEN_WIDTH/15;
hints.r.x=SCREEN_WIDTH/15;
helps.r.x=SCREEN_WIDTH/4+100;
int conteurcontrols=0,gravcontr=510;
int currentframecontrol=1,currentframehint=1,currentframehelp=1;
pcontrols.cor.w=SCREEN_WIDTH/10;
pcontrols.cor.h=SCREEN_WIDTH/7+SCREEN_WIDTH/40;
pcontrols.cor.x=SCREEN_WIDTH/2-pcontrols.cor.w/2;
pcontrols.cor.y=gravcontr;
contr.r.y=60;
hints.r.y=60;
helps.r.y=20;
int verifhint=0;
int nexthint=1;
int staterobots=0;
//-----------HINT AND CONTROLLS p2-----------------
SDL_Surface controllsp2[12],hintp2[6],helpp2[2];
loadenigmeanswer(12,controllsp2,"controls/controls%d.png",1500,800);
loadenigmeanswer(6,hintp2,"hints/control%d.png",1500,800);
loadenigmeanswer(2,helpp2,"help/help%d.png",700,300);
reponse contrp2,hintsp2,helpsp2;
Personn p2controls;
contrp2.r.x=SCREEN_WIDTH/15;
hintsp2.r.x=SCREEN_WIDTH/15;
helpsp2.r.x=SCREEN_WIDTH/4+100;
int conteurcontrolsp2=0,gravcontrp2=510;
int currentframecontrolp2=1,currentframehintp2=1,currentframehelpp2=1;
p2controls.cor.w=SCREEN_WIDTH/10;
p2controls.cor.h=SCREEN_WIDTH/7+SCREEN_WIDTH/40;
p2controls.cor.x=SCREEN_WIDTH/2-p2controls.cor.w/2;
p2controls.cor.y=gravcontrp2;
contrp2.r.y=60;
hintsp2.r.y=60;
helpsp2.r.y=20;
int verifhintp2=0;
int nexthintp2=1;
int staterobotsp2=0;
while(boucle)
{

if(e2.vie==0 && e.vie==0){
staterobots=1;
}
 rectvieenemy2.r.x=e2.dest.x-20;
 rectvieenemy2.r.y=e2.dest.y-50;
r6.r.x=e.dest.x-40;
r6.r.y=e.dest.y-50;
//printf("\ncurrentframe : %d || x= %d|| y=%d",currentframelive,r5.r.x,r5.r.y);

       x2 = event.button.x;
	y2 = event.button.y;
//afficher_image(screen,imge);
//----------------------------------------------------
//printf(" x=%d || y=%d || xenemy=%d ||  p.vie=%d",p.cor.x,p.cor.y,e.dest.x,p.viep);
bool pressing_m = false;

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
			}//-------------------PLAYER 1 COMMANDS---------------------
                    if (event.key.keysym.sym == SDLK_RIGHT ) {    
                       dir=1; 
                       stopr=0;
                       orientation=0;
                       
            }
                    if (event.key.keysym.sym == SDLK_LEFT ) {
                        dir=0; 
                        stopl=0;
                        orientation=1;
                        
                    }
                    if (event.key.keysym.sym == SDLK_UP) {
                        jump=0;
                        if(p.cor.y==grav)
                        velocity=-20;
                              } 
                     if (event.key.keysym.sym == SDLK_UP&& bg.R.y < 0 && p.cor.x>1385 && staterobots==0) {
                       staterobots=4;}
                    if (event.key.keysym.sym == SDLK_SPACE && verifshoot==1) {
                        b1.pos.x=p.cor.x+100;
                        b1.pos.y=p.cor.y+100;
                        bigx= b1.pos.x;
                        hit=1; 
                        orr_b = orientation;
                        verifshoot=0;}  
                      if (event.key.keysym.sym == SDLK_RETURN && gamestate==3) {
                      suivant++;
                      
                    }  
                    if (event.key.keysym.sym == SDLK_s && verifhint==1) {
                      nexthint++;
                     
                      
                    }  
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
				//-------------------PLAYER 2 COMMANDS---------------------
                    if (event.key.keysym.sym == SDLK_d ) {    
                       dirp2=1; 
                       stoprp2=0;
                       orientationp2=0;
                       
            }
                    if (event.key.keysym.sym == SDLK_q ) {
                        dirp2=0; 
                        stoplp2=0;
                        orientationp2=1;
                        
                    }
                    if (event.key.keysym.sym == SDLK_z) {
                        jumpp2=0;
                        if(p2.cor.y==gravp2)
                        velocityp2=-20;
                              } 
                   /*  if (event.key.keysym.sym == SDLK_z&& bg2.R.y < 0 && p2.cor.x>1385 && staterobotsp2==0) {
                       staterobots=4;}
                    if (event.key.keysym.sym == SDLK_r && verifshootp2==1) {
                        b1p2.pos.x=p2.cor.x+100;
                        b1p2.pos.y=p2.cor.y+100;
                        bigxp2= b1p2.pos.x;
                        hitp2=1; 
                        orr_bp2 = orientationp2;
                        verifshoot=0;}  
                      if (event.key.keysym.sym == SDLK_t && gamestatep2==3) {
                      suivantp2++;
                      
                    }  
                    if (event.key.keysym.sym == SDLK_s && verifhintp2==1) {
                      nexthintp2++;
                     
                      
                    }  
                     if (event.key.keysym.sym == SDLK_y && e1_stage!=0) {
                       gamestatep2=2;
                       nextp2=0;
                    }   
                 if (event.key.keysym.sym == SDLK_u && e1_stage!=0) {
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
              
                    }*/
                    break;
        case SDL_KEYUP:
					if(event.key.keysym.sym == SDLK_TAB){
                        pressing_m = false;
                        printf("m no\n");
                    }
                    //-----------------PLAYER 1 ----------------------
                    if (event.key.keysym.sym == SDLK_RIGHT ) {
                        
                        dir=2;
                        stopr=1;
                         
                    }
     
                    if (event.key.keysym.sym == SDLK_LEFT ) {
                        
                        dir=2;
                        stopl=1;
                        
                   }
                    if (event.key.keysym.sym == SDLK_UP ) {
                        jump=1;
                      
                  }
                   //-----------------PLAYER 2 ----------------------
                  if (event.key.keysym.sym == SDLK_d ) {
                        
                        dirp2=2;
                        stoprp2=1;
                         
                    }
     
                    if (event.key.keysym.sym == SDLK_q ) {
                        
                        dirp2=2;
                        stoplp2=1;
                        
                   }
                    if (event.key.keysym.sym == SDLK_z ) {
                        jumpp2=1;
                      
                  }
                 
                  
                  
                    break;
            
		     
}}

//-----FIRST PLAYER-----//
if (enigme1==1){
	lvl_depl1++;
	if (lvl_depl1 == 1){
		SDL_FreeSurface(bg.S[0]);
		Resize(&(bg.S[0]), "Assets/bg/bg02.png", SCREEN_WIDTH*3.75, SCREEN_HEIGHT*1.8);
	}
}
if (enigme2==1){
	lvl_depl3++;
	if (lvl_depl3 == 1){
		SDL_FreeSurface(bg.S[2]);
		Resize(&(bg.S[2]), "Assets/bg/bg22.png", SCREEN_WIDTH*3.75, SCREEN_HEIGHT*1.8);
		SDL_FreeSurface(bg.M[1]);
		Resize(&(bg.M[1]), "Assets/BG_M22.png", SCREEN_WIDTH*3.75, SCREEN_HEIGHT*1.8);
	}
}
//-----SECOND PLAYER-----//
if (enigme1_2==1){
	lvl2_depl1++;
	if (lvl2_depl1 == 1){
		SDL_FreeSurface(bg2.S[0]);
		Resize(&(bg2.S[0]), "Assets/bg/bg02.png", SCREEN_WIDTH*3.75, SCREEN_HEIGHT*1.8);
	}
}
if (enigme2_2==1){
	lvl2_depl3++;
	if (lvl2_depl3 == 1){
		SDL_FreeSurface(bg.S[2]);
		Resize(&(bg2.S[2]), "Assets/bg/bg22.png", SCREEN_WIDTH*3.75, SCREEN_HEIGHT*1.8);
		SDL_FreeSurface(bg.M[1]);
		Resize(&(bg2.M[1]), "Assets/BG_M22.png", SCREEN_WIDTH*3.75, SCREEN_HEIGHT*1.8);
	}
}
//printf("\nxenemy= %d || yenemy= %d || px= %d || py= %d",e.dest.x,e.dest.y,p.cor.x,p.cor.y);

//----------------------------------gamestate1------------------------------
if(gamestate==1){
printf("\n t2 = %d ", t2);

run_game(2, right, left , up, &staterobots, &e2.dest, &test,&bg2, &P, &p2.cor, screen, SCREEN_W2, SCREEN_H, &g_e_a, 180, &anim_frame2, &anim_frame_time2, move_interval2, last_move_time2, &game_ended, &trigger2, &boucle, &e.dest, &b1, &b2, &limit2, &level2, &movex, t2, det_green2, det_red2, det_blue2, det_black2, &e1_stage_2, &enigme1_2, &enigme2_2);

run_game(1 , right, left , up, &staterobots, &e2.dest, &test,&bg, &P, &p.cor, screen, SCREEN_W2, SCREEN_H, &g_e_a, 180, &anim_frame, &anim_frame_time, move_interval, last_move_time, &game_ended, &trigger, &boucle, &e.dest, &b1, &b2, &limit, &level, &movex, t, det_green, det_red, det_blue, det_black, &e1_stage, &enigme1, &enigme2);

aff_e(&viecaractere,&currentframelive,screen,r5.r); 
//printf("\n movex : %d",movex);
//affichertemps(start_time,screen,temps,SCREEN_W,SCREEN_H);
//printf("\nt = %d\n",start_time);
//printf("\ne1_stage = %d",e1_stage);

affichertemps(screen,temps,SCREEN_W,SCREEN_H);
//printf("\nt = %d\n",start_time);
//printf("\nbg pos = %d",bg.R.x);
//printf("\ncol = %d",t);

xp_map=p.cor.x-bg.R.x;
yp_map=p.cor.y-bg.R.y;
SDL_Rect RP;
RP = p.cor;
RP.x = xp_map;
RP.y = yp_map;

xe_map=e.dest.x-bg.R.x;
ye_map=e.dest.y-bg.R.y;
SDL_Rect RE;
RE = e.dest;
RE.x = xe_map;
RE.y = ye_map;

//printf("\n\n\nplayer %d %d\n",p.cor.x,p.cor.y);
//printf("\n\nenemie %d %d\n",e.dest.x,e.dest.y);

miniMap(pressing_m,&m,RP,eg,RE,screen,SCREEN_W,SCREEN_H,"Assets/bg/bg0.png","Assets/bg/bg0.png","Assets/bg/bg0.png");

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

if(t2==3 && verifp2==1){
gravp2=p2.cor.y;
verifp2=0;}
if(t2==0 && verifp2 ==0){
	gravp2=SCREEN_H2-p2.cor.h*1.55;
	verifp2=1;
}
//---------------------------HIT OF CARAC------------------------

				if(hit==1&&b1.pos.x<bigx+500  && orr_b==0 ){		
						aff_b(b1,screen);
						b1.pos.x+=40;
						
				}

				else if(hit==1&&b1.pos.x>bigx-500  && orr_b==1 ){
						aff_b(b1,screen);
						b1.pos.x-=40;
				}
				

			
				else{
				hit=0;
				b1.pos.x=-6000;
				b1.pos.y=-6000;
				verifshoot=1;
				}
//----------------------------------------------------------------
				
				//if(p.viep>0){
						player4(&pvierefp2,damage,&currentframedamage,r7.r,&conteur,&stoprp2,&stoplp2,&orientationp2,&movep2,&jumpp2,&dirp2,&current_framess,&last_frame_time_stop_rightp2,&last_frame_time_stop_leftp2,&last_frame_time3p2,&last_frame_timessp2,&last_frame_timeleftp2 ,&last_frame_timejumpp2,&current_framejumpp2,&current_frame,&current_framelp2,&current_frame3p2,&current_frameleftp2,&p2,&gravp2,&velocityp2,&stopp2,screen,framescaracp2,frameslcaracp2,framesrightcaracp2,framesleftcaracp2,framesjumpcaracp2,framessscaracp2,SCREEN_HEIGHT,SCREEN_WIDTH);
			player4(&pvieref,damage,&currentframedamage,r7.r,&conteur,&stopr,&stopl,&orientation,&move,&jump,&dir,&current_framess,&last_frame_time_stop_right,&last_frame_time_stop_left,&last_frame_time3,&last_frame_timess,&last_frame_timeleft ,&last_frame_timejump,&current_framejump,&current_frame,&current_framel,&current_frame3,&current_frameleft,&p,&grav,&velocity,&stop,screen,framescarac,frameslcarac,framesrightcarac,framesleftcarac,framesjumpcarac,framessscarac,SCREEN_HEIGHT,SCREEN_WIDTH);
			shoot(&p,&currentframelive,&xp2,&pvieref,&hit2,&xp,&b2,&e,&bullet_counter,&bullet_counter2,&hitready2,&vie_counter,&vie_counter2,screen,&bg);
			shoot(&p,&currentframelive,&xp2e2,&pvieref,&hit2e2,&xpe2,&b22,&e2,&bullet_countere22,&bullet_counter2e2,&hitready2e2,&vie_countere2,&vie_counter2e2,screen,&bg);//}	
      		if(e2.vie>0){
      		aff_e(&vieenemy2,&currentframeliveenemy2,screen,rectvieenemy2.r);
      					enemymouvements(&b1,&currentframeliveenemy2,&xe2,&ye2,&bigxe2,&b22,&hitready2e2,&e2,&p,&hit2e2,&hit3e2,&movexe2,framesenemy2,frameslenemy2,screen,framesleftenemy2,framesrightenemy2,&oke2,&current_frameleft12,&current_frame212,&last_frame_timeleft12,&last_frame_time212);
      		}
      		if(e.vie>0)	{
      		aff_e(&vieenemy,&currentframeliveenemy,screen,r6.r);
			enemymouvements(&b1,&currentframeliveenemy,&x,&y,&bigx2,&b2,&hitready2,&e,&p,&hit2,&hit3,&movex,framesenemy,frameslenemy,screen,framesleftenemy,framesrightenemy,&ok,&current_frameleft1,&current_frame21,&last_frame_timeleft1,&last_frame_time21);
     	 				}								
 x = collisionBB(e.dest,b1.pos);
xe2 = collisionBB(e2.dest,b1.pos);      
 //printf("%d",level);
 
 //--------FIRST PLAYER-------//
if (level == 1){
	t=collisionPP(p.cor,bg.M[0],bg.R,251, 220, 156);
	det_green=collisionPP(p.cor,bg.M[0],bg.R,40, 200, 40);
}
if (level == 2){
	det_black=0;
	det_green=0;
	det_red=0;
	det_blue=0;

}
if (level == 3){
	lvl_depl2++;
	t=collisionPP(p.cor,bg.M[1],bg.R,251, 220, 156);
	det_black=collisionPP(p.cor,bg.M[1],bg.R,40, 40, 40);
	det_green=collisionPP(p.cor,bg.M[1],bg.R,40, 200, 40);
	det_red=collisionPP2(p.cor,bg.M[1],bg.R,200, 40, 40);
	det_blue=collisionPP(p.cor,bg.M[1],bg.R,40, 40, 200);

}
//-----SECOND PLAYER-----//
if (level2 == 1){
	t2=collisionPP(p2.cor,bg2.M[0],bg2.R,251, 220, 156);
	det_green2=collisionPP(p2.cor,bg2.M[0],bg2.R,40, 200, 40);
}
if (level2 == 2){
	det_black2=0;
	det_green2=0;
	det_red2=0;
	det_blue2=0;

}
if (level2 == 3){
	lvl2_depl2++;
	t=collisionPP(p2.cor,bg2.M[1],bg2.R,251, 220, 156);
	det_black2=collisionPP(p2.cor,bg2.M[1],bg2.R,40, 40, 40);
	det_green2=collisionPP(p2.cor,bg2.M[1],bg2.R,40, 200, 40);
	det_red2=collisionPP2(p2.cor,bg2.M[1],bg2.R,200, 40, 40);
	det_blue2=collisionPP(p2.cor,bg2.M[1],bg2.R,40, 40, 200);

}

if (lvl_depl2==1){
	bg.R.x = 0;
	bg.R.y = -SCREEN_HEIGHT*.85;
	p.cor.x = SCREEN_WIDTH/2+p.cor.w/2;
	e.dest.y=grav;
	e.dest.x=SCREEN_WIDTH+SCREEN_WIDTH/2;
	movex=SCREEN_WIDTH+SCREEN_WIDTH/2;

}
if(level == 1 &&nour==0)
{
initialiser_audio(music);
nour=1;} 
if(level == 3 &&nour1==0&&nour==1)
{
liberer_musique(music);
initialiser_audio1(music1);
nour1=1;
 }
 //------------------------------HINTS---------------------------
 if(conteurcontrols>=0){
 conteurcontrols++;
 if(conteurcontrols==40){
 gamestate=3;
 conteurcontrols=-100;
 }
 }
 }
 if(staterobots==4){
 currentframehelp=1;
 aff_e(&help,&currentframehelp,screen,helps.r); 
 }
 if(gamestate==2){
enigmefinal(&enigme1,&gamestate,ref,&r,&r2,&r3,&r4,&next,&frame,&currentframeenigme,&current_framereponse,&current_framereponse2,&current_framereponse3,&current_framereponse4,screen,&e1,&e1_stage,framesattend,framesnumber1,framesnumber2,framesnumber3,framesnumber4,framefinal);
 }
 //-----------------CONTROLS--------------------
 if(gamestate==3){
 if(suivant==1){
 gamestate=1;
 suivant=0;
 }
 if(suivant==0){
 aff_e(&controlls,&currentframecontrol,screen,contr.r); 
 currentframecontrol++;
 if(currentframecontrol==12){
 currentframecontrol=1;
 }
player4(&pvieref,damage,&currentframedamage,r7.r,&conteur,&stopr,&stopl,&orientation,&move,&jump,&dir,&current_framess,&last_frame_time_stop_right,&last_frame_time_stop_left,&last_frame_time3,&last_frame_timess,&last_frame_timeleft ,&last_frame_timejump,&current_framejump,&current_frame,&current_framel,&current_frame3,&current_frameleft,&pcontrols,&gravcontr,&velocity,&stop,screen,framescarac,frameslcarac,framesrightcarac,framesleftcarac,framesjumpcarac,framessscarac,SCREEN_HEIGHT,SCREEN_WIDTH);
 }}
 //-----------------CONTROLS--------------------
  if(e2.dest.x-p.cor.x<600 && gamestate==1 && verifhint==0){
 gamestate=4;
 verifhint=1;  
 }
 if(verifhint==1 && gamestate==4){
 bullet_counter2e2=0;
 bullet_countere22=0;
  aff_e(&hint,&currentframehint,screen,hints.r); 
   if(nexthint>5){
   gamestate=1;
   }
   currentframehint=nexthint;
 }
  serialPortReadDataLength = Arduino_read(serialPortBuffer, SERIAL_PORT_BUFFER_LENGTH);
        serialPortBuffer[serialPortReadDataLength] = 0;
 //--------------------------------MANETTE-------------------------------
 printf("right= %d,left=%d,up=%d \n",right,left,up);
    if(serialPortReadDataLength > 0)
        {    
            if(strStartsWith("R", serialPortBuffer))
            {
                 right=1;
                 left=0;
                 up=0;
            }
             if(strStartsWith("L", serialPortBuffer))
            {
                 left=1;
                  right=0;
                   up=0;
            }
            if(strStartsWith("U", serialPortBuffer))
            {
                 up=1;
                   right=0;
                 left=0;
            }
            if(strStartsWith("K", serialPortBuffer))
            {
                 up=1;
                   right=1;
                 left=0;
            }
            if(strStartsWith("O", serialPortBuffer))
            {
                 up=1;
                   right=0;
                 left=1;
            }
            if(strStartsWith("h", serialPortBuffer))
            {
                 
                 shoott=1;
            }
            if(strStartsWith("S", serialPortBuffer))
            {
                 right=0;
                 left=0;
                 up=0;
            }
             if (right ) {    
             	dir=1; 
             	stopr=0;
               orientation=0;
            }else{
            	dir=2;
					stopr=1;
            }
            if (left ) {
            	dir=0; 
               stopl=0;
               orientation=1;
            }else{
            	dir=2;
            	stopl=1;
            }
            if (up) {
            	jump=0;
               if(p.cor.y==grav)
            	   velocity=-20;
            }else{
            	jump=1;
            }
            if(shoott && verifshoot==1){
            b1.pos.x=p.cor.x+100;
                        b1.pos.y=p.cor.y+100;
                        bigx= b1.pos.x;
                        hit=1; 
                        orr_b = orientation;
                        verifshoot=0;
            }
            else{
            shoott=0;
            }
                             
           }
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
void enemymouvements(bullett *b1,int* currentframeliveenemy,int* x,int* y,int *bigx2,bullett *b2,int *hitready2,Ennemi *e,Personn *p,int *hit2,int* hit3,int *movex,SDL_Surface** framesenemy,SDL_Surface** frameslenemy,SDL_Surface *screen,SDL_Surface** framesleftenemy,SDL_Surface** framesrightenemy,int *ok,int *current_frameleft1,int* current_frame21, int* last_frame_timeleft1, int* last_frame_time21)
					{				
					
					if(*x==0)
      				*y = collisionBB(e->dest,b1->pos);
      	
      		       if(*x!=*y){
     		 			(e->vie)--;
     		 			(*currentframeliveenemy)--;
     		 			*y=1;}
					
					
					IA(e,p);
     	 					
   							if(e->STATE==0){
   								*hit2 = 0;
   								*hit3 = 0;
									move_waiting(movex,screen,framesenemy,frameslenemy,framesleftenemy,framesrightenemy,13,ok,e,current_frameleft1,last_frame_timeleft1,current_frame21,last_frame_time21);	
    							}
   							if(e->STATE==1){
      							e->direction=1;
      							*hit2=1;
      							move_following(screen,framesrightenemy, current_frameleft1, last_frame_timeleft1,13,e);
       							if(*hitready2==0){
       								b2->pos.x=e->dest.x+100;
       								b2->pos.y=e->dest.y+100;
       								*hit2=1;
     	 								*hitready2=1;}}     									
  								if(e->STATE==4){
      							e->direction=-1;
      							*hit2=1;
      							move_following(screen,framesleftenemy, current_frame21, last_frame_time21,13,e);
      							if(*hitready2==1){
       								b2->pos.x=e->dest.x+100;
      							 	b2->pos.y=e->dest.y+100;
      							 	*bigx2=b2->pos.x;
       								*hit2=1;
     	 								*hitready2=0;}}}
void shoot(Personn *p,int *currentframelive,int *xp2,int *pvieref,int *hit2,int* xp,bullett *b2,Ennemi *e,int *bullet_counter,int *bullet_counter2,int *hitready2,int *vie_counter,int *vie_counter2,SDL_Surface *screen,background *bg) {
//printf("\n xp = %d || viee=%d || vie= %d",*xp,*vie_counter,p->viep);
     		 			
     		 			
 if(e->STATE==0){
 *bullet_counter=0;
 *bullet_counter2=0;
 } 		 			
     		 			
 if(*bullet_counter<=100){
 (*bullet_counter)++;
 }
  if(*bullet_counter2<=100){
 (*bullet_counter2)++;
 }

 
     		 			if(*xp==0 && *vie_counter>10){
     				 	*currentframelive=p->viep;
     				 	*pvieref=p->viep;
     				 	(p->viep)--;
     		 			*vie_counter=0;}
     		 			
    		
     
     	//-------------------------SENDING BULLET TO LEFT ------------------------------- 
     			if(e->vie>0){
     			if (bg->R.y<0){
      			if(e->direction<0){
     							if(*xp==1)
    							 	(*vie_counter)++;
      						if (*hitready2==0)
      							(*bullet_counter2)++;
      	 		
     				 if (!(p->cor.x + p->cor.w/1.5 >= b2->pos.x + b2->pos.w && p->cor.x <= b2->pos.x && p->cor.y <= b2->pos.y && p->cor.y + p->cor.h >= b2->pos.y + b2->pos.h)&& *hit2 == 1 && *hitready2==0 && *bullet_counter2>100){
      					
      					affbulletleft(screen,b2,30);
      					*xp=1;}	
       				
       				else{
       					       if(p->cor.x + p->cor.w/1.5 >= b2->pos.x + b2->pos.w && p->cor.x <= b2->pos.x && p->cor.y <= b2->pos.y && p->cor.y + p->cor.h >= b2->pos.y + b2->pos.h){
       					       *xp=0;}
       					       b2->pos.x=e->dest.x+100;
							b2->pos.y=e->dest.y+100;
						if (*bullet_counter2>100){
							*hitready2=1;
							*bullet_counter2=0;}
							}
						
							
      				if (b2->pos.x<=p->cor.x-400){
      				                     b2->pos.x=e->dest.x+100;
							b2->pos.y=e->dest.y+100;
						if (*bullet_counter2>100){
							*hitready2=1;
							*bullet_counter2=0;}}
							if (b2->pos.x<0){
      				                     b2->pos.x=e->dest.x+100;
							b2->pos.y=e->dest.y+100;
						if (*bullet_counter2>100){
							*hitready2=1;
							*bullet_counter2=0;}}
							
							
						}
						//-------------------- Bullet to the right------------
						if((*xp2==0 && *vie_counter2>10)){
     		 			*currentframelive=p->viep;
     		 			*pvieref=p->viep;
     				 	(p->viep)--; 	
     		 		*vie_counter2=0;}
						if(e->direction>0){
					
					if(*xp2==1){
					(*vie_counter2)++;
					}
    							 
				       if (*hitready2==1){
      				      (*bullet_counter)++;
      					} 						   
      				//-WHILE NOT COLLIDED-
     					
     					 if (!(p->cor.x + p->cor.w/1.5 >= b2->pos.x + b2->pos.w && p->cor.x <= b2->pos.x && p->cor.y <= b2->pos.y && p->cor.y + p->cor.h >= b2->pos.y + b2->pos.h)&& *hit2 == 1 && *hitready2==1 && *bullet_counter>100){
      				affbullet(screen,b2,30);
      				*xp2=1;}	
       				//-WHILE  COLLIDED-
      				 else{
     		 					
     		 					if(p->cor.x + p->cor.w/1.5 >= b2->pos.x + b2->pos.w && p->cor.x <= b2->pos.x && p->cor.y <= b2->pos.y && p->cor.y + p->cor.h >= b2->pos.y + b2->pos.h){
     		 						*xp2=0;}
     		 						
								b2->pos.x=e->dest.x+100;
								b2->pos.y=e->dest.y+100;
								if (*bullet_counter>100){
									*hitready2=0;
									*bullet_counter=0;}
									
								}
						
     					if (b2->pos.x>=p->cor.x+300){
								b2->pos.x=e->dest.x+100;
								b2->pos.y=e->dest.y+100;
								if (*bullet_counter>100){
									*hitready2=0;
									*bullet_counter=0;}}}
}}}
int strStartsWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}
