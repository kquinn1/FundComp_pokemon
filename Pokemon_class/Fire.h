//Katie Quinn
//represents the Fire type
//will set the type to fire
#ifndef FIRE_H
#define FIRE_H
#include <string>
#include "Pokemon.h"
using namespace std;

class Fire: public Pokemon{
  public:
	Fire(string, int); // constructor

};

Fire::Fire(string myName, int myLevel): Pokemon(myName, myLevel){
  Pokemon::setType("fire");
}

#endif
