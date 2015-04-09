//Katie Quinn
//Squirtle.cpp
#include "Squirtle.h"
#include <iostream>
using namespace std;

const int S_BASE_A = 48;
const int S_BASE_D = 65;
const int S_BASE_SPEED= 43;
const int S_BASE_SPEC = 50;
const int S_BASE_HP = 44; //base stats for bulbasaur

Squirtle::Squirtle(int level) : Water(level){
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

void Squirtle::print(){
  cout << "SQUIRTLE";
}
