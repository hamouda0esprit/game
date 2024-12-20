#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct{
	SDL_Surface *S[10];
	SDL_Surface *M[2];
	SDL_Rect R;
	SDL_Rect R2;
}background;

typedef struct{
	char name[20];
	int score;
}player;

void run_game(int playercount, int right, int left, int up, int *state,SDL_Rect *rect2,int* test,background* bg, player* P, SDL_Rect *rect, SDL_Surface* screen, int SCREEN_WIDTH, int SCREEN_HEIGHT, int *g_e_a, int WIDTH, int *anim_frame, int *anim_frame_time, Uint32 move_interval, Uint32 last_move_time, int *game_ended, int *trigger, int *done, SDL_Rect *dest, SDL_Rect *b1, SDL_Rect *b2, int *limit, int *level, int *movex, int t, int det_green, int det_red, int det_blue, int det_black,int *e1_stage, int *enigme1, int *enigme2);
void initBack(background *b, int SCREEN_WIDTH, int SCREEN_HEIGHT);
void afficherBack(background bg, SDL_Surface *screen, int level);
void scrolling(SDL_Rect *r, int direction, int SCREEN_WIDTH);
void initAnim(int i, char *ch);
int strStartsWith(const char *pre, const char *str);
void Score_Storing(player *P);
void Score_Extracting(char *ch1, int *x1, char *ch2, int *x2, char *ch3, int *x3);
int comparePlayers(const void *a, const void *b);
void Resize(SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT);
void initialiser_audio(Mix_Music *music);
void liberer_musique(Mix_Music *music);
void initialiser_audiobref(Mix_Chunk *music);
void liberer_musiquebref(Mix_Chunk *music);
void initialiser_audio1(Mix_Music *music);
void initialiser_audio2(Mix_Music *music);

