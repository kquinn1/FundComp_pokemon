//Katie Quinn
//Tauros.cpp

#include "Tauros.h"
#include <iostream>
using namespace std;

const int B_BASE_HP = 75; //base stats for Tauros
const int B_BASE_A = 100;
const int B_BASE_D = 95;
const int B_BASE_SPEED= 110;
const int B_BASE_SPEC = 70;
const int CATCH = 45;

Tauros::Tauros(int level) : Normal(level){
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

  Pokemon::setName("TAUROS");
  setAttacks();
//set up experience type for leveling up
  Pokemon::setEXPtype("S"); //will allow for accurate calculations
//set catch rate
  Pokemon::setCatch(CATCH);
}

void Tauros::print() {
// such that type and pokemon are virual need a function definition
// in the species class
  cout << "TAUROS";
}

void Tauros::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove( "tackle", "normal", 35,35, 95);
  setMove("stomp", "normal", 65, 20,100);
  setMove("rage", "normal", 20, 20 , 100);
  setMove("take down","normal", 90, 20, 85);
}

