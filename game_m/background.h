#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct{
	SDL_Surface *S;
	SDL_Rect R;
}background;

typedef struct{
	SDL_Surface *S;
	SDL_Rect R;
}button;

typedef struct{
	char name[20];
	int score;
}player;

void run_game(background* bg, player* P, button* B1, SDL_Rect *rect, SDL_Surface* screen, int SCREEN_WIDTH, int SCREEN_HEIGHT, int *g_e_a, int WIDTH, int *anim_frame, int *anim_frame_time, Uint32 move_interval, Uint32 last_move_time, int *game_ended, int *trigger, int *done, SDL_Rect *dest, SDL_Rect *b1, SDL_Rect *b2, int *limit);
void initBack(background *b, int SCREEN_WIDTH, int SCREEN_HEIGHT, int anim_frame);
void afficherBack(background bg, SDL_Surface *screen);
void scrolling(SDL_Rect *r, int direction, int SCREEN_WIDTH);
void initAnim(int anim_frame, char *ch);
void initButton(button *B1, int SCREEN_WIDTH);
void Score_Storing(player *P);
void Score_Extracting();
int comparePlayers(const void *a, const void *b);
void Resize(SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT);
