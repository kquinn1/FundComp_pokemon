//Katie Quinn
//Shop class allows players to buy items, etc.

#include "Shop.h"
#include <iostream>
using namespace std;

const int PRICE = 20; //const price for pokeball

Shop::Shop(Player* myplay){
  buyer = myplay;

  cout << "Welcome to the PokeMart! " << endl;
  cout << "Your current cash: " << buyer->getMoney() << endl;

  if( buyer->getMoney() == 0 ) {
	cout << "Sorry, you cannot buy items at the shop without cash. " << endl;
	cout << "Try defeating trainers at the gym to acquire cash. " << endl;
  } else{
	cout << "You can buy pokeballs if you wish!" << endl; //temp for testing
  }
}

void Shop::dispItems(){
  int uChoice;
  bool valid = false;
//allow the buyer to purchase items and add them to their items
//display the items avialbe to purchase
// view items for sale:
// view items on person:
// view how much things are
// simplification: only pokeballs
  while(valid != true){
    cout << "Items available: pokeballs." << endl << "Current price: $20 " << endl;
    cout << "Would you like to make a purchase?" << endl;
    cout << "Type 1 to buy, 0 to walk away: ";
    cin >> uChoice;
    if (uChoice == 0) {
	valid = true;
   } else if (uChoice == 1){
	if( canBuy(PRICE) == 1 ) {
	// decrease money
	  buyer->setMoney(-PRICE);
	  buyer->addItem( new Item("pokeball", "catch poke", "null image", 20) ) ;
	}else cout << "Cannot buy. Insufficient cash at this point." << endl;	
	valid = true;
    } else cout << "ERROR! Enter correct input next time.";
 }
cout << "Thanks for stopping by! " << endl;
	
}

int Shop::canBuy(int price){
//return 1 if they can buy, 0 if they cannot
  if( price <= buyer->getMoney() ) return 1;
  else return 0;
}
