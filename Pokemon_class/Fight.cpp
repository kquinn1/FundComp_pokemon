//Katie Quinn
//Fight.cpp
// Fight inherits from Battle 
//Fight implementation file

//#include "Battle.h"
#include "Fight.h"
#include <stdio.h> //NULL
#include <stdlib.h> //srand, rand
#include <time.h> // time
#include <iostream>
#include <limits> //dealing with incorrect input
using namespace std;

Fight::Fight(Player* m_player, Enemy* m_enemy):Battle(m_player){ // call to the battle class constructor
   myEnemy = m_enemy;
   battle();// commence the battle
}

void Fight::battle(){
//enemy and player class battle
//enemy greets player
  cout << endl << myEnemy->getName() << " wants to battle!!!!" << endl;

//intialize turn variable
  int turn = 0;
 // int quit = 0;
  int enemy;
//the player should choose the current pokemon to use
  if(myPlayer->isDefeated() == 0) {
	Battle::choosePoke();
//simplification: usually is the first pokemon available, then has options to switch later on

//the enemy will use the last pokemon available to use in vector
//as the pokemon when fainted will be pop_back'd
        enemy = myEnemy->getNumPoke();
        enemy--;
        myEnemy->setCurrentPokemon(myEnemy->getPokemon(enemy));

       cout << "Enemy sent out " <<  myEnemy->getCurrentPokemon()->getName() << endl;
       cout << "Go! " << myPlayer->getCurrentPokemon()->getName() << endl;

       cout << myEnemy->getCurrentPokemon()->getName() << " has " << myEnemy->getCurrentPokemon()->getHP() << " HP!" <<endl;
//determine who goes first e.g. who has the fastest speed
       if((myPlayer->getCurrentPokemon()->getSpeed())<(myEnemy->getCurrentPokemon()->getSpeed())) turn++;
       while(isWinner()==0){ // && quit == 0){
// while there is not a winner
           if((turn%2 + 1) %2){//Player's turn
   	     playerTurn(); //should pass an int denoting a wild pokemon or not
             }
 
          else{//the enemy's turn	
             enemyTurn();
          } 
           turn++; //increment the turn in order to change turns 
  }  
//winner logic, if player wins gains experience, gains 
        if(myPlayer->isDefeated()==1){
             cout << endl << "The player has been defeated!" << endl;
        }else if(myEnemy->isDefeated()==1){
     //set experience on last pokemon
          setExperience();
          cout << "The trainer has been defeated!" << endl; 
          cout << "You receive: " << myEnemy->getMoney() << " in cash!" << endl;
          myPlayer->setMoney(myEnemy->getMoney() );
          cout << "Cash total: " << myPlayer->getMoney() << endl;
       }else { cout << "ERROR!" << endl;}
  }else cout << "Pokemon not healthy enough for battle." << endl;
}

void Fight::playerTurn(){
//function represents a player's turn
  int damage_inflicted;
  int result; //store the result of updating the HP should change
  int uChoice;
  int switchChoice; //for while loop
  int valid = 0; //to use in while loop
//option to change pokemon, run, or fight, item implemented later
  Battle::battleMenu(); //display options on a turn
//  cin >> uChoice;
//deal with non numeric input
  while( !(cin >> uChoice) ){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << "Invalid input. Enter a number." << endl;
    }
  switch(uChoice){
     case 1://Fight 
//show attacks & decide on the attack
	uChoice = Battle::showAttacks();
//use the attack on the pokemon
//display the battle
  cout << myPlayer->getCurrentPokemon()->getName() << " will use " << myPlayer->getCurrentPokemon()->getAttack(uChoice)->getName() << "." << endl;
//calculate the damage inflicted
	damage_inflicted =Damage("Player", uChoice);
//set the PP on the attack used
	myPlayer->getCurrentPokemon()->getAttack(uChoice)->updatePP();
// validate damage amount
  damage_inflicted = Battle::checkDamage(damage_inflicted, myEnemy->getCurrentPokemon()->getHP());  
  cout << myPlayer->getCurrentPokemon()->getName() << " has inflicted " << damage_inflicted << " on " << myEnemy->getCurrentPokemon()->getName() << "!" << endl;
//check to see if enemy pokemon fainted: set new pokemon
  result = myEnemy->getCurrentPokemon()->updateHP(damage_inflicted);
   cout<< myEnemy->getCurrentPokemon()->getName() << " now has " << myEnemy->getCurrentPokemon()->getHP() << " HP remaining. " << endl;
//check to see if need to set new pokemon
	if(result == 1){//set a new enemy pokemon only if the enemy is not defeated e.g. no pokemon remaining
	   if(myEnemy->isDefeated()==0){
		 cout << myEnemy->getCurrentPokemon()->getName() << " has fainted! " << endl;
		//set experience based on the level of the defeated pokemon
		 setExperience();
		 setEnemyPoke();		
  		 cout << "Enemy sent out " << myEnemy->getCurrentPokemon()->getName() << endl;
  		cout << myEnemy->getCurrentPokemon()->getName() << " has " << myEnemy->getCurrentPokemon()->getHP() << " HP!" <<endl;
 		while(valid == 0){ 
//TO DO FIX THIS
		  cout << "Switch Pokemon? Type 1 to switch or 0 to stay with current pokemon: ";
		//  cin >> switchChoice;
  		  while( !(cin >> switchChoice) ){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid input. Enter a number." << endl;
   		 }
		  if(switchChoice == 1) {
			choosePoke();
			valid = 1;
		  }
		  else if(switchChoice== 0) valid = 1; //do nothing
	  	  else cout << "Invalid option!" << endl;
	        }
	   }

        }
        break;
     case 2://Change Pokemon
	choosePoke();
	break;
     case 3://Run
	cout << "Cannot run away from a trainer!" << endl;
	//can run away from a wild pokemon
	//fix player turn to accomadate both types of battles
        break;
     default:
        cout << "Invalid option." << endl;
	break;
     }
}

