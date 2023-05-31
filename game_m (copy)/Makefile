# définition des cibles particulières
.PHONY: clean, mrproper
 
# désactivation des règles implicites
.SUFFIXES:


CC = gcc
CFLAGS = -Wall -w
RM = rm -rf


EXEC = prog
# -l
LIBS = -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lserialport
# -L
LIBSPATH = 
# -I
INCLUDESPATH = 

SOURCES = mainn.c carac.c background.c fonction.c Menu.c Functions.c minimap.c lot5.c -lm
OBJECTS = $(SOURCES:.c=.o)


all : mainn.o carac.o background.o fonction.o Main.o Functions.o minimap.o lot5.o arduino.o -lm
	$(CC) $^ -o $(EXEC) $(INCLUDESPATH) $(LIBSPATH) $(LIBS)

%.o : %.c
	$(CC)  $(LIBSPATH) $(INCLUDESPATH) -c $< -o $@ $(CFLAGS)
carac.o : carac.c fonctionn.h
	$(CC) $(CFLAGS) $(INCLUDESPATH) -c $< -o $@
background.o : background.c background.h
	$(CC) $(CFLAGS) $(INCLUDESPATH) -c $< -o $@
fonction.o : fonction.c fonction.h
	$(CC) $(CFLAGS) $(INCLUDESPATH) -c $< -o $@
Functions.o : Functions.c Link.h
	$(CC) $(CFLAGS) $(INCLUDESPATH) -c $< -o $@
mainn.o : mainn.c Link.h
	$(CC) $(CFLAGS) $(INCLUDESPATH) -c $< -o $@
lot5.o : lot5.c lot5.h
	$(CC) $(CFLAGS) $(INCLUDESPATH) -c $< -o $@
Main.o : Main.c Link.h
	$(CC) $(CFLAGS) $(INCLUDESPATH) -c $< -o $@
minimap.o : minimap.c minimap.h
	$(CC) $(CFLAGS) $(INCLUDESPATH) -c $< -o $@
clean :
	$(RM) *.o
	
mrproper : clean
	$(RM) $(EXEC)
