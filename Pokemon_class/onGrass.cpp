//Katie Quinn
//onGrass implementation file
//
#include "onGrass.h"
#include <stdio.h> //NULL
#include <stdlib.h> //srand, rand
#include <time.h> // time
#include <iostream>
#include "Oddish.h"
#include "Jigglypuff.h"
#include "Snorlax.h"
#include "Eevee.h"
#include "Pikachu.h"
#include "Bulbasaur.h"
#include "Charmander.h"
#include "Squirtle.h"
using namespace std;

const int CAUGHT = 1;
const int ESCAPED = 0;
const int BALL = 255; // assume that a poke ball is used

onGrass::onGrass(Player* m_player){//, Pokemon* m_poke, int isonGrass){
  srand( time(NULL) );//initialize random seed
  int pokeRand; // number to see if pokemon is instantiated
  int randLevel; // make the pokemon a random level
  myPlayer= m_player; //set player pointer
// calculate the probability for a battle
  pokeRand = rand()%100; //pick a number between 0 and 99
  if(pokeRand<20 ) cout << "No Pokemon found in grass!" << endl; //do nothing
  else if (pokeRand>20 && pokeRand<30 ){
	randLevel = rand()%20 + 1;
	myWild = (new Oddish(randLevel));
  } 
  else if(pokeRand>30 && pokeRand<40){
	randLevel = rand()%20 + 1;
        myWild = (new Jigglypuff(randLevel));
  } 
  else if(pokeRand>40 && pokeRand<50){
	randLevel = rand()%20 + 1;
	myWild = (new Snorlax(randLevel));
  }
  else if(pokeRand>50 && pokeRand<60){
	randLevel = rand()%20 + 1;
	myWild = (new Eevee(randLevel));
  }
  else if(pokeRand>60 && pokeRand<70) {
	randLevel = rand()%20 + 1;
        myWild = (new Pikachu(randLevel));
  } 
  else if(pokeRand>70 && pokeRand<80){
	randLevel = rand()%20 + 1;
        myWild = (new Bulbasaur(randLevel));
  }
  else if(pokeRand>80 && pokeRand<90){
	randLevel = rand()%20 + 1;
        myWild = (new Charmander(randLevel));
  
  }
  else{// if(pokeRand>90){
	randLevel = rand()%20 + 1;
        myWild = (new Squirtle(randLevel));
  }
  if(pokeRand>20){
// for testing	cout << randLevel << " the level. " << endl;
	battle(); //battle against the pokemon created
  }

  //while
 //pick the pokemon set to myWild
 //sent to battle

}

//should there be a deconstructor?
//onGrass::~onGrass(){ }}

void onGrass::battle(){
//wild pokemon and player class battle
  cout << "A level " << myWild->getLevel() <<" " << myWild->getName() << " wants to battle!!!!" << endl;
// only one pokemon to battle
//intialize turn variable
  int turn = 0;
  int quit = 0;
  int enemy;
//the player should choose the current pokemon to use
  choosePoke();
//simplification: usually is the first pokemon available, then has options to switch later on


  cout << myWild->getName() << " has " << myWild->getHP() << " HP!" <<endl;
//determine who goes first e.g. who has the fastest speed
  if((myPlayer->getCurrentPokemon()->getSpeed())<(myWild->getSpeed())) turn++;
  while(isWinner()==0 && quit == 0){ // && quit == 0){
// while there is not a winner
    if((turn%2 + 1) %2){//Player's turn
   	quit = playerTurn(); //should pass an int denoting a onGrass pokemon or not
      }

    else{//the enemy's turn	
        enemyTurn();
    } 
    turn++; //increment the turn in order to change turns 
  }  
//Todo:
//winner logic, if player wins gains experience, gains 
  if(myPlayer->isDefeated()==1){
     cout << endl << "The player has been defeated!" << endl;
  }else if(myWild->getHP()==0){
     //set experience on last pokemon
     setExperience();
     cout << "The wild pokemon has fainted!" << endl; 
  }else if(quit ==2){
     cout << "Successfuly caught " << myWild->getName() << endl;
  }
  else{ cout << "You ran away!" << endl;}
}

