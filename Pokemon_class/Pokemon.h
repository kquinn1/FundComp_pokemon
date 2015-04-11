//Katie Quinn
//CSE 20212 - For final project
//Base class for pokemon
//
// to do: add attacks
#ifndef POKEMON_H
#define POKEMON_H
#include <string>
using namespace std; //for string
//#include "Attack.h"
class Pokemon{
  public: 
	Pokemon(int level); //base variables will be set in other classes
	void updateEV_A(int);
	void updateEV_D(int);
	void updateEV_Speed(int);
	void updateEV_Spec(int);
	void updateEV_HP(int);
 	void initEVs(); //set EVs to 0
	void setIVs(); //set IVs
	void setIV_HP();
	void setAttack();
	void setDef();
	void set_spec_A();
	void set_spec_D();
	void setSpeed();
        void setHP(); // HP initially
	int GetAttack();	
	int getDefense();
	int getSpecA();
	int getSpecD();
	int getSpeed();
	int getHP();
	int updateHP(int);//return a 0 if well, 1 if fainted
	int getLevel();
// should be implemented in other classes but private data?
	string getType();
	void updateLevel(int);
	void setType(string);
	void setBaseA(int);
 	void setBaseD(int);
 	void setBaseSpec(int);
 	void setBaseSpeed(int);
 	void setBaseHP(int);
	virtual void print()= 0;
	void restoreHP(); //restore HP to maxHP
	
  private:
	string type;
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
	int maxHP; //max health, or the initial HP
};

#endif
