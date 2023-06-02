#include "background.h"
#define SERIAL_PORT_BUFFER_LENGTH   20

void initBack(background *b, int SCREEN_WIDTH, int SCREEN_HEIGHT){
	char ch[20];
	
	for (int i=0;i<=3;i++){
		initAnim(i,&ch);
		if (i==0 || i==2){
			Resize(&(b->S[i]), ch, SCREEN_WIDTH*3.75, SCREEN_HEIGHT*1.8);
		}
		if (i==1){
			Resize(&(b->S[i]), ch, SCREEN_WIDTH*2, SCREEN_HEIGHT);
		}
		if (i==3){
		       Resize(&(b->S[i]), ch, SCREEN_WIDTH*5, SCREEN_HEIGHT*.92);
		}
		
	}
	b->R.y=-SCREEN_HEIGHT*.85;
	Resize(&(b->M[0]), "Assets/BG_M.png", SCREEN_WIDTH*3.75, SCREEN_HEIGHT*1.8);
	Resize(&(b->M[1]), "Assets/BG_M2.png", SCREEN_WIDTH*3.75, SCREEN_HEIGHT*1.8);
	
	b->R.w = SCREEN_WIDTH;
	b->R.h = SCREEN_HEIGHT;
}

void afficherBack(background bg, SDL_Surface * screen, int level){
	SDL_BlitSurface(bg.S[level-1] ,0, screen, &bg.R);
}


