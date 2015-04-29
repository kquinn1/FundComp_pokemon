//Katie Quinn
//Item implementation file
// Item class stores a name, a description, the image (stored as a string)
// as well as an integer representing the price
// This intended to include multiple items
// simplified to only include pokeballs
#include "Item.h"
#include <string>

Item::Item(string myName, string myDescrip, string myImg, int myPrice){
  name = myName;
  description = myDescrip;
  imgName = myImg;
  price = myPrice; //set all the private variables with constructor
}
//deconstructor not sure if needed
Item::~Item() { }

//set functions for Item class
void Item::setName(string myName){
  name = myName;
}

void Item::setDescrip(string myDescrip){
  description = myDescrip;
}

void Item::setPrice(int myPrice){
  price = myPrice;
}
//get functions for Item class
string Item::getName(){ return name; }

string Item::getDescrip(){ return description; }

string Item::getImage(){ return imgName; }

int Item::getPrice(){ return price; }
