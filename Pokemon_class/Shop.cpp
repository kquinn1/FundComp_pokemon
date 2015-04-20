//Katie Quinn
//Shop class allows players to buy items, etc.

#include "Shop.h"
#include <iostream>
using namespace std;

Shop::Shop(Player* myplay){
  buyer = myplay;

  cout << "Welcome to the PokeMart! " << endl;
  cout << "Your current cash: " << buyer->getMoney() << endl;

  if( buyer->getMoney() == 0 ) {
	cout << "Sorry, you cannot buy items at the shop without cash. " << endl;
	cout << "Try defeating trainers at the gym to acquire cash. " << endl;
  } else{
	cout << "You can buy things" << endl; //temp for testing
  }
}

void Shop::dispItems(){

//allow the buyer to purchase items and add them to their items
//display the items avialbe to purchase
// view items for sale:
// view items on person:
// view how much things are
// 
}

int Shop::canBuy(int price){
//return 1 if they can buy, 0 if they cannot
  if( price <= buyer->getMoney() ) return 1;
  else return 0;
}
