//Katie Quinn
//Pokemon species class
//Magnemite.h
//While the pokemon class and the type class are abstract, this class is concrete
// Magnemite class

#ifndef MAGNEMITE_H
#define MAGNEMITE_H
#include "Pokemon.h"
#include "Electric.h"
class Magnemite : public Electric {
  public:
	Magnemite(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
};
#endif
