#include"IA2.h"
int main(int argc, char* argv[])
{
    int SCREEN_W = 1280;
    int SCREEN_H =(int) SCREEN_W / 1.777777777777777777777777777777777;
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }


    Uint32 start_time = SDL_GetTicks();
    // Create a window
    SDL_Surface* screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H , 32, SDL_SWSURFACE);
    SDL_Surface* icon = IMG_Load("./assets/on.png");
    SDL_WM_SetIcon(icon, NULL);
    SDL_WM_SetCaption("tache blanche", NULL);
    if (screen == NULL)
    {
        printf("Failed to create SDL window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Load the PNG image
    SDL_Surface* background = IMG_Load("./assets/BG.jpg");
    if (background == NULL)
    {
        printf("Failed to load PNG image: %s", IMG_GetError());
        SDL_FreeSurface(screen);
        SDL_Quit();
        return 1;
    }
    background = resizeSurface(background, SCREEN_W, SCREEN_H);
    // Convert the surface to the same format as the screen surface
    SDL_Surface* optimizedBackground = SDL_DisplayFormat(background);
    SDL_FreeSurface(background);
    if (optimizedBackground == NULL)
    {
        printf("Failed to optimize SDL surface: %s", SDL_GetError());
        SDL_FreeSurface(screen);
        SDL_Quit();
        return 1;
    }

    // Blit the background surface to the screen surface
    if (SDL_BlitSurface(optimizedBackground, NULL, screen, NULL) != 0)
    {
        printf("Failed to blit SDL surface: %s", SDL_GetError());
        SDL_FreeSurface(optimizedBackground);
        SDL_FreeSurface(screen);
        SDL_Quit();
        return 1;
    }
    SDL_Rect camera;
    camera.x = 0;
    camera.y = 0;
    camera.w = SCREEN_W;
    camera.h = SCREEN_H;

    tto_board b;
    init_board(&b,SCREEN_W,SCREEN_H); 


    int mouse_x, mouse_y;

    SDL_Flip(screen);

    int startposx = (int)((SCREEN_W - (SCREEN_H * 0.75)) / 2);
    int startposy = (int)((SCREEN_H - (SCREEN_H * 0.75)) / 2);
    int open_riddle = 0;
    int role = 1;
    int move;
    // Wait for the user to close the window
    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch(event.type){
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT && open_riddle == 1 && role == 1 && check_win(b.matrix, role) != 1 && check_win(b.matrix, -role) != 1 && check_draw(b.matrix) != 1){
                        if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) )
                            {
                                b.matrix[0][0] = 1;
                            }
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2))
                            {
                                b.matrix[0][1] = 1;
                            }
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) )
                            {
                                b.matrix[0][2] = 1;
                            }
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) )
                            {
                                b.matrix[1][0] = 1;
                            }
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) )
                            {
                                b.matrix[1][1] = 1;
                            }                   
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)))
                            {
                                b.matrix[1][2] = 1;
                            }
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085) +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) )
                            {
                                b.matrix[2][0] = 1;
                            }
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)))
                            {
                                b.matrix[2][1] = 1;
                            }
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)))
                            {
                                b.matrix[2][2] = 1;
                            }
                        
                        
                    }
                    break;
                case SDL_MOUSEBUTTONUP:

                    if(event.button.button == SDL_BUTTON_LEFT && open_riddle == 1 && role == 1){
                        if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) )
                            {printf("%d %d %d\n",check_win(b.matrix, role),check_win(b.matrix, -role),check_draw(b.matrix));
                            role = -1;}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2))
                            {printf("%d %d %d\n",check_win(b.matrix, role),check_win(b.matrix, -role),check_draw(b.matrix));
                            role = -1;}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) )
                            {printf("%d %d %d\n",check_win(b.matrix, role),check_win(b.matrix, -role),check_draw(b.matrix));
                            role = -1;}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) )
                            {printf("%d %d %d\n",check_win(b.matrix, role),check_win(b.matrix, -role),check_draw(b.matrix));
                            role = -1;}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) )
                            {printf("%d %d %d\n",check_win(b.matrix, role),check_win(b.matrix, -role),check_draw(b.matrix));
                            role = -1;}                     
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)))
                            {printf("%d %d %d\n",check_win(b.matrix, role),check_win(b.matrix, -role),check_draw(b.matrix));
                            role = -1;}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085) +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) )
                            {printf("%d %d %d\n",check_win(b.matrix, role),check_win(b.matrix, -role),check_draw(b.matrix));
                            role = -1;}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)))
                            {printf("%d %d %d\n",check_win(b.matrix, role),check_win(b.matrix, -role),check_draw(b.matrix));
                            role = -1;}
                        else if(event.motion.x>= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) && event.motion.x<= (int)(startposx +( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1) + ((SCREEN_H * 0.75)*0.2) + ( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2) && event.motion.y>= (int)(startposy +( (SCREEN_H * 0.75) * 0.1)  +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)) && event.motion.y<=(int)(startposy +( (SCREEN_H * 0.75) * 0.1)) + ((SCREEN_H * 0.75)*0.2 +(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)+(SCREEN_H * 0.75)*0.2 + ( SCREEN_H * 0.085)))
                            {printf("%d %d %d\n",check_win(b.matrix, role),check_win(b.matrix, -role),check_draw(b.matrix));
                            role = -1;}
                        
                        
                    }
                    break;
                
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_TAB){
                        open_riddle = !open_riddle;
                        printf("open %d\n",open_riddle);
                    }
                    break;
                case SDL_KEYUP:
                    
                    break;
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
    
                
        // Fill the screen with a background color
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        // Blit the background surface to the screen surface
        if (SDL_BlitSurface(optimizedBackground, &camera, screen, NULL) != 0)
        {
            printf("Failed to blit SDL surface: %s", SDL_GetError());
            SDL_FreeSurface(optimizedBackground);
            SDL_FreeSurface(screen);
            SDL_Quit();
            return 1;
        }
        if(open_riddle == 1){
            // Get AI's best move and update board
            if(role == -1){
                if(check_win(b.matrix, role) != 1 && check_win(b.matrix, -role) != 1 && check_draw(b.matrix) != 1){
                    move = find_best_move(b.matrix);
                    printf("move = %d\n",move);
                    int row = (move-1) / 3;
                    int col = (move-1) % 3;
                    b.matrix[row][col] = -1;
                    
                    role = 1;
                }
                if(check_win(b.matrix, 1) == 1)
                    printf("you won!\n");
                else if(check_win(b.matrix, -1) == 1){
                    printf("you lost!\n");
                }else if(check_draw(b.matrix) == 1){
                    printf("draw!\n");
                }
                
            }
            update_board(&b,SCREEN_W,SCREEN_H);
            displayBoard(&b,screen);
        }
        SDL_Flip(screen);
		SDL_Delay(5);
    }

    // Clean up and exit
    SDL_FreeSurface(optimizedBackground);
    freeBoard(&b);
    SDL_Quit();
    return 0;
}
