//Katie Quinn
//Staryu.cpp
#include "Staryu.h"
#include <iostream>
using namespace std;

const int S_BASE_A = 45;
const int S_BASE_D = 55;
const int S_BASE_SPEED= 85;
const int S_BASE_SPEC = 70;
const int S_BASE_HP = 30; //base stats for staryu
const int CATCH = 225;

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
  Pokemon::setSpecial();
  Pokemon::setSpeed();

  Pokemon::setName("STARYU");
  setAttacks();

  Pokemon::setEXPtype("S");
//set catch rate
  Pokemon::setCatch(CATCH);
}

void Staryu::print(){
  cout << "STARYU";
}

void Staryu::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove( "tackle", "normal", 35, 35, 95);
  setMove("water gun", "water", 40, 25,100);
  setMove("hydro pump", "water", 120, 5, 80);
  setMove("swift","normal", 60, 20,100);//acc could be off
}
