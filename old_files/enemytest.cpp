//Katie Quinn
//4-12-15
//Enemytest.cpp
//This short program tests the enemy class to see if it is working properly

#include "Enemy.h"
#include <iostream>
using namespace std;

int main() {
  Enemy en1(0,0,0,"Starmie",20,"Horsea",10 );

  cout << "Enemy 1 has the following pokemon: " ;
  en1.getPokemon(0)->print();
  en1.getPokemon(1)->print();
  cout << endl << endl;

  Enemy en2(0,0,0,"Psyduck",10,"",0);
  cout << "Enemy 2 has the following pokemon: ";
  en2.getPokemon(0)->print();
   
  return 0;
}
