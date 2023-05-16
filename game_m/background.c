#include "background.h"

void initBack(background *b, int SCREEN_WIDTH, int SCREEN_HEIGHT){
	char ch[20];
	
	for (int i=0;i<=9;i++){
		initAnim(i,&ch);
		Resize(&(b->S[i]), ch, SCREEN_WIDTH*3.75, SCREEN_HEIGHT*1.8);
	}
	b->R.y=-SCREEN_HEIGHT*.85;
	Resize(&(b->M), "Assets/BG_M.png", SCREEN_WIDTH*3.75, SCREEN_HEIGHT*1.8);
	
	b->R.w = SCREEN_WIDTH;
	b->R.h = SCREEN_HEIGHT;
}

void afficherBack(background bg, SDL_Surface * screen){
	SDL_BlitSurface(bg.S[0], 0, screen, &bg.R);
}

void scrolling(SDL_Rect *r, int direction, int SCREEN_WIDTH){
	if (direction==1){
		r->x+=SCREEN_WIDTH/40;
	}else{
		r->x-=SCREEN_WIDTH/40;
	}
}

void initAnim(int i, char *ch){
	sprintf(ch, "Assets/bg/bg%d.png", i);
}

void Score_Storing(player *P){
	FILE *fp = fopen("Assets/Files/scores.txt", "a");
	
	printf("\nInput Your Name : ");
	fflush(stdin);
	scanf("%s",P->name);
	printf("\nYour Score : %d\n",P->score);
	
	fprintf(fp, "%s %d\n", P->name, P->score);
	fclose(fp);
}

void Score_Extracting(char *ch1, int *x1, char *ch2, int *x2, char *ch3, int *x3){
	FILE *fp = fopen("Assets/Files/scores.txt", "r");
	
	player players[200];
	
	int num_players = 0;
	
	while (fscanf(fp, "%s %d\n", players[num_players].name, &players[num_players].score) == 2) {
		num_players++;
	}
	
	qsort(players, num_players, sizeof(player), comparePlayers);
	
	strcpy(ch1, players[0].name);
	*x1 = players[0].score;
	
	strcpy(ch2, players[1].name);
	*x2 = players[1].score;
	
	strcpy(ch3, players[2].name);
	*x3 = players[2].score;
	
	/*printf("\n\nTop 3 scoring players:");
	for (int i = 0; i < 3 && i < num_players; i++) {
		printf("\n%d. %s - %d", i+1, players[i].name, players[i].score);
	}*/
	fclose(fp);
}

int comparePlayers(const void *a, const void *b) {
	player *playerA = (player *)a;
	player *playerB = (player *)b;

	return (playerB->score - playerA->score);
}

void Resize(SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT){
	SDL_Surface *Buffer = IMG_Load(dir);
	
	
	*(Image) = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, Buffer->format->BitsPerPixel, Buffer->format->Rmask, Buffer->format->Gmask,  Buffer->format->Bmask, Buffer->format->Amask);

	
	SDL_SoftStretch(Buffer, NULL, *(Image), NULL);
	
	SDL_FreeSurface(Buffer);
}

