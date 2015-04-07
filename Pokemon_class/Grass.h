//Katie Quinn
//represents the grass class will set type to grass
#ifndef GRASS_H
#define GRASS_H
#include <string>
#include "Pokemon.h"
using namespace std;

class Grass: public Pokemon{
  public:
	Grass(int);
	virtual void print() = 0;
};

Grass::Grass(int myLevel): Pokemon(myLevel){
  Pokemon::setType("grass");
}

#endif
