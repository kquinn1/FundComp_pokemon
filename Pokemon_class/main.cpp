//Katie Quinn
//file will test out a battle
#include "Fight.h"
#include "Enemy.h"
#include "Player.h" //not sure if these two are needed
#include <iostream>
#include <string>
using namespace std;

int main(){
  Enemy en1(0,0,0,"Starmie",20,"Horsea",10); 
  Player my_play(0,0);
//declare pointers to each
/*  Enemy *myenemy;
  myenemy = &en1; 
  Player *myplay;
  */
  Fight myfight(my_play&,en1&);
//pray to god this works

  return 0;
}
