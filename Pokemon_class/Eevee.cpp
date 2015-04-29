//Katie Quinn
//Eevee.cpp

#include "Eevee.h"
#include <iostream>
using namespace std;

const int B_BASE_A = 49;
const int B_BASE_D = 49;
const int B_BASE_SPEED= 45;
const int B_BASE_SPEC = 65;
const int B_BASE_HP = 45; //base stats for eevee
const int CATCH = 45;

Eevee::Eevee(int level) : Normal(level){
//set base stats to calculate stats
  Pokemon::setBaseA(B_BASE_A);
  Pokemon::setBaseD(B_BASE_D);
  Pokemon::setBaseSpec(B_BASE_SPEC);
  Pokemon::setBaseSpeed(B_BASE_SPEED);
  Pokemon::setBaseHP(B_BASE_HP);
  
//since all stats have been declared, set dependant stats
  Pokemon::setHP(); //set HP initially
  Pokemon::setAttack();
  Pokemon::setDef();
  Pokemon::setSpecial();
  Pokemon::setSpeed();

  Pokemon::setName("EEVEE");
  setAttacks();
//set up experience type for leveling up
  Pokemon::setEXPtype("MF"); //will allow for accurate calculations

//set catch rate
  Pokemon::setCatch(CATCH);
}

void Eevee::print() {
// such that type and pokemon are virual need a function definition
// in the species class
  cout << "EEVEE";
}

void Eevee::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove( "tackle", "normal", 35,35, 95);
  setMove("quick attack", "nromal", 40, 30,100);
  setMove("bite", "normal", 60, 25 , 100);
  setMove("take down","normal", 90, 20,85);
}

