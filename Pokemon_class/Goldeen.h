//Katie Quinn
//Goldeen.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Goldeen class

#ifndef GOLDEEN_H
#define GOLDEEN_H
#include "Pokemon.h"
#include "Water.h"
#include "Attack.h"
#include <vector>

class Goldeen : public Water {
  public:
	Goldeen(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
	Attack* getAttack(int);
  private:
	vector<Attack*> attacks;
//should a private member contain the sprite?

};

#endif