void run_game(background* bg, player* P, SDL_Rect *rect, SDL_Surface* screen, int SCREEN_WIDTH, int SCREEN_HEIGHT, int *g_e_a, int WIDTH, int *anim_frame, int *anim_frame_time, Uint32 move_interval, Uint32 last_move_time, int *game_ended, int *trigger, int *done, SDL_Rect *dest, SDL_Rect *b1, SDL_Rect *b2, int *limit, int *level, int *movex){
			afficherBack(*bg,screen);
			//SDL_BlitSurface(bg->S, 0, screen, &(bg->R));
			//printf("\n bg pos x : %d\n bg pos y : %d",bg->R.x,bg->R.y);
			//printf("\n limit : %d",*limit);
			P->score++;
			*anim_frame_time+=1;
			if(*anim_frame_time ==10){
				*anim_frame+=1;
				*anim_frame_time=0;
			}
			if(*anim_frame==9){
				*anim_frame=0;
			}
			Uint8* keys = SDL_GetKeyState(NULL);	
			if(!(*game_ended)){
			
				if (*level == 1){
					if (rect->x>1385){
						if (keys[SDLK_UP] && bg->R.y < 0){
							bg->R.y=0;
							b1->y+=SCREEN_HEIGHT*.85;
							b2->y+=SCREEN_HEIGHT*.85;
							dest->y+=SCREEN_HEIGHT*.85;
						}
						if (keys[SDLK_DOWN] && bg->R.y == 0){
							bg->R.y=-SCREEN_HEIGHT*.85;
							b1->y-=SCREEN_HEIGHT*.85;
							b2->y-=SCREEN_HEIGHT*.85;
							dest->y-=SCREEN_HEIGHT*.85;
						}
					}
				}
			
				if (keys[SDLK_RIGHT]){
					Uint32 current_time = SDL_GetTicks();
					if (current_time - last_move_time >= move_interval){
						if(*trigger==1 && rect->x > (SCREEN_WIDTH / 2)){
							scrolling(&(bg->R),0,SCREEN_WIDTH);
							if (!(*limit)){
							       scrolling(dest,0,SCREEN_WIDTH);
							       //dest->x-=SCREEN_WIDTH/40;
							       *movex-=SCREEN_WIDTH/40;
							       b1->x-=SCREEN_WIDTH/40;
							       b2->x-=SCREEN_WIDTH/40;
							}
						}
						//scrolling(rect,1,SCREEN_WIDTH);
						last_move_time = current_time;
					}
				}
				
				if (keys[SDLK_LEFT]){
					Uint32 current_time = SDL_GetTicks();
					if (current_time - last_move_time >= move_interval){ 
						if(*trigger==1 && rect->x < (SCREEN_WIDTH / 2)){
							scrolling(&(bg->R),1,SCREEN_WIDTH);
							if (!(*limit)){
							       scrolling(dest,1,SCREEN_WIDTH);
							       //dest->x+=SCREEN_WIDTH/40;
							        *movex+=SCREEN_WIDTH/40;
							       b1->x+=SCREEN_WIDTH/40;
							       b2->x+=SCREEN_WIDTH/40;
							}
						}
						//scrolling(rect,0,SCREEN_WIDTH);
						last_move_time = current_time;
					}
				}
			}else{
				
				if(*g_e_a<1){
					*g_e_a+=1;
					Score_Storing(P);
					*done = 0;
				}
			}
			if(bg->R.x >= 0){
				bg->R.x = 0;
				*limit = 1;
			}
			if (bg->R.x <= -SCREEN_WIDTH*2.4175-SCREEN_WIDTH/3){
				bg->R.x = -SCREEN_WIDTH*2.4175-SCREEN_WIDTH/3;
				*limit = 1;
			}
			if ((bg->R.x > -SCREEN_WIDTH*2.41-SCREEN_WIDTH/3)&&(bg->R.x < 0)){
			       *limit = 0;
			}
			
			*trigger = 0;
			printf("\nplayer pos : %d",rect->x);
			if(*limit){
				if(bg->R.x >=(-SCREEN_WIDTH*2.4175)/2){
					if(rect->x+rect->w >= SCREEN_WIDTH-(SCREEN_WIDTH/3)){
						rect->x = SCREEN_WIDTH-(rect->w)-(SCREEN_WIDTH/3);
						*trigger = 1;
					}
				}else{
					if(rect->x <= SCREEN_WIDTH/3){
						rect->x = SCREEN_WIDTH/3;
						*trigger = 1;
					}
					if(rect->x+rect->w >= SCREEN_WIDTH - SCREEN_WIDTH/50){
						rect->x = SCREEN_WIDTH-rect->w-SCREEN_WIDTH/50;
					}
				}
				
			}else{
				if(rect->x <= SCREEN_WIDTH/3){
					rect->x = SCREEN_WIDTH/3;
					*trigger = 1;
				}
				if(rect->x+rect->w >= SCREEN_WIDTH-(SCREEN_WIDTH/3)){
					rect->x = SCREEN_WIDTH-(rect->w)-(SCREEN_WIDTH/3);
					*trigger = 1;
				}
			}
			
			
			
			//printf("\n bg pos = %d", bg->R.x);
			
}
