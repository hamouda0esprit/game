# définition des cibles particulières
.PHONY: clean, mrproper
 
# désactivation des règles implicites
.SUFFIXES:


CC = gcc
CFLAGS = -Wall -w
RM = rm -rf


EXEC = prog
# -l
LIBS = -lSDL -lSDL_image -lSDL_ttf 
# -L
LIBSPATH = 
# -I
INCLUDESPATH = 

SOURCES = mainn.c  carac.c
OBJECTS = $(SOURCES:.c=.o)


all : mainn.o  carac.o 
	$(CC) $^ -o $(EXEC) $(INCLUDESPATH) $(LIBSPATH) $(LIBS)

%.o : %.c
	$(CC)  $(LIBSPATH) $(INCLUDESPATH) -c $< -o $@ $(CFLAGS)
carac.o : carac.c fonctionn.h
	$(CC) $(CFLAGS) $(INCLUDESPATH) -c $< -o $@

clean :
	$(RM) *.o
	
mrproper : clean
	$(RM) $(EXEC)
