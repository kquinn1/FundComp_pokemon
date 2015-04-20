OBJS = Gym.cpp Player.cpp Player.h Timer.cpp Timer.h globals.h function.cpp function.h

CC = g++

COMPILER_FLAGS = 

LINKER_FLAGS = -lSDL -lSDL_image

OBJ_NAME = test

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean: 
	rm -f *.o main *~
