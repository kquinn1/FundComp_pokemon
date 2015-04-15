//Katie Quinn
//Snorlax.cpp

#include "Snorlax.h"
#include <iostream>
using namespace std;

const int B_BASE_HP = 160; //base stats for Snorlax
const int B_BASE_A = 110;
const int B_BASE_D = 65;
const int B_BASE_SPEED= 30;
const int B_BASE_SPEC = 65;

Snorlax::Snorlax(int level) : Normal(level){
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

  Pokemon::setName("SNORLAX");
  setAttacks();
//set up experience type for leveling up
  Pokemon::setEXPtype("S"); //will allow for accurate calculations

}

void Snorlax::print() {
// such that type and pokemon are virual need a function definition
// in the species class
  cout << "SNORLAX";
}

void Snorlax::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove( "headbutt", "normal", 70,15, 100);
  setMove("body slam", "normal", 85, 15,100);
  setMove("double edge", "normal", 100, 15 , 100);
  setMove("hyper beam","normal", 150, 5,90);
}

