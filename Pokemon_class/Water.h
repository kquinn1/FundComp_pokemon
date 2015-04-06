//Katie Quinn
//represents the water type of pokemon
//will set type to water
#ifndef WATER_H
#define WATER_H
#include <string>
#include "Pokemon.h"
using namespace std;

class Water: public Pokemon{
  public:
	Water(string, int);
};

Water::Water(string myName, int myLevel): Pokemon(myName, myLevel){
  Pokemon::setType("water");
}

#endif
