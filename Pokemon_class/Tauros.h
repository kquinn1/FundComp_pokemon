//Katie Quinn
//Tauros.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete

#ifndef TAUROS_H
#define TAUROS_H
#include "Pokemon.h"
#include "Normal.h"

class Tauros : public Normal {
  public:
	Tauros(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
};
#endif
