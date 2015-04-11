//Katie Quinn
//Goldeen.cpp
#include "Goldeen.h"
#include <iostream>
using namespace std;

const int G_BASE_A = 67;
const int G_BASE_D = 60;
const int G_BASE_SPEED= 63;
const int G_BASE_SPEC = 50;
const int G_BASE_HP = 45; //base stats for goldeen

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

  setAttacks();
}

void Goldeen::print(){
  cout << "GOLDEEN";
}

void Goldeen::setAttacks(){
//simplification of attacks, starts out with four attacks
  setMove( "horn attack", "normal", 65,25, 100);
  setMove("fury attack", "normal", 15, 20,85);//learn by tm
  setMove("waterfall", "water", 80,15 ,100);
  setMove("bubblebeam","water", 65, 20,100);//learn by tm
}
