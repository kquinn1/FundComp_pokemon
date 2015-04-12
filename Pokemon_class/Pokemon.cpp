// Katie Quinn55
// Implementation for Pokemon Class

#include "Pokemon.h"
#include <iostream>
#include <stdlib.h> // srand, rand
#include <time.h>
#include <string>
#include <math.h> // sqrt
using namespace std;

// updated constructor
Pokemon::Pokemon(int myLevel){
  level = myLevel;
  
  //call to intialize EVs to 0
  initEVs();

  //set IVs
  setIVs();

  //set other dependent stats in species and type classes
}

string Pokemon::getType(){
  return type;
}

void Pokemon::setType(string myType){
  type = myType;
}

void Pokemon::setBaseA(int a){
  base_A = a;
}

void Pokemon::setBaseD(int d){
  base_D = d;
}


void Pokemon::setBaseSpec(int spec){
  base_Spec = spec;
}

void Pokemon::setBaseSpeed(int s){
  base_Speed = s;
}

void Pokemon::setBaseHP(int h){
  base_HP = h;
}

void Pokemon::initEVs(){

// EVs start at 0
  EV_A = 0;
  EV_D = 0;
  EV_Spec = 0;
  EV_Speed = 0;
  EV_HP = 0;

}
void Pokemon::setIVs(){
// IVs are a random number between 0 and 15 except IV_HP
// initalize random seed
  srand( time(NULL) );

  IV_A = rand() % 16; // generate rand between 0 and 15
  IV_D = rand() % 16;
  IV_Spec = rand() % 16;
  IV_Speed = rand() % 16;

//set IV_HP
  setIV_HP();
}
void Pokemon::updateEV_A(int update){
//update experience
//Check to see theres a formula
  EV_A += update;
}

void Pokemon::updateEV_D(int update){
  EV_D += update;
}

void Pokemon::updateEV_Spec(int update){
  EV_Spec += update;
}

void Pokemon::updateEV_Speed(int update){
  EV_Speed += update;
}

void Pokemon::updateEV_HP(int update){
  EV_HP += update;
}
void Pokemon::setIV_HP(){
//set the IV_HP using the other IV values
// IV_HP takes the last binary digit from IV Attack, Defense, Speed, and 
// Special. Arranges it in that order
// need a function to convert decimal IVs to binary
// take last digit, set to IV_HP
// EDIT FUNCTION
  IV_HP = rand() % 16; // set as a random number for now
}
void Pokemon::setAttack(){
//determines the attack stat of a pokemon
  attack =( ((IV_A + base_A + ( sqrt(EV_A) / 8 ) )* level )/50 ) + 5;
}

void Pokemon::setDef(){
//determines the defense stat of a pokemon
  defense =( ((IV_D + base_D + ( sqrt(EV_D) / 8 )) * level )/50 ) + 5;
}


void Pokemon::set_spec_A(){
//determines the special attack of a pokemon
specAttack = ( ((IV_Spec + base_Spec + ( sqrt(EV_Spec) / 8 )) * level )/50 ) + 5;
}


void Pokemon::set_spec_D(){
//determines the special defense of a pokemon
specDefense =( ((IV_Spec + base_Spec + ( sqrt(EV_Spec) / 8 ))* level )/50 ) + 5;
}


void Pokemon::setSpeed(){
//determines the speed of a pokemon
  speed =( ((IV_Speed + base_Speed + ( sqrt(EV_Speed) / 8 )) * level )/50 ) + 5;
}


void Pokemon::setHP(){
//determines the HP initially of a pokemon 
//determines the maximum health effectively
  HP  = ( ((IV_HP + base_HP + ( sqrt(EV_HP) / 8 ) + 50 )* level )/50 ) + 10;
  maxHP = HP; // to be used for healing
//need a function to restore hp
}

void Pokemon::restoreHP(){
  HP = maxHP; //function restores pokemon to full health
}

int Pokemon::GetAttack(){
  return attack;
}

int Pokemon::getDefense(){
  return defense;
}

int Pokemon::getSpecA(){
  return specAttack;
}

int Pokemon::getSpecD(){
  return specDefense;
}

int Pokemon::getSpeed(){
  return speed;
}

int Pokemon::getLevel(){
  return level;
}

int Pokemon::getHP(){
  return HP;
}

int Pokemon::updateHP(int damage){
//should this be changed?
  HP-=damage;
  if(HP<0){
     cout << "Pokemon has fainted!"; 
     return 1;
  }
  else return 0;
}

void Pokemon::updateLevel(int update){
  level+=update;
  cout << "New level: " << level << endl;
// set the other dependant stats 
  setAttack();
  setDef();
  set_spec_A();
  set_spec_D();
  setSpeed();
}

Attack* Pokemon::getAttack(int i){
  return attacks[i];
}

void Pokemon:: setMove(string myName, string myType, int myPower, int myPP, int myAcc){
  attacks.push_back(new Attack(myName, myType, myPower, myPP, myAcc));
}
