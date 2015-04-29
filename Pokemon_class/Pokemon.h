//Katie Quinn
//Pokemon.h
//CSE 20212 - For final project
//Base class for pokemon
//
#ifndef POKEMON_H
#define POKEMON_H
#include "Attack.h"
#include <vector>
#include <string>
using namespace std; //for string
class Pokemon{
  public: 
	Pokemon(int level); //base variables will be set in other classes
	void updateEV_A(int); // update EVs or experience stats
	void updateEV_D(int);
	void updateEV_Speed(int);
	void updateEV_Spec(int);
	void updateEV_HP(int);
 	void initEVs(); //set EVs to 0
	void setIVs(); //set IVs, random number
	void setIV_HP(); 
	void setAttack();// Attack calculation
	void setDef(); // Defense calculation
	void setSpecial();// Special calculation
	void setSpeed();// Speed calculation
        void setHP(); // HP calculation
	void setName(string s){ name = s; } ; //set the name of pokemon
	void setEXPtype(string e){ EXPtype = e; } ; 
// sets the EXP type which determines how a pokemon lvels up
	int getEXP(){ return EXP; };
	void calcEXP(int); //calculates and sets EXP based on EXP type
	string getName(){return name;};
	int ifLevelUp(); //determine if level up
	void levelUp(); //level up
	int getMax(){ return maxHP; }; //returns the maxHP
	int GetAttack(); //return Attack stat
	int getDefense();//return Defesne stat
	int getSpecial();//return special stat 
	int getSpeed();//return speed stat
	int getHP();// return the current HP
	int updateHP(int);//return a 0 if well, 1 if fainted
	int getLevel();//return the Level of pokemon
	string getType();//the type i.e. fire, electic, etc
	void updateLevel(int);// update the level by an amount
	void setType(string);//set the type electic, fire, etc.
// this is initialized in the derived classes
	void setBaseA(int);//set the base attack for pokemon
 	void setBaseD(int);//set the base defense for pokemon
 	void setBaseSpec(int);//set the base special for pokemon
 	void setBaseSpeed(int);//set the base speed
 	void setBaseHP(int);//set the base HP
// the derived classes also set the catch rate
	void setCatch(int); 
	int getCatch(); 
	int getBaseA(){ return base_A; };
 	int getBaseD(){ return base_D; };
 	int getBaseSpec(){ return base_Speed; };
 	int getBaseSpeed(){ return base_Spec; };
 	int getBaseHP(){ return base_HP; };
// to have an abstract calss
	virtual void print()= 0;
// used in healing function
	void restoreHP(); //restore HP to maxHP
// get the attack to manipulate
	Attack* getAttack(int);
//the derived clases set the moves or attacks, push backs specific attacks
	void setMove(string, string, int, int, int); 
  private:
	string type;//fire, electric, etc.
	string name;//the name of the pokemon
	string EXPtype;
//for experience: the EXP type determines how fast EXP increase
	int EXP; // the amount of exp
	int base_A;// base stats are particular for the type of pokemon
	int base_D;
	int base_Speed;
	int base_Spec;
	int base_HP;
	int IV_A;//individualistic values or Pokemon "genes"
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
	int special;	
	int speed;
	int level;// the level, changes as pokemon gets more EXP
	int catchRate;// the rate at which a pokemon can be catched for grass
	int HP; // health
	int maxHP; //max health, or the initial HP
	vector<Attack*> attacks;// the attacks that a pokemon has
};

#endif
