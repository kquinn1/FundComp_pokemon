//Katie Quinn
//Pokemon species class
//Pikachu.cpp implementation file
#include "Pikachu.h"
#include <iostream>
using namespace std;

const int PIK_BASE_A = 55;
const int PIK_BASE_D = 30;
const int PIK_BASE_SPEED = 90;
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
  Pokemon::setSpecial();
  Pokemon::setSpeed();

  Pokemon::setName("PIKACHU");
  setAttacks(); //set attacks for pikachu, does not allow the user to decide

  Pokemon::setEXPtype("MF");
}

void Pikachu::print(){
	cout << "PIKACHU";
}

void Pikachu::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove("quick attack", "normal", 40,30, 100);
  setMove("thunderbolt", "electric", 90, 15,100);//learn by tm
  setMove("thundershock", "electric", 40,30 ,100);
  setMove("mega punch","normal", 80, 20,85);//learn by tm
}

