//Katie Quinn
//Fight implementation file
#include "Fight.h"
#include <stdio.h> //NULL
#include <stdlib.h> //srand, rand
#include <time.h> // time
#include <iostream>
using namespace std;

Fight::Fight(Player* m_player, Enemy* m_enemy){//, Pokemon* m_poke, int isWild){
  myPlayer= m_player;
  //if statement
//  if(isWild==1){// a wild pokemon battle
 //  myWild = m_poke;  
 //  wildBattle();
 // }else{ // an enemy pokemon battle
   myEnemy = m_enemy;
   battle();
 // }
}

//should there be a deconstructor?
//Fight::~Fight(){ }}

void Fight::battle(){
//enemy and player class battle
//intialize turn variable
  int turn = 0;
 // int quit = 0;
  int enemy;
//the player should choose the current pokemon to use
  choosePoke();
//simplification: usually is the first pokemon available, then has options to switch later on

//the enemy will use the last pokemon available to use in vector
//as the pokemon when fainted will be pop_back'd
  enemy = myEnemy->getNumPoke();
  enemy--;
  myEnemy->setCurrentPokemon(myEnemy->getPokemon(enemy));

  cout << "Enemy sent out " ;
  myEnemy->getCurrentPokemon()->print();
  cout << endl<< "Go! ";
  myPlayer->getCurrentPokemon()->print();
  cout << endl;


  cout << "Enemy has " << myEnemy->getCurrentPokemon()->getHP() << " HP!" <<endl;
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
//Todo:
//winner logic, if player wins gains experience, gains 
  if(myPlayer->isDefeated()==1){
     cout << "The player has been defeated!" << endl;
  }else if(myEnemy->isDefeated()==1){
     cout << "The trainer has been defeated!" << endl;
  }else { cout << "ERROR!" << endl;}
}

