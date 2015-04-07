//Katie Quinn
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
// Pikachu class

#ifndef PIKACHU_H
#define PIKACHU_H
#include <string>
#include "Pokemon.h"
#include "Electric.h"
#include <iostream>
using namespace std;

const int PIK_BASE_A = 55;
const int PIK_BASE_D = 30;
const int PIK_BASE_SPEED= 90;
const int PIK_BASE_SPEC = 50;
const int PIK_BASE_HP = 35; //base stats for pikachu

class Pikachu : public Electric {
  public:
	Pikachu(int); //need to set up constructor to call Pokemon constructor
	void print();
//should a private member contain the sprite?

};

Pikachu::Pikachu(int level) : Electric(level){
  Pokemon::setBaseA(PIK_BASE_A);
  Pokemon::setBaseD(PIK_BASE_D);
  Pokemon::setBaseSpec(PIK_BASE_SPEC);
  Pokemon::setBaseSpeed(PIK_BASE_SPEED);
  Pokemon::setBaseHP(PIK_BASE_HP);
  
//since all stats have been declared, set dependant stats
  Pokemon::setHP(); //set HP initially
  Pokemon::setAttack();
  Pokemon::setDef();
  Pokemon::set_spec_A();
  Pokemon::set_spec_D();
  Pokemon::setSpeed();
}

void Pikachu::print(){
	cout << "PIKACHU";
}

#endif
