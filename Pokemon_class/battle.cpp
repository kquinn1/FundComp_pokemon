//Katie Quinn
//testing out a battle
#include "Pokemon.h"
#include "Pikachu.h"
#include "Electric.h"
#include "Attack.h"
#include <iostream>
#include <stdio.h> //NULL
#include <stdlib.h> //srand, rand
#include <time.h> // time
#include <string>
using namespace std;

float typeBonus(string attack_type,string  d_type){
//determine type modifier bonus
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

int Damage(int baseSpeed,int a_level, int a_attack, int d_defense, int attack_power, string attack_type, string a_type, string d_type, int acc_attack){
  srand( time(NULL) );//initialize random seed

  int ifAttack;

  ifAttack = rand()%100;

  if(ifAttack>acc_attack) return 0; //account for accuracy
  
  int STAB;
  float type;
  float randomInt;
  float critNum;
  float Modifier;

  //account for critical hit
  float crit;
  crit = (baseSpeed/512) * 100;
  critNum = rand()%100; //generate a number 0 and 100
  
  if(crit>=critNum) crit = 2; //it is a critical hit
  else crit = 1;

  int damage;
//determine if STAB bonus applies
  if(attack_type == a_type) STAB = 1.5;
  else STAB = 1; //the pokemon and it's attack are different
   
  type = typeBonus(attack_type, d_type);
//adjust type for formula used
  type *= 10;
  randomInt = 1;
 // randomInt=rand()%.15 + 0.85; //random number between 217 and 255

  Modifier = STAB * type * crit * randomInt;

  cout << "The random integer used was: " << randomInt << endl; //for testing
  
  damage = ( ( (2*a_level+10)/250 ) * (a_attack/d_defense) * attack_power + 2 ) * Modifier;

  cout << " The damage was : " << damage << endl; //for testing

  return damage;
}
int main(){
  Pikachu one(15);
  Pikachu two(15);
 
  int turn=0;
  int uChoice;
  int damageD;
  int result;

  if(one.getSpeed()<two.getSpeed()) turn++;//player 2 starts first
  //else player 1 starts first
  while(one.getHP()>0 && two.getHP()>0){
    if((turn%2 + 1) %2){//Pikachu's turn
	cout << " It is Pikachu 1's turn. " << endl;
	cout << "choose an attack to use." << endl;
	for(int i= 0; i<4; i++){
	    cout << "Choice: " << i;
	    cout << " " << one.getAttack(i)->getName() << endl;
	}
	cin >> uChoice;
//need to account for pp decreasing, cannot use if PP < 0

	damageD = Damage(one.getSpeed(),one.getLevel(), one.GetAttack(),two.getDefense(), one.getAttack(uChoice)->getPower(),one.getAttack(uChoice)->getType(),one.getType(),two.getType(),one.getAttack(uChoice)->getAcc());

	cout << "Damage done: " << damageD << endl;

	result=two.updateHP(damageD);
	if(result==1) break; //if pokemon fainted
	cout << "Current opponenent HP: " << two.getHP() << endl;

//update the amount of times you use an attack
	one.getAttack(uChoice)->updatePP(); //decrease PP by 1

     }
    else{//second Pikachu's turn
	cout << "Second pikachu turn. Implemented later" << endl;
    // update HP returns an int, use this to break out of the while loop
    // don't need to flip the turn logic this way
    }
    turn++; //increment the turn in order to switch turns
  }
// a pokemon has fainted
  if((turn%2 + 1) %2 ) {// due to increased turn
	cout << "Pikachu 1 has won!" <<endl;
  }
  else{ cout << "Pikachu 2 has won!" << endl; }
  
  return 0;
}
