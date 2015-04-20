OBJS = walk.cpp function.h function.cpp globals.h Player.cpp Player.h Timer.cpp Timer.h

CC = g++

COMPILER_FLAGS = 

LINKER_FLAGS = -lSDL -lSDL_image

OBJ_NAME = test

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean: 
	rm -f *.o main *~
