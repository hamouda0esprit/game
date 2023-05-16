#ifndef FONCTIONN_H
#define FONCTIONN_H
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct{
SDL_Rect cor;
int viep;
}Personn;
typedef struct{
SDL_Rect pos;
SDL_Surface *image;
}bullett;
void aff_e(SDL_Surface **framesright,int *current_frame21,SDL_Surface *screen,SDL_Rect dest);
void initcarac(int NUM_FRAMESstopleft,int NUM_FRAMESstopright,int NUM_FRAMESright,int NUM_FRAMESjump,int NUM_FRAMESleft, SDL_Surface **frames, SDL_Surface **framesl, SDL_Surface **framesright, SDL_Surface **framesleft, SDL_Surface **framesjump,SDL_Surface **framesss);
void loadanimationcaractere(int numframes ,SDL_Surface **frames,char dest[],int SCREEN_WIDTH, int SCREEN_HEIGHT);
void Resizecaractere(SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT);
void update_animationright2(int *current_frame, Uint32 *last_frame_time,int NUM_FRAMES);
void render_animationright2(SDL_Surface *screen, SDL_Surface **frames, int current_frame,Personn *p);
void player4(int *stopr,int *stopl,int* orientation,int* move,int* jump,int* dir,int* current_framess,Uint32* last_frame_time_stop_right,Uint32* last_frame_time_stop_left,Uint32* last_frame_time2,Uint32* last_frame_timess,Uint32* last_frame_timeleft ,Uint32* last_frame_timejump,int* current_framejump,int* current_frame_stop_right,int* current_frame_stop_left,int* current_frame2,int* current_frameleft,Personn *p,int* grav,int* velocity,int* stop,SDL_Surface *screen,SDL_Surface **frame_stop_right,SDL_Surface**frames_stop_left,SDL_Surface**framesright,SDL_Surface**framesleft,SDL_Surface**framesjump,SDL_Surface**framesss, int SCREEN_HEIGHT, int SCREEN_WIDTH);
void update_and_render_animationcaractere(int rep,SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, Personn *p,int SCREEN_WIDTH,int SCREEN_HEIGHT ); 
#endif