void Fight::setExperience(){
//set the experience for the pokemon in battle
//calculate the experience
  myPlayer->getCurrentPokemon()->calcEXP(myEnemy->getCurrentPokemon()->getLevel()); 
//add to EVs the base stats of the enemy pokemon
  myPlayer->getCurrentPokemon()->updateEV_A(myEnemy->getCurrentPokemon()->getBaseA());
  myPlayer->getCurrentPokemon()->updateEV_D(myEnemy->getCurrentPokemon()->getBaseD());
  myPlayer->getCurrentPokemon()->updateEV_Speed(myEnemy->getCurrentPokemon()->getBaseSpeed());
  myPlayer->getCurrentPokemon()->updateEV_Spec(myEnemy->getCurrentPokemon()->getBaseSpec());
  myPlayer->getCurrentPokemon()->updateEV_HP(myEnemy->getCurrentPokemon()->getBaseHP());

//check to see if the pokemon has gained a level

}
void Fight::enemyTurn(){
//function represents an enemy's turn`
//choose an attack randomly
  srand( time(NULL) );//initialize random seed
  int randChoice;
  int damage_inflicted;
  int result; //whether or not the user needs to choose an enemy pokemon
  int valid = 0; 
//set statistics needed to calculate the damage 
  while(valid==0){
    randChoice=rand()%4; //choose a random number in between 0 and 3
//rand Choice must have valid PP
    if(myEnemy->getCurrentPokemon()->getAttack(randChoice)->getPP() > 0){
       valid = 1; //the attack is valid
    }
   }
  cout << myEnemy->getCurrentPokemon()->getName() << " will use " << myEnemy->getCurrentPokemon()->getAttack(randChoice)->getName()<< "." << endl;
//calculate the damage inflicted
//damage_inflicted =Damage(speed, level, attack, player_defense, attack_power, attack_type, type, player_type, attack_acc);
  damage_inflicted = Damage("Enemy", randChoice);
//set the PP on the attack used
  myEnemy->getCurrentPokemon()->getAttack(randChoice)->updatePP();
// validate damage amount
  damage_inflicted = Battle::checkDamage(damage_inflicted, myPlayer->getCurrentPokemon()->getHP());  
  cout << myEnemy->getCurrentPokemon()->getName()<< " has inflicted " << damage_inflicted << " on " << myPlayer->getCurrentPokemon()->getName() << "!" << endl;
//check to see if enemy pokemon fainted: set new pokemon
  result = myPlayer->getCurrentPokemon()->updateHP(damage_inflicted);
  cout << myPlayer->getCurrentPokemon()->getName() << " now has " << myPlayer->getCurrentPokemon()->getHP() << " HP remaining. " << endl;
  if(result == 1){//a pokemon has fainted
//only if the player is not defeated e.g. no pokemon remaining
//set a new pokemon
    if(myPlayer->isDefeated()==0){
	cout << myPlayer->getCurrentPokemon()->getName()<< " has fainted!" << endl ;
	Battle::choosePoke();
     }
  }
}

