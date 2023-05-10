#ifndef FONCTIONN_H
#define FONCTIONN_H
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct{
SDL_Rect cor;
}Personn;
typedef struct{
SDL_Rect pos;
SDL_Surface *image;
}bullett;

void update_animation2(int *current_frame, Uint32 *last_frame_time,int NUM_FRAMES);
void render_animation2(SDL_Surface *screen, SDL_Surface **frames, int current_frame,int x,int y);
void clear_animation2(SDL_Surface **frames, int num_frames);
void update_animationright2(int *current_frame, Uint32 *last_frame_time,int NUM_FRAMES);
void render_animationright2(SDL_Surface *screen, SDL_Surface **frames, int current_frame,int x,int y);
void player4(int* orientation,int* jump,int* dir,int* current_framess,Uint32* last_frame_time_stop_right,Uint32* last_frame_time_stop_left,Uint32* last_frame_time2,Uint32* last_frame_timess,Uint32* last_frame_timeleft ,Uint32* last_frame_timejump,int* current_framejump,int* current_frame_stop_right,int* current_frame_stop_left,int* current_frame2,int* current_frameleft,Personn *p,int* grav,int* velocity,int* stop,SDL_Surface *screen,SDL_Surface **frame_stop_right,SDL_Surface**frames_stop_left,SDL_Surface**framesright,SDL_Surface**framesleft,SDL_Surface**framesjump,SDL_Surface**framesss);

#endif
