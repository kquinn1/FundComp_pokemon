//Katie Quinn
//Shop class allows players to buy items, etc.

#include "Shop.h"
#include <iostream>
using namespace std;

Shop::Shop(Player* myplay){
  buyer = myplay;

  cout << "Welcome to the PokeMart! " << endl;
  cout << "Your current cash: " << buyer->getMoney() << endl;
//allow the buyer to purchase items and add them to their items
// view items for sale:
// view items on person:
// view how much things are
// 

}
