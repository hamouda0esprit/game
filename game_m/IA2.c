#include"IA2.h"





void init_board(tto_board *b,int SCREEN_W, int SCREEN_H){
    int i,j;


    b->board_surface = IMG_Load("assets/square.png");
    if (b->board_surface == NULL)
    {
        printf("Failed to load PNG image: %s", IMG_GetError());
        SDL_FreeSurface(b->board_surface);
        SDL_Quit();
    }
    b->board_surface = resizeSurface(b->board_surface, SCREEN_H * 0.75, SCREEN_H * 0.75);

    b->board_position.x = (SCREEN_W - (SCREEN_H * 0.75)) / 2;
    b->board_position.y = (SCREEN_H - (SCREEN_H * 0.75)) / 2;
    b->board_position.h = SCREEN_H * 0.75;
    b->board_position.w = SCREEN_H * 0.75;
    

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            b->images_matrix[i][j] = IMG_Load("assets/element.png");
            if (b->images_matrix[i][j] == NULL)
            {
                printf("Failed to load PNG image: %s", IMG_GetError());
                SDL_FreeSurface(b->images_matrix[i][j]);
                SDL_Quit();
            }
            b->images_matrix[i][j] = resizeSurface(b->images_matrix[i][j], ((SCREEN_H * 0.75)*0.2), ((SCREEN_H * 0.75)*0.2));

            b->images_position[i][j].x = 0;
            b->images_position[i][j].y = 0;
            b->images_position[i][j].h = (SCREEN_H * 0.75)*0.2;
            b->images_position[i][j].w = (SCREEN_H * 0.75)*0.2;
            




            b->pieces_matrix[i][j] = IMG_Load("assets/none.png");
            if (b->pieces_matrix[i][j] == NULL)
            {
                printf("Failed to load PNG image: %s", IMG_GetError());
                SDL_FreeSurface(b->pieces_matrix[i][j]);
                SDL_Quit();
            }
            b->pieces_matrix[i][j] = resizeSurface(b->pieces_matrix[i][j], ((SCREEN_H * 0.75)*0.2)*0.7, ((SCREEN_H * 0.75)*0.2)*0.7);

            b->pieces_position[i][j].x = 0;
            b->pieces_position[i][j].y = 0;
            b->pieces_position[i][j].h = ((SCREEN_H * 0.75)*0.2)*0.7;
            b->pieces_position[i][j].w = ((SCREEN_H * 0.75)*0.2)*0.7;

            b->matrix[i][j] = 0;
        }
    }

    int startposx = (int)((SCREEN_W - (SCREEN_H * 0.75)) / 2);
    int startposy = (int)((SCREEN_H - (SCREEN_H * 0.75)) / 2);
    for(i=0;i<3;i++){
        b->images_position[i][0].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1));
        b->images_position[i][0].y = (int)(startposy +( (SCREEN_H * 0.75) * 0.1));

        b->images_position[i][1].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1));
        b->images_position[i][1].y = (int)(startposy +( (SCREEN_H * 0.75) * 0.1));

        b->images_position[i][2].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1));
        b->images_position[i][2].y =(int)(startposy + ( (SCREEN_H * 0.75) * 0.1));
        

        b->pieces_position[i][0].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2)*0.15);
        b->pieces_position[i][0].y = (int)(startposy +( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);

        b->pieces_position[i][1].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);
        b->pieces_position[i][1].y = (int)(startposy +( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);

        b->pieces_position[i][2].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);
        b->pieces_position[i][2].y =(int)(startposy + ( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);
        
        startposy = (int)(startposy + (SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085));

    }


}


void displayBoard(tto_board *game_board, SDL_Surface *screen) {
    // Blit the board surface to the screen
    SDL_BlitSurface(game_board->board_surface, NULL, screen, &game_board->board_position);
    // Blit the image and piece surfaces to the screen
    for (int i = 0; i < 3; i++) {
        
        for (int j = 0; j < 3; j++) {
            SDL_BlitSurface(game_board->images_matrix[i][j], NULL, screen, &game_board->images_position[i][j]);
            SDL_BlitSurface(game_board->pieces_matrix[i][j], NULL, screen, &game_board->pieces_position[i][j]);
        }
    }
}

void freeBoard(tto_board *game_board) {
    // Free the board surface
    SDL_FreeSurface(game_board->board_surface);

    // Free the image and piece surfaces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            SDL_FreeSurface(game_board->images_matrix[i][j]);
            SDL_FreeSurface(game_board->pieces_matrix[i][j]);
        }
    }

    // Set all surface pointers to NULL
    game_board->board_surface = NULL;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            game_board->images_matrix[i][j] = NULL;
            game_board->pieces_matrix[i][j] = NULL;
        }
    }
}









void update_board(tto_board *b,int SCREEN_W,int SCREEN_H){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b->matrix[i][j] == 1) {
                b->pieces_matrix[i][j] = IMG_Load("assets/x.png");
            } else if (b->matrix[i][j] == -1)  {
                b->pieces_matrix[i][j] = IMG_Load("assets/o.png");
            }else{
                b->pieces_matrix[i][j] = IMG_Load("assets/none.png");
            }
            b->pieces_matrix[i][j] = resizeSurface(b->pieces_matrix[i][j], ((SCREEN_H * 0.75)*0.2)*0.7, ((SCREEN_H * 0.75)*0.2)*0.7);
        }
    }

    
}
void change_image_at_position(tto_board *my_board, int position, SDL_Surface *new_image,int SCREEN_H ) {
    // Calculate the row and column of the cell based on the position
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    // Change the image surface at the specified position
    my_board->pieces_matrix[row][col] = new_image;

    my_board->pieces_matrix[row][col] = resizeSurface(my_board->pieces_matrix[row][col], ((SCREEN_H * 0.75)*0.2)*0.7, ((SCREEN_H * 0.75)*0.2)*0.7);
}


// Function to check if a given player has won
int check_win(int board[3][3], int player) {
    int i, j;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    // No win
    return 0;
}

// Function to check if the board is in a draw state
int check_draw(int board[3][3]) {
    int i, j;
    // Check if any cell is empty
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    // Draw
    return 1;
}

int evaluate(int board[3][3]) {
    if (check_win(board, 1)) {
        return 10;
    } else if (check_win(board, -1)) {
        return -10;
    } else {
        return 0;
    }
}

int minimax(int board[3][3], int depth, int is_maximizing_player) {
    if (check_win(board, 1)) {
        return 10;
    } else if (check_win(board, -1)) {
        return -10;
    } else if (check_draw(board)) {
        return 0;
    }

    if (is_maximizing_player) {
        int best_score = INT_MIN;
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = 1;
                    int score = minimax(board, depth + 1, 0);
                    board[i][j] = 0;
                    if (score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = INT_MAX;
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = -1;
                    int score = minimax(board, depth + 1, 1);
                    board[i][j] = 0;
                    if (score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
}

int find_best_move(int board[3][3]) {
    int best_score = INT_MIN;
    int best_move = -1;
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1;
                int score = minimax(board, 0, 0);
                board[i][j] = 0;
                if (score > best_score) {
                    best_score = score;
                    best_move = i * 3 + j + 1;
                }
            }
        }
    }
    return best_move;
}
