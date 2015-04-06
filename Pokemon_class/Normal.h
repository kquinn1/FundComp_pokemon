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
	void setType();
	virtual void setBaseA() = 0;
        virtual void setBaseD() = 0;
        virtual void setBaseSpec() = 0;
        virtual void setBaseSpeed() = 0;
        virtual void setBaseHP() = 0; //implementation needs to be in pokemon species class
  private: // nothing is private?

};

void Normal::setType(){
  type="normal";
}

#endif
