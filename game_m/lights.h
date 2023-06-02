#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>


typedef struct {
    SDL_Surface *board_surface;
    SDL_Rect board_position;

    int matrix[3][3];

    SDL_Surface *images_matrix[3][3];
    SDL_Rect images_position[3][3];

    SDL_Surface *pieces_on_matrix[3][3];
    SDL_Rect pieces_on_position[3][3];

    SDL_Surface *pieces_off_matrix[3][3];
    SDL_Rect pieces_off_position[3][3];

}board;


void init_board2(board *b,int SCREEN_W, int SCREEN_H);

void displayBoard2(board *game_board, SDL_Surface *screen);
void freeBoard2(board *game_board);

int verify_matrix(int matrix[3][3]);
void reverse_neighbors(int matrix[3][3], int position);




int play_lights(board *b,SDL_Surface *screen,int pressing,SDL_Event event,int startposx,int startposy,int SCREEN_W, int SCREEN_H);
