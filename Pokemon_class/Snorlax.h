//Katie Quinn
//Snorlax.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete

#ifndef SNORLAX_H
#define SNORLAX_H
#include "Pokemon.h"
#include "Normal.h"

class Snorlax : public Normal {
  public:
	Snorlax(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
//should a private member contain the sprite?
  private:
};
#endif
