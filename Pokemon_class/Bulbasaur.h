//Katie Quinn
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
//Bulbasuar class

#ifndef BUlBASAUR_H
#define BULBASAUR_H
#include <string>
#include "Pokemon.h"
#include "Grass.h"
#include <iostream>
using namespace std;

const int B_BASE_A = 49;
const int B_BASE_D = 49;
const int B_BASE_SPEED= 45;
const int B_BASE_SPEC = 65;
const int B_BASE_HP = 45; //base stats for bulbasaur

class Bulbasaur : public Grass {
  public:
	Bulbasaur(int); //need to set up constructor to call Pokemon constructor
	void print();
//should a private member contain the sprite?

};

Bulbasaur::Bulbasaur(int level) : Grass(level){
  Pokemon::setBaseA(B_BASE_A);
  Pokemon::setBaseD(B_BASE_D);
  Pokemon::setBaseSpec(B_BASE_SPEC);
  Pokemon::setBaseSpeed(B_BASE_SPEED);
  Pokemon::setBaseHP(B_BASE_HP);
  
//since all stats have been declared, set dependant stats
  Pokemon::setHP(); //set HP initially
  Pokemon::setAttack();
  Pokemon::setDef();
  Pokemon::set_spec_A();
  Pokemon::set_spec_D();
  Pokemon::setSpeed();
}

void Bulbasaur::print() {
// such that type and pokemon are virual need a function definition
// in the species class
 cout << "BULBASAUR";
}

#endif
