//Katie Quinn
//Heal.cpp
//Simple script heals pokemon
#include "Heal.h"
#include <iostream>
using namespace std;

Heal::Heal(Player* myPlay){
   int numPoke;// the number of pokemon to heal

   toHeal = myPlay; // the player to heal
   
   cout << endl << "Healing pokemon" << endl; // display message to user

   numPoke = toHeal->getNumPoke();

   for(int i = 0; i < numPoke; i++){
      //heal pokemon
	toHeal->getPokemon(i)->restoreHP();
	for(int j = 0; j<4; j++){
	// reset the PP on the attacks
		toHeal->getPokemon(i)->getAttack(j)->resetPP();
	}
   }
  cout << "Pokemon have been healed!" << endl;
}
