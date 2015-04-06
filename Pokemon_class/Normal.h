//Katie Quinn
//Represents the normal type class
//class will set type to Normal 
#ifndef NORMAL_H
#define NORMAL_H
#include <string>
#include "Pokemon.h"
using namespace std;

class Normal: public Pokemon{
  public:
	Normal(string, int);
};

Normal::Normal(string myName, int myLevel) : Pokemon(myName, myLevel){
  Pokemon::setType("normal");
}

#endif
