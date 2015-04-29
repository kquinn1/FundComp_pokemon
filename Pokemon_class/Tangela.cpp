//Katie Quinn
//Tangela.cpp

#include "Tangela.h"
#include <iostream>
using namespace std;

const int B_BASE_HP = 65; //base stats for tangela
const int B_BASE_A = 55;
const int B_BASE_D = 115;
const int B_BASE_SPEED= 60;
const int B_BASE_SPEC = 100;
const int CATCH = 45;

Tangela::Tangela(int level) : Grass(level){
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

  Pokemon::setName("TANGELA");
  setAttacks();
//set up experience type for leveling up
  Pokemon::setEXPtype("MF"); //will allow for accurate calculations

//set catch rate 
  Pokemon::setCatch(CATCH);

}

void Tangela::print() {
// such that type and pokemon are virual need a function definition
// in the species class
  cout << "TANGELA";
}

void Tangela::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove( "bind", "normal", 15,20, 75);
  setMove("vine whip", "grass", 35, 10,100);
  setMove("constrict", "normal", 10, 35 ,100);
  setMove("slam","normal", 80, 20,75);
}

