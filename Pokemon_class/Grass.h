//Katie Quinn
//represents the grass class will set type to grass
#ifndef GRASS_H
#define GRASS_H
#include <string>
#include "Pokemon.h"
using namespace std;

class Grass: public Pokemon{
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
  type="grass";
}

#endif
