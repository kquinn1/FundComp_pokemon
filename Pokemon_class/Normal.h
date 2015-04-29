//Katie Quinn
//Normal.h
//Represents the normal type class
//class will set type to Normal 
#ifndef NORMAL_H
#define NORMAL_H
#include <string>
#include "Pokemon.h"
using namespace std;

class Normal: public Pokemon{
  public:
	Normal(int);
	virtual void print() = 0; //cannot instantiate this class
};

#endif
