//Katie Quinn
//Growlithe.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Growlithe class

#ifndef GROWLITHE_H
#define GROWLITHE_H
#include "Pokemon.h"
#include "Fire.h"

class Growlithe : public Fire {
  public:
	Growlithe(int); //need to set up constructor to call Pokemon constructor
	void print(); // for concrete class
	void setAttacks();//set the attacks in derived class

};

#endif