void Fight::playerTurn(){
//function represents a player's turn
  int damage_inflicted;
  int result; //store the result of updating the HP should change
  int uChoice;
//set statistics needed for damage
  int speed;
  int level;
  int attack;
  int enemy_defense;
  int attack_power;
  string attack_type;
  string type;
  string enemy_type;
  int attack_acc;
//option to change pokemon, run, or fight, item implemented later
  battleMenu(); //display options on a turn
  cin >> uChoice;
  switch(uChoice){
     case 1://Fight 
//show attacks & decide on the attack
	uChoice = showAttacks();
//set the variables to pass to damage function
        speed = myPlayer->getCurrentPokemon()->getSpeed();
	level = myPlayer->getCurrentPokemon()->getLevel();
	attack = myPlayer->getCurrentPokemon()->GetAttack();
	enemy_defense = myEnemy->getCurrentPokemon()->getDefense();
//don't account for special attacks ackkkk
	attack_power = myPlayer->getCurrentPokemon()->getAttack(uChoice)->getPower();
	attack_type = myPlayer->getCurrentPokemon()->getAttack(uChoice)->getType();
	type = myPlayer->getCurrentPokemon()->getType();
	enemy_type = myEnemy->getCurrentPokemon()->getType();
	attack_acc = myPlayer->getCurrentPokemon()->getAttack(uChoice)->getAcc();
//use the attack on the pokemon
//display the battle
  myPlayer->getCurrentPokemon()->print() ;
  cout<< " will use " << myPlayer->getCurrentPokemon()->getAttack(uChoice)->getName() << "." << endl;
//calculate the damage inflicted
	damage_inflicted =Damage(speed, level, attack, enemy_defense, attack_power, attack_type, type, enemy_type, attack_acc);
//set the PP on the attack used
	myPlayer->getCurrentPokemon()->getAttack(uChoice)->updatePP();
  myPlayer->getCurrentPokemon()->print() ;
  cout<< " has inflicted " << damage_inflicted << " on ";
  myEnemy->getCurrentPokemon()->print() ;
  cout << "!" << endl;
//check to see if enemy pokemon fainted: set new pokemon
  result = myEnemy->getCurrentPokemon()->updateHP(damage_inflicted);
   myEnemy->getCurrentPokemon()->print() ;
   cout<< " now has " << myEnemy->getCurrentPokemon()->getHP() << " HP remaining. ";
//check to see if need to set new pokemon
//	result = myEnemy->getCurrentPokemon()->updateHP(damage_inflicted);
	if(result == 1){//set a new enemy pokemon
//only if the enemy is not defeated e.g. no pokemon remaining
	   if(myEnemy->isDefeated()==0){
		 myEnemy->getCurrentPokemon()->print();
		 cout << " has fainted! " << endl;
		 setEnemyPoke();		
  		 cout << "Enemy sent out " ;
  		 myEnemy->getCurrentPokemon()->print();
		 cout << endl;
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
        cout << "Invalid option. You fail." << endl;
	break;
     }
}

void Fight::enemyTurn(){
//function represents an enemy's turn
//choose an attack randomly
  srand( time(NULL) );//initialize random seed
  int randChoice;
  int damage_inflicted;
  int result; //whether or not the user needs to choose an enemy pokemon
 //set statistics needed to calculate the damage 
  int speed;
  int level;
  int attack;
  int player_defense;
  int attack_power;
  string attack_type;
  string type;
  string player_type;
  int attack_acc;
  randChoice=rand()%4; //choose a random number in between 0 and 3
//calculate the damage inflicted
  speed = myEnemy->getCurrentPokemon()->getSpeed();
  level = myEnemy->getCurrentPokemon()->getLevel();
  attack = myEnemy->getCurrentPokemon()->GetAttack();
  player_defense = myPlayer->getCurrentPokemon()->getDefense();
//don't account for special attacks ackkkk
  attack_power = myEnemy->getCurrentPokemon()->getAttack(randChoice)->getPower();
  attack_type = myEnemy->getCurrentPokemon()->getAttack(randChoice)->getType();
  type = myEnemy->getCurrentPokemon()->getType();
  player_type = myPlayer->getCurrentPokemon()->getType(); 
  attack_acc = myEnemy->getCurrentPokemon()->getAttack(randChoice)->getAcc();
//use the attack on the pokemon
//display the battle
   myEnemy->getCurrentPokemon()->print();
   cout << " will use " << myEnemy->getCurrentPokemon()->getAttack(randChoice)->getName()<< "." << endl;
//calculate the damage inflicted
  damage_inflicted =Damage(speed, level, attack, player_defense, attack_power, attack_type, type, player_type, attack_acc);
//set the PP on the attack used
  myEnemy->getCurrentPokemon()->getAttack(randChoice)->updatePP();
  myEnemy->getCurrentPokemon()->print();
  cout << " has inflicted " << damage_inflicted << " on ";
 myPlayer->getCurrentPokemon()->print() ;
   cout << "!" << endl;
//check to see if enemy pokemon fainted: set new pokemon
  result = myPlayer->getCurrentPokemon()->updateHP(damage_inflicted);
  myPlayer->getCurrentPokemon()->print() ;
  cout << " now has " << myPlayer->getCurrentPokemon()->getHP() << " HP remaining. ";
  if(result == 1){//set a new enemy pokemon
//only if the player is not defeated e.g. no pokemon remaining
    if(myPlayer->isDefeated()==0){
        myPlayer->getCurrentPokemon()->print();
	cout << " has fainted!" ;
	choosePoke();
	cout << "Go! ";
        myPlayer->getCurrentPokemon()->print();
	cout << endl;
     }
  }
}

void Fight::wildBattle(){
//the player and a wild pokemon battle
//the player should choose the current pokemon to use
}

void Fight::choosePoke(){
//this function allows the user to choose which pokemon to use
  int size;
  int uChoice;
  int valid = 0;
  while( valid == 0 ){
    cout << "Pick the pokemon you will use: " << endl;  
  //declare iterator
    size = myPlayer->getNumPoke();
    for(int i=0; i<size; i++){
      cout << "Choice " << i << ": ";
      myPlayer->getPokemon(i)->print();
      cout <<"      Current HP: "<< myPlayer->getPokemon(i)->getHP() << endl;
    }  
    cout << "I choose..." ;
    cin >> uChoice;
//set the current Pokemon
    if(myPlayer->getPokemon(uChoice)->getHP()==0){
//can't use a fainted pokemon
      cout <<"This pokemon has fainted!" << endl;
    } else valid = 1;
  }
  myPlayer->setCurrentPokemon(myPlayer->getPokemon(uChoice));
}

void Fight::battleMenu(){
  cout << "Choose an option: " << endl;
  cout << "1. Fight " << endl;
  cout << "2. Change Pokemon " << endl;
  cout << "3. Run " << endl;
//cout << "4. Item " << endl;
  cout << "Your choice: " ;
}

int Fight::showAttacks(){
  int valid = 0; //in order to check for a valid attack
  int uChoice;
  while(valid == 0){
    cout << "Choose an attack...." << endl;
    for(int i = 0; i<4; i++){
        cout << i << ". ";
        cout << myPlayer->getCurrentPokemon()->getAttack(i)->getName() <<endl;
        cout << "Type: " ;
        cout << myPlayer->getCurrentPokemon()->getAttack(i)->getType() << endl;
        cout << "PP: " ;
        cout << myPlayer->getCurrentPokemon()->getAttack(i)->getPP() << endl;
    }
    cin >> uChoice;
    if(myPlayer->getCurrentPokemon()->getAttack(uChoice)->getPP() == 0 ){
      cout << "This attack is not valid! " <<endl;
    } else {valid = 1; }
  }
  return uChoice;
}
//calculate the damage a pokemon does
int Fight::Damage(int baseSpeed,int a_level, int a_attack, int d_defense, int attack_power, string attack_type, string a_type, string d_type, int acc_attack){
  srand( time(NULL) );//initialize random seed
  int ifAttack;//determine if there is an attack
  ifAttack = rand()%100;
  if(ifAttack>acc_attack){//account for probability there is an attack, based on attack accuracy
   cout << endl <<"Attack missed!" << endl;
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
  if(crit>=critNum) {crit = 2; cout <<"Critical hit" <<endl; } //it is a critical hit
  else crit = 1;
  int damage;
//determine if STAB bonus applies
  if(attack_type == a_type) STAB = 1.5;
  else STAB = 1; //the pokemon and it's attack are different
//adjust the type variable based on the attack type and the type of defensive pokemon
  type = typeCalc(attack_type, d_type);
//for the damage formula
  randomInt=rand()%15 + 86; //random number between 85 and 100;
  randomInt/=100;
  Modifier = STAB * type * crit * randomInt;
 //  cout << "The random integer used was: " << randomInt << endl; //for testing
  damage = (((2*(double)a_level+10)/250) * ((double)a_attack/(double)d_defense) * attack_power + 2 ) * Modifier;

  return damage;
}

float Fight::typeCalc(string attack_type,string d_type){
//calculate the type modification variable for the damage calculation
//float typeBonus(string attack_type,string  d_type){
  float type;
  if(attack_type == "normal") type = 1;
  else if(d_type == "normal") type = 1;
  else if (attack_type == d_type) type = 0.5;
  else if(attack_type == "fire"){
     if(d_type == "water") type = 0.5;
     else if(d_type == "grass") type = 2;
     else type = 1;
     }
  else if(attack_type == "water"){
     if(d_type == "fire") type = 2;
     else if(d_type == "grass") type = 0.5;
     else type = 1;                                                                
  }
  else if(attack_type == "grass"){
     if(d_type == "fire") type = 0.5;
     else if(d_type == "water") type = 2;
     else type = 1;
  }
  else if(attack_type == "electric"){
     if(d_type == "grass") type = 0.5; 
     else if(d_type == "water") type = 2;
     else type = 1;
  } 
  return type;
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
