//Katie Quinn
//Horsea.h
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Horsea class

#ifndef HORSEA_H
#define HORSEA_H
#include "Pokemon.h"
#include "Water.h"
#include "Attack.h"
#include <vector>

class Horsea : public Water {
  public:
	Horsea(int); //need to set up constructor to call Pokemon constructor
	void print();
	void setAttacks();
	Attack* getAttack(int);
  private:
	vector<Attack*> attacks;
//should a private member contain the sprite?
};
#endif
