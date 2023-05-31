#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include<limits.h>

typedef struct {
    SDL_Surface *board_surface;
    SDL_Rect board_position;

    int matrix[3][3];

    SDL_Surface *images_matrix[3][3];
    SDL_Rect images_position[3][3];

    SDL_Surface *pieces_matrix[3][3];
    SDL_Rect pieces_position[3][3];
}tto_board;


void init_board(tto_board *b,int SCREEN_W, int SCREEN_H);

void displayBoard(tto_board *game_board, SDL_Surface *screen);
void freeBoard(tto_board *game_board);

int verify_matrix(int matrix[3][3]);
void reverse_neighbors(int matrix[3][3], int position);
void update_board(tto_board *b,int SCREEN_W,int SCREEN_H);

void change_image_at_position(tto_board *my_board, int position, SDL_Surface *new_image,int SCREEN_H );



int check_win(int board[3][3], int player);
int check_draw(int board[3][3]);

int find_best_move(int board[3][3]);
int minimax(int board[3][3], int depth, int is_maximizing_player) ;
int evaluate(int board[3][3]);
