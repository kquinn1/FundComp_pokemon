//Katie Quinn
//Grass.cpp
//Implement of Grass.h
//represents the grass class, sets pokemon type to grass

#include <string>
#include "Grass.h"

Grass::Grass(int myLevel): Pokemon(myLevel){
  Pokemon::setType("grass");
}
