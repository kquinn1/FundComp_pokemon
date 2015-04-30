# cse20212-project
Repository for final project for CSE20212
Simple pokemon game

To use: download all files in Pokemon_class
use make clean or rm *.o to get rid of .o files
recompile using make
Executable given: Pokemon

Pokemon_class: 
This directory includes the Pokemon class. This is a top level entity class for the pokemon hierarchy. It calculates the pokemon stats using equations. It is a virtual class.
Derived off of the pokemon class are types classes. There are currently
the type classes: electric, fire, water, grass and normal. The type classes
are abstract too. Derived from the type classes are specific pokemon
species. There are currently 20 pokemon implemented in this directory.

The executable:
The player walks around by event handling using SDL.
Collision detection is utilized in order to determine where the player is.
If the player is on the grass: an onGrass object is instantiated
  this object has a pointer to the player, allowing for the player's pokemon and attacks to be changed if in battle
  also has a pointer to a wild pokemon, in case it is instantiated
  It calculates a random number, if the number is in a specific range a pokemon is created at a random level 1-20.
  It is more likely to not run into a random pokemon.
  If a pokemon is found in the grass the player goes into battle with the pokemon using stdin input
  The player may run away from pokemon found in grass.
  Damage is done to pokemon using the damage formula.
  The player, if they have pokeballs, can attempt to catch the pokemon according to the catch rate equation.

If the player enters the PC healing center door:
  All pokemon are healed. The player is placed slightly backwards to the PC door.

If the player enters the Store door:
  The player has the opportunity to buy pokeballs if they have cash using stdin.

If the player enters the Gym door:
  Instantiates 3 Fight objects using 3 trainers.
  The player has the opportunity to beat 3 trainers based on the Cerlulean Center Gym. Trainers can be beaten once.
  The player cannot run away from the battles. They either win, or all pokemon faint.
  Recommended to go back to the PC if this occurs.
  Similar to onGrass battles as Fight and onGrass are both derived from the Battle class (abstract). 
  Fight occurs using stdin

If the player enters the Home door:
  The game quits. Also can quit the game by Xing out of the window.

Known issues/features:
  -The collision is a bit off.
  -If you move up initially, the game will automatically quit. However, intentionally want to start at the Home door.
  -The Item class is created to be a lot more complex. Right now, it doesn't seem necessary to have the extra class but the class provides flexibility for the future. Could just keep track of the number of pokeballs, as the program does.
  -Collision detection is used around buildings. If you keep walking or change directions while the program is trying to move you off the building, you could be stuck moving until out of the particular rectangle boundaries that are a little off.
  -From time to time, a player could get stuck in the grass and keep running into pokemon. Issue doesn't occur often and may have been fixed with dealing with incorrect input update to handle strings.
  -Most input from stdin is error handled. It expects an integer of a certain range. If out of range, the program asks again. If the input is a string and not numeric as expected, it handles this efficiently. 
