//Katie Quinn
//Charmander.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Charmander class

#ifndef CHARMANDER_H
#define CHARMANDER_H
#include "Pokemon.h"
#include "Fire.h"

class Charmander : public Fire {
  public:
	Charmander(int); //need to set up constructor to call Pokemon constructor
	void print(); // for concrete class
	void setAttacks();
  private:
//should a private member contain the sprite?

};

#endif
