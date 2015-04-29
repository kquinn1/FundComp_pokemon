//Katie Quinn
//CSE 20212
// implementation for pokemon attack class

#include "Attack.h"
#include <iostream>
#include <string>
using namespace std;

// Attack constructor
Attack::Attack(string& myName, string& myType, int& myPower, int& myPP, int& myAcc){
// constructor for Attack
  name = myName;
  type = myType; // electric, fire, etc. for type bonus
  power = myPower; // the power an attack has
  pp = myPP; // the amount of times an attack can be used
  maxPP = pp; // set the max var to be used for healing
  accuracy = myAcc; 
}

// get functions will be used in battle classes
string Attack::getName(){ return name; }
string Attack::getType(){ return type; }

int Attack::getPower(){ return power; }

int Attack::getPP(){ return pp; }

int Attack::getAcc(){ return accuracy;}

void Attack::updatePP(){
// this function will be called if the move is used
  pp-=1; //decrease the number of times the moves can be used by 1
}

void Attack::resetPP(){
//set PP to max PP
//this function is called when a pokemon is healed
  pp = maxPP; 
}
