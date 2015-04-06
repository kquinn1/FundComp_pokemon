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
	void setType();
	virtual void setBaseA() = 0;
        virtual void setBaseD() = 0;
        virtual void setBaseSpec() = 0;
        virtual void setBaseSpeed() = 0;
        virtual void setBaseHP() = 0; //implementation needs to be in pokemon species class
  private: // nothing is private?

};

Electric::Electric(string myName, int myLevel): Pokemon(myName, myLevel){
  setType();
}

void Electric::setType(){
  type="electric";
}

#endif
