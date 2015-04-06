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
	void setType();
	virtual void setBaseA() = 0;
        virtual void setBaseD() = 0;
        virtual void setBaseSpec() = 0;
        virtual void setBaseSpeed() = 0;
        virtual void setBaseHP() = 0; //implementation needs to be in pokemon species class
  private: // nothing is private?

};

void Fire::setType(){
  type="fire";
}

#endif
