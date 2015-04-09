//Katie Quinn
//Staryu.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Staryu class

#ifndef STARYU_H
#define STARYU_H
#include <string>
#include "Pokemon.h"
#include "Water.h"
class Staryu : public Water {
  public:
	Staryu(int); //need to set up constructor to call Pokemon constructor
	void print();
//should a private member contain the sprite?

};

#endif
