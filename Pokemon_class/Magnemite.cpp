//Katie Quinn
//Pokemon species class
//Magnemite.cpp implementation file
#include "Magnemite.h"
#include <iostream>
using namespace std;

const int PIK_BASE_HP = 25; //base stats for magnemite
const int PIK_BASE_A = 35;
const int PIK_BASE_D = 70;
const int PIK_BASE_SPEED = 45;
const int PIK_BASE_SPEC = 95;
const int CATCH = 190;

Magnemite::Magnemite(int level) : Electric(level){
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

  Pokemon::setName("MAGNEMITE");
  setAttacks(); //set attacks for pikachu, does not allow the user to decide

  Pokemon::setEXPtype("MF");

//set catch rate
  Pokemon::setCatch(CATCH);
}

void Magnemite::print(){
	cout << "MAGNEMITE";
}

void Magnemite::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove("tackle", "normal", 35,35, 95);
  setMove("thunderbolt", "electric", 90, 15,100);//learn by tm
  setMove("thundershock", "electric", 40,30 ,100);
  setMove("swift","normal", 60, 20,100);
}

