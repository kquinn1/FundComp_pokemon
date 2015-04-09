//Katie Quinn
//Psyduck.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Psyduck class

#ifndef PSYDUCK_H
#define PSYDUCK_H
#include <string>
#include "Pokemon.h"
#include "Water.h"
class Psyduck : public Water {
  public:
	Psyduck(int); //need to set up constructor to call Pokemon constructor
	void print();
//should a private member contain the sprite?

};

#endif
