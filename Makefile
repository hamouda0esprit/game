prog:minimap.o main.o
	gcc minimap.o main.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm -g
main.o:main.c
	gcc -c main.c -g
function.o:minimap.c
	gcc -c minimap.c -g
