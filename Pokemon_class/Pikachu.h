//Katie Quinn
//Pokemon species class
//Pikachu.h
//While the pokemon class and the type class are abstract, this class is concrete
// Pikachu class

#ifndef PIKACHU_H
#define PIKACHU_H
#include "Pokemon.h"
#include "Electric.h"
class Pikachu : public Electric {
  public:
	Pikachu(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
//should a private member contain the sprite?
  private:
};
#endif
