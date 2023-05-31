#include "Link.h"

int Main_Menu() {
	
	//Window size variables
	int SCREEN_WIDTH = 1720;
	int SCREEN_HEIGHT;
	
	//Menu bg size variables
	int MENU_BG_WIDTH;
	int MENU_BG_HEIGHT;
	
	//Buttons sizes variables
	int BUTTON_WIDTH;
	int BUTTON_HEIGHT;
	
	int S_BUTTON_WIDTH;
	int S_BUTTON_HEIGHT;
	
	//Slider size variables
	int SLIDER_WIDTH;
	int SLIDER_HEIGHT;
	
	//Slider knob size variables
	int SLIDER_WIDTH_KNOB;
	int SLIDER_HEIGHT_KNOB;
	
	//variables
	int center_x;
	int center_y;
	int m_center_x;
	int m_center_y;
	int s_center_x;
	int s_center_y;
	int slider_center_x;
	int slider_center_y;
	
	int j;
	calc_res(SCREEN_WIDTH, &SCREEN_HEIGHT, &MENU_BG_WIDTH, &MENU_BG_HEIGHT, &BUTTON_WIDTH, &BUTTON_HEIGHT, &S_BUTTON_WIDTH, &S_BUTTON_HEIGHT, &SLIDER_WIDTH, &SLIDER_HEIGHT, &SLIDER_WIDTH_KNOB, &SLIDER_HEIGHT_KNOB, &center_x, &center_y, &m_center_x, &m_center_y, &s_center_x, &s_center_y, &slider_center_x, &slider_center_y); 
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(SDL_INIT_AUDIO);
	TTF_Init();
	
	//Initializing audio
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Uint8 volume = 128;
	
	//Initializing Fonts
	TTF_Font *font;
	SDL_Color text_color = {0, 0, 0};
	
	//Declaring Audio
	Mix_Chunk *Audio_Click = Mix_LoadWAV("M_Assets/Audio/click.wav");
	Mix_Chunk *Audio_Quit = Mix_LoadWAV("M_Assets/Audio/quit.wav");
	Mix_Chunk *Audio_Button_Hover = Mix_LoadWAV("M_Assets/Audio/Button_Hover.wav");
	Mix_Music *Audio_Bg_Music = Mix_LoadMUS("M_Assets/Audio/SONG.mp3");
	
	
	
	//Play_Audio(Audio_Bg_Music);
	
	//Window
	SDL_Surface *screen;
	
	SDL_Rect destRec;// = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}; {position x, position y, width, height}
	
	//Background & Double Buffering
	SDL_Surface *background;// = IMG_Load("Assets/Background.png");
	
	//Buttons
	//Buttons textures, positions and sizes
	SDL_Rect button1Rect;// = {center_x,center_y - SCREEN_WIDTH/10, BUTTON_WIDTH, BUTTON_HEIGHT};
	SDL_Rect button2Rect;// = {center_x, center_y, BUTTON_WIDTH, BUTTON_HEIGHT};
	SDL_Rect button3Rect;// = {center_x, center_y + SCREEN_WIDTH/10, BUTTON_WIDTH, BUTTON_HEIGHT};
	SDL_Rect button4Rect;// = {SCREEN_WIDTH/40, SCREEN_HEIGHT/40, S_BUTTON_WIDTH, S_BUTTON_HEIGHT};
	SDL_Rect button5Rect;
	SDL_Rect button6Rect;
	
	SDL_Surface *button1Image ; 
	SDL_Surface *button1HImage ; 
	
	SDL_Surface *button2Image ; 
	SDL_Surface *button2HImage ; 
	
	SDL_Surface *button3Image ; 
	SDL_Surface *button3HImage ; 
	
	SDL_Surface *button4Image ; 
	SDL_Surface *button4HImage ; 
	
	SDL_Surface *button5Image ;
	SDL_Surface *button5HImage ; 
	
	SDL_Surface *button6Image ;
	SDL_Surface *button6HImage ;
	
	//Audio Controller
	SDL_Rect slider;// = {slider_center_x, slider_center_y - (SCREEN_HEIGHT/6), SLIDER_WIDTH, SLIDER_HEIGHT};
	SDL_Rect slider_k;// = {0, slider_center_y - (SCREEN_HEIGHT/6), SLIDER_WIDTH_KNOB, SLIDER_HEIGHT_KNOB};
	
	SDL_Surface *slider_bar;
	SDL_Surface *slider_knob;
	
	//Sound text
	SDL_Rect text_rect;// = {0, slider_center_y - (SCREEN_HEIGHT/4.4)};
	SDL_Surface *text_Sound;// = TTF_RenderText_Blended(font, "Sound Controls", text_color);
	//text_rect.x = (screen->w - text_Sound->w) / 2;
	
	SDL_Rect top3_1_rect;
	SDL_Surface *top3_1;
	SDL_Rect top3_2_rect;
	SDL_Surface *top3_2;
	SDL_Rect top3_3_rect;
	SDL_Surface *top3_3;// = TTF_RenderText_Blended(font, "Sound Controls", text_color);
	
	//Top players variables & Text
	char top3_1_ch[12],top3_2_ch[12],top3_3_ch[12];
	int top3_1_x=0, top3_2_x=0, top3_3_x=0;
	
	Score_Extracting(&top3_1_ch, &top3_1_x, &top3_2_ch, &top3_2_x, &top3_3_ch, &top3_3_x);
	
	char chf1[16], chf2[16], chf3[16];
	sprintf(chf1, "%s %d", top3_1_ch,top3_1_x);
	sprintf(chf2, "%s %d", top3_2_ch,top3_2_x);
	sprintf(chf3, "%s %d", top3_3_ch,top3_3_x);
	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
	/*char buf[10];
	for(j=0;j<9;j++){
		char ch[30] = "Assets/Animation/BG/BG_";
		snprintf(buf, 10, "%d", j);
		strcat(ch,buf);
		strcat(ch,".png");
		printf("\nBG : %s\n",ch);
		SDL_Delay(100);
		SDL_FreeSurface(background);
		Resize(screen, &(background), ch, SCREEN_WIDTH, SCREEN_HEIGHT);
		SDL_Flip(screen);
	}*/
	
	// Loading the animation frames
	const int num_frames = 88;
	SDL_Surface* frames[num_frames];
	char filename[40];
	for (j = 0; j < num_frames; j++) {
		// Format the filename
		sprintf(filename, "M_Assets/Animation/BG/BG_%d.jpg", j);
		
		// Load the next frame
		Resize(&(frames[j]), filename, SCREEN_WIDTH, SCREEN_HEIGHT);
	}
	
	// Set up the animation loop
	int frame_index = 0;
	Uint32 last_frame_time = SDL_GetTicks();
	const Uint32 frame_interval = 15; // milliseconds per frame
	
	// Loading the animation frames 2
	const int num_frames2 = 246;
	SDL_Surface* frames2[num_frames2];
	// Set up the animation loop
	int frame_index2 = 0;
	Uint32 last_frame_time2 = SDL_GetTicks();
	const Uint32 frame_interval2 = 20; // milliseconds per frame
	
	// Set up the cursor
	SDL_Rect cursorPos;
	
	SDL_Surface* cursorSurface = IMG_Load("M_Assets/Cursor1.png");
	Uint8 cursorData[] = {0, 0, 0, 0, 0, 0, 0, 0};
	Uint8 cursorMask[] = {0, 0, 0, 0, 0, 0, 0, 0};
	SDL_Cursor* cursor = SDL_CreateCursor(cursorData, cursorMask, 1, 1, 0, 0);

	// set cursor
	SDL_SetCursor(cursor);
	
	bool isMouseOverButton1 = false;
	bool isMouseOverButton2 = false;
	bool isMouseOverButton3 = false;
	bool isMouseOverButton4 = false;
	bool isMouseOverButton5 = false;
	bool isMouseOverButton6 = false;
	
	bool isSettingsClicked = false;
	bool isPlayClicked = false;
	bool isScorebClicked = false;
	
	bool AlreadyHovered1 = false;
	bool AlreadyHovered2 = false;
	bool AlreadyHovered3 = false;
	bool AlreadyHovered4 = false;
	bool AlreadyHovered5 = false;
	bool AlreadyHovered6 = false;
	
	bool isAudioControllerClicked = false;
	
	bool loop = false;
	
	Mix_PlayMusic( Audio_Bg_Music, -1 );
	Mix_VolumeMusic(volume/2);
	
	int res = 0;
	int i=0;
	
	int selector = 0;
	int selector2 = 0;
	int selector3 = 0;
	//Window loop
	SDL_Event event;
	SDL_bool done = SDL_FALSE;
	while(!done){
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					done = SDL_TRUE;
					break;
				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_ESCAPE){
						Play_Audio(Audio_Quit);
						
						SDL_Delay(300); 
						
						done = SDL_TRUE;
					}
					if(loop){
						if(event.key.keysym.sym == SDLK_DOWN){
							if (selector<3 && !isSettingsClicked  && !isPlayClicked){
								selector++;
								Mix_PlayChannel(-1, Audio_Button_Hover, 0);
							}
							if (selector2<2 && isSettingsClicked  && !isPlayClicked){
								selector2++;
								Mix_PlayChannel(-1, Audio_Button_Hover, 0);
							}
							if(selector3==0 && !isSettingsClicked && isPlayClicked){
								selector3=1;
								Mix_PlayChannel(-1, Audio_Button_Hover, 0);
							}
						}
						
						if(event.key.keysym.sym == SDLK_UP){
							if(selector==0 && !isSettingsClicked && !isPlayClicked){
								selector=1;
								Mix_PlayChannel(-1, Audio_Button_Hover, 0);
							}
							if(selector2==0 && isSettingsClicked && !isPlayClicked){
								selector2=1;
								Mix_PlayChannel(-1, Audio_Button_Hover, 0);
							}
							
							if (selector>1 && !isSettingsClicked && !isPlayClicked){
								selector--;
								Mix_PlayChannel(-1, Audio_Button_Hover, 0);
							}
							if (selector2>1 && isSettingsClicked && !isPlayClicked){
								selector2--;
								Mix_PlayChannel(-1, Audio_Button_Hover, 0);
							}
							if(selector3==0 && !isSettingsClicked && isPlayClicked){
								selector3=1;
								Mix_PlayChannel(-1, Audio_Button_Hover, 0);
							}
							
						}
						if(event.key.keysym.sym == SDLK_RETURN){
							if(selector==1){
								//Playing Audio
								Play_Audio(Audio_Click);
								
								isPlayClicked = true;
								isMouseOverButton1 = false;
							}
							if(selector==2){
								//Playing Audio
								Play_Audio(Audio_Click);
								
								isSettingsClicked = true;
								isMouseOverButton2 = false;
							}
							if(selector==3){
								//Playing Audio
								Play_Audio(Audio_Quit);
								
								SDL_Delay(300); 
								
								done = SDL_TRUE;
							}
							if(selector2==1){
								//Playing Audio
								Play_Audio(Audio_Quit);
								
								isSettingsClicked = false;
								isMouseOverButton4 = false;
							}
							if(selector2==2){
								//Playing Audio
								Play_Audio(Audio_Click);
								
								i=0;
								if (res!=1){
									res = 1;
								}else{
									res = 0;
								}
							}
							if(selector3==1){
								//Playing Audio
								Play_Audio(Audio_Click);
								
								isPlayClicked=0;
								isMouseOverButton4 = false;
							}
						}
						if(event.key.keysym.sym == SDLK_f){
							//Playing Audio
							Play_Audio(Audio_Click);
							
							i=0;
							if (res!=1){
								res = 1;
							}else{
								res = 0;
							}
						}
					}
					break;
					
				case SDL_MOUSEBUTTONDOWN:
					if(loop){
						if (event.button.button == SDL_BUTTON_LEFT){
							SDL_FreeSurface(cursorSurface);
							cursorSurface = IMG_Load("M_Assets/Cursor2.png");
							if (event.motion.x >= slider.x && event.motion.x <= slider.x + slider.w && event.motion.y >= slider.y && event.motion.y <= slider.y + slider.h) {
								isAudioControllerClicked = true;
							}
						}
					}
					break;
				case SDL_MOUSEMOTION:
					cursorPos.x = event.motion.x;
					cursorPos.y = event.motion.y;
					if(loop){
						selector=0;
						selector2=0;
						selector3=0;
						//Mouse over buttons detection
						if(!isPlayClicked){
							if (!isScorebClicked){
								MOD(&AlreadyHovered1, &isMouseOverButton1, isSettingsClicked, event, button1Rect, BUTTON_WIDTH, BUTTON_HEIGHT, Audio_Button_Hover);
								MOD(&AlreadyHovered2, &isMouseOverButton2, isSettingsClicked, event, button2Rect, BUTTON_WIDTH, BUTTON_HEIGHT, Audio_Button_Hover);
								MOD(&AlreadyHovered3, &isMouseOverButton3, isSettingsClicked, event, button3Rect, BUTTON_WIDTH, BUTTON_HEIGHT, Audio_Button_Hover);
								MOD(&AlreadyHovered4, &isMouseOverButton4, !isSettingsClicked, event, button4Rect, S_BUTTON_WIDTH, S_BUTTON_HEIGHT, Audio_Button_Hover);
								MOD(&AlreadyHovered5, &isMouseOverButton5, !isSettingsClicked, event, button5Rect, BUTTON_WIDTH, BUTTON_HEIGHT, Audio_Button_Hover);
							}
							MOD(&AlreadyHovered6, &isMouseOverButton6, isSettingsClicked, event, button6Rect, BUTTON_WIDTH, BUTTON_HEIGHT, Audio_Button_Hover);
						}else{
							MOD(&AlreadyHovered4, &isMouseOverButton4, isSettingsClicked, event, button4Rect, S_BUTTON_WIDTH, S_BUTTON_HEIGHT, Audio_Button_Hover);
						}
						
						//Mouse over audio slider detection
						if (isAudioControllerClicked && isSettingsClicked) { 
							int x = event.motion.x - SLIDER_WIDTH_KNOB / 2;
							if (x < (SCREEN_WIDTH - SLIDER_WIDTH) / 2) {
								x = (SCREEN_WIDTH - SLIDER_WIDTH) / 2;
							} else {
								if (x > (SCREEN_WIDTH + SLIDER_WIDTH) / 2 - SLIDER_WIDTH_KNOB) {
									x = (SCREEN_WIDTH + SLIDER_WIDTH) / 2 - SLIDER_WIDTH_KNOB;
								}
							}
							slider_k.x = x;
							volume = (int)(256 * (float)(x - slider_center_x) / SLIDER_WIDTH);
							Mix_VolumeChunk(Audio_Click, volume);
							Mix_VolumeChunk(Audio_Quit, volume);
							Mix_VolumeChunk(Audio_Button_Hover, volume);
							Mix_VolumeMusic(volume/2);
						}
					}
					break;
				case SDL_MOUSEBUTTONUP:
					if(loop){
						if (event.button.button == SDL_BUTTON_LEFT){
							SDL_FreeSurface(cursorSurface);
							cursorSurface = IMG_Load("M_Assets/Cursor1.png");
							if (isAudioControllerClicked){
								isAudioControllerClicked = false;
							}
							//Mouse click detection
							if(!isPlayClicked){
								if (isMouseOverButton1 && !isSettingsClicked) {
									//Playing Audio
									Play_Audio(Audio_Click);
									
									isPlayClicked=1;
								}
								if (isMouseOverButton2 && !isSettingsClicked) {
									//Playing Audio
									Play_Audio(Audio_Click);
									
									isSettingsClicked = true;
								}
								if (isMouseOverButton3 && !isSettingsClicked) {
									//Playing Audio
									Play_Audio(Audio_Quit);
									
									SDL_Delay(300); 
									
									done = SDL_TRUE;
								}
								if (isMouseOverButton6 && ! isSettingsClicked) {
									//Playing Audio
									Play_Audio(Audio_Click);
									
									if (isScorebClicked){
										isScorebClicked = false;
									}else{
										isScorebClicked = true;
									}
								}
							}
							
							if (isMouseOverButton4 && (isSettingsClicked || isPlayClicked)) {
								//Playing Audio
								Play_Audio(Audio_Click);
								isPlayClicked = false;
								isSettingsClicked = false;
							}
							if (isMouseOverButton5 && isSettingsClicked) {
								//Playing Audio
								Play_Audio(Audio_Click);
								
								i=0;
								if (res!=1){
									res = 1;
								}else{
									res = 0;
								}
							}
						}
					}
					break;
			}
		}
		
		
		
		//Render FullScreen
		i++;
		if(i<2){
			if(res==1){
				SCREEN_WIDTH=1600;
				//Calculating new sizes
				calc_res(SCREEN_WIDTH, &SCREEN_HEIGHT, &MENU_BG_WIDTH, &MENU_BG_HEIGHT, &BUTTON_WIDTH, &BUTTON_HEIGHT, &S_BUTTON_WIDTH, &S_BUTTON_HEIGHT, &SLIDER_WIDTH, &SLIDER_HEIGHT, &SLIDER_WIDTH_KNOB, &SLIDER_HEIGHT_KNOB, &center_x, &center_y, &m_center_x, &m_center_y, &s_center_x, &s_center_y, &slider_center_x, &slider_center_y); 
				
				//Rendering screen
				screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
			}else{
				SCREEN_WIDTH=1200;
				//Calculating new sizes
				calc_res(SCREEN_WIDTH, &SCREEN_HEIGHT, &MENU_BG_WIDTH, &MENU_BG_HEIGHT, &BUTTON_WIDTH, &BUTTON_HEIGHT, &S_BUTTON_WIDTH, &S_BUTTON_HEIGHT, &SLIDER_WIDTH, &SLIDER_HEIGHT, &SLIDER_WIDTH_KNOB, &SLIDER_HEIGHT_KNOB, &center_x, &center_y, &m_center_x, &m_center_y, &s_center_x, &s_center_y, &slider_center_x, &slider_center_y); 
				
				//Rendering screen
				screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
			}
			for(j=0; j<num_frames2; j++){
				sprintf(filename, "M_Assets/Animation/Char/Char_%d.png", j);
				Resize(&(frames2[j]), filename, SCREEN_WIDTH, SCREEN_HEIGHT);
			}
			
			//Repositioning Textures
			button1Rect = calc_Rec(button1Rect ,center_x ,center_y - SCREEN_WIDTH/20, BUTTON_WIDTH, BUTTON_HEIGHT);
			button2Rect = calc_Rec(button2Rect ,center_x ,center_y + SCREEN_WIDTH/27, BUTTON_WIDTH, BUTTON_HEIGHT);
			button3Rect = calc_Rec(button3Rect ,center_x ,center_y + SCREEN_WIDTH/8, BUTTON_WIDTH, BUTTON_HEIGHT);
			button4Rect = calc_Rec(button4Rect ,SCREEN_WIDTH/40 , SCREEN_HEIGHT/40, S_BUTTON_WIDTH, S_BUTTON_HEIGHT);
			button5Rect = calc_Rec(button5Rect ,center_x , center_y  + SCREEN_WIDTH/7, BUTTON_WIDTH, BUTTON_HEIGHT);
			button6Rect = calc_Rec(button5Rect ,SCREEN_WIDTH - SCREEN_WIDTH/15 , SCREEN_HEIGHT - SCREEN_HEIGHT/8.5, BUTTON_WIDTH, BUTTON_HEIGHT);
			
			//Resizing and repositioning audio slider
			slider = calc_Rec(slider,slider_center_x, slider_center_y - (SCREEN_HEIGHT/9), SLIDER_WIDTH, SLIDER_HEIGHT);
			slider_k = calc_Rec(slider_k, 0, slider_center_y - (SCREEN_HEIGHT/9), SLIDER_WIDTH_KNOB, SLIDER_HEIGHT_KNOB);
			slider_k.x = slider_center_x + (int)(volume / 256.0 * SLIDER_WIDTH) - SLIDER_WIDTH_KNOB / 2;
			
			//Initializing text
			font = TTF_OpenFont("M_Assets/Fonts/Helvetica-Bold.ttf", SCREEN_WIDTH/40);
			text_Sound = TTF_RenderText_Blended(font, "Sound Controls", text_color);
			
			top3_1 = TTF_RenderText_Blended(font, chf1, text_color);
			top3_2 = TTF_RenderText_Blended(font, chf2, text_color);
			top3_3 = TTF_RenderText_Blended(font, chf3, text_color);
			
			//Resizing textures
			Resize(&(button1Image), "M_Assets/button1.png", BUTTON_WIDTH, BUTTON_HEIGHT);
			Resize(&(button1HImage), "M_Assets/button1_hover.png", BUTTON_WIDTH, BUTTON_HEIGHT);
			Resize(&(button2Image), "M_Assets/button2.png", BUTTON_WIDTH, BUTTON_HEIGHT);
			Resize(&(button2HImage), "M_Assets/button2_hover.png", BUTTON_WIDTH, BUTTON_HEIGHT);
			Resize(&(button3Image), "M_Assets/button3.png", BUTTON_WIDTH, BUTTON_HEIGHT);
			Resize(&(button3HImage), "M_Assets/button3_hover.png", BUTTON_WIDTH, BUTTON_HEIGHT);
			Resize(&(button4Image), "M_Assets/Back_button.png", S_BUTTON_WIDTH, S_BUTTON_HEIGHT);
			Resize(&(button4HImage), "M_Assets/Back_button_hover.png", S_BUTTON_WIDTH, S_BUTTON_HEIGHT);
			Resize(&(button6Image), "M_Assets/B_SB.png", S_BUTTON_WIDTH/4, S_BUTTON_WIDTH/4);
			Resize(&(button6HImage), "M_Assets/B_SB_H.png", S_BUTTON_WIDTH/4, S_BUTTON_WIDTH/4);
			if(res==1){
				Resize(&(button5Image), "M_Assets/FSM_button.png", BUTTON_WIDTH, BUTTON_HEIGHT);
				Resize(&(button5HImage), "M_Assets/FSM_button_hover.png", BUTTON_WIDTH, BUTTON_HEIGHT);
			}else{
				Resize(&(button5Image), "M_Assets/FS_button.png", BUTTON_WIDTH, BUTTON_HEIGHT);
				Resize(&(button5HImage), "M_Assets/FS_button_hover.png", BUTTON_WIDTH, BUTTON_HEIGHT);
			}
			Resize(&(slider_bar), "M_Assets/slider_bar.png", SLIDER_WIDTH, SLIDER_HEIGHT);
			Resize(&(slider_knob), "M_Assets/slider_knob.png", SLIDER_WIDTH_KNOB, SLIDER_HEIGHT_KNOB);
			
			//Repositioning text
			text_rect = calc_Rec(text_rect, (screen->w - text_Sound->w) / 2, slider_center_y - (SCREEN_HEIGHT/6), 1, 1);
			
			top3_1_rect = calc_Rec(top3_1_rect, (screen->w - top3_1->w) / 2, slider_center_y - (SCREEN_HEIGHT/10), 1, 1);
			top3_2_rect = calc_Rec(top3_2_rect, (screen->w - top3_2->w) / 2, slider_center_y, 1, 1);
			top3_3_rect = calc_Rec(top3_3_rect, (screen->w - top3_3->w) / 2, slider_center_y + (SCREEN_HEIGHT/10), 1, 1);
		}
		
		// Update the opening animation
		Uint32 current_time = SDL_GetTicks();
		if (current_time - last_frame_time >= frame_interval && !loop) {
			// Draw the next frame
			SDL_BlitSurface(frames[frame_index], NULL, screen, NULL);

			// Update the frame index
			frame_index = (frame_index + 1) % num_frames;
			
			// Remember the time of this frame 
			last_frame_time = current_time;
			if (frame_index==num_frames-1){
				loop=true;
			}
		}
		//printf("\nframe_index2 = %d\n",frame_index2);
		//Render the background
		if(loop){
			SDL_BlitSurface(background, NULL, screen, NULL);
			if(!isPlayClicked){
				Uint32 current_time2 = SDL_GetTicks();
				if (current_time2 - last_frame_time2 >= frame_interval2) {
					// Draw the next frame
					SDL_BlitSurface(frames2[frame_index2], NULL, screen, NULL);

					// Update the frame index
					frame_index2 = (frame_index2 + 1) % num_frames2;
					
					// Remember the time of this frame
					last_frame_time2 = current_time2;
				}
			}
		}
		
		if(isPlayClicked){
			//SDL_FreeSurface(background);
			Resize(&(background), "M_Assets/BG_PLAY_C.png", SCREEN_WIDTH, SCREEN_HEIGHT);
			done = SDL_TRUE;
		}else{
			if(isSettingsClicked){
				//SDL_FreeSurface(background);
				Resize(&(background), "M_Assets/BG_S.png", SCREEN_WIDTH, SCREEN_HEIGHT);
			}else{
				//SDL_FreeSurface(background);
				Resize(&(background), "M_Assets/BG.png", SCREEN_WIDTH, SCREEN_HEIGHT);
			}
		}
		
		if(loop){
			if(!isPlayClicked){
				selector3=0;
				if (!isSettingsClicked){
					selector2=0;
					if (!isScorebClicked){
						if(selector==1){
							isMouseOverButton1=true;
							isMouseOverButton2=false;
							isMouseOverButton3=false;
						}
						if (selector==2){
							isMouseOverButton1=false;
							isMouseOverButton2=true;
							isMouseOverButton3=false;
						}
						if (selector==3){
							isMouseOverButton1=false;
							isMouseOverButton2=false;
							isMouseOverButton3=true;
						}
						//Buttons hover textures change
						BHTC(isMouseOverButton1, screen, button1HImage, button1Image, button1Rect);
						BHTC(isMouseOverButton2, screen, button2HImage, button2Image, button2Rect);
						BHTC(isMouseOverButton3, screen, button3HImage, button3Image, button3Rect);
					}else{
						SDL_BlitSurface(top3_1, NULL, screen, &top3_1_rect);
						SDL_BlitSurface(top3_2, NULL, screen, &top3_2_rect);
						SDL_BlitSurface(top3_3, NULL, screen, &top3_3_rect);
					}
					BHTC(isMouseOverButton6, screen, button6HImage, button6Image, button6Rect);
				}else{
					selector=0;
					if(selector2==1){
						isMouseOverButton4=true;
						isMouseOverButton5=false;
					}
					if (selector2==2){
						isMouseOverButton4=false;
						isMouseOverButton5=true;
					}
					//Displaying Sliders
					SDL_BlitSurface(slider_bar, NULL, screen, &slider);
					SDL_BlitSurface(slider_knob, NULL, screen, &slider_k);
					
					//Displaying text
					SDL_BlitSurface(text_Sound, NULL, screen, &text_rect);
					
					//Button hover texture change
					BHTC(isMouseOverButton4, screen, button4HImage, button4Image, button4Rect);
					BHTC(isMouseOverButton5, screen, button5HImage, button5Image, button5Rect);
				}
			}else{
				BHTC(isMouseOverButton4, screen, button4HImage, button4Image, button4Rect);
				selector=0;
				selector2=0;
				if (selector3==1){
					isMouseOverButton4=true;
				}
				
			}
			
			// Draw cursor
			SDL_BlitSurface(cursorSurface, NULL, screen, &cursorPos);
		}
		//Update screen
		SDL_Flip(screen);
		SDL_Delay(5);
	}
	
	//Freeing Buttons Textures & Surfaces
	SDL_FreeSurface(button1Image);
	SDL_FreeSurface(button1HImage);
	SDL_FreeSurface(button2Image);
	SDL_FreeSurface(button2HImage);
	SDL_FreeSurface(button3Image);
	SDL_FreeSurface(button3HImage);
	SDL_FreeSurface(button4Image);
	SDL_FreeSurface(button4HImage);
	SDL_FreeSurface(button5Image);
	SDL_FreeSurface(button5HImage);
	SDL_FreeSurface(button6Image);
	SDL_FreeSurface(button6HImage);
	
	//Freeing the background
	SDL_FreeSurface(background);
	
	//Freeing font & text
	TTF_CloseFont(font);
	SDL_FreeSurface(text_Sound);
	
	SDL_FreeSurface(top3_1);
	SDL_FreeSurface(top3_2);
	SDL_FreeSurface(top3_3);
	
	//Freeing Audio
	Mix_FreeChunk(Audio_Click);
	Mix_FreeChunk(Audio_Quit);
	Mix_FreeChunk(Audio_Button_Hover);
	Mix_FreeMusic(Audio_Bg_Music);
	Mix_CloseAudio();
	
	//Clear screen
	SDL_SetVideoMode(0, 0, 0, 0);
	
	//Quit SDL
	SDL_Quit();
	return isPlayClicked;
}

