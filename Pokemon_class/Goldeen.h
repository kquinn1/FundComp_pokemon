//Katie Quinn
//Goldeen.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Goldeen class

#ifndef GOLDEEN_H
#define GOLDEEN_H
#include <string>
#include "Pokemon.h"
#include "Water.h"

class Goldeen : public Water {
  public:
	Goldeen(int); //need to set up constructor to call Pokemon constructor
	void print();
//should a private member contain the sprite?

};

#endif
