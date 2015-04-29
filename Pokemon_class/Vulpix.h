//Katie Quinn
//Vulpix.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Vulpix class

#ifndef VULPIX_H
#define VULPIX_H
#include "Pokemon.h"
#include "Fire.h"

class Vulpix : public Fire {
  public:
	Vulpix(int); //need to set up constructor to call Pokemon constructor
	void print(); // for concrete class
	void setAttacks();//set the attacks in derived class

};

#endif
