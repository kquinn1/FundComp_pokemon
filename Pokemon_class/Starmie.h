//Katie Quinn
//Starmie.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Staryu class

#ifndef STARMIE_H
#define STARMIE_H
#include "Pokemon.h"
#include "Water.h"
class Starmie : public Water {
  public:
	Starmie(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
  private:
//should a private member contain the sprite?

};

#endif
