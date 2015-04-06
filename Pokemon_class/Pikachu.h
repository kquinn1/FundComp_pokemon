//Katie Quinn
//Pokemon species class
//While the pokemon class and the type class are abstract, this class is concrete
#ifndef PIKACHU_H
#define PIKACHU_H
#include <string>
#include "Pokemon.h"
#include "Electric.h"

const int PIK_BASE_A = 55;
const int PIK_BASE_D = 30;
const int PIK_BASE_SPEED= 90;
const int PIK_BASE_SPEC = 50;
const int PIK_BASE_HP = 35; //base stats for pikachu

class Pikachu : public Electric {
  public:
	Pikachu(string, int); //need to set up constructor to call Pokemon constructor
 	void setBaseA();
        void setBaseD();
        void setBaseSpec();
        void setBaseSpeed();
        void setBaseHP(); //implementation in this class
//should a private member contain the sprite?

};

Pikachu::Pikachu(string myName, int level) : Electric(myName, level){
  setBaseA();
  setBaseD();
  setBaseSpec();
  setBaseSpeed();
  setBaseHP();
}

void Pikachu::setBaseA(){
  base_A = PIK_BASE_A;
}

void Pikachu::setBaseD(){
  base_D = PIK_BASE_D;
}

void Pikachu::setBaseSpec(){
  base_Spec = PIK_BASE_SPEC;
}

void Pikachu::setBaseSpeed(){
  base_Speed = PIK_BASE_SPEED;
}

void Pikachu::setBaseHP(){
  base_HP = PIK_BASE_HP;
}

#endif