//calculate the damage a pokemon does
int Fight::Damage(string turn,int choice){
//int Fight::Damage(int baseSpeed,int a_level, int a_attack, int d_defense, int attack_power, string attack_type, string a_type, string d_type, int acc_attack){
//change this function. Send in one string. Calculate variables within function no need to passe in main.

//set statistics needed for damage
  int baseSpeed;
  int a_level;
  int a_attack;
  int d_defense;
  int attack_power;
  string attack_type;
  string a_type;
  string d_type;
  int acc_attack;//change variables

  if(turn=="Player"){
//set the variables to pass to damage function
        baseSpeed = myPlayer->getCurrentPokemon()->getSpeed();
	a_level = myPlayer->getCurrentPokemon()->getLevel();
	attack_power = myPlayer->getCurrentPokemon()->getAttack(choice)->getPower();
	a_type = myPlayer->getCurrentPokemon()->getType();
	d_type = myEnemy->getCurrentPokemon()->getType();
  	acc_attack = myPlayer->getCurrentPokemon()->getAttack(choice)->getAcc();
	attack_type = myPlayer->getCurrentPokemon()->getAttack(choice)->getType();
	if(attack_type!="normal"){
  	//must use special defense/attack
  	   a_attack = myPlayer->getCurrentPokemon()->getSpecial();
  	   d_defense = myEnemy->getCurrentPokemon()->getSpecial();
        }else{
	//use regular attack and defense
	   a_attack = myPlayer->getCurrentPokemon()->GetAttack();
	   d_defense = myEnemy->getCurrentPokemon()->getDefense();
	}
  }else{//enemy turn
	baseSpeed = myEnemy->getCurrentPokemon()->getSpeed();
	a_level = myEnemy->getCurrentPokemon()->getLevel();
  	attack_power = myEnemy->getCurrentPokemon()->getAttack(choice)->getPower();
  	a_type = myEnemy->getCurrentPokemon()->getType();
  	d_type = myPlayer->getCurrentPokemon()->getType(); 
  	acc_attack = myEnemy->getCurrentPokemon()->getAttack(choice)->getAcc();
  	attack_type = myEnemy->getCurrentPokemon()->getAttack(choice)->getType();
	if(attack_type!="normal"){
  	//must use special defense/attack
  	   a_attack = myEnemy->getCurrentPokemon()->getSpecial();
  	   d_defense = myPlayer->getCurrentPokemon()->getSpecial();
        }else{
	//use regular attack and defense
  	   a_attack = myEnemy->getCurrentPokemon()->GetAttack();
 	   d_defense = myPlayer->getCurrentPokemon()->getDefense();
	}
  }

  srand( time(NULL) );//initialize random seed
  int ifAttack;//determine if there is an attack
  ifAttack = rand()%100;
  if(ifAttack>acc_attack){//account for probability there is an attack, based on attack accuracy
   cout << "Attack missed!" << endl;
   return 0;
  }
  int STAB;
  float type;
  float randomInt;
  float critNum;
  float Modifier;
  //Determine if there is a critical hit
  float crit;
  crit = ((double)baseSpeed/512) * 100;
  critNum = rand()%100; //generate a number 0 and 100
  if(crit>=critNum) {crit = 2; cout <<"CRITICAL HIT" <<endl; } //it is a critical hit
  else crit = 1;
  int damage;
//determine if STAB bonus applies
  if(attack_type == a_type) STAB = 1.5;
  else STAB = 1; //the pokemon and it's attack are different
//adjust the type variable based on the attack type and the type of defensive pokemon
  type = Battle::typeCalc(attack_type, d_type);
//display appropriate message
  if(type==2) cout << "It's super effective!" << endl;
  else if(type==0.5) cout << "It's not very effective." << endl;

//for the damage formula
  randomInt=rand()%15 + 86; //random number between 85 and 100;
  randomInt/=100;
  Modifier = STAB * type * crit * randomInt;
 //  cout << "The random integer used was: " << randomInt << endl; //for testing
  damage = (((2*(double)a_level+10)/250) * ((double)a_attack/(double)d_defense) * attack_power + 2 ) * Modifier;

  return damage;
}

int Fight::isWinner(){
//if there is a winner
  if(myEnemy->isDefeated()==0 && myPlayer->isDefeated()==0) return 0;
  return 1; //there is a  winner
}

void Fight::setEnemyPoke(){
  int enemy;
//delete the first in the vector though not ideal
  myEnemy->deletePokemon(); 
  enemy = myEnemy->getNumPoke();
  enemy--;
  myEnemy->setCurrentPokemon(myEnemy->getPokemon(enemy));
//the enemy will use the last pokemon available to use in vector
}
