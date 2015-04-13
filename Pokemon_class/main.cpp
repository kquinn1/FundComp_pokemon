//Katie Quinn
//This file will represent a text based version of the pokemon gym.
//The gym will be implemented later in order to include graphics, etc.
#include "Fight.h"
#include "Enemy.h"
#include "Player.h" //not sure if these two are needed
#include <iostream>
#include <string>
using namespace std;

int main(){
  Player Ash(0,0);
  Enemy jrTrainer("Junior Trainer",0,0,0,"Goldeen",5,"",0); //first junior trainer has one pokemon
  Enemy swimmer("Swimmer",0,0,0,"Staryu",10,"Horsea",10); //second trainer: swimmer has 1 pokemon
  Enemy misty("Misty",0,0,0,"Starmie",4,"Staryu",10);
//should update the enemy class in order to have names
//Implement prize money if the player wins
//declare pointers to each
  Enemy *first;
  Enemy *second;
  Enemy *third;
  first = &jrTrainer; 
  second = &swimmer;
  third = &misty;
  Player *myplay;
  myplay = &Ash;
  
 // cout << endl << endl << "Junior trainer wants to battle! " << endl << endl;
  Fight myfight(myplay , first );
 // cout << endl << endl << "Swimmer wants to battle!" << endl << endl;
  Fight myfight2(myplay, second);
 // cout << endl << endl << "Gym leader Misty wants to battle!" << endl << endl;
  Fight myfight3(myplay, third);
//pray to god this works

  return 0;
}