//Mouse over detection function
void MOD(bool *AlreadyHovered, bool *isMouseOverButton, bool isSettingsClicked, SDL_Event event, SDL_Rect buttonRect, int BUTTON_WIDTH, int BUTTON_HEIGHT, Mix_Chunk *Audio_Button_Hover){
	if (event.motion.x >= buttonRect.x && event.motion.x <= buttonRect.x + buttonRect.w && event.motion.y >= buttonRect.y && event.motion.y <= buttonRect.y + buttonRect.h) {
		if (!(*AlreadyHovered) && !isSettingsClicked){
			//Playing Audio
			Mix_PlayChannel(-1, Audio_Button_Hover, 0);
			*AlreadyHovered = true;
		}
		*isMouseOverButton = true;
	}else{
		if (*AlreadyHovered==true){
			*AlreadyHovered = false;
		}
		*isMouseOverButton = false;
	}
}

//Button hover texture change function
void BHTC(bool isMouseOverButton, SDL_Surface *screen, SDL_Surface *buttonHImage, SDL_Surface *buttonImage, SDL_Rect buttonRect){
	if(isMouseOverButton){
		SDL_BlitSurface(buttonHImage, NULL, screen, &buttonRect);
	}else{
		SDL_BlitSurface(buttonImage, NULL, screen, &buttonRect);
	}
}

