//Katie Quinn
//shop class allows the user to buy different items
//
#include "Player.h"
#include "Item.h"
//is the second one necessary?
class Shop{
  public:
	Shop(Player*);
	void dispItems(); // display the items for sale
	int canBuy(int); // check to see if the player can buy
	// if they can the item purchased should be added to the end of the item vector
  private:
      	Player* buyer;
};
