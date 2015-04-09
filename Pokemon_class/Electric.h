//Katie Quinn
//Electric.h
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
	virtual void print() = 0;//abstract class
};

#endif