void Play_Audio(Mix_Chunk *Audio){
	Mix_PlayChannel(-1, Audio, 0);
}

/*void Resize(SDL_Surface *(*Image), char dir[], int WIDTH, int HEIGHT){
	SDL_Surface *Buffer = IMG_Load(dir);
	
	
	*(Image) = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, Buffer->format->BitsPerPixel, Buffer->format->Rmask, Buffer->format->Gmask,  Buffer->format->Bmask, Buffer->format->Amask);

	
	SDL_SoftStretch(Buffer, NULL, *(Image), NULL);
	
	SDL_FreeSurface(Buffer);
}*/

void calc_res(int SCREEN_WIDTH, int *SCREEN_HEIGHT, int *MENU_BG_WIDTH, int *MENU_BG_HEIGHT, int *BUTTON_WIDTH,int *BUTTON_HEIGHT, int *S_BUTTON_WIDTH, int *S_BUTTON_HEIGHT, int *SLIDER_WIDTH, int *SLIDER_HEIGHT, int *SLIDER_WIDTH_KNOB, int *SLIDER_HEIGHT_KNOB, int *center_x, int *center_y, int *m_center_x, int *m_center_y, int *s_center_x, int *s_center_y, int *slider_center_x, int *slider_center_y){
	float ratio_screen = 1.7777777777777777;
	*SCREEN_HEIGHT = (float)(SCREEN_WIDTH / ratio_screen);
	
	//Menu bg size variables
	*MENU_BG_WIDTH = SCREEN_WIDTH/3;
	float ratio_menu_bg = 0.6666666666666666;
	*MENU_BG_HEIGHT = (float)(*MENU_BG_WIDTH / ratio_menu_bg);
	
	//Buttons sizes variables
	*BUTTON_WIDTH = SCREEN_WIDTH/5;
	float ratio_buttons = 3.5555555555555554;
	*BUTTON_HEIGHT = (float)(*BUTTON_WIDTH / ratio_buttons);
	
	*S_BUTTON_WIDTH = SCREEN_WIDTH/8;
	float s_ratio_buttons = 1.9154929577464788;
	*S_BUTTON_HEIGHT = (float)(*S_BUTTON_WIDTH / s_ratio_buttons);
	
	//Slider size variables
	*SLIDER_WIDTH = SCREEN_WIDTH/4;
	float ratio_slider = 6.02970297029703;
	*SLIDER_HEIGHT = (float)(*SLIDER_WIDTH / ratio_slider);
	
	//Slider knob size variables
	*SLIDER_WIDTH_KNOB = SCREEN_WIDTH/70;
	float ratio_slider_knob = 0.34183673469387754;
	*SLIDER_HEIGHT_KNOB = (float)(*SLIDER_WIDTH_KNOB / ratio_slider_knob);
	
	//variables
	*center_x = (SCREEN_WIDTH - *BUTTON_WIDTH) / 2;
	*center_y = (*SCREEN_HEIGHT - *BUTTON_HEIGHT) / 2;
	*m_center_x = (SCREEN_WIDTH - *MENU_BG_WIDTH) / 2;
	*m_center_y = (*SCREEN_HEIGHT - *MENU_BG_HEIGHT) / 2;
	*s_center_x = (SCREEN_WIDTH - *MENU_BG_WIDTH*1.2) / 2;
	*s_center_y = (*SCREEN_HEIGHT - *MENU_BG_HEIGHT*1.2) / 2;
	*slider_center_x = (SCREEN_WIDTH - *SLIDER_WIDTH) / 2;
	*slider_center_y = (*SCREEN_HEIGHT - *SLIDER_HEIGHT) / 2;
}

SDL_Rect calc_Rec(SDL_Rect Rec, int m_center_x, int m_center_y, int MENU_BG_WIDTH, int MENU_BG_HEIGHT){
	Rec.x=m_center_x;
	Rec.y=m_center_y;
	Rec.w=MENU_BG_WIDTH;
	Rec.h=MENU_BG_HEIGHT;
	return Rec;
}
void menu(){
	
}
