//Katie Quinn
//Fight implementation file
#include "Fight.h"
#include <stdio.h> //NULL
#include <stdlib.h> //srand, rand
#include <time.h> // time
//#include <iostream>
Fight::Fight(Player* m_player, Enemy* m_enemy, Pokemon* m_poke, int isWild){
  myPlayer= m_player;
  //if statement
  if(isWild==1){// a wild pokemon battle
   myWild = m_poke;  
   wildBattle();
  }else{ // an enemy pokemon battle
   myEnemy = m_enemy;
   battle();
  }
}

//should there be a deconstructor?
//Fight::~Fight(){ }}

void Fight::battle(){
//enemy and player class battle


}

void Fight::wildBattle(){
//the player and a wild pokemon battle

}

//calculate the damage a pokemon does
int Fight::Damage(int baseSpeed,int a_level, int a_attack, int d_defense, int attack_power, string attack_type, string a_type, string d_type, int acc_attack){
  srand( time(NULL) );//initialize random seed
  int ifAttack;//determine if there is an attack
  ifAttack = rand()%100;
  if(ifAttack>acc_attack){//account for probability there is an attack, based on attack accuracy
   cout << "Attack missed!" << endl;
   return 0;
  }
  int STAB;
  float type;
  float randomInt;
  float critNum;
  float Modifier;
  //Determine if there is a critical hit
  float crit;
  crit = ((double)baseSpeed/512) * 100;
  critNum = rand()%100; //generate a number 0 and 100
  if(crit>=critNum) {crit = 2; cout <<"Critical hit" <<endl; } //it is a critical hit
  else crit = 1;
  int damage;
//determine if STAB bonus applies
  if(attack_type == a_type) STAB = 1.5;
  else STAB = 1; //the pokemon and it's attack are different
//adjust the type variable based on the attack type and the type of defensive pokemon
  type = typeBonus(attack_type, d_type);
//for the damage formula
  randomInt=rand()%15 + 86; //random number between 85 and 100;
  randomInt/=100;
  Modifier = STAB * type * crit * randomInt;
 //  cout << "The random integer used was: " << randomInt << endl; //for testing
  damage = (((2*(double)a_level+10)/250) * ((double)a_attack/(double)d_defense) * attack_power + 2 ) * Modifier;

  return damage;
}

float Fight::typeCalc(string attack_type,string d_type){
//calculate the type modification variable for the damage calculation
//float typeBonus(string attack_type,string  d_type){
  float type;
  if(attack_type == "normal") type = 1;
  else if(d_type == "normal") type = 1;
  else if (attack_type == d_type) type = 0.5;
  else if(attack_type == "fire"){
     if(d_type == "water") type = 0.5;
     else if(d_type == "grass") type = 2;
     else type = 1;
     }
  else if(attack_type == "water"){
     if(d_type == "fire") type = 2;
     else if(d_type == "grass") type = 0.5;
     else type = 1;                                                                
  }
  else if(attack_type == "grass"){
     if(d_type == "fire") type = 0.5;
     else if(d_type == "water") type = 2;
     else type = 1;
  }
  else if(attack_type == "electric"){
     if(d_type == "grass") type = 0.5; 
     else if(d_type == "water") type = 2;
     else type = 1;
  } 
  return type;
}
