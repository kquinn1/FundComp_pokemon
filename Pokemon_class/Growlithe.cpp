//Katie Quinn
//Growlithe.cpp
#include "Growlithe.h"
#include <iostream>
using namespace std;

const int C_BASE_HP = 55; //base stats for growlithe
const int C_BASE_A = 70;
const int C_BASE_D = 45;
const int C_BASE_SPEED= 60;
const int C_BASE_SPEC = 50;
const int CATCH = 190;

Growlithe::Growlithe(int level) : Fire(level){
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

  Pokemon::setName("GROWLITHE");
  setAttacks(); 

//set exp type for experience calculations
  Pokemon::setEXPtype("S");

//set catch rate for grass
  Pokemon::setCatch(CATCH);
}

void Growlithe::print(){
  cout << "GROWLITHE";
}

void Growlithe::setAttacks(){
//simplification of attacks, starts out with four attacks
 setMove( "bite", "normal", 60,25, 100);
 setMove("ember", "fire", 40, 25,100);
 setMove("flamethrower", "fire", 95,15 ,70);
 setMove("take down","normal", 90, 20,85);//learn by tm
}

