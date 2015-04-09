//Katie Quinn
//Goldeen.cpp
#include "Goldeen.h"
#include <iostream>
using namespace std;

const int G_BASE_A = 67;
const int G_BASE_D = 60;
const int G_BASE_SPEED= 63;
const int G_BASE_SPEC = 50;
const int G_BASE_HP = 45; //base stats for bulbasaur

Goldeen::Goldeen(int level) : Water(level){
  Pokemon::setBaseA(G_BASE_A);
  Pokemon::setBaseD(G_BASE_D);
  Pokemon::setBaseSpec(G_BASE_SPEC);
  Pokemon::setBaseSpeed(G_BASE_SPEED);
  Pokemon::setBaseHP(G_BASE_HP);
  
//since all stats have been declared, set dependant stats
  Pokemon::setHP(); //set HP initially
  Pokemon::setAttack();
  Pokemon::setDef();
  Pokemon::set_spec_A();
  Pokemon::set_spec_D();
  Pokemon::setSpeed();
}

void Goldeen::print(){
  cout << "GOLDEEN";
}

