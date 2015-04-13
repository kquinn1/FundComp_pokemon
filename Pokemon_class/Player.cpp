//Katie Quin
//Player implementation file
//
#include "Player.h"
#include "Pikachu.h"
#include "Charmander.h"
#include "Squirtle.h"
#include "Bulbasaur.h"
//will need to include all the pokemon classes

Player::Player(int myX, int myY){
  X = myX;
  Y = myY; //set the first position
 
  money = 0; //start out with 0 cash, earn money from trainer battles

 //initalzie the current pokemon
 setPokemon(); 
}

void Player::updateX(int i){
//update the X position
//function will be more complex
  X+=i;
}

void Player::updateY(int i){
//update the Y position
//function will be more complex
  Y+=i;
}

void Player::setPokemon(){
//start with 4 pokemon, add the ability to push_back more pokemon
//default pokemon a player starts with
//can change this later
//what level should the pokemon start out with?
  myPoke.push_back(new Pikachu(10) );
  myPoke.push_back(new Charmander(10) );
  myPoke.push_back(new Bulbasaur(10) );
  myPoke.push_back(new Squirtle(10) );

  numPoke = 4;
}

void Player::setCurrentPokemon(Pokemon* poke){
  inAction = poke;
//set the current pokemon, e.g. the one that is in battle
//is this necessary?
}

Pokemon* Player::getPokemon(int i){
  return myPoke[i];
}

Pokemon* Player::getCurrentPokemon(){
//return the pokemon that is currently in action e.g. battle 
  return inAction;
}

void Player::addPokemon(Pokemon* poke,  int level){
//this function may have to be more complex
  myPoke.push_back(poke);
}

void Player::deletePokemon(int i){
  myPoke.erase(myPoke.begin()+ i); //cannot do erase(i)?
}

int Player::isDefeated(){
//returns a 1 if defeated
//returns a 0 if not
  for(int i = 0; i<numPoke; i++){
      if(getPokemon(i)->getHP() > 0 ) return 0;
  }
  return 1; //all pokemon have HP of 0 or less, player is defeated
}
