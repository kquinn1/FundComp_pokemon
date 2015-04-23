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

  //initialize EXP to 0
  EXP = 0; 
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


void Pokemon::setSpecial(){
//determines the special attack/defense of a pokemon
special = ( ((IV_Spec + base_Spec + ( sqrt(EV_Spec) / 8 )) * level )/50 ) + 5;
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

int Pokemon::getSpecial(){
  return special;
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
  if(HP<0) HP = 0; //set HP to zero, can't be negative
  if(HP==0){
     return 1;
  }
  else return 0;
}

void Pokemon::updateLevel(int update){
//this will be called if enough EXP points
  level+=update;
  cout << "New level: " << level << endl;
// set the other dependant stats 
  setAttack();
  setDef();
  setSpecial();
  setSpeed();
}

Attack* Pokemon::getAttack(int i){
  return attacks[i];
}

void Pokemon:: setMove(string myName, string myType, int myPower, int myPP, int myAcc){
  attacks.push_back(new Attack(myName, myType, myPower, myPP, myAcc));
}

void Pokemon::calcEXP(int enemy_level){
//will calculate the experience to award given a specific pokemon type
  int exp2add; 
//should I use a switch statement here?
  if(EXPtype=="F"){//currently have no fast pokemon but implemented for future
//calculate experience for fast pokemon
     exp2add = ( 4 * pow(enemy_level,3) ) / 5;
  }else if(EXPtype=="MF"){
//calculate experience for medium fast pokemon
     exp2add = pow(enemy_level,3);
  }else if(EXPtype=="MS"){
//calculate experience for medium slow pokemon
     exp2add = ((float)(1.2)* pow(enemy_level, 3) ) - (15 * pow(enemy_level,2)) +(100 * enemy_level) - 140;
	//check this one!
  }else if(EXPtype=="S"){
//want to make sure that the last case is right
     exp2add = ( 5 * pow(enemy_level,3) ) / 4;
  }
//display message
  cout << name << " has gained " << exp2add << " EXP!" << endl;
// add experience to the pokemon
  EXP+=exp2add;

  cout << "Current experience: " << EXP << endl;

  if( ifLevelUp() ) levelUp();
  //esle do nothing
}

int Pokemon::ifLevelUp(){
  int stat;
// I calculated regression equations based on EXP table found online
//regression equations used to determine EXP needed to level up
  if(EXPtype == "F"){
	stat =(0.614)*(pow(level+1,0.3942));
  }else if(EXPtype == "MF"){
  	stat = (0.5546)*(pow(level+1, 0.3958));
  }else if(EXPtype == "MS"){
	stat = (0.4899)*(pow(level+1,0.4305));
  }else if(EXPtype == "S"){
	stat = (0.5093)*(pow(level+1,0.3954));
  }
  if( EXP >= stat ) return 1;
  else return 0;
}

void Pokemon::levelUp(){
  int currentHP;
  int oldMaxHP;

  level++; //increment the level
  cout << "Pokemon has reached new level: " << level << endl;
  setAttack();
  setDef();
  setSpecial();
  setSpeed();
//when you set the HP make sure that the HP is incremented by appr. amount
  currentHP = HP;
  oldMaxHP = maxHP;
  setHP(); //re calculate the base statistics
  HP = currentHP + (maxHP - oldMaxHP); 
// HP is incremented by the change in maxHP 
}

void Pokemon::setCatch(int catchR){
  catchRate = catchR;
}

int Pokemon::getCatch(){
  return catchRate;
}

