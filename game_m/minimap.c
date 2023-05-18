/**
* @file minimap.c
* @brief Testing the mini map.
* @author C Team
* @version 0.1
* @date may 04, 2023
*
* Testing program for minimap
*
*/

#include"minimap.h"

void format_time(int seconds, char time_str []) {
    int minutes = seconds / 60;
    int remaining_seconds = seconds % 60;
    sprintf(time_str, "%02d:%02d", minutes, remaining_seconds);
}

int ms_to_sec(int milliseconds) {
    return (milliseconds / 1000);
}

void get_points(int x,int y,int w,int h, points *p){
    //printf("fonction get_points\n");
    p->p1x = x+w/6; p->p1y = y;
    p->p2x = x+w/2; p->p2y = y; 
    p->p3x = x+w-w/6; p->p3y = y; 
    p->p4x = x+w/6; p->p4y = y+h/2; 
    p->p5x = x+w/6; p->p5y = y+h; 
    p->p6x = x+w/2; p->p6y = y+h; 
    p->p7x = x+w-w/6; p->p7y = y+h; 
    p->p8x = x+w-w/6; p->p8y = y+h/2;  
}
SDL_Color GetPixel(SDL_Surface *pSurface, int x, int y) {
    SDL_Color color;
    Uint32 pixel = 0;  // Initialize pixel to a default value
    Uint8 *pPixel;

    // Check if the provided coordinates are within the surface bounds
    if (x >= 0 && x < pSurface->w && y >= 0 && y < pSurface->h) {
        // Get the pixel at the specified coordinates
        Uint8 bytesPerPixel = pSurface->format->BytesPerPixel;
        Uint8 *pRow = (Uint8 *)pSurface->pixels + y * pSurface->pitch;
        pPixel = pRow + x * bytesPerPixel;

        // Perform a memory access check before copying the pixel data
        if (pPixel >= (Uint8 *)pSurface->pixels && pPixel < ((Uint8 *)pSurface->pixels + pSurface->pitch * pSurface->h)) {
            memcpy(&pixel, pPixel, bytesPerPixel);

            // Get the individual color components
            SDL_GetRGB(pixel, pSurface->format, &color.r, &color.g, &color.b);
        }
    }

    return color;
}







float distance(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}
void maj_map(minimap *m, SDL_Surface *screen,int SCREEN_W,int SCREEN_H,char minimapNormal[], char minimapEnemie[] , char minimapEnigme[] ){
    if (distance(m->positionBonhomme.x, m->positionBonhomme.y, m->positionEnemi.x, m->positionEnemi.y) < SCREEN_W/25) {
        m->image_miniature = IMG_Load(minimapEnemie);
    }
    
    else if (distance(m->positionBonhomme.x, m->positionBonhomme.y, m->positionEnigme.x, m->positionEnigme.y) < SCREEN_W/25) {
        m->image_miniature = IMG_Load(minimapEnigme);
    }
    else{
        m->image_miniature = IMG_Load(minimapNormal);
    }

    m->image_miniature = resizeSurface(m->image_miniature,SCREEN_W/5,SCREEN_H/5);
}
void afficherminimap(minimap m, SDL_Surface *screen,int SCREEN_W,int SCREEN_H) {
    
    SDL_BlitSurface(m.image_miniature, NULL, screen, &m.positionMinimap);

    
    if (distance(m.positionBonhomme.x, m.positionBonhomme.y, m.positionEnemi.x, m.positionEnemi.y) < SCREEN_W/25) {
        SDL_BlitSurface(m.enemi, NULL, screen, &m.positionEnemi);
    }

    
    if (distance(m.positionBonhomme.x, m.positionBonhomme.y, m.positionEnigme.x, m.positionEnigme.y) < SCREEN_W/25) {
        SDL_BlitSurface(m.enigme, NULL, screen, &m.positionEnigme);
    }

    SDL_BlitSurface(m.bonhomm, NULL, screen, &m.positionBonhomme);
}




