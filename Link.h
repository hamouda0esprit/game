#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


int Main_Menu();
void main_2();
void MOD(bool *AlreadyHovered, bool *isMouseOverButton, bool isSettingsClicked, SDL_Event event, SDL_Rect buttonRect, int BUTTON_WIDTH, int BUTTON_HEIGHT, Mix_Chunk *Audio_Button_Hover);
void BHTC(bool isMouseOverButton, SDL_Surface *screen, SDL_Surface *buttonHImage, SDL_Surface *buttonImage, SDL_Rect buttonRect);
void Play_Audio(Mix_Chunk *Audio);
//void Resize(SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT);
void calc_res(int SCREEN_WIDTH, int *SCREEN_HEIGHT, int *MENU_BG_WIDTH, int *MENU_BG_HEIGHT, int *BUTTON_WIDTH,int *BUTTON_HEIGHT, int *S_BUTTON_WIDTH, int *S_BUTTON_HEIGHT, int *SLIDER_WIDTH, int *SLIDER_HEIGHT, int *SLIDER_WIDTH_KNOB, int *SLIDER_HEIGHT_KNOB, int *center_x, int *center_y, int *m_center_x, int *m_center_y, int *s_center_x, int *s_center_y, int *slider_center_x, int *slider_center_y);
SDL_Rect calc_Rec(SDL_Rect Rec, int m_center_x, int m_center_y, int MENU_BG_WIDTH, int MENU_BG_HEIGHT);
