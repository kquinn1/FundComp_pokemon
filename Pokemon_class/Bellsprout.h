//Katie Quinn
//Bellsprout.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Bellsprout class

#ifndef BELLSPROUT_H
#define BELLSPROUT_H
#include "Pokemon.h"
#include "Grass.h"

class Bellsprout : public Grass {
  public:
	Bellsprout(int); //need to set up constructor to call Pokemon constructor
	void print(); //prints the name
	void setAttacks();//sets the attacks for a pokemon
};
#endif
