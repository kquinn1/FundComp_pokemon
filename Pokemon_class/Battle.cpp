//Katie Quinn
//Battle.cpp
//top level class of inheritance hierarchy 
#include "Battle.h"
#include <iostream>
using namespace std;

// constructor sets the pointer to the player
Battle::Battle(Player* myplay){
  myPlayer = myplay;
}

void Battle::choosePoke(){
//this function allows the user to choose which pokemon to use
  int size;
  int uChoice;
  int valid = 0;
  while( valid == 0 ){
    cout << "Pick the pokemon you will use: " << endl;  
  //declare iterator
    size = myPlayer->getNumPoke();
// display the pokemon and there current HP
    for(int i=0; i<size; i++){
      cout << "Choice " << i << ": "<<myPlayer->getPokemon(i)->getName();
      cout <<"      Current HP: "<< myPlayer->getPokemon(i)->getHP() << endl;
    }  
    cout << "I choose..." ;
    cin >> uChoice;
//set the current Pokemon
    if(myPlayer->getPokemon(uChoice)->getHP()==0){
//can't use a fainted pokemon
      cout <<"This pokemon has fainted!" << endl;
    } else valid = 1;
  }
  myPlayer->setCurrentPokemon(myPlayer->getPokemon(uChoice));
  cout << "Go! " << myPlayer->getCurrentPokemon()->getName() << endl;
}

void Battle::battleMenu(){
// display the options to the user
  cout << "Choose an option: " << endl;
  cout << "1. Fight " << endl;
  cout << "2. Change Pokemon " << endl;
  cout << "3. Run " << endl;
  cout << "Your choice: " ;
}

int Battle::showAttacks(){
// show a pokemon's attacks to the user  
  int valid = 0; //in order to check for a valid attack
  int uChoice;
  while(valid == 0){
    cout << "Choose an attack...." << endl;
    for(int i = 0; i<4; i++){
        cout << i << ". ";
        cout << myPlayer->getCurrentPokemon()->getAttack(i)->getName() <<endl;
        cout << "Type: " ;
        cout << myPlayer->getCurrentPokemon()->getAttack(i)->getType() << endl;
        cout << "PP: " ;
        cout << myPlayer->getCurrentPokemon()->getAttack(i)->getPP() << endl;
    }
    cin >> uChoice;
    if(myPlayer->getCurrentPokemon()->getAttack(uChoice)->getPP() == 0 ){
      cout << "This attack is not valid! " <<endl;
    } else {valid = 1; }
  }
  return uChoice;
}

// this function is called when the damage formula function is called
// it is instantiated in each class as whether it is an enemy pokemon or
// the single wild pokemon changes the actions performed
float Battle::typeCalc(string attack_type,string d_type){
//calculate the type modification variable for the damage calculation
// this has to be "hard coded" in a sense

// depending on the type of the attack and the type of the defensive pokemon,
// a special multiplier is used
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

//used to check to see if more damage done than HP available
int Battle::checkDamage(int damage, int HP){
  if (damage > HP) return HP;
  else return damage;
}
