//Katie Quinn
//Bulbasaur.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Bulbasuar class

#ifndef BUlBASAUR_H
#define BULBASAUR_H
#include <string>
#include "Pokemon.h"
#include "Grass.h"
class Bulbasaur : public Grass {
  public:
	Bulbasaur(int); //need to set up constructor to call Pokemon constructor
	void print();
//should a private member contain the sprite?

};
#endif
