//Katie Quinn
//Heal.h
//
//This class heals a player's pokemon and resets their attacks
#include "Player.h"

class Heal{
  public:
	Heal(Player*);
	//~Heal(); //constructor and deconstructor
//is there a need for a deconstructor
  private:
        Player* toHeal;
};

