#include "Heal.h"
#include <iostream>
using namespace std;

Heal::Heal(Player* myPlay){
   int numPoke;

   toHeal = myPlay;
   
   cout << endl << "Healing pokemon" << endl;

   numPoke = toHeal->getNumPoke();

   for(int i = 0; i < numPoke; i++){
      //heal pokemon
	toHeal->getPokemon(i)->restoreHP();
	for(int j = 0; j<4; j++){
		toHeal->getPokemon(i)->getAttack(j)->resetPP();
	}
   }
  cout << "Pokemon have been healed!" << endl;
}
