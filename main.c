#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"minimap.h"
int main(int argc, char* argv[])
{

    char tmp[30];
    SDL_Surface * player = NULL;
    SDL_Rect jr = {650, 400, 50, 100};

    plyr p;
    p.jr = jr;
    p.player = player;

    SDL_Surface * enemi = NULL;
    SDL_Rect en = {150, 400, 50, 100};

    SDL_Surface * enigme = NULL;
    SDL_Rect eg = {1050, 200, 50, 100};

    
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }


    Uint32 start_time = SDL_GetTicks();
    
    SDL_Surface* screen = SDL_SetVideoMode(SCREEN_W,720 , 32, SDL_SWSURFACE);
    if (screen == NULL)
    {
        printf("Failed to create SDL window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    
    SDL_Surface* background = IMG_Load("./assets/BG.jpg");
    if (background == NULL)
    {
        printf("Failed to load PNG image: %s", IMG_GetError());
        SDL_FreeSurface(screen);
        SDL_Quit();
        return 1;
    }

    
    SDL_Surface* masque = IMG_Load("./assets/masque.png");
    if (masque == NULL)
    {
        printf("Failed to load PNG image: %s", IMG_GetError());
        SDL_FreeSurface(screen);
        SDL_Quit();
        return 1;
    }

    minimap  m;
    initmap(&m);
    
    SDL_Surface* optimizedBackground = SDL_DisplayFormat(background);
    SDL_FreeSurface(background);
    if (optimizedBackground == NULL)
    {
        printf("Failed to optimize SDL surface: %s", SDL_GetError());
        SDL_FreeSurface(screen);
        SDL_Quit();
        return 1;
    }

    
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

    enemi = IMG_Load("./assets/robot.png");
    if (enemi == NULL)
    {
        printf("Failed to load PNG image: %s", IMG_GetError());
        SDL_FreeSurface(player);
        SDL_FreeSurface(background);
        SDL_FreeSurface(screen);
        SDL_Quit();
        return 1;
    }

    SDL_BlitSurface(enemi, NULL, screen, &en);


    enigme = IMG_Load("./assets/task.png");
    SDL_BlitSurface(enigme, NULL, screen, &eg);
    p.player = IMG_Load("./assets/player.png");
    SDL_BlitSurface(p.player, NULL, screen, &p.jr);

    


    
    SDL_Flip(screen);

    int temps;

    
    
    bool running = true;
    bool moving_left = false;
    bool moving_right = false;
    bool pressing_m = false;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch(event.type){
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_a && p.jr.x + 50 +  p.jr.w >= 0){
                        moving_left = true;SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
                    }
                    if(event.key.keysym.sym == SDLK_d &&  p.jr.x + 50 +  p.jr.w <= SCREEN_W){
                        moving_right = true;
                    }
                    if(event.key.keysym.sym == SDLK_TAB){
                        pressing_m = true;
                        printf("m yes\n");
                    }
                    break;
                case SDL_KEYUP:
                    if(event.key.keysym.sym == SDLK_a){
                        moving_left = false;
                    }
                    if(event.key.keysym.sym == SDLK_d){
                        moving_right = false;
                    }
                    if(event.key.keysym.sym == SDLK_TAB){
                        pressing_m = false;
                        printf("m no\n");
                    }
                    break;
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        
        if(moving_left &&  p.jr.x + 5 +  p.jr.w >= 0){
            p.jr.x -= 5;  
        }
        
        if(moving_right &&  p.jr.x +5+  p.jr.w <= SCREEN_W){
            p.jr.x += 5;  
        }
                
        
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

        
        if (SDL_BlitSurface(optimizedBackground, &camera, screen, NULL) != 0)
        {
            printf("Failed to blit SDL surface: %s", SDL_GetError());
            SDL_FreeSurface(optimizedBackground);
            SDL_FreeSurface(screen);
            SDL_Quit();
            return 1;
        }

        
        SDL_BlitSurface(enemi, NULL, screen, &en);
        SDL_BlitSurface(enigme, NULL, screen, &eg);
        SDL_BlitSurface(p.player, NULL, screen, &p.jr);
        

        
        affichertemps(start_time,screen,tmp);
        miniMap(pressing_m,&m,p.jr,eg,en,screen,camera);
        printf("%d\n",collisionPP(p.jr,masque));
        SDL_Flip(screen);
		SDL_Delay(5);
    }
    printf("time : %s \n",tmp);

    
    LibererMinimap(&m);
    SDL_FreeSurface(optimizedBackground);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(player);
    SDL_Quit();
    return 0;
}
