//Katie Quinn
//Represents the electric type
//sets the type to electic
#ifndef ELECTRIC_H
#define ELECTRIC_H
#include <string>
#include "Pokemon.h"
using namespace std;

class Electric: public Pokemon{
  public:
	Electric(int myLevel);
	virtual void print() = 0;
};

Electric::Electric(int myLevel): Pokemon(myLevel){
  Pokemon::setType("electric");
}

#endif
