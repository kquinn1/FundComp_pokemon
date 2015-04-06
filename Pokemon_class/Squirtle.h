//Katie Quinn
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Squirtle class

#ifndef SQUIRTLE_H
#define SQUIRTLE_H
#include <string>
#include "Pokemon.h"
#include "Water.h"

const int S_BASE_A = 48;
const int S_BASE_D = 65;
const int S_BASE_SPEED= 43;
const int S_BASE_SPEC = 50;
const int S_BASE_HP = 44; //base stats for bulbasaur

class Squirtle : public Water {
  public:
	Squirtle(string, int); //need to set up constructor to call Pokemon constructor
//should a private member contain the sprite?

};

Squirtle::Squirtle(string myName, int level) : Water(myName, level){
  Pokemon::setBaseA(S_BASE_A);
  Pokemon::setBaseD(S_BASE_D);
  Pokemon::setBaseSpec(S_BASE_SPEC);
  Pokemon::setBaseSpeed(S_BASE_SPEED);
  Pokemon::setBaseHP(S_BASE_HP);
  
//since all stats have been declared, set dependant stats
  Pokemon::setHP(); //set HP initially
  Pokemon::setAttack();
  Pokemon::setDef();
  Pokemon::set_spec_A();
  Pokemon::set_spec_D();
  Pokemon::setSpeed();
}

#endif
