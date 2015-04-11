//Katie Quinn
//Bulbasaur.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Bulbasuar class

#ifndef BUlBASAUR_H
#define BULBASAUR_H
#include "Pokemon.h"
#include "Grass.h"
#include "Attack.h"
#include <vector>

class Bulbasaur : public Grass {
  public:
	Bulbasaur(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
	Attack* getAttack(int);
//should a private member contain the sprite?
  private:
	vector<Attack*> attacks;
};
#endif
