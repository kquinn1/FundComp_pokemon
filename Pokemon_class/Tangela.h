//Katie Quinn
//Tangela.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete

#ifndef TANGELA_H
#define TANGELA_H
#include "Pokemon.h"
#include "Grass.h"

class Tangela : public Grass {
  public:
	Tangela(int); //need to set up constructor to call Pokemon constructor
	void print(); //prints the name
	void setAttacks();//sets the attacks for a pokemon
};
#endif
