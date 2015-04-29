//Katie Quinn
//Bellsprout.cpp

#include "Bellsprout.h"
#include <iostream>
using namespace std;

const int B_BASE_HP = 50; //base stats for bellsprout
const int B_BASE_A = 75;
const int B_BASE_D = 35;
const int B_BASE_SPEED= 40;
const int B_BASE_SPEC = 70;
const int CATCH = 255;

Bellsprout::Bellsprout(int level) : Grass(level){
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

  Pokemon::setName("BELLSPROUT");
  setAttacks();
//set up experience type for leveling up
  Pokemon::setEXPtype("MS"); //will allow for accurate calculations

//set catch rate 
  Pokemon::setCatch(CATCH);

}

void Bellsprout::print() {
// such that type and pokemon are virual need a function definition
// in the species class
  cout << "BELLSPROUT";
}

void Bellsprout::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove( "wrap", "normal", 15, 20, 90);
  setMove("vine whip", "grass", 35, 10,100);
  setMove("razor leaf", "grass", 55, 25 , 95);
  setMove("slam","grass", 80, 20,75);
}

