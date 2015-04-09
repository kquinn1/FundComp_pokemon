//Katie Quinn
//Grass.cpp
//Implementation of Grass.h
//represents the grass class will set type to grass
#include <string>
#include "Grass.h"

Grass::Grass(int myLevel): Pokemon(myLevel){
  Pokemon::setType("grass");
}

