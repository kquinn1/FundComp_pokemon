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
	Electric(string myName, int myLevel);
  private: // nothing is private?

};

Electric::Electric(string myName, int myLevel): Pokemon(myName, myLevel){
  Pokemon::setType("electric");
}

#endif
