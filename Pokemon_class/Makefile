#Object files:
OBJ = walking.o Attack.o Shop.o Bulbasaur.o Charmander.o Electric.o Enemy.o Battle.o Fight.o Fire.o Goldeen.o Grass.o Heal.o Horsea.o Pikachu.o Player.o Pokemon.o Psyduck.o Shellder.o Squirtle.o Starmie.o Water.o Staryu.o Item.o Oddish.o Jigglypuff.o Snorlax.o Eevee.o Normal.o onGrass.o  Timer.o Bellsprout.o Tangela.o Magnemite.o Growlithe.o Vulpix.o Tauros.o
#Header files:
HDR =  Attack.h Shop.h Bulbasaur.h Charmander.h Electric.h Enemy.h Battle.h Fight.h Fire.h Goldeen.h Grass.h Heal.h Horsea.h Pikachu.h Player.h Pokemon.h Psyduck.h Shellder.h Squirtle.h Starmie.h Water.h Staryu.h Item.h Oddish.h Jigglypuff.h Snorlax.h Eevee.h Normal.h onGrass.h Timer.h Bellsprout.h Tangela.h Magnemite.h Growlithe.h Vulpix.h Tauros.h

#Libraries (further on)
#LIBS = `pkg-config --cflags --libs SDL SDL_image `

#Executable
EXEC = walk

#one rule to rule them all
all: $(EXEC)

#compile
CPP = g++ -c -o $@ $<
#LINK = ${LIBS}
CXX = g++ -o $@

#Rules
%.o : %.cpp ${HDRS}
	${CPP}

#Executable rule
$(EXEC) : ${OBJ}
	${CXX} ${OBJ} -lSDL -lSDL_image # ${LINK}
#clean
clean:
	rm *.o $(EXEC)
