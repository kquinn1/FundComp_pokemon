//Katie Quinn
//Shellder.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Shellder class

#ifndef SHELLDER_H
#define SHELLDER_H
#include "Pokemon.h"
#include "Water.h"
#include "Attack.h"
#include <vector>

class Shellder : public Water {
  public:
	Shellder(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
	Attack* getAttack(int);
  private:
	vector<Attack*> attacks;
//should a private member contain the sprite?

};

#endif
