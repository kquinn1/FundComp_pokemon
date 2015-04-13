//Katie Quin
//Enemy implementation file
//
#include "Enemy.h"
#include "Bulbasaur.h"
#include "Charmander.h"
#include "Goldeen.h"
#include "Horsea.h"
#include "Pikachu.h"
#include "Psyduck.h"
#include "Shellder.h"
#include "Squirtle.h"
#include "Starmie.h"
#include "Staryu.h"
//will need to include all the pokemon classes

Enemy::Enemy(string myName, int myX, int myY, int prize, string poke1,int poke1Level, string poke2, int poke2Level){
  name = myName;
  X = myX;
  Y = myY; //set the first position
  prizeMoney = prize; //money that the enemy gives to player if defeated

  numPoke = 0; 
//initalzie the current pokemon using strings
 if (poke1 != "") setPokemon(poke1,poke1Level); 
 if (poke2 != "") setPokemon(poke2,poke2Level); 
}

void Enemy::setPokemon(string poke, int myLevel){
//start with 2 pokemon, the function is called twice in main
//add the ability to push_back more pokemon
//use if statements to decide what pokemon to instantiate
//very ugly function
  if(poke == "Bulbasaur"){
    myPoke.push_back(new Bulbasaur(myLevel) ); 
    numPoke++;
  }
  else if(poke == "Charmander"){ 
    myPoke.push_back(new Charmander(myLevel) ); 
    numPoke++;
  } 
  else if(poke == "Goldeen"){ 
    myPoke.push_back(new Goldeen(myLevel) ); 
    numPoke++;
  } 
  else if(poke == "Horsea"){ 
    myPoke.push_back(new Horsea(myLevel) ); 
    numPoke++;
  } 
  else if(poke == "Pikachu"){ 
    myPoke.push_back(new Pikachu(myLevel) ); 
    numPoke++;
  }
  else if(poke == "Psyduck"){ 
    myPoke.push_back(new Psyduck(myLevel) ); 
    numPoke++;
  } 
  else if(poke == "Shellder"){ 
    myPoke.push_back(new Shellder(myLevel) );
    numPoke++;
  } 
  else if(poke == "Squirtle"){ 
    myPoke.push_back(new Squirtle(myLevel) ); 
    numPoke++;
  } 
  else if(poke == "Starmie"){ 
    myPoke.push_back(new Starmie(myLevel) ); 
    numPoke++;
  } 
  else if(poke == "Staryu"){ 
    myPoke.push_back(new Staryu(myLevel) );
    numPoke++;
  } 
}

void Enemy::setCurrentPokemon(Pokemon* poke){
  inAction = poke;
//set the current pokemon, e.g. the one that is in battle
//is this necessary?
}

Pokemon* Enemy::getPokemon(int i){
  return myPoke[i];
}

Pokemon* Enemy::getCurrentPokemon(){
//return the pokemon that is currently in action e.g. battle 
  return inAction;
}

void Enemy::deletePokemon(){
// will use: erase a pokemon that is defeated?
  myPoke.pop_back(); 
  numPoke--;
}

int Enemy::isDefeated(){
//returns a 1 if defeated
//returns a 0 if not
//Ask/check what this is doing
/*  vector<Pokemon*>::const_iterator it;
  for(it=myPoke.begin(); it != myPoke.end(); ++it){
    if(*it->getHP > 0){return 0;};  
  }*/
  for(int i = 0; i<numPoke; i++){
      if(getPokemon(i)->getHP() > 0) return 0;
   }
  return 1; //all pokemon have HP of 0, the enemy is defeated
}

