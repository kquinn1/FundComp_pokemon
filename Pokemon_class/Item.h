//Katie Quinn
//Item class used for game eventually
//Implementation
#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;
class Item{
  public: 
	Item(string, string, string, int);
	~Item();
	void setName(string);
	void setDescrip(string);
	void setPrice(int); //set functions for private variables

	string getName();
	string getDescrip(); 
	string getImage();
	int getPrice();

  private:
	string name;
	string description;
	string imgName;
	int price; // private variables
};

#endif   
