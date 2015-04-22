//Katie Quinn
//Charmander.cpp
#include "Charmander.h"
#include <iostream>
using namespace std;

const int C_BASE_A = 52;
const int C_BASE_D = 43;
const int C_BASE_SPEED= 65;
const int C_BASE_SPEC = 50;
const int C_BASE_HP = 39; //base stats for charmander
const int CATCH = 45;

Charmander::Charmander(int level) : Fire(level){
//set base stats
  Pokemon::setBaseA(C_BASE_A);
  Pokemon::setBaseD(C_BASE_D);
  Pokemon::setBaseSpec(C_BASE_SPEC);
  Pokemon::setBaseSpeed(C_BASE_SPEED);
  Pokemon::setBaseHP(C_BASE_HP);
  
//since all stats have been declared, set dependant stats
  Pokemon::setHP(); //set HP initially
  Pokemon::setAttack();
  Pokemon::setDef();
  Pokemon::setSpecial();
  Pokemon::setSpeed();

  Pokemon::setName("CHARMANDER");
  setAttacks(); 

//set exp type for experience calculations
  Pokemon::setEXPtype("MS");

//set catch rate for grass
  Pokemon::setCatch(CATCH);
}

void Charmander::print(){
  cout << "CHARMANDER";
}

void Charmander::setAttacks(){
//simplification of attacks, starts out with four attacks
 setMove( "scratch", "normal", 40,35, 100);
 setMove("ember", "fire", 40, 25,100);
 setMove("flamethrower", "fire", 95,15 ,70);
 setMove("mega kick","normal", 120, 5,75);//learn by tm
}

