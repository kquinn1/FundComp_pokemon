// Katie Quinn
// CSE 20212
//
// test to make sure pokemon stats are working correctly

#include "Pokemon.h"
#include "Electric.h"
#include "Pikachu.h"
#include <iostream>
using namespace std;

int main(){
  Pikachu poke1("Pikachu",81);
  
  cout<< "The " << poke1.getName() << " has the following stats..." <<endl;
  cout<< "Attack: " << poke1.getAttack() << endl;
  cout<< "Defense: " << poke1.getDefense() << endl;
  cout<< "Special Attack: " << poke1.getSpecA() << endl;
  cout<< "Special Defense: " << poke1.getSpecD() << endl;
  cout<< "Level: " << poke1.getLevel() << endl;
  cout<< "Speed: " << poke1.getSpeed() << endl;
  cout<< "HP: " << poke1.getHP() << endl;

  return 0;
}
