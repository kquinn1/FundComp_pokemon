//Katie Quinn
//Eevee.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Eevee class

#ifndef EEVEE_H
#define EEVEE_H
#include "Pokemon.h"
#include "Normal.h"

class Eevee : public Normal {
  public:
	Eevee(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
//should a private member contain the sprite?
  private:
};
#endif
