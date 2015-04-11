//Katie Quinn
//Horsea.cpp
#include "Horsea.h"
#include <iostream>
using namespace std;

const int H_BASE_HP = 30; //base stats for horsea
const int H_BASE_A = 40;
const int H_BASE_D = 70;
const int H_BASE_SPEED= 60;
const int H_BASE_SPEC = 70;

Horsea::Horsea(int level) : Water(level){
  Pokemon::setBaseA(H_BASE_A);
  Pokemon::setBaseD(H_BASE_D);
  Pokemon::setBaseSpec(H_BASE_SPEC);
  Pokemon::setBaseSpeed(H_BASE_SPEED);
  Pokemon::setBaseHP(H_BASE_HP);
  
//since all stats have been declared, set dependant stats
  Pokemon::setHP(); //set HP initially
  Pokemon::setAttack();
  Pokemon::setDef();
  Pokemon::set_spec_A();
  Pokemon::set_spec_D();
  Pokemon::setSpeed();
}
void Horsea::print(){
  cout << "HORSEA" ; 
}

void Horsea::setAttacks(){
//simplification of attacks, starts out with four attacks
  attacks.push_back(new Attack( "bubble", "water", 20,30, 100) );
  attacks.push_back(new Attack("water gun", "water", 40, 25,100) );
  attacks.push_back(new Attack("hydro pump", "water", 120,5 ,80) );
  attacks.push_back(new Attack("take down","normal", 90, 20,85) );//learn by tm
}

Attack* Horsea::getAttack(int i){
  return attacks[i];
}
