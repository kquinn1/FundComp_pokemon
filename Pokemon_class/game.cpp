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
#include "Heal.h" //if you need to heal pokemon mid game
#include "Shop.h"
#include <iostream>
#include <string>
using namespace std;

const int FALSE = 0;
const int TRUE = 1;

int main(){
  int uChoice;
  bool quit = false;
  int hasFought = FALSE;
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

// display options to the user
// 	1. go to grass
// 	2. go to gym
// 	3. go to shop
// 	4. heal pokemon


  while(quit == false){
	
        cout << "Choose an option: " << endl << "1. Go to grass" << endl << "2. Go to the gym. " << endl << "3. Go to the shop" << endl << "4. Heal Pokemon" << endl << "5. Quit" << endl;
  cout << "Choice: " << endl;
        cin >> uChoice;
      	if(uChoice == 1)
		onGrass m1(myplay);
	else if (uChoice == 2) {
	   if(hasFought == FALSE){
		cout << "Welcome to the Cerlulean gym!" << endl;
 		Fight myfight(myplay , first );
  		Fight myfight2(myplay, second);
  		Fight myfight3(myplay, third);
		hasFought = TRUE;
	   }
	   else cout << "Already beat the gym leader! " << endl;
// if the player has gone to the gym but failed to beat the gym leader
// need an option for that
	}
	else if(uChoice ==3){
		Shop myShop(myplay);
	}
	else if(uChoice == 4){
		Heal healing(myplay);
	}
	else if(uChoice == 5){
		cout << "Quitting the pokemon simulator." << endl;
		cout << "Thank you for playing!!!" << endl;
		quit = true;
	}
	else{	
		cout << "Invalid choice!" << endl;
         }

  }  // need to initialize all objects before going into the case statement
	//else it won't work
	//
// need to change the pokemon the player can instantiate
// need to have pokemon level up after each round
// need to add items
// need to allow people to switch pokemon in between defeating

  return 0;
}
