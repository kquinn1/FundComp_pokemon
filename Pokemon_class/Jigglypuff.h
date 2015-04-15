//Katie Quinn
//Jigglypuff.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Jigglypuff class

#ifndef JIGGLYPUFF_H
#define JIGGLYPUFF_H
#include "Pokemon.h"
#include "Normal.h"

class Jigglypuff : public Normal{
  public:
	Jigglypuff(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
//should a private member contain the sprite?
  private:
};
#endif
