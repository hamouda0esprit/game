prog:lot5.o main.o 
	gcc lot5.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g 
main.o:main.c 
	gcc -c main.c -g 
lot5.o:lot5.c 
	gcc -c lot5.c -g

