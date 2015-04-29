//Katie Quinn
//Jigglypuff.cpp

#include "Jigglypuff.h"
#include <iostream>
using namespace std;

const int B_BASE_HP = 115; //base stats for jigglypuff
const int B_BASE_A = 45;
const int B_BASE_D = 20;
const int B_BASE_SPEED= 20;
const int B_BASE_SPEC = 25;
const int CATCH = 170;

Jigglypuff::Jigglypuff(int level) : Normal(level){
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

  Pokemon::setName("JIGGLYPUFF");
  setAttacks();
//set up experience type for leveling up
  Pokemon::setEXPtype("F"); //will allow for accurate calculations
//set catch rate
  Pokemon::setCatch(CATCH);
}

void Jigglypuff::print() {
// such that type and pokemon are virual need a function definition
// in the species class
  cout << "JIGGLYPUFF";
}

void Jigglypuff::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove( "pound", "normal", 40,35, 100);
  setMove("double slap", "normal", 15, 10,85);
  setMove("body slam", "normal",85, 15 , 100);
  setMove("double-edge","normal", 100, 15,100);
}

