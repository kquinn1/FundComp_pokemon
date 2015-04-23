#Object files:
OBJ = game.o Attack.o Bulbasaur.o Charmander.o Electric.o Enemy.o Battle.o Fight.o Fire.o Goldeen.o Grass.o Heal.o Horsea.o Pikachu.o Player.o Pokemon.o Psyduck.o Shellder.o Squirtle.o Starmie.o Water.o Staryu.o Item.o Oddish.o Jigglypuff.o Snorlax.o Eevee.o Normal.o onGrass.o Shop.o
#Header files:
HDR =  Attack.h Bulbasaur.h Charmander.h Electric.h Enemy.h Battle.h Fight.h Fire.h Goldeen.h Grass.h Heal.h Horsea.h Pikachu.h Player.h Pokemon.h Psyduck.h Shellder.h Squirtle.h Starmie.h Water.h Staryu.h Item.h Oddish.h Jigglypuff.h Snorlax.h Eevee.h Normal.h onGrass.h Shop.h 

#Libraries (further on)
#LiBS = `pkg-config -- `

#Executable
EXEC = game

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
	${CXX} ${OBJ} #${LINK}
#clean
clean:
	rm *.o $(EXEC)
