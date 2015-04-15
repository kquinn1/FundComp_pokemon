//Katie Quinn
//Oddish.cpp

#include "Oddish.h"
#include <iostream>
using namespace std;

const int B_BASE_HP = 45; //base stats for Oddish
const int B_BASE_A = 50;
const int B_BASE_D = 55;
const int B_BASE_SPEED= 30;
const int B_BASE_SPEC = 75;

Oddish::Oddish(int level) : Grass(level){
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

  Pokemon::setName("ODDISH");
  setAttacks();
//set up experience type for leveling up
  Pokemon::setEXPtype("MS"); //will allow for accurate calculations

}

void Oddish::print() {
// such that type and pokemon are virual need a function definition
// in the species class
  cout << "ODDISH";
}

void Oddish::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove( "absorb", "grass", 20,20, 100);
  setMove("petal dance", "grass", 70, 20,100);
  setMove("mega drain", "grass", 40, 10, 100);
  setMove("solar beam","grass", 120, 10,100);
}