void scrolling(SDL_Rect *r, int direction, int SCREEN_WIDTH){
	if (direction==1){
		r->x+=SCREEN_WIDTH/120;
	}else{
		r->x-=SCREEN_WIDTH/120;
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

void run_game(Ennemi e,int *detectrobot,int *detect,int *enigme3 ,int *movex2, int *movex4, SDL_Rect *dest4, int *movex3, SDL_Rect *dest3, int right, int left, int up, int *state,SDL_Rect *dest2,int* test,background* bg, player* P, SDL_Rect *rect, SDL_Surface* screen, int SCREEN_WIDTH, int SCREEN_HEIGHT, int *g_e_a, int WIDTH, int *anim_frame, int *anim_frame_time, Uint32 move_interval, Uint32 last_move_time, int *game_ended, int *trigger, int *done, SDL_Rect *dest, SDL_Rect *b1, SDL_Rect *b2, int *limit, int *level, int *movex, int t, int det_green, int det_red, int det_blue, int det_black,int *e1_stage, int *enigme1, int *enigme2){
			afficherBack(*bg,screen,*level);
			
			int speed = SCREEN_WIDTH/120;
			//SDL_BlitSurface(bg->S, 0, screen, &(bg->R));
			//printf("\n bg pos x : %d\n bg pos y : %d",bg->R.x,bg->R.y);
			//printf("\n limit : %d",*limit);
			//printf("\n enigme2 = %d", *enigme2);
			//printf("\n det_black = %d ", det_black);
			//printf("\n det_red = %d ", det_red);
			//printf("\n det_green = %d ", det_green);
			//printf("\n det_blue = %d ", det_blue);
			
			if (det_green != 0){
				if(*level==1){
					if(bg->R.x <= 0 && bg->R.x > -1100 && bg->R.y != 0){
						*e1_stage = 1;
					}
					if(bg->R.x <= -1100 && bg->R.x > -2800 && bg->R.y != 0){
						*e1_stage = 2;
					}
					if(bg->R.x <= -3700 && bg->R.y != 0){
						*e1_stage = 3;
					}
					if(bg->R.x <= -4000 && bg->R.y == 0){
						*e1_stage = 4;
					}
					if(bg->R.x <= 0 && bg->R.x > -600 && bg->R.y == 0){
					*e1_stage = 5;
					}
				}
				
			}else{
				*e1_stage = 0;
			}
			if (*level==1 && *enigme1 == 1){
				if(bg->R.x <= 0 && bg->R.x > -300 && bg->R.y == 0 && *limit && rect->x < 300){
					*level+=1;
				}
			}
			if (*level==2){
				if (rect->x > SCREEN_WIDTH-SCREEN_WIDTH/4){
					*level+=1;
				}
			}
			if (*level == 3){
				if (det_blue!=0){
					if(rect->x >= SCREEN_WIDTH/2){
						rect->x = rect->x - SCREEN_WIDTH;
					}else{
						rect->x = rect->x + SCREEN_WIDTH;
					}
					
				}
				if (*enigme2 == 1 && bg->R.y == 0 && rect->x >= SCREEN_WIDTH/1.5 && *limit == 1 && e.vie<=0){
				       *level += 1;
				       *detectrobot=1;
				}
				if (*enigme2 == 1 && bg->R.y == 0 && rect->x >= SCREEN_WIDTH/1.5 && *limit == 1 && e.vie>0){
				       
				       *detectrobot=5;
				}
			}
			
			if (*level == 4 && ( t == 0 || t == 3 ) && *limit == 0){
			       rect->x-=speed/1.2;
			       bg->R.x-=speed/1.2;
			}
			if (*level == 4 && *enigme3 == 1 && det_blue != 0){
			       printf("\nwon ! won ! won ! won ! won ! won ! won ! won ! won ! won ! won ! won ! won ! won ! won ! won ! won ! won ! won ! ");
			}
			
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
				if (*level == 1 && *state==1){
					if (rect->x>1385){
						if ((keys[SDLK_UP] || up) && bg->R.y < 0){
							bg->R.y=0;
							b1->y+=SCREEN_HEIGHT*.85;
							b2->y+=SCREEN_HEIGHT*.85;
							dest->y+=SCREEN_HEIGHT*.85;
							rect->y=rect->y+SCREEN_HEIGHT/2;
							
							*test=1;
						}
						if (keys[SDLK_DOWN] && bg->R.y == 0){
							bg->R.y=-SCREEN_HEIGHT*.85;
							b1->y-=SCREEN_HEIGHT*.85;
							b2->y-=SCREEN_HEIGHT*.85;
							dest->y-=SCREEN_HEIGHT*.85;
							rect->y=rect->y-SCREEN_HEIGHT/2;
						}
					}
				}
				if(*level == 3){
					if (det_black!=0 && bg->R.y < 0 && (keys[SDLK_UP] || up)){
					*detect=0;
						bg->R.y=0;
						b1->y+=SCREEN_HEIGHT*.85;
						b2->y+=SCREEN_HEIGHT*.85;
						dest3->y+=SCREEN_HEIGHT*.85;
						dest4->x+=11000;
						rect->y=rect->y+SCREEN_HEIGHT/2;
					}
					if (det_black!=0 && keys[SDLK_DOWN] && bg->R.y == 0){
					                     *detect=1;
								bg->R.y=-SCREEN_HEIGHT*.85;
								b1->y-=SCREEN_HEIGHT*.85;
								b2->y-=SCREEN_HEIGHT*.85;
								dest3->y-=SCREEN_HEIGHT*.85;
								dest4->x-=11000;
								rect->y=rect->y-SCREEN_HEIGHT/2;
					}
				}
				if (*level != 4){
				       if (keys[SDLK_RIGHT] || right){
					       Uint32 current_time = SDL_GetTicks();
					       if (current_time - last_move_time >= move_interval){
							       if(*trigger==1 && rect->x > (SCREEN_WIDTH / 2)){
							       if((t==0 || t==1 || t==3) && (det_red == 0 || det_red == 1)){
								       scrolling(&(bg->R),0,SCREEN_WIDTH);
								       if (!(*limit)){
									       if(*level == 1){
									          scrolling(dest,0,SCREEN_WIDTH);
									          scrolling(dest2,0,SCREEN_WIDTH);
									          *movex-=speed;
									          //*movex3-=speed;
									       }
									       if(*level == 3){
									          scrolling(dest3,0,SCREEN_WIDTH);
									          scrolling(dest4,0,SCREEN_WIDTH);
									          /**movex3-=speed;
									          *movex4-=speed;*/
									       }
									          //dest->x-=SCREEN_WIDTH/40;
										       
									          b1->x-=speed;
									          b2->x-=speed;
								       }
							       }
						       }
						       if((t==0 || t==1 || t==3) && (det_red == 0 || det_red == 1)){
							       scrolling(rect,1,SCREEN_WIDTH);
						       }
						       last_move_time = current_time;
					       }
				       }
				       
				       if (keys[SDLK_LEFT] || left){
					       Uint32 current_time = SDL_GetTicks();
					       if (current_time - last_move_time >= move_interval){ 
						       if(*trigger==1 && rect->x < (SCREEN_WIDTH / 2)){
							       if((t==0 || t==2 || t==3) && (det_red == 0 || det_red == 2)){
								       scrolling(&(bg->R),1,SCREEN_WIDTH);
								       if (!(*limit)){
									          if(*level == 1){
									          scrolling(dest,1,SCREEN_WIDTH);
									          scrolling(dest2,1,SCREEN_WIDTH);
									          *movex+=speed;
									          //*movex2+=speed;
									       }
									       if(*level == 3){
									          scrolling(dest3,1,SCREEN_WIDTH);
									          scrolling(dest4,1,SCREEN_WIDTH);
									          /**movex3+=speed;
									          *movex4+=speed;*/
									       }
									          //dest->x+=SCREEN_WIDTH/40;
										       
									          b1->x+=speed;
									          b2->x+=speed;
								       }
							       }
						       }
						       if((t==0 || t==2 || t==3) && (det_red == 0 || det_red == 2)){
							       scrolling(rect,0,SCREEN_WIDTH);
						       }
						       
						       last_move_time = current_time;
					       }
				       }
				}else{
				       if (det_red != 0){
				              bg->R.x = 0;
                                          dest->x = 0;
				       }
				       if (keys[SDLK_RIGHT] || right){
					       Uint32 current_time = SDL_GetTicks();
					       if (current_time - last_move_time >= move_interval){
							       if(*trigger==1 && rect->x > (SCREEN_WIDTH / 2)){
							       if(t==0 || t==1 || t==3){
								       scrolling(&(bg->R),0,SCREEN_WIDTH);
								       if (!(*limit)){
									       if(*level == 1){
									          scrolling(dest,0,SCREEN_WIDTH);
									          scrolling(dest2,0,SCREEN_WIDTH);
									          *movex-=speed;
									          //*movex3-=speed;
									       }
									       if(*level == 3){
									          scrolling(dest3,0,SCREEN_WIDTH);
									          scrolling(dest4,0,SCREEN_WIDTH);
									          /**movex3-=speed;
									          *movex4-=speed;*/
									       }
									          //dest->x-=SCREEN_WIDTH/40;
										       
									          b1->x-=speed;
									          b2->x-=speed;
								       }
							       }
						       }
						       if(t==0 || t==1 || t==3){
							       scrolling(rect,1,SCREEN_WIDTH);
						       }
						       last_move_time = current_time;
					       }
				       }
				       
				       if (keys[SDLK_LEFT] || left){
					       Uint32 current_time = SDL_GetTicks();
					       if (current_time - last_move_time >= move_interval){ 
						       if(*trigger==1 && rect->x < (SCREEN_WIDTH / 2)){
							       if(t==0 || t==2 || t==3){
								       scrolling(&(bg->R),1,SCREEN_WIDTH);
								       if (!(*limit)){
									          if(*level == 1){
									          scrolling(dest,1,SCREEN_WIDTH);
									          scrolling(dest2,1,SCREEN_WIDTH);
									          *movex+=speed;
									          //*movex2+=speed;
									       }
									       if(*level == 3){
									          scrolling(dest3,1,SCREEN_WIDTH);
									          scrolling(dest4,1,SCREEN_WIDTH);
									          /**movex3+=speed;
									          *movex4+=speed;*/
									       }
									          //dest->x+=SCREEN_WIDTH/40;
										       
									          b1->x+=speed;
									          b2->x+=speed;
								       }
							       }
						       }
						       if(t==0 || t==2 || t==3){
							       scrolling(rect,0,SCREEN_WIDTH);
						       }
						       
						       last_move_time = current_time;
					       }
				       }
				}
			}else{
				
				if(*g_e_a<1){
					*g_e_a+=1;
					Score_Storing(P);
					*done = 0;
				}
			}
			if(*level==1 || *level==3){
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
			}
			if(*level==2){
				if(bg->R.x >= 0){
					bg->R.x = 0;
					*limit = 1;
				}
				if (bg->R.x <= -SCREEN_WIDTH*0.5175-SCREEN_WIDTH/3){
					bg->R.x = -SCREEN_WIDTH*0.5175-SCREEN_WIDTH/3;
					*limit = 1;
				}
				if ((bg->R.x > -SCREEN_WIDTH*0.5-SCREEN_WIDTH/3)&&(bg->R.x < 0)){
			       *limit = 0;
				}
			}
			if(*level==4){
			       if(bg->R.x >= 0){
					bg->R.x = 0;
					*limit = 1;
				}
				if (bg->R.x <= -SCREEN_WIDTH*3.6175-SCREEN_WIDTH/3){
					bg->R.x = -SCREEN_WIDTH*3.6175-SCREEN_WIDTH/3;
					*limit = 1;
				}
				if ((bg->R.x > -SCREEN_WIDTH*3.6-SCREEN_WIDTH/3)&&(bg->R.x < 0)){
			       *limit = 0;
				}
			}
			//printf("\nlevel & limit= %d | %d",*level,*limit);
			
			if (rect->x < rect->w/3){
						rect->x = rect->w/3;
					}
			*trigger = 0;
			//printf("\nplayer pos : %d",rect->x);
			if(*limit){
				if(*level==1 || *level==3){
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
				}if(*level==2){
					if(bg->R.x >=(-SCREEN_WIDTH*0.5175)/2){
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
				}
				if(*level==4){
					if(bg->R.x >=(-SCREEN_WIDTH*3.6175)/2){
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
void initialiser_audio(Mix_Music *music)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
    printf("%s",SDL_GetError());
    
}
music=Mix_LoadMUS("bp.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME);

}
void initialiser_audio1(Mix_Music *music)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
    printf("%s",SDL_GetError());
    
}
music=Mix_LoadMUS("transition.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME);

}
void initialiser_audio2(Mix_Music *music)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
    printf("%s",SDL_GetError());
    
}
music=Mix_LoadMUS("an.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME);

}

void liberer_musique(Mix_Music *music)
{
Mix_FreeMusic(music);
}
void initialiser_audiobref(Mix_Chunk *music)
{
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
music = Mix_LoadWAV("simple.wav");
Mix_PlayChannel( -1, music, 0 );
if(music==NULL) printf("%s",SDL_GetError());
}

void liberer_musiquebref(Mix_Chunk *music)
{
Mix_FreeChunk(music);
}








