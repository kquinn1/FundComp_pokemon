//Katie Quinn
//Starmie.cpp
#include "Starmie.h"
#include <iostream>
using namespace std;

const int S_BASE_HP = 60; //base stats for starmie
const int S_BASE_A = 75;
const int S_BASE_D = 85;
const int S_BASE_SPEED= 115;
const int S_BASE_SPEC = 100;

Starmie::Starmie(int level) : Water(level){
  Pokemon::setBaseA(S_BASE_A);
  Pokemon::setBaseD(S_BASE_D);
  Pokemon::setBaseSpec(S_BASE_SPEC);
  Pokemon::setBaseSpeed(S_BASE_SPEED);
  Pokemon::setBaseHP(S_BASE_HP);
  
//since all stats have been declared, set dependant stats
  Pokemon::setHP(); //set HP initially
  Pokemon::setAttack();
  Pokemon::setDef();
  Pokemon::set_spec_A();
  Pokemon::set_spec_D();
  Pokemon::setSpeed();

  setAttacks();
}

void Starmie::print(){
  cout << "STARMIE";
}

void Starmie::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove( "tackle", "normal", 35,35,95);
  setMove("water gun", "water", 40, 25,100);
  setMove("double edge", "normal", 100, 15,100);//by tm
  setMove("bubble beam","water", 65, 20,100);//learn by tm
}
