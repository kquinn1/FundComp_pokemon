//Katie Quinn
//Pokemon species class
//Pikachu.cpp implementation file
#include "Pikachu.h"
#include <iostream>
using namespace std;

const int PIK_BASE_A = 55;
const int PIK_BASE_D = 30;
const int PIK_BASE_SPEED= 90;
const int PIK_BASE_SPEC = 50;
const int PIK_BASE_HP = 35; //base stats for pikachu

Pikachu::Pikachu(int level) : Electric(level){
  Pokemon::setBaseA(PIK_BASE_A);
  Pokemon::setBaseD(PIK_BASE_D);
  Pokemon::setBaseSpec(PIK_BASE_SPEC);
  Pokemon::setBaseSpeed(PIK_BASE_SPEED);
  Pokemon::setBaseHP(PIK_BASE_HP);
  
//since all stats have been declared, set dependant stats
  Pokemon::setHP(); //set HP initially
  Pokemon::setAttack();
  Pokemon::setDef();
  Pokemon::set_spec_A();
  Pokemon::set_spec_D();
  Pokemon::setSpeed();

  setAttacks(); //set attacks for pikachu, does not allow the user to decide
}

void Pikachu::print(){
	cout << "PIKACHU";
}

void Pikachu::setAttacks(){
//simplification of attacks, starts out with four attacks
 attacks.push_back(new Attack( "quick attack", "normal", 40,30, 100) );
 attacks.push_back(new Attack("thunderbolt", "electric", 90, 15,100) );//learn by tm
 attacks.push_back(new Attack("thundershock", "electric", 40,30 ,100) );
 attacks.push_back(new Attack("mega punch","normal", 80, 20,85) );//learn by tm
}

Attack* Pikachu::getAttack(int i){
  return attacks[i];
}

