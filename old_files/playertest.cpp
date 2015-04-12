//Katie quinn
//simple program to test the player class
#include "Player.h"
#include <iostream>
using namespace std;

int main(){
  Player myPlayer(0,0);
//instatiante a player
//
//this line will print out the pokemon included in the pokemon point vector
  myPlayer.getPokemon(0)->print(); 
  myPlayer.getPokemon(1)->print(); 
  myPlayer.getPokemon(2)->print(); 
  myPlayer.getPokemon(3)->print(); 
  return 0;
}

