//Katie Quinn
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Staryu class

#ifndef STARYU_H
#define STARYU_H
#include <string>
#include "Pokemon.h"
#include "Water.h"
#include <iostream>
using namespace std;

const int S_BASE_A = 45;
const int S_BASE_D = 55;
const int S_BASE_SPEED= 85;
const int S_BASE_SPEC = 70;
const int S_BASE_HP = 30; //base stats for bulbasaur

class Staryu : public Water {
  public:
	Staryu(int); //need to set up constructor to call Pokemon constructor
//should a private member contain the sprite?

};

Staryu::Staryu(int level) : Water(level){
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

void Staryu::print(){
  cout << "STARYU";
}

#endif
