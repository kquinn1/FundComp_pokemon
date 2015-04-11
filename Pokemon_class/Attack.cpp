//Katie Quinn
//CSE 20212
// implementation for pokemon attack class

#include "Attack.h"
#include <iostream>
#include <string>
using namespace std;

Attack::Attack(string myName, string myType, int myPower, int myPP, int myAcc){
// constructor for Attack
  name = myName;
  type = myType;
  power = myPower;
  pp = myPP;
  maxPP = pp; // set the max var to be used for healing
  accuracy = myAcc;
}
string Attack::getName(){ return name; }
string Attack::getType(){ return type; }

int Attack::getPower(){ return power; }

int Attack::getPP(){ return pp; }

int Attack::getAcc(){ return accuracy;}

void Attack::updatePP(){
// this function will be called if the move is used
  pp-=1; //decrease the number of times the moves can be used by 1
}
