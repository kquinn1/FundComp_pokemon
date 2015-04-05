//Katie Quinn
//CSE 20212 - For final project
//Base class for pokemon
//
// to do: add attacks
// determine way to store base stats effectively
// the base stats determine the differences between pokemon
#ifndef POKEMON_H
#define POKEMON_H
#include <string>
using namespace std; //for string
//#include "Attack.h"
class Pokemon{
  public: 
	Pokemon(string, int, int, int, int, int, int);
// the constructor passes the name, level, and base stats
// after adding inheritance the constructor should be:
// 	Pokemon(string Name, int level) //base variables will be set in other classes
	void updateEVs(int);
 	void initEVs(); //set EVs to 0
	void setIVs(); //set IVs
	void setIV_HP();
	void setAttack();
	void setDef();
	void set_spec_A();
	void set_spec_D();
	void setSpeed();
        void setHP(); // HP initially
	string getName();
	int getAttack();	
	int getDefense();
	int getSpecA();
	int getSpecD();
	int getSpeed();
	int getHP();
	int updateHP(int);//return a 0 if well, 1 if fainted
	int getLevel();
	void updateLevel(int);
/*	virtual void setBaseA() = 0;
 *	virtual void setBaseD() = 0;
 *	virtual void setBaseSpec() = 0;
 *	virtual void setBaseSpeed() = 0;
 *	virtual void setBaseHP() = 0; //implementation needs to be in pokemon species class
 */
	
  private:
	string Name;
	int base_A;// base stats are particular for the type of pokemon
	int base_D;
	int base_Speed;
	int base_Spec;
	int base_HP;
	int IV_A;//individualistic values
	int IV_D;
	int IV_Spec;
	int IV_Speed;
	int IV_HP;
	int EV_A;// represent effort or experience
	int EV_D;
	int EV_Spec;
	int EV_Speed;
	int EV_HP;
	int attack;// following stats based on base, IVs, and EVs
	int defense;
	int specAttack;	
	int specDefense;
	int speed;
	int level;
	int HP; // health
/*
	Attack attack_one;// the attacks are stored as objects
	Attack attack_two;
	Attack attack_three;
	Attack attack_four;
*/
};

#endif
