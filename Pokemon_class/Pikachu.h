//Katie Quinn
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
// Pikachu class

#ifndef PIKACHU_H
#define PIKACHU_H
#include <string>
#include "Pokemon.h"
#include "Electric.h"
#include <iostream>
#include "Attack.h"
#include <vector> //create a vector of attacks
using namespace std;

const int PIK_BASE_A = 55;
const int PIK_BASE_D = 30;
const int PIK_BASE_SPEED= 90;
const int PIK_BASE_SPEC = 50;
const int PIK_BASE_HP = 35; //base stats for pikachu

class Pikachu : public Electric {
  public:
	Pikachu(int); //need to set up constructor to call Pokemon constructor
	void print();
//	void setAttackPower(int);
	void setAttacks();
	Attack* getAttack(int i);
// functions to handle attacks?
//should a private member contain the sprite?
  private:
	vector<Attack*> attacks;
/*	Attack a1;// should call non default constructors here
	Attack a2;
	Attack a3;
	Attack a4; */
};

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

#endif
