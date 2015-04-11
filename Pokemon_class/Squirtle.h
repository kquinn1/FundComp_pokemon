//Katie Quinn
//Squirtle.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Squirtle class

#ifndef SQUIRTLE_H
#define SQUIRTLE_H
#include "Pokemon.h"
#include "Water.h"

class Squirtle : public Water {
  public:
	Squirtle(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
  private:
//should a private member contain the sprite?
};
#endif
