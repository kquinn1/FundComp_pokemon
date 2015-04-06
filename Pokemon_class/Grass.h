//Katie Quinn
//represents the grass class will set type to grass
#ifndef GRASS_H
#define GRASS_H
#include <string>
#include "Pokemon.h"
using namespace std;

class Grass: public Pokemon{
  public:
	Grass(string, int);
};

Grass::Grass(string myName, int myLevel): Pokemon(myName, myLevel){
  Pokemon::setType("grass");
}

#endif