int onGrass::playerTurn(){
//function represents a player's turn
  int damage_inflicted;
  int result; //store the result of updating the HP should change
  int uChoice;
  int switchChoice; //for while loop
  int valid = 0; //to use in while loop
//option to change pokemon, run, or onGrass, item implemented later
  battleMenu(); //display options on a turn
  cin >> uChoice;
  switch(uChoice){
     case 1://onGrass 
//show attacks & decide on the attack
	uChoice = showAttacks();
//use the attack on the pokemon
//display the battle
  cout << myPlayer->getCurrentPokemon()->getName() << " will use " << myPlayer->getCurrentPokemon()->getAttack(uChoice)->getName() << "." << endl;
//calculate the damage inflicted
	damage_inflicted =Damage("Player", uChoice);
//set the PP on the attack used
	myPlayer->getCurrentPokemon()->getAttack(uChoice)->updatePP();
  cout << myPlayer->getCurrentPokemon()->getName() << " has inflicted " << damage_inflicted << " on " << myWild->getName() << "!" << endl;
//check to see if enemy pokemon fainted: set new pokemon
  result = myWild->updateHP(damage_inflicted);
   cout<< myWild->getName() << " now has " << myWild->getHP() << " HP remaining. " << endl;
//check to see if need to set new pokemon
	if(result == 1){//set a new enemy pokemon only if the enemy is not defeated e.g. no pokemon remaining
	   if(myWild->getHP()==0){
		 cout << myWild->getName() << " has fainted! " << endl;
		 return 1;
 		while(valid == 0){ 
//TO DO FIX THIS
		  cout << "Switch Pokemon? Type 1 or 0: ";
		  cin >> switchChoice;
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
// calculate the probability they can run away
//To do : calculate to see whether they can run away or not
	cout << "Sucessfuly ran away" << endl;
        return 1;
	break;
     case 4:
	if( isCaught() == CAUGHT ) {
  		cout << "Catching pokemon..." << endl;
		myPlayer->addPokemon(myWild);
		return 2;
	}
	else{
		cout << "Failed to catch pokemon!" << endl;
	}
	break;
     default:
        cout << "Invalid option." << endl;
	break;
     }
     return 0; //the player did not run away
}

int onGrass::isCaught(){
//return a 1 if caught
//return a 0 if not
//using formula
  srand( time(NULL) );//initialize random seed
  // to use for the random number
  int M = rand()%255; //generate random int between 0 and 255
  int stat;

  stat = (myWild->getMax() * 255 * 4 ) / (myWild->getHP() * BALL );

  if( stat >= M ) return CAUGHT;
  else return ESCAPED;
}

void onGrass::setExperience(){
//set the experience for the pokemon in battle
//calculate the experience
  myPlayer->getCurrentPokemon()->calcEXP(myWild->getLevel()); 
//add to EVs the base stats of the enemy pokemon
  myPlayer->getCurrentPokemon()->updateEV_A(myWild->getBaseA());
  myPlayer->getCurrentPokemon()->updateEV_D(myWild->getBaseD());
  myPlayer->getCurrentPokemon()->updateEV_Speed(myWild->getBaseSpeed());
  myPlayer->getCurrentPokemon()->updateEV_Spec(myWild->getBaseSpec());
  myPlayer->getCurrentPokemon()->updateEV_HP(myWild->getBaseHP());

//check to see if the pokemon has gained a level

}
void onGrass::enemyTurn(){
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
    if(myWild->getAttack(randChoice)->getPP() > 0){
       valid = 1; //the attack is valid
    }
   }
  cout << myWild->getName() << " will use " << myWild->getAttack(randChoice)->getName()<< "." << endl;
//calculate the damage inflicted
//damage_inflicted =Damage(speed, level, attack, player_defense, attack_power, attack_type, type, player_type, attack_acc);
  damage_inflicted = Damage("Enemy", randChoice);
//set the PP on the attack used
  myWild->getAttack(randChoice)->updatePP();
  cout << myWild->getName()<< " has inflicted " << damage_inflicted << " on " << myPlayer->getCurrentPokemon()->getName() << "!" << endl;
//check to see if enemy pokemon fainted: set new pokemon
  result = myPlayer->getCurrentPokemon()->updateHP(damage_inflicted);
  cout << myPlayer->getCurrentPokemon()->getName() << " now has " << myPlayer->getCurrentPokemon()->getHP() << " HP remaining. " << endl;
  if(result == 1){//a pokemon has fainted
//only if the player is not defeated e.g. no pokemon remaining set a new pokemon
    if(myPlayer->isDefeated()==0){
	cout << myPlayer->getCurrentPokemon()->getName()<< " has fainted!" << endl ;
	choosePoke();
     }
  }
}
void onGrass::choosePoke(){
//this function allows the user to choose which pokemon to use
  int size;
  int uChoice;
  int valid = 0;
  while( valid == 0 ){
    cout << "Pick the pokemon you will use: " << endl;  
  //declare iterator
    size = myPlayer->getNumPoke();
    for(int i=0; i<size; i++){
      cout << "Choice " << i << ": "<<myPlayer->getPokemon(i)->getName();
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
  cout << "Go! " << myPlayer->getCurrentPokemon()->getName() << endl;
}

void onGrass::battleMenu(){
  cout << "Choose an option: " << endl;
  cout << "1. Fight " << endl;
  cout << "2. Change Pokemon " << endl;
  cout << "3. Run " << endl;
  cout << "4. Catch Enemy " << endl;
//cout << "4. Item " << endl;
  cout << "Your choice: " ;
}

int onGrass::showAttacks(){
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
int onGrass::Damage(string turn,int choice){
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
	d_type = myWild->getType();
  	acc_attack = myPlayer->getCurrentPokemon()->getAttack(choice)->getAcc();
	attack_type = myPlayer->getCurrentPokemon()->getAttack(choice)->getType();
	if(attack_type!="normal"){
  	//must use special defense/attack
  	   a_attack = myPlayer->getCurrentPokemon()->getSpecial();
  	   d_defense = myWild->getSpecial();
        }else{
	//use regular attack and defense
	   a_attack = myPlayer->getCurrentPokemon()->GetAttack();
	   d_defense = myWild->getDefense();
	}
  }else{//enemy turn
	baseSpeed = myWild->getSpeed();
	a_level = myWild->getLevel();
  	attack_power = myWild->getAttack(choice)->getPower();
  	a_type = myWild->getType();
  	d_type = myPlayer->getCurrentPokemon()->getType(); 
  	acc_attack = myWild->getAttack(choice)->getAcc();
  	attack_type = myWild->getAttack(choice)->getType();
	if(attack_type!="normal"){
  	//must use special defense/attack
  	   a_attack = myWild->getSpecial();
  	   d_defense = myPlayer->getCurrentPokemon()->getSpecial();
        }else{
	//use regular attack and defense
  	   a_attack = myWild->GetAttack();
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
  type = typeCalc(attack_type, d_type);
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

float onGrass::typeCalc(string attack_type,string d_type){
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

int onGrass::isWinner(){
//if there is a winner
  if(myWild->getHP()!=0 && myPlayer->isDefeated()==0) return 0;
  return 1; //there is a  winner
}