void LibererMinimap(minimap *m) {
    
    SDL_FreeSurface(m->image_miniature);
    m->image_miniature = NULL;

    
    SDL_FreeSurface(m->bonhomm);
    m->bonhomm = NULL;

    
    SDL_FreeSurface(m->enigme);
    m->enigme = NULL;

    
    SDL_FreeSurface(m->enemi);
    m->enemi = NULL;

    
    SDL_FreeSurface(m->enigme);
    m->enigme = NULL;

    
    SDL_FreeSurface(m->enemi);
    m->enemi = NULL;
}
void affichertemps(SDL_Surface* screen, char tmp[], int SCREEN_W, int SCREEN_H) {
    static Uint32 start_time = 0; // Start time as a static variable to persist its value across function calls

    if (start_time == 0) {
        start_time = SDL_GetTicks(); // Initialize the start time if it's not set
    }

    SDL_Surface* temps_surface = IMG_Load("./assets/time.png");
    temps_surface = resizeSurface(temps_surface, SCREEN_W / 5.4468085106382978723404255319149, SCREEN_H / 7.0588235294117647058823529411765);
    Uint32 current_time = SDL_GetTicks();
    Uint32 elapsed_time = current_time - start_time;
    int temps = ms_to_sec(elapsed_time);

    if (temps_surface == NULL) {
        printf("Erreur lors du chargement de l'image du temps: %s\n", SDL_GetError());
        exit(1);
    }

    if (TTF_Init() == -1) {
        printf("Erreur lors de l'initialisation de la bibliothèque SDL_ttf: %s\n", TTF_GetError());
        exit(1);
    }

    char temps_str[10];
    format_time(temps, temps_str);
    strcpy(tmp, temps_str);

    TTF_Font* font = TTF_OpenFont("./assets/Helvetica-Bold.ttf", SCREEN_W / 53.333333333333333333333333333333);

    if (font == NULL) {
        printf("Erreur lors du chargement de la police d'écriture: %s\n", TTF_GetError());
        exit(1);
    }

    SDL_Color color = {255, 255, 255};
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, temps_str, color);

    if (text_surface == NULL) {
        printf("Erreur lors de la création de la surface de texte: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Rect temps_rect = {0, 0, temps_surface->w, temps_surface->h};
    SDL_Surface* temps_final_surface = SDL_CreateRGBSurface(0, temps_surface->w, temps_surface->h, 32, 0, 0, 0, 0);
    SDL_BlitSurface(temps_surface, NULL, temps_final_surface, &temps_rect);

    Uint32 colorkey = *(Uint32*)temps_surface->pixels;
    SDL_SetColorKey(temps_final_surface, SDL_SRCCOLORKEY, colorkey);

    int x = (temps_surface->w - text_surface->w) / 1.5;
    int y = (temps_surface->h - text_surface->h) / 1.8;

    SDL_Rect text_rect = {x, y, text_surface->w, text_surface->h};
    SDL_BlitSurface(text_surface, NULL, temps_final_surface, &text_rect);

    SDL_Rect screen_rect = {SCREEN_W - temps_final_surface->w - (SCREEN_W / 64), SCREEN_W / 64, temps_final_surface->w, temps_final_surface->h};
    SDL_BlitSurface(temps_final_surface, NULL, screen, &screen_rect);

    SDL_FreeSurface(temps_surface);
    SDL_FreeSurface(text_surface);
    SDL_FreeSurface(temps_final_surface);
    TTF_CloseFont(font);
}



void initmap(minimap *m,int SCREEN_W,int SCREEN_H,char minimapNormal[] ) {
    
    m->positionMinimap.x = SCREEN_W/64; 
    m->positionMinimap.y = SCREEN_W/64; 
    
    m->image_miniature = IMG_Load(minimapNormal);
    m->image_miniature = resizeSurface(m->image_miniature,SCREEN_W/5,SCREEN_H/5);
    //printf("w %d  h %d",SCREEN_W/5,SCREEN_H/5);
    if (m->image_miniature == NULL) {
        printf("Erreur lors du chargement de l'image miniature de la minimap: %s\n", SDL_GetError());
        exit(1);
    }
    
    
    m->bonhomm = IMG_Load("./assets/steve.jpg");
    
    if (m->bonhomm == NULL) {
        printf("Erreur lors du chargement de l'image du bonhomme miniature: %s\n", SDL_GetError());
        exit(1);
    }
    
    m->positionBonhomme.x = 0; 
    m->positionBonhomme.y = 0; 
    m->positionBonhomme.w = 40;
    m->positionBonhomme.h = 40;

    
    m->enigme = IMG_Load("./assets/enigme.png");
    
    if (m->enigme == NULL) {
        printf("Erreur lors du chargement de l'enigme miniature: %s\n", SDL_GetError());
        exit(1);
    }
    
    m->positionEnigme.x = 0; 
    m->positionEnigme.y = 0; 
    m->positionEnigme.w = 40;
    m->positionEnigme.h = 40;

    
    m->enemi = IMG_Load("./assets/enemi.png");
    
    if (m->enemi == NULL) {
        printf("Erreur lors du chargement de l'enemi miniature: %s\n", SDL_GetError());
        exit(1);
    }
    
    m->positionEnemi.x = 0;
    m->positionEnemi.y = 0; 
    m->positionEnemi.w = 40;
    m->positionEnemi.h = 40;


}
void annimerMinimap(SDL_Rect posJoueur,SDL_Rect posEnemie,SDL_Rect posEnigme, minimap *m, int redimensionnement,int SCREEN_W,int SCREEN_H){
    m->positionBonhomme.x = (((posJoueur.x)) / redimensionnement + m->positionMinimap.x)- (m->positionBonhomme.w /2);
    m->positionBonhomme.y = (((posJoueur.y)) / redimensionnement + m->positionMinimap.y)- (m->positionBonhomme.h /2);
    m->positionEnemi.x = (((posEnemie.x)) / redimensionnement + m->positionMinimap.x)-(m->positionEnemi.w /2);
    m->positionEnemi.y = (((posEnemie.y)) / redimensionnement + m->positionMinimap.y)-(m->positionEnemi.h /2);
    m->positionEnigme.x = (((posEnigme.x)) / redimensionnement + m->positionMinimap.x)-(m->positionEnigme.w /2);
    m->positionEnigme.y = (((posEnigme.y)) / redimensionnement + m->positionMinimap.y)-(m->positionEnigme.h /2);
}




int collisionPP(SDL_Rect p, SDL_Surface *Masque,SDL_Rect MasqueRect,int R,int G,int B) {
    //printf("collisionPP\n");
    points p_points;
    get_points(p.x + abs(MasqueRect.x), p.y + abs(MasqueRect.y),
               p.w, p.h, &p_points);
    SDL_Color color = {R, G, B, 0};
    //printf("1\n");
    for (int i = 1; i <= 8; i++) {
        int x = 0, y = 0;
        switch (i) {
            case 1:
                x = p_points.p1x;
                y = p_points.p1y;
                break;
            case 2:
                x = p_points.p2x;
                y = p_points.p2y;
                break;
            case 3:
                x = p_points.p3x;
                y = p_points.p3y;
                break;
            case 4:
                x = p_points.p4x;
                y = p_points.p4y;
                break;
            case 5:
                x = p_points.p5x;
                y = p_points.p5y;
                break;
            case 6:
                x = p_points.p6x;
                y = p_points.p6y;
                break;
            case 7:
                x = p_points.p7x;
                y = p_points.p7y;
                break;
            case 8:
                x = p_points.p8x;
                y = p_points.p8y;
                break;
        }
        //printf("2\n");

        SDL_Color pixel_color = GetPixel(Masque, x, y);
        //printf("3\n");
        //printf("passed ?\n");
        if (pixel_color.r == color.r && pixel_color.g == color.g && pixel_color.b == color.b) {
            //printf("pass1\n");
            if(i == 1 || i == 4)
                return 1;
            //printf("pass2\n");
            if(i == 3 || i == 8)
                return 2;
            //printf("pass3\n");
            if(i == 5 || i == 6 || i == 7)
                return 3;
            //printf("pass4\n");
        }
        
    }
    return 0;
    
}

SDL_Surface* resizeSurface(SDL_Surface* surface, int width, int height) {
    // Create a new surface with the desired width and height
    SDL_Surface* newSurface = SDL_CreateRGBSurface(surface->flags, width, height, surface->format->BitsPerPixel, surface->format->Rmask, surface->format->Gmask, surface->format->Bmask, surface->format->Amask);

    // Use SDL_gfx library to resize the surface
    SDL_SoftStretch(surface, NULL, newSurface, NULL);

    // Free the original surface
    SDL_FreeSurface(surface);

    // Return the resized surface
    return newSurface;
}

void fullmap(minimap * m,int SCREEN_W,int SCREEN_H,char minimapNormal[] ){
    m->image_miniature = IMG_Load(minimapNormal);
    m->image_miniature = resizeSurface(m->image_miniature,SCREEN_W/2,SCREEN_H/2);
    m->positionMinimap.x = SCREEN_W /4;
    m->positionMinimap.y = SCREEN_H /4; 
}
void smallmap(minimap * m,int SCREEN_W,int SCREEN_H,char minimapNormal[] ){
    m->image_miniature = IMG_Load(minimapNormal);
    m->image_miniature = resizeSurface(m->image_miniature,SCREEN_W/5,SCREEN_H/5);
    m->positionMinimap.x = SCREEN_W/64;
    m->positionMinimap.y = SCREEN_W/64; 
}

void maj_fullmap(minimap *m, int SCREEN_W,int SCREEN_H,char minimapNormal[], char minimapEnemie[] , char minimapEnigme[] ){
    if (distance(m->positionBonhomme.x, m->positionBonhomme.y, m->positionEnemi.x, m->positionEnemi.y) < SCREEN_W/10) {
        m->image_miniature = IMG_Load(minimapEnemie);
    }

   
    else if (distance(m->positionBonhomme.x, m->positionBonhomme.y, m->positionEnigme.x, m->positionEnigme.y) < SCREEN_W/10) {
        m->image_miniature = IMG_Load(minimapEnigme);
    }
    else{
        m->image_miniature = IMG_Load(minimapNormal);
    }

    m->image_miniature = resizeSurface(m->image_miniature,SCREEN_W/2,SCREEN_H/2);
}

void afficherFULLminimap(minimap m, SDL_Surface *screen,int SCREEN_W,int SCREEN_H) {
    
    SDL_BlitSurface(m.image_miniature, NULL, screen, &m.positionMinimap);

   
    if (distance(m.positionBonhomme.x, m.positionBonhomme.y, m.positionEnemi.x, m.positionEnemi.y) < SCREEN_W/10) {
        SDL_BlitSurface(m.enemi, NULL, screen, &m.positionEnemi);
    }

    
    if (distance(m.positionBonhomme.x, m.positionBonhomme.y, m.positionEnigme.x, m.positionEnigme.y) < SCREEN_W/10) {
        SDL_BlitSurface(m.enigme, NULL, screen, &m.positionEnigme);
    }

    
    SDL_BlitSurface(m.bonhomm, NULL, screen, &m.positionBonhomme);
}

void miniMap(bool pressing_m,minimap *m,SDL_Rect pjr,SDL_Rect peg,SDL_Rect pen,SDL_Surface *screen,int SCREEN_W,int SCREEN_H,char minimapNormal[] , char minimapEnemie[] , char minimapEnigme[]){
    //printf("1\n");
    if(pressing_m == false){
            
            smallmap(m,SCREEN_W,SCREEN_H,minimapNormal);
            
            annimerMinimap(pjr,pen,peg, m, 5,SCREEN_W,SCREEN_H);
            
            
            maj_map(m,screen,SCREEN_W,SCREEN_H,minimapNormal,minimapEnemie,minimapEnigme);
            
            afficherminimap(*m, screen,SCREEN_W,SCREEN_H);
            
            
        }else{
            
            fullmap(m,SCREEN_W,SCREEN_H,minimapNormal);
            
            annimerMinimap(pjr,pen,peg, m, 2,SCREEN_W,SCREEN_H);
            
            
            maj_fullmap(m,SCREEN_W,SCREEN_H,minimapNormal,minimapEnemie,minimapEnigme);
            
            afficherFULLminimap(*m, screen,SCREEN_W,SCREEN_H);
            
        }
}
