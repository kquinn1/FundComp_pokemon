OBJS = main.cpp Battle.cpp Battle.h globals.h

CC = g++

COMPILER_FLAGS = 

LINKER_FLAGS = -lSDL -lSDL_image

OBJ_NAME = main

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean: 
	rm -f *.o main *~
