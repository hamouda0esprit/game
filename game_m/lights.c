#include"lights.h"
#include"minimap.h"




void init_board2(board *b,int SCREEN_W, int SCREEN_H){
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
            




            b->pieces_off_matrix[i][j] = IMG_Load("assets/off.png");
            if (b->pieces_off_matrix[i][j] == NULL)
            {
                printf("Failed to load PNG image: %s", IMG_GetError());
                SDL_FreeSurface(b->pieces_off_matrix[i][j]);
                SDL_Quit();
            }
            b->pieces_off_matrix[i][j] = resizeSurface(b->pieces_off_matrix[i][j], ((SCREEN_H * 0.75)*0.2)*0.7, ((SCREEN_H * 0.75)*0.2)*0.7);

            b->pieces_off_position[i][j].x = 0;
            b->pieces_off_position[i][j].y = 0;
            b->pieces_off_position[i][j].h = ((SCREEN_H * 0.75)*0.2)*0.7;
            b->pieces_off_position[i][j].w = ((SCREEN_H * 0.75)*0.2)*0.7;


            b->pieces_on_matrix[i][j] = IMG_Load("assets/on.png");
            if (b->pieces_on_matrix[i][j] == NULL)
            {
                printf("Failed to load PNG image: %s", IMG_GetError());
                SDL_FreeSurface(b->pieces_on_matrix[i][j]);
                SDL_Quit();
            }
            b->pieces_on_matrix[i][j] = resizeSurface(b->pieces_on_matrix[i][j], ((SCREEN_H * 0.75)*0.2)*0.7, ((SCREEN_H * 0.75)*0.2)*0.7);

            b->pieces_on_position[i][j].x = 0;
            b->pieces_on_position[i][j].y = 0;
            b->pieces_on_position[i][j].h = ((SCREEN_H * 0.75)*0.2)*0.7;
            b->pieces_on_position[i][j].w = ((SCREEN_H * 0.75)*0.2)*0.7;

            
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
        

        b->pieces_on_position[i][0].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2)*0.15);
        b->pieces_on_position[i][0].y = (int)(startposy +( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);

        b->pieces_on_position[i][1].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);
        b->pieces_on_position[i][1].y = (int)(startposy +( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);

        b->pieces_on_position[i][2].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);
        b->pieces_on_position[i][2].y =(int)(startposy + ( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);


        b->pieces_off_position[i][0].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2)*0.15);
        b->pieces_off_position[i][0].y = (int)(startposy +( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);

        b->pieces_off_position[i][1].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);
        b->pieces_off_position[i][1].y = (int)(startposy +( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);

        b->pieces_off_position[i][2].x = (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);
        b->pieces_off_position[i][2].y =(int)(startposy + ( (SCREEN_H * 0.75) * 0.1) +((SCREEN_H * 0.75)*0.2)*0.15);
        
        
        startposy = (int)(startposy + (SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085));

    }


}


void displayBoard2(board *game_board, SDL_Surface *screen) {
    // Blit the board surface to the screen
    SDL_BlitSurface(game_board->board_surface, NULL, screen, &game_board->board_position);
    // Blit the image and piece surfaces to the screen
    for (int i = 0; i < 3; i++) {
        
        for (int j = 0; j < 3; j++) {
            SDL_BlitSurface(game_board->images_matrix[i][j], NULL, screen, &game_board->images_position[i][j]);
            if(game_board->matrix[i][j] == 0)
                SDL_BlitSurface(game_board->pieces_off_matrix[i][j], NULL, screen, &game_board->pieces_off_position[i][j]);
            else
                SDL_BlitSurface(game_board->pieces_on_matrix[i][j], NULL, screen, &game_board->pieces_on_position[i][j]);
        }
    }
}

void freeBoard2(board *game_board) {
    // Free the board surface
    SDL_FreeSurface(game_board->board_surface);

    // Free the image and piece surfaces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            SDL_FreeSurface(game_board->images_matrix[i][j]);
            SDL_FreeSurface(game_board->pieces_off_matrix[i][j]);
            SDL_FreeSurface(game_board->pieces_on_matrix[i][j]);
        }
    }

    // Set all surface pointers to NULL
    game_board->board_surface = NULL;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            game_board->images_matrix[i][j] = NULL;
            game_board->pieces_off_matrix[i][j] = NULL;
            game_board->pieces_on_matrix[i][j] = NULL;
        }
    }
}



int verify_matrix(int matrix[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                return 0; // found a zero, so not all elements are 1
            }
        }
    }
    return 1; // no zeros found, so all elements are 1
}


void reverse_neighbors(int matrix[3][3], int position) {
    // Calculate the row and column of the cell based on the position
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    // Reverse the value of the cell itself
    matrix[row][col] = !matrix[row][col];

    // Reverse the values of the top, bottom, left, and right cells
    if (row > 0) {
        matrix[row-1][col] = !matrix[row-1][col]; // Top cell
    }
    if (row < 2) {
        matrix[row+1][col] = !matrix[row+1][col]; // Bottom cell
    }
    if (col > 0) {
        matrix[row][col-1] = !matrix[row][col-1]; // Left cell
    }
    if (col < 2) {
        matrix[row][col+1] = !matrix[row][col+1]; // Right cell
    }
}




int play_lights(board *b,SDL_Surface *screen,int pressing,SDL_Event event,int startposx,int startposy,int SCREEN_W, int SCREEN_H){
    if(pressing == 1){
        displayBoard2(b,screen);
        if(verify_matrix(b->matrix) != 1){
            while (SDL_PollEvent(&event))
            {
            switch(event.type){
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT){
                        if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) )
                           { reverse_neighbors(b->matrix,1);}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2))
                            { reverse_neighbors(b->matrix,2);}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) )
                            { reverse_neighbors(b->matrix,3);}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) )
                            { reverse_neighbors(b->matrix,4);}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) )
                            { reverse_neighbors(b->matrix,5);}                   
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)))
                            { reverse_neighbors(b->matrix,6);}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085) +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) )
                            { reverse_neighbors(b->matrix,7);}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)))
                            { reverse_neighbors(b->matrix,8);}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)))
                            { reverse_neighbors(b->matrix,9);}
                        
                        
                    }
                    break;
                
                }
            }
        }
        return verify_matrix(b->matrix);
    
    }
}
