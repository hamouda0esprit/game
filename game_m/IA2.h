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

    SDL_Surface *x_matrix[3][3];

    SDL_Surface *o_matrix[3][3];
}tto_board;






void init_board(tto_board *b,int SCREEN_W, int SCREEN_H);
void displayBoard(tto_board *game_board, SDL_Surface *screen);
void freeBoard(tto_board *game_board);



int check_win(int board[3][3], int player);
int check_draw(int board[3][3]);

int find_best_move(int board[3][3]);
int minimax(int board[3][3], int depth, int is_maximizing_player) ;
int evaluate(int board[3][3]);

bool user_play(int board[3][3],SDL_Event event,int startposx,int startposy,int SCREEN_W, int SCREEN_H);
int AI_play(int board[3][3],int role);

int run_tictactoe(int open_riddle,tto_board *b,SDL_Event event,int startposx,int startposy,int SCREEN_W, int SCREEN_H,int * role, SDL_Surface *screen);
