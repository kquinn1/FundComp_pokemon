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
	Fire(int); // constructor
	virtual void print() = 0; //cannot instantiate this class

};

Fire::Fire(int myLevel): Pokemon(myLevel){
  Pokemon::setType("fire");
}

#endif
