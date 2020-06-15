/*********************************************************************
** Author: Karen Berba
** Date: 1/27/19
** Description:

Penguin class

Inherits from Animal class. Has a default constructor and a custom constructor that takes in an integer age.

NOTES:
- Penguin cost $1,000
- Penguins have 5 babies
- Penguins have a feeding cost that is the same as the base cost
- A penguin’s payoff per day is 10% of their cost per animal

*********************************************************************/

#include "Penguin.hpp"

/*
source(s):

https://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/

https://stackoverflow.com/questions/7405740/how-can-i-initialize-base-class-member-variables-in-derived-class-constructor

*/
// default constructor
Penguin::Penguin() : Animal(0) {    // age is 0 for baby penguins
  Penguin::setNumBabies(5);
  Penguin::setInitialCost(1000);
  Penguin::setFoodCost(BASE_FOOD_COST);
  Penguin::setPayoff(0.10 * 1000);
}


// custom constructor
Penguin::Penguin(int tAge) : Animal(tAge) {     // for newly bought penguins
  Penguin::setNumBabies(5);
  Penguin::setInitialCost(1000);
  Penguin::setFoodCost(BASE_FOOD_COST);
  Penguin::setPayoff(0.10 * 1000);
}
