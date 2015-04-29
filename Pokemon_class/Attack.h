// Katie Quinn
// CSE 20212
// Attack.h
// Attack class for pokemon
#ifndef ATTACK_H
#define ATTACK_H
#include <string>
using namespace std; //for string

class Attack{
  public:
	Attack(string&, string&, int&, int&, int&); //constructor
	string getType();//get functions for data hiding
	int getPower();// return the attack power
	int getPP();// return the number of times an attack can be used
	int getAcc();// return the accuracy of an attack
	string getName();// return the name of attack
	void resetPP(); // set PP to the max PP
	void updatePP(); //decrease pp if move used
  private:
	string name;
	string type;// electic, fire, etc. Used for type bonus
	int power;// power of the attack
	int pp; //how many times the move can be used
	int maxPP; // in order to reset after healing
	int accuracy;// accuracy of the attack

};

#endif
