//Katie Quinn
//Bulbasaur.cpp

#include "Bulbasaur.h"
#include <iostream>
using namespace std;

const int B_BASE_A = 49;
const int B_BASE_D = 49;
const int B_BASE_SPEED= 45;
const int B_BASE_SPEC = 65;
const int B_BASE_HP = 45; //base stats for bulbasaur

Bulbasaur::Bulbasaur(int level) : Grass(level){
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

  Pokemon::setName("BULBASAUR");
  setAttacks();
//set up experience type for leveling up
  Pokemon::setEXPtype("MS"); //will allow for accurate calculations

}

void Bulbasaur::print() {
// such that type and pokemon are virual need a function definition
// in the species class
  cout << "BULBASAUR";
}

void Bulbasaur::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove( "tackle", "normal", 35,35, 95);
  setMove("vine whip", "grass", 35, 10,100);
  setMove("razor leaf", "grass", 55, 25 , 95);
  setMove("solar beam","grass", 120, 10,100);
}

