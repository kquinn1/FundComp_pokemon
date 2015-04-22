//Katie Quinn
//CSE 20212 - For final project
//Base class for pokemon
//
// to do: add attacks
#ifndef POKEMON_H
#define POKEMON_H
#include "Attack.h"
#include <vector>
#include <string>
using namespace std; //for string
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
	void setSpecial();
	void setSpeed();
        void setHP(); // HP initially
	void setName(string s){ name = s; } ;
	void setEXPtype(string e){ EXPtype = e; } ;
	int getEXP(){ return EXP; };
	void calcEXP(int); //calculates and sets EXP
	string getName(){return name;};
	int ifLevelUp(); //determine if level up
	void levelUp(); //level up
	int getMax(){ return maxHP; };
	int GetAttack();	
	int getDefense();
	int getSpecial();
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
	void setCatch(int); //i){ catchRate = i;} ;
	int getCatch(); //{ return catchRate ; } ; 
	int getBaseA(){ return base_A; };
 	int getBaseD(){ return base_D; };
 	int getBaseSpec(){ return base_Speed; };
 	int getBaseSpeed(){ return base_Spec; };
 	int getBaseHP(){ return base_HP; };
	virtual void print()= 0;
	void restoreHP(); //restore HP to maxHP
	Attack* getAttack(int);
	void setMove(string, string, int, int, int); //used in other pokemon to push back specific attacks
  private:
	string type;
	string name;
	string EXPtype;//for experience
	int EXP; // for experience
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
	int special;	
	int speed;
	int level;
	int catchRate;
	int HP; // health
	int maxHP; //max health, or the initial HP
	vector<Attack*> attacks;
};

#endif
