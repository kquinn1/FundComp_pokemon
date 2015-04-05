// Katie Quinn
// CSE 20212
// Attack class for pokemon
#ifndef ATTACK_H
#define ATTACK_H
#include <string>

class Attack{
  public:
	Attack(string, int, int, int); //constructor
	string getType();//get functions for data hiding
	int getPower();
	int getPP():
	int getAcc();
	void updatePP(); //decrease pp if move used
  private:
	string type;
	int power;
	int pp; //how many times the move can be used
	int accuracy;

};

#endif
