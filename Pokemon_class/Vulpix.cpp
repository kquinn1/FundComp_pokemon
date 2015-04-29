//Katie Quinn
//Vulpix.cpp
#include "Vulpix.h"
#include <iostream>
using namespace std;

const int C_BASE_HP = 38; //base stats for vulpix
const int C_BASE_A = 41;
const int C_BASE_D = 40;
const int C_BASE_SPEED= 65;
const int C_BASE_SPEC = 65;
const int CATCH = 190;

Vulpix::Vulpix(int level) : Fire(level){
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

  Pokemon::setName("VULPIX");
  setAttacks(); 

//set exp type for experience calculations
  Pokemon::setEXPtype("MF");

//set catch rate for grass
  Pokemon::setCatch(CATCH);
}

void Vulpix::print(){
  cout << "VULPIX";
}

void Vulpix::setAttacks(){
//simplification of attacks, starts out with four attacks
 setMove( "quick attack", "normal", 40,30, 100);
 setMove("ember", "fire", 40, 25,100);
 setMove("flamethrower", "fire", 95,15 ,70);
 setMove("fire spin","fire", 15, 15,70);
}

