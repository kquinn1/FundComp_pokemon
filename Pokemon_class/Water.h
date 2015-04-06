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
	void setType();
	virtual void setBaseA() = 0;
        virtual void setBaseD() = 0;
        virtual void setBaseSpec() = 0;
        virtual void setBaseSpeed() = 0;
        virtual void setBaseHP() = 0; //implementation needs to be in pokemon species class
  private: // nothing is private?

};

void Fire::setType(){
  type="water";
}

#endif
