//Katie Quinn
//Gym.cpp
//
//This file will represent a text based version of the pokemon gym.
//The gym includes three trainers and is based off the Cerulean gym in
//Pokemon Yellow
//The gym will be implemented later in order to include graphics, etc.

#include "Fight.h"
#include "Enemy.h"
#include "onGrass.h"
#include "Player.h" //not sure if these two are needed
//#include "Heal.h" if you need to heal pokemon mid game
#include <iostream>
#include <string>
using namespace std;

int main(){
  Player Ash(0,0);
  Enemy swimmer("Swimmer",0,0,80,"Shellder",16,"Horsea",16); 
  //swimmer has two pokemon, cash prize of 80
  Enemy jrTrainer("Junior Trainer",0,0,380,"Goldeen",19,"",0); 
  //junior trainer has one pokemon, cash prize of 380
  Enemy misty("Misty",0,0,2079,"Starmie",21,"Staryu",18);
  //Misty (gym leader) has two pokemon, higher levels. Prize of 2079
//declare pointers to each
  Enemy *first;
  Enemy *second;
  Enemy *third;
  first = &swimmer; 
  second = &jrTrainer;
  third = &misty;
  Player *myplay;
  myplay = &Ash;


  onGrass m1(myplay); //testing
// need to change the pokemon the player can instantiate
// need to have pokemon level up after each round
// need to add items
// need to allow people to switch pokemon in between defeating
// eventually: fights implemented when the player intersects their line of sight  
  cout << "Welcome to the Cerlulean gym!" << endl;
  Fight myfight(myplay , first );
// if need to heal  Heal healing(myplay);
  Fight myfight2(myplay, second);
  Fight myfight3(myplay, third);

  cout << myplay->getUserName() << ", you win!" << endl;

  return 0;
}
