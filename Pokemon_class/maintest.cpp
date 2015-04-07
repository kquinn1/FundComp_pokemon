// Katie Quinn
// CSE 20212
//
// test to make sure pokemon stats are working correctly

#include "Pokemon.h"
#include "Electric.h"
#include "Pikachu.h"
#include "Water.h"
#include "Squirtle.h"
#include "Fire.h"
#include "Charmander.h"
#include "Grass.h"
#include "Bulbasaur.h"
#include <iostream>
using namespace std;

int main(){
  Pikachu poke1(10);
  
  cout<< "The " ;
  poke1.print() ;
  cout << " has the following stats..." <<endl;
  cout << "type: " << poke1.getType() << endl;
  
  cout<< "Attack: " << poke1.getAttack() << endl;
  cout<< "Defense: " << poke1.getDefense() << endl;
  cout<< "Special Attack: " << poke1.getSpecA() << endl;
  cout<< "Special Defense: " << poke1.getSpecD() << endl;
  cout<< "Level: " << poke1.getLevel() << endl;
  cout<< "Speed: " << poke1.getSpeed() << endl;
  cout<< "HP: " << poke1.getHP() << endl << endl << endl;


  Charmander poke(10);
  
  cout<< "The ";
  poke.print();
  cout << " has the following stats..." <<endl;
  cout << "type: " << poke.getType() << endl;
  
  cout<< "Attack: " << poke.getAttack() << endl;
  cout<< "Defense: " << poke.getDefense() << endl;
  cout<< "Special Attack: " << poke.getSpecA() << endl;
  cout<< "Special Defense: " << poke.getSpecD() << endl;
  cout<< "Level: " << poke.getLevel() << endl;
  cout<< "Speed: " << poke.getSpeed() << endl;
  cout<< "HP: " << poke.getHP() << endl << endl << endl;

  Squirtle s(15);
  
  cout<< "The ";
  s.print() ;
  cout<< " has the following stats..." <<endl;
  cout << "type: " << s.getType() << endl;
  
  cout<< "Attack: " << s.getAttack() << endl;
  cout<< "Defense: " << s.getDefense() << endl;
  cout<< "Special Attack: " << s.getSpecA() << endl;
  cout<< "Special Defense: " << s.getSpecD() << endl;
  cout<< "Level: " << s.getLevel() << endl;
  cout<< "Speed: " << s.getSpeed() << endl;
  cout<< "HP: " << s.getHP() << endl << endl << endl;

  Bulbasaur  b(10);
  
  cout<< "The ";
  b.print();
  cout << " has the following stats..." <<endl;
  cout << "type: " << b.getType() << endl;
  cout<< "Attack: " << b.getAttack() << endl;
  cout<< "Defense: " << b.getDefense() << endl;
  cout<< "Special Attack: " << b.getSpecA() << endl;
  cout<< "Special Defense: " << b.getSpecD() << endl;
  cout<< "Level: " << b.getLevel() << endl;
  cout<< "Speed: " << b.getSpeed() << endl;
  cout<< "HP: " << b.getHP() << endl;

  return 0;
}
