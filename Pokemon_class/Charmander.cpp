//Katie Quinn
//Charmander.cpp
#include "Charmander.h"
#include <iostream>
using namespace std;

const int C_BASE_A = 52;
const int C_BASE_D = 43;
const int C_BASE_SPEED= 65;
const int C_BASE_SPEC = 50;
const int C_BASE_HP = 39; //base stats for bulbasaur

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

