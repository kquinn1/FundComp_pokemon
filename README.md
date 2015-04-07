# cse20212-project
Repository for final project for CSE20212
Simple pokemon game

test.cpp opens a file that contains a background image.
To compile g++ -lSDL test.cpp
screen is the executable

Pokemon_class: directory includes the Pokemon class. This is a top level entity class for the pokemon hierarchy. It is a virtual class.
Derived off of the pokemon class are types classes. There are currently
the type classes: electric, fire, water, grass and normal. The type classes
are abstract too. Derived from the type classes are specific pokemon
species. Current implemented species are: Pikachu, Charmander, Squirtle, and 
Bulbasaur. 
The file maintest.cpp was compiled (a.out). This file instantiates different
species of pokemon and lists their stats. Their stats have been checked for accuracy.

A player class (player.h) as well as an attack class (attack.h & attack.cpp)
have been started. They have not been implemented yet.
A pokemon should have different attacks. Perhaps the species of pokemon
will set the pokemon attacks or the user can decide.

The player class should have its x and y coordinates. The player should have
six or so pokemon that belong to it (composition). Not sure if this should
be preset or if the player should decide what pokemon it should have.
