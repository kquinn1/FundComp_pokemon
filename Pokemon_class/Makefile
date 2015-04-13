#Object files:
OBJ = Attack.o Bulbasaur.o Charmander.o Electric.o Enemy.o Fight.o Fire.o Goldeen.o Grass.o Horsea.o Pikachu.o Player.o Pokemon.o Psyduck.o Shellder.o Squirtle.o Starmie.o Water.o Staryu.o
#Header files:
HDR = Attack.h Bulbasaur.h Charmander.h Electric.h Enemy.h Fight.h Fire.h Goldeen.h Grass.h Horsea.h Pikachu.h Player.h Pokemon.h Psyduck.h Shellder.h Squirtle.h Starmie.h Water.h Staryu.h 
#Libraries (further on)
#LiBS = `pkg-config -- `

#Executable
EXEC = poke.out

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
