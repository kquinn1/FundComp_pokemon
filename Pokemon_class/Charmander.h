//Katie Quinn
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Charmander class

#ifndef CHARMANDER_H
#define CHARMANDER_H
#include <string>
#include "Pokemon.h"
#include "Fire.h"
#include <iostream>
using namespace std;

const int C_BASE_A = 52;
const int C_BASE_D = 43;
const int C_BASE_SPEED= 65;
const int C_BASE_SPEC = 50;
const int C_BASE_HP = 39; //base stats for bulbasaur

class Charmander : public Fire {
  public:
	Charmander(int); //need to set up constructor to call Pokemon constructor
	void print(); // for concrete class
//should a private member contain the sprite?

};

Charmander::Charmander(int level) : Fire(level){
  Pokemon::setBaseA(C_BASE_A);
  Pokemon::setBaseD(C_BASE_D);
  Pokemon::setBaseSpec(C_BASE_SPEC);
  Pokemon::setBaseSpeed(C_BASE_SPEED);
  Pokemon::setBaseHP(C_BASE_HP);
  
//since all stats have been declared, set dependant stats
  Pokemon::setHP(); //set HP initially
  Pokemon::setAttack();
  Pokemon::setDef();
  Pokemon::set_spec_A();
  Pokemon::set_spec_D();
  Pokemon::setSpeed();
}

void Charmander::print(){
  cout << "CHARMANDER";
}

#endif
