#include "background.h"

void main(){
	
	background bg;
	int SCREEN_WIDTH = 800;
	int SCREEN_HEIGHT =  (float)(SCREEN_WIDTH / 1.7777777777777777);
	SDL_Surface *screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
	
	int WIDTH=50;
	int HEIGHT=50;
	
	int center_x = (SCREEN_WIDTH - WIDTH) / 2;
	int center_y = (SCREEN_HEIGHT - HEIGHT) / 2;
	 
	SDL_Rect rect = {center_x, center_y, WIDTH, HEIGHT};	
	
	char ch[20];
	int anim_frame=0;
	int anim_frame_time=0;
	
	button B1;
	initButton(&B1, SCREEN_WIDTH);
	player P;
	P.score =0;
	
	
	int trigger;
	
	Uint32 move_interval = 5;
	Uint32 last_move_time = SDL_GetTicks();
	
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Event event;
	
	Uint32 color = SDL_MapRGB(screen->format, 255, 0, 0);
	
	int x;
	int y;
	
	int game_ended=0;
	int g_e_a=0;
	
	int Button_Clicked=0;
	
	SDL_bool done = SDL_FALSE;
	while(!done){
		x = event.button.x;
		y = event.button.y;
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					done = SDL_TRUE;
					break;
				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_a){
						printf("\nGAME ENDED !\n");
						game_ended=1;
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (x >= B1.R.x && x <= B1.R.x + B1.R.w && y >= B1.R.y && y <= B1.R.y + B1.R.h){
						Score_Extracting();
					}
			}
		}
		run_game(&bg, &P, &B1, &rect, screen, SCREEN_WIDTH, SCREEN_HEIGHT, color, &g_e_a, WIDTH, &anim_frame, &anim_frame_time, move_interval, last_move_time, &game_ended, &trigger, &done);
		SDL_FillRect(screen, &rect, color);
		
		SDL_Delay(5);
		SDL_Flip(screen);
		SDL_FreeSurface(bg.S);
	}
}

