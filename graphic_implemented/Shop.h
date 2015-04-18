#ifndef SHOP_H
#define SHOP_H
#include "Player.h"


// need an SDL class to inherit from with all the graphics funcions
class Shop{
    public:
	Shop(Player*);
 
    private:
	Player* myPlay;
}
