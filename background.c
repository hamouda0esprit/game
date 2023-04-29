#include "background.h"

void initBack(background *b, int SCREEN_WIDTH, int SCREEN_HEIGHT, int anim_frame){
	char ch[20];
	initAnim(anim_frame,ch);
	//printf("\n %s",ch);
	//b->S = IMG_Load(ch);
	Resize(&(b->S), ch, SCREEN_WIDTH*3.3, SCREEN_HEIGHT*2.16);
	b->R.w = SCREEN_WIDTH*3.3;
	b->R.h = SCREEN_HEIGHT*2.16;
}

void afficherBack(background bg, SDL_Surface * screen){
	SDL_BlitSurface(bg.S, 0, screen, &bg.R);
}

void scrolling(SDL_Rect *r, int direction, int SCREEN_WIDTH){
	if (direction==1){
		r->x+=SCREEN_WIDTH/40;
	}else{
		r->x-=SCREEN_WIDTH/40;
	}
}

void initAnim(int anim_frame, char *ch){
	sprintf(ch, "Assets/bg/bg%d.png", anim_frame);
}

void initButton(button *B1, int SCREEN_WIDTH){
	Resize(&(B1->S), "Assets/B_Score.png", SCREEN_WIDTH/8, SCREEN_WIDTH/16);
	B1->R.x=SCREEN_WIDTH/80;
	B1->R.y=SCREEN_WIDTH/80;
	B1->R.w = SCREEN_WIDTH/8;
	B1->R.h = SCREEN_WIDTH/16;
}

void Score_Storing(player_2 *P){
	FILE *fp = fopen("Assets/Files/scores.txt", "a");
	
	printf("\nInput Your Name : ");
	fflush(stdin);
	scanf("%s",P->name);
	printf("\nYour Score : %d\n",P->score);
	
	fprintf(fp, "%s %d\n", P->name, P->score);
	fclose(fp);
}

void Score_Extracting(){
	FILE *fp = fopen("Assets/Files/scores.txt", "r");
	
	player_2 players[200];
	
	int num_players = 0;
	
	while (fscanf(fp, "%s %d\n", players[num_players].name, &players[num_players].score) == 2) {
		num_players++;
	}
	
	qsort(players, num_players, sizeof(player_2), comparePlayers);
	//printf("\nnum players = %d",num_players);
	printf("\n\nTop 3 scoring players:");
	for (int i = 0; i < 3 && i < num_players; i++) {
		printf("\n%d. %s - %d", i+1, players[i].name, players[i].score);
	}
	
	printf("\n");
	fclose(fp);
}

int comparePlayers(const void *a, const void *b) {
	player_2 *playerA = (player_2 *)a;
	player_2 *playerB = (player_2 *)b;

	return (playerB->score - playerA->score);
}


void run_game(background* bg, player_2* P, button* B1, SDL_Rect *rect, SDL_Surface* screen, int SCREEN_WIDTH, int SCREEN_HEIGHT, Uint32 color, int *g_e_a, int *anim_frame, int *anim_frame_time, Uint32 move_interval, Uint32 last_move_time, int *game_ended, int *trigger) {
			initBack(bg, SCREEN_WIDTH, SCREEN_HEIGHT, *anim_frame);
			afficherBack(*bg,screen);
			SDL_BlitSurface(B1->S, 0, screen, &(B1->R));
			
			
			P->score++;
			*anim_frame_time+=1;
			if(*anim_frame_time ==10){
				*anim_frame+=1;
				*anim_frame_time=0;
			}
			if(*anim_frame==12){
				*anim_frame=0;
			}
			//printf("\nanim_frame = %d",*anim_frame);
			//printf("\nanim_frame_time = %d",*anim_frame_time);
			//printf("\n trigger = %d", *trigger);
			
			Uint8* keys = SDL_GetKeyState(NULL);
			if(!(*game_ended)){
				if (keys[SDLK_RIGHT]){
					Uint32 current_time = SDL_GetTicks();
					if (current_time - last_move_time >= move_interval){
						if(*trigger==1){
							scrolling(&(bg->R),0,SCREEN_WIDTH);
							printf("\n moving right !");
						}
						scrolling(rect,1,SCREEN_WIDTH);
						last_move_time = current_time;
					}
				}
				
				if (keys[SDLK_LEFT]){
					Uint32 current_time = SDL_GetTicks();
					if (current_time - last_move_time >= move_interval){
						if(*trigger==1){
							scrolling(&(bg->R),1,SCREEN_WIDTH);
							
						}
						scrolling(rect,0,SCREEN_WIDTH);
						last_move_time = current_time;
					}
				}
			}else{
				
				if(*g_e_a<1){
					*g_e_a+=1;
					Score_Storing(P);
				}
			}
			
			*trigger = 0;
			if(rect->x <= SCREEN_WIDTH/8){
				rect->x = SCREEN_WIDTH/8;
				*trigger = 1;
			}
			if(rect->x+rect->w >= SCREEN_WIDTH-(SCREEN_WIDTH/8)){
				rect->x = SCREEN_WIDTH-(rect->w)-(SCREEN_WIDTH/8);
				*trigger = 1;
			}
			printf("\n bg pos = %d", bg->R.x);
			if(bg->R.x >= 0){
				bg->R.x = 0;
			}
			if (bg->R.x <= -SCREEN_WIDTH*2-SCREEN_WIDTH/3){
				bg->R.x = -SCREEN_WIDTH*2-SCREEN_WIDTH/3;
			}
}
