//Katie Quinn
//Psyduck.cpp
#include "Psyduck.h"
#include <iostream>
using namespace std;

const int P_BASE_A = 52;
const int P_BASE_D = 48;
const int P_BASE_SPEED= 55;
const int P_BASE_SPEC = 50;
const int P_BASE_HP = 50; //base stats for psyduck

Psyduck::Psyduck(int level) : Water(level){
  Pokemon::setBaseA(P_BASE_A);
  Pokemon::setBaseD(P_BASE_D);
  Pokemon::setBaseSpec(P_BASE_SPEC);
  Pokemon::setBaseSpeed(P_BASE_SPEED);
  Pokemon::setBaseHP(P_BASE_HP);
  
//since all stats have been declared, set dependant stats
  Pokemon::setHP(); //set HP initially
  Pokemon::setAttack();
  Pokemon::setDef();
  Pokemon::set_spec_A();
  Pokemon::set_spec_D();
  Pokemon::setSpeed();
}
void Psyduck::print(){
  cout << "PSYDUCK" ; 
}

void Psyduck::setAttacks(){
//simplification of attacks, starts out with four attacks
  attacks.push_back(new Attack( "scratch", "normal", 40,35, 100) );
  attacks.push_back(new Attack("hydro pump", "water", 120, 5,80) );
  attacks.push_back(new Attack("fury swipes", "normal", 18,15,80) );
  attacks.push_back(new Attack("mega punch","normal", 80, 20,85) );//learn by tm
}

Attack* Psyduck::getAttack(int i){
  return attacks[i];
}