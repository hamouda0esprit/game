#ifndef FONCTIONN_H
#define FONCTIONN_H
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{
char *url;
SDL_Rect pos_img_affiche; 
SDL_Rect pos_img_ecran;
SDL_Surface *img;
}image;
typedef struct{
int dir;
SDL_Rect R;
}Personn;
SDL_Surface* load_image(const char* filename);
void clear_animation(SDL_Surface **frames, int num_frames);
void loadanimation(int numframes ,SDL_Surface **frames,char dest[],int SCREEN_WIDTH,int SCREEN_HEIGHT);
void player(Personn *p,int SCREEN_HEIGHT,int* velocity,int* jump ,int* stop ,int* dir,SDL_Surface** frames,SDL_Surface** framesl,SDL_Surface** framesright,SDL_Surface** framesleft,SDL_Surface**framesjump,SDL_Surface *screen,int NUM_FRAMESstopleft,int NUM_FRAMESstopright, int NUM_FRAMESright,int NUM_FRAMESleft,int NUM_FRAMESjump,int* orientation,int* move,int* current_framestopright,int* current_framestopleft,int* current_frame2,int* current_frameleft,int* current_framejump,Uint32* last_frame_timestopright,Uint32* last_frame_timestopleft,Uint32* last_frame_time2 , Uint32* last_frame_timeleft,Uint32* last_frame_timejump);
void update_and_render_animation(SDL_Surface *screen, SDL_Surface **frames, int *current_frame, Uint32 *last_frame_time, int NUM_FRAMES, Personn *p,int move,int SCREEN_WIDTH,int SCREEN_HEIGHT );
void Resize(SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT);

#endif
