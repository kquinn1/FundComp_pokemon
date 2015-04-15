//Katie Quinn
//Oddish.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Oddiesh class

#ifndef ODDISH_H
#define ODDISH_H
#include "Pokemon.h"
#include "Grass.h"

class Oddish : public Grass {
  public:
	Oddish(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
//should a private member contain the sprite?
  private:
};
#endif
