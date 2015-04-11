//Katie Quinn
//Shellder.cpp
#include "Shellder.h"
#include <iostream>
using namespace std;

const int S_BASE_HP = 30; //base stats for shellder
const int S_BASE_A = 65;
const int S_BASE_D = 100;
const int S_BASE_SPEED= 40;
const int S_BASE_SPEC = 45;

Shellder::Shellder(int level) : Water(level){
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
}

void Shellder::print(){
  cout << "SHELLDER";
}

void Shellder::setAttacks(){
//simplification of attacks, starts out with four attacks
  attacks.push_back(new Attack( "tackle", "normal", 35, 35, 95) );
  attacks.push_back(new Attack("clamp", "water", 35, 10, 75);
  attacks.push_back(new Attack("ice beam", "water", 95, 10, 100) );//type=ice
  attacks.push_back(new Attack("take down","normal", 90, 20, 85) );//learn by tm
}

Attack* Shellder::getAttack(int i){
  return attacks[i];
}
